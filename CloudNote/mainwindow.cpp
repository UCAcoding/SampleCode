#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include <QRegularExpression>  //정규식
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    //NetworkAccessManager 객체 생성
    netMngNotes = new QNetworkAccessManager(this);

    //로딩 스크린 에니메이션 설정
    QMovie *movie = new QMovie(":/img/res/img/loading.gif");
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(5); //로딩창
    ui->labelGif->setMovie(movie);
    movie->start();

    //라벨에 넣을 이미지 세팅
    QPixmap logo1(":/img/res/img/cloudnote.png");
    ui->labelLogo->setPixmap(logo1.scaled(250,250,Qt::KeepAspectRatio));
    ui->labelLogin->setPixmap(logo1.scaled(120,120,Qt::KeepAspectRatio));
    ui->labelSignup->setPixmap(logo1.scaled(120,120,Qt::KeepAspectRatio));
    ui->labelLogo2->setPixmap(logo1.scaled(120,120,Qt::KeepAspectRatio));
    QPixmap logo2(":/img/res/img/applogo.png");
    ui->noteLogo->setPixmap(logo2.scaled(28,28,Qt::KeepAspectRatio));

    //라인 에디트에 넣을 정규식 패턴일이 객체들
//    /정규 표현식 (regexs 또는 regexps라고도 함)은 조작 된 문자열에서 일치 할 수있는 패턴을 나타내는 텍스트 구문입니다.

    //자주쓰는 정규식 https://gocoding.tistory.com/93
    QRegularExpression rxUN("[A-Za-z0-9]{4,20}");  //유저 네임 넣을수 있는 문자들
    //QValidator는 입력을 제한할 수 있는 기능을 가지고 있습니다.
    //rxUN의 입력 이상은 제한하게 된다.
    QValidator *valiUN = new QRegularExpressionValidator(rxUN, this);

    QRegularExpression rxPW("[A-Za-z0-9]{6,20}"); //패스워드 넣을수 있는 문자들
    QValidator *valiPW = new QRegularExpressionValidator(rxPW, this);
                                        //\\은 쉼표 같은 것이다 \\s는 공백문자가 일치한다 대문자S는 공백문자가 아닌것 일치
    QRegularExpression rxTitle("[A-Za-z0-9\\s]{1,100}");  //타이틀 넣을수 있는 문자들
    QValidator *valiTitle = new QRegularExpressionValidator(rxTitle, this);

    //QLineEdit와 QComboBox로 입력을 받을 때 입력이 가능한 유효문자열을 밸리데이터(QValidator)로 제한할 수 있다. Qt는
    ui->lineLoginUN->setValidator(valiUN);
    ui->lineLoginPW->setValidator(valiPW);
    ui->lineSignupUN->setValidator(valiUN);
    ui->lineSignupPW->setValidator(valiPW);
    ui->lineSignupPWRe->setValidator(valiPW);
    ui->lineAddTitle->setValidator(valiTitle);

    //사용자 자동 로그인을 위한 텍스트 파일에 인증 데이터가 있는지 확인
    readAuthFile();

}

MainWindow::~MainWindow()
{
    delete ui;
}


//자동 로그인을 위한 인증
// authuser.txt
void MainWindow::readAuthFile()
{
    qDebug() << "890";

    QStringList authList;

    QFile authFile("authuser.txt");

    if (authFile.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        while (!authFile.atEnd()) authList.append(authFile.readLine());
    }
    authFile.close();

    //qDebug() << authList[0] << authList[1] << authList[2];

    if(!authList.isEmpty())
    {
        if(authList[0]=="loggedin\n")
        {
            storedUN = authList[1].remove("\n");
            qDebug() << authList[1].remove("\n");
            storedPW = authList[2].remove("\n");
            qDebug() << authList[2].remove("\n");
            loginAuthAuto();
        }
        else
        {
            ui->stackedWidget->setCurrentIndex(0);
        }
    }
    else
    {
       ui->stackedWidget->setCurrentIndex(0);
    }




}

//로그인 또는 로그아웃 시 authuser.txt 파일 작성
void MainWindow::setAuthFile(QStringList authstrlist)
{
    QFile newauthfile("authuser.txt");
    if (newauthfile.open(QIODevice::ReadWrite)) {
        QTextStream stream(&newauthfile);
        stream << authstrlist[0] << "\n";
        stream << authstrlist[1] << "\n";
        stream << authstrlist[2] << "\n";
    }
    newauthfile.close();
    ui->stackedWidget->setCurrentIndex(0);
}




//사용자가 이미 주어진 Qstring 제목을 가진 메모를 가지고 있는지 확인합니다
bool MainWindow::checkTitle(QString title)
{
    for (auto& i : noteList)
    {
        qDebug() << i << "note";
        if(i == title){
            return false;
            break;
        }
    }
    return true;
}


//사용자 이름이 이미 사용 중인지 확인하거나 가입할 때 메모
void MainWindow::validateUsername()
{
    newUN = ui->lineSignupUN->text();
    newPW = ui->lineSignupPW->text();
    newName = ui->lineSignupName->text();

    QString url = "https://test-9f6f3-default-rtdb.firebaseio.com/" + newUN + "/auth/username.json";
    //qDebug() << url;

    netRepValUN = netMngNotes->get(QNetworkRequest(QUrl(url)));
    connect(netRepValUN, &QNetworkReply::readyRead, this, &MainWindow::readUNVali);

}

//validateUsername()에서 보낸 네트워크 요청의 네트워크 응답을 읽습니다.
void MainWindow::readUNVali()
{
    QByteArray valResult = netRepValUN->readAll();
    qDebug() << valResult << "123";
    if(valResult == "null"){
        qDebug() << "Valid";
        createAccount();
    }
    else
    {
        qDebug() << "Not Valid";
        showAlert("누군가 이미 그 사용자 이름을 사용하고 있습니다! 새 사용자 이름을 입력하세요.");
    }
}

//어카운트 등록 함수
void MainWindow::createAccount()
{
    QVariantMap newAccVM;
    newAccVM["username"] = newUN;
    newAccVM["password"] = newPW;
    newAccVM["name"] = newName;
    QJsonDocument newAccJson = QJsonDocument::fromVariant(newAccVM);

    QString url = "https://test-9f6f3-default-rtdb.firebaseio.com/" + newUN + "/auth.json";
    qDebug() << url;

    QNetworkRequest newAccReq((QUrl(url)));
    newAccReq.setHeader(QNetworkRequest::ContentTypeHeader, QString("application/json"));
    netMngNotes->put(newAccReq, newAccJson.toJson());

    ui->lineSignupUN->clear();
    ui->lineSignupPW->clear();
    ui->lineSignupPWRe->clear();
    showAlert("등록 성공! 다음 화면에서 로그인");
    ui->stackedWidget->setCurrentIndex(1);  //1번 페이지로 이동
}


//로그인 버튼 누르면 동작 하는 함수
//아이디랑 패스워드를 가져와서 동작 한다
void MainWindow::loginAuth()
{  //텍스트 가져 오고
    loginUN = ui->lineLoginUN->text();
    loginPW = ui->lineLoginPW->text();
  //파이어베이스랑 대조 한다
    QString url = "https://test-9f6f3-default-rtdb.firebaseio.com/" + loginUN + "/auth.json";
    netRepAuth = netMngNotes->get(QNetworkRequest(QUrl(url)));
    //커넥트 설명 할 것  json파일을 읽어서 readLAuthg함수로 간다
    connect(netRepAuth, &QNetworkReply::readyRead, this, &MainWindow::readLAuth);

}


//로그인 동작 함수
//loginAuth()에서 보낸 네트워크 요청의 네트워크 응답을 읽습니다
//
void MainWindow::readLAuth()
{   //위 읽어온 json파일을 authResult로 보낸다.
    QByteArray authResult = netRepAuth->readAll();
    qDebug() << authResult << "456";
    if(authResult != "null")  //파일이 어떤 문자가 있다면
    {
        QString auth = QString(authResult);
        auth.remove('"');  //분해 한다
        auth.remove('{');
        auth.remove('}');
        auth.remove('\\');
        QRegularExpression separator("[(,|:|)]");
        QStringList unamepw = auth.split(separator);
        qDebug() << unamepw; //확인 부터 하고

        //몇번째 리스트인지 확인서 출력
        if(loginUN == unamepw[5] && loginPW == unamepw[3])
        {
            qDebug() << "234";
            authUser = loginUN;
            authName = unamepw[1];
            QStringList auth = {"로그인",loginUN,loginPW};
            setAuthFile(auth);  //로그인 사용자 데이터를 setAuthfile로 보낸다. txt로 만들어진다.
            showAlert("좋아요" + authName + "! \n로그인 성공.");
            ui->lineLoginUN->clear();
            ui->lineLoginPW->clear();
            ui->stackedWidget->setCurrentIndex(3);
            getAllNotes(authUser);
            ui->labelUsersNotes->setText(authName + "'s Notes");
        }
        else
        {

            ui->lineLoginUN->clear();
            ui->lineLoginPW->clear();
            showAlert("잘못된 비밀번호나 아뒤!");
        }
    }
    else
    {
        qDebug() << "잘못 이름";
        ui->lineLoginUN->clear();
        ui->lineLoginPW->clear();
        showAlert("이름이 존재하지 않음!");
    }


}

//텍스트 파일에 저장된 자격 증명에 의한 자동 로그인
void MainWindow::loginAuthAuto()
{
    QString url = "https://test-9f6f3-default-rtdb.firebaseio.com/" + storedUN + "/auth.json";
    netRepAuthAuto = netMngNotes->get(QNetworkRequest(QUrl(url)));
    connect(netRepAuthAuto, &QNetworkReply::readyRead, this, &MainWindow::readLAuthAuto);

}

//loginAuthAuto()에서 보낸 네트워크 요청의 네트워크 응답을 읽습니다.
void MainWindow::readLAuthAuto()
{
    QByteArray authResult = netRepAuthAuto->readAll();
    //qDebug() << authResult << "456";
    QString auth = QString(authResult);
    auth.remove('"');
    auth.remove('{');
    auth.remove('}');
    auth.remove('\\');
    QRegularExpression separator("[(,|:|)]");
    QStringList unamepw = auth.split(separator);
    //qDebug() << unamepw;
    if(storedUN == unamepw[5] && storedPW == unamepw[3])
    {
        //qDebug() << "234";
        authUser = storedUN;
        authName = unamepw[1];
        ui->stackedWidget->setCurrentIndex(3);
        getAllNotes(authUser);
        ui->labelUsersNotes->setText(authName + "'s Notes");
    }
    else
    {
        //qDebug() << "잘못된 사용자 이름 또는 비밀번호";
        ui->stackedWidget->setCurrentIndex(0);
    }

}

//목록에서 메모를 선택하면 편집 및 삭제 버튼 활성화
void MainWindow::enableEditDelete()
{
    ui->btnEditNote->setEnabled(true);
    ui->btnDeleteNote->setEnabled(true);
}

//메세지 보낼때 표시 되는 함수
void MainWindow::showAlert(QString msg)
{   //메시지 박스 설정
    QMessageBox::information(this, "내 메모장", msg);
}


//보기를 새로 고치고 데이터베이스에서 데이터를 다시 가져옵니다.
void MainWindow::refresh()
{
    ui->listWidget->clear();
    ui->lineNoteTitle->clear();
    ui->plainTextEdit->clear();
    ui->btnEditNote->setEnabled(false);
    ui->btnDeleteNote->setEnabled(false);
    getAllNotes(authUser);
}

//메모를 삭제하기 전에 확인 받기
void MainWindow::confirmDelete()
{
    //메시지 박스 버튼 설정
    QMessageBox::StandardButton reply = QMessageBox::question(this,"삭제 확인", "선택한 항목을 삭제 함?", QMessageBox::Yes | QMessageBox::No);

    if(reply == QMessageBox::Yes){
        deleteNote();  //딜리트 노트로 감
    }
}




//로그아웃하기 전에 확인 받기
void MainWindow::confirmLogout()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this,"로그아웃 확인", "로그아웃 할래?", QMessageBox::Yes | QMessageBox::No);

    if(reply == QMessageBox::Yes){
        logout();  //로그아웃이 아래 함수 go
    }
}

//로그아웃하고 사용자 데이터를 지웁니다.
void MainWindow::logout()
{
    qDebug() << "로그아웃";
    QStringList lout = {"loggedout","null","null"};
    ui->stackedWidget->setCurrentIndex(5);  //로딩창이 잠깐 든다
    ui->listWidget->clear();

    noteList.clear();
    ui->lineAddTitle->clear();
    ui->lineNoteTitle->clear();
    ui->plainNoteText->clear();
    ui->plainTextEdit->clear();
    setAuthFile(lout);  //로그아웃 사용자 데이터를 setAuthFile로 보낸다 .
}

//데이터베이스에서 사용자의 메모 목록을 요청합니다.
void MainWindow::getAllNotes(QString user)
{
    //qDebug() << "getting all notes" << user;

    QString url = "https://test-9f6f3-default-rtdb.firebaseio.com/" + user + "/notenames.json";
    //qDebug() << url << "678";
    netRepGetNotes = netMngNotes->get(QNetworkRequest(QUrl(url)));
    connect(netRepGetNotes, &QNetworkReply::readyRead, this, &MainWindow::readAllNotes );
}

//받은 메모 목록을 listWidget에 추가합니다.
void MainWindow::showNoteList()
{
    ui->listWidget->clear();
    for (auto& i : noteList)
    {
        //qDebug() << i;
        if(i != "null"){
            ui->listWidget->addItem(i);
            //ui->listWidget->addItem("1234");
        }
    }

}

//getAllNotes()에서 보낸 네트워크 요청의 네트워크 응답을 읽습니다.
void MainWindow::readAllNotes()
{
    QByteArray noteListQb = netRepGetNotes->readAll();
    //qDebug() << noteListQb;

    if(noteListQb != "null"){

        QString noteListStr = QString(noteListQb);
        qDebug() << noteListStr;
        noteListStr.remove('"');
        noteListStr.remove('[');
        noteListStr.remove(']');
        noteListStr.remove('{');
        noteListStr.remove('}');
        noteListStr.remove('~');
        noteListStr.remove(':');
        //qDebug() << noteListStr;

        QStringList noteNameList = noteListStr.split(",");
        //qDebug() << noteNameList;
        noteList = noteNameList;
        showNoteList();
    }
    else{
        //qDebug() << noteListQb << "345";
        showAlert("아직 메모가 없습니다. 첫 번째 메모를 작성하세요");
    }


}

//shows the given the note in the plaintextedit
void MainWindow::showNote()
{
    QByteArray showNoteQb = netRepShowNote->readAll();  //글자를 모두 일거 보낸다
    QString showNoteStr = QString(showNoteQb);
    qDebug() << showNoteStr;
    showNoteStr.remove('"');

    if(!editOn){
        ui->plainTextEdit->setPlainText(showNoteStr);
    }
    else{
        ui->plainNoteText->setPlainText(showNoteStr);
    }

}

//데이터베이스에서 주어진 메모를 가져옵니다.
void MainWindow::getNote(QString notename)
{

    QString url = "https://test-9f6f3-default-rtdb.firebaseio.com/" + authUser + "/notes/" + notename + "/content.json";

    qDebug() << url;
    netRepShowNote = netMngNotes->get(QNetworkRequest(QUrl(url)));
    connect(netRepShowNote, &QNetworkReply::readyRead, this, &MainWindow::showNote);
}

//데이터베이스에 메모를 보냅니다.
void MainWindow::pushNote()
{

    QString newtitle = ui->lineAddTitle->text();

    QString url = "https://test-9f6f3-default-rtdb.firebaseio.com/" + authUser + "/notes/" + newtitle + ".json";

    QVariantMap newNoteVM;
    newNoteVM["content"] = ui->plainNoteText->toPlainText();
    QJsonDocument newNoteJson = QJsonDocument::fromVariant(newNoteVM);

    QNetworkRequest newNoteReq((QUrl(url)));
    newNoteReq.setHeader(QNetworkRequest::ContentTypeHeader, QString("application/json"));
    netMngNotes->put(newNoteReq, newNoteJson.toJson());

    QString url2 = "https://test-9f6f3-default-rtdb.firebaseio.com/" + authUser + "/notenames.json";

    QVariantMap uplistVM;

    if(!editOn){
       noteList.append(newtitle);
    }
    else{
        editOn = false;
    }

    for (auto& i : noteList)
    {
        //qDebug() << i;
        if(i != "null"){
            uplistVM[i] = "~";
        }
    }

    QJsonDocument upListJson = QJsonDocument::fromVariant(uplistVM);

    QNetworkRequest upListReq((QUrl(url2)));
    upListReq.setHeader(QNetworkRequest::ContentTypeHeader, QString("application/json"));
    netMngNotes->put(upListReq, upListJson.toJson());

    ui->lineAddTitle->clear();
    ui->plainNoteText->clear();
    ui->stackedWidget->setCurrentIndex(3);

    ui->labelSaveEdit->setText("새로운 노트를 만듭니다.");
    ui->lineAddTitle->setReadOnly(false);
    ui->btnSaveNote->setText("저장");

    showAlert("노트 저장!");
    refresh();

}

//에디트 모드로 전환
void MainWindow::editNote()
{
    editOn = true;
    ui->stackedWidget->setCurrentIndex(4);
    ui->labelSaveEdit->setText("Edit Your Note. (note title can't be changed)");
    ui->lineAddTitle->setReadOnly(true);
    ui->btnSaveNote->setText("SAVE");
    ui->lineAddTitle->setText(selectedNote);
    getNote(selectedNote);
}

//sends delete request to the selected note
void MainWindow::deleteNote()
{
    QString url = "https://test-9f6f3-default-rtdb.firebaseio.com/" + authUser + "notes/" + selectedNote + ".json";
    netDelNote = netMngNotes->deleteResource(QNetworkRequest(QUrl(url)));

    QVariantMap uplistVM;
    noteList.removeAll(selectedNote);

    for (auto& i : noteList)
    {
        //qDebug() << i;
        if(i != "null"){
            uplistVM[i] = "~";
        }
    }

    QString url2 = "https://test-9f6f3-default-rtdb.firebaseio.com/" + authUser + "/notenames.json";

    QJsonDocument upListJson = QJsonDocument::fromVariant(uplistVM);
    QNetworkRequest upListReq((QUrl(url2)));
    upListReq.setHeader(QNetworkRequest::ContentTypeHeader, QString("application/json"));
    netMngNotes->put(upListReq, upListJson.toJson());

    showAlert("Note Deleted!");
    refresh();
}

//1.번 새로운 창 열리는 버튼
void MainWindow::showAbout()
{
    About about;
    about.setModal(true);  //모달 다이얼 로그 창을 연다
    about.exec();  //사용 종료
}

//***********************funtion buttons slots************************************************
void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{//리스트 위젯에 문자 클릭했을때 동작하는 함수
    //리스트 위젯에서 오른쪽 버튼 눌러서 itemclicked를 선택해야 한다
    //qDebug() << item->text();
    selectedNote = item->text();
    ui->lineNoteTitle->setText(selectedNote);
    getNote(selectedNote);
}


void MainWindow::on_btnSignupCreate_clicked()
{
    if( ui->lineSignupUN->text()=="" || ui->lineSignupPW->text()=="" || ui->lineSignupPWRe->text()=="" ){
        //메세지 박스로 만들어진 알렛 함수 만들것
        showAlert("모든 세부 사항을 기입하십시오");
    }
    else if(ui->lineSignupPW->text() != ui->lineSignupPWRe->text())
    {
        showAlert("비밀 번호 매칭 실패");
    }
    else if(!(ui->lineSignupUN->text().length() >= 4 && ui->lineSignupPW->text().length() >= 6))
    {
        showAlert("사용자 이름  4-20 이어야 합니다. 비밀번호 길이는 6-20이어야 합니다.");
    }
    else{
        validateUsername();
    }
}


void MainWindow::on_btnLogin_clicked()
{   //글자를 모두 안채웠다면
    if(ui->lineLoginUN->text() == "" || ui->lineLoginPW->text() == ""){
        showAlert("닉넴과 패스워드 채울것!");
    }
    else{ //모두 채웠다면
        //아래 함수로 이동
        loginAuth();
    }

}


void MainWindow::on_btnSaveNote_clicked()
{

    if(ui->lineAddTitle->text().length() > 0 && ui->plainNoteText->toPlainText().length() > 0){

        if(editOn){
            pushNote();
        }
        else{
            if(checkTitle(ui->lineAddTitle->text()))
            {
                pushNote();
                //qDebug() << "Note title is unique";

            }
            else
            {
                showAlert("이미 해당 제목의 메모가 있습니다! 다른 제목을 입력하세요.");
            }
        }

        //qDebug() << "valid title";
    }
    else
    {
        showAlert("모든 필드 입력하세요");
        //qDebug() << "invalid title";
    }
    //
}


void MainWindow::on_btnDeleteNote_clicked()
{
    confirmDelete();
}


void MainWindow::on_btnEditNote_clicked()
{
    editNote();
}


void MainWindow::on_btnAuthLogout_clicked()
{
    confirmLogout();
}


void MainWindow::on_listWidget_itemSelectionChanged()
{
    enableEditDelete();
}


void MainWindow::on_btnRefresh_clicked()
{
    refresh();
}


//***********************navigation buttons slots*********************************************
void MainWindow::on_btnNavLogin_clicked()
{  //인덱스 1번 페이지로
    ui->stackedWidget->setCurrentIndex(1);
}



//2번째,   가입하는 만들기  버튼
void MainWindow::on_btnNavSignup_clicked()
{  //인덱스 2번 페이지로 이동
    ui->stackedWidget->setCurrentIndex(2);

}

void MainWindow::on_btnCancelLogin_clicked()
{//캔슬 버튼을 누르면 인덱스 0번 페이지로 이동
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_btnCancelSignup_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_btnNavCreate_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void MainWindow::on_btnCancelSave_clicked()
{
    if(editOn){
        editOn = false;
    }
    ui->stackedWidget->setCurrentIndex(3);
    ui->labelSaveEdit->setText("새로운 노트 만듬");
    ui->lineAddTitle->setReadOnly(false);
    ui->btnSaveNote->setText("SAVE");
}


void MainWindow::on_btnAbout_clicked()
{  //어바웃 위젯 창 열리는 버튼
    showAbout();
}

















