#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "about.h"
#include <QMainWindow>
#include <QWidget>
#include <QListWidgetItem>
#include <QtNetwork>


using std::string;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void getAllNotes(QString user); //데이터베이스에서 사용자의 메모 목록을 요청합니다.
    QStringList noteNameList;

public slots:
    void readAllNotes(); //getAllNotes()에서 보낸 네트워크 요청의 네트워크 응답을 읽습니다.
    void showNote(); //plaintextedit에 메모를 보여줍니다.
    void readUNVali(); //validateUsername()에서 보낸 네트워크 요청의 네트워크 응답을 읽습니다.


    void readLAuth(); //로그인시 동작 함수//loginAuth()에서 보낸 네트워크 요청의 네트워크 응답을 읽습니다
    void enableEditDelete(); //목록에서 메모를 선택하면 편집 및 삭제 버튼 활성화

private slots:
    void on_listWidget_itemClicked(QListWidgetItem *item); //리스트 위젯에 문자 클릭했을때 동작하는 함수
    void on_btnNavLogin_clicked();
    void on_btnNavSignup_clicked();
    void on_btnCancelLogin_clicked();
    void on_btnCancelSignup_clicked();
    void on_btnNavCreate_clicked();
    void on_btnCancelSave_clicked();
    void on_btnSignupCreate_clicked(); //로그인 클릭함수  성공시 validateUsername();
    void on_btnSaveNote_clicked();  //메모 저장 함수 성공시 pushNote(); 호출
    void on_btnLogin_clicked();  //로그인시 실행될 함수 성공시 loginAuth() 호출
    void on_btnEditNote_clicked();  //on_btnEditNote_clicked 호출
    void on_btnDeleteNote_clicked(); //on_btnDeleteNote_clicked 호출 함수
    void on_btnAuthLogout_clicked(); // confirmLogout(); 호출
    void on_listWidget_itemSelectionChanged(); // enableEditDelete(); 호출
    void on_btnRefresh_clicked(); //호출
    void on_btnAbout_clicked();

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager * netMngNotes;
    QNetworkReply * netRepGetNotes;
    QNetworkReply * netRepShowNote;
    QNetworkReply * netRepValUN;
    QNetworkReply * netRepAuth;
    QNetworkReply * netDelNote;
    QNetworkReply * netRepAuthAuto;
    QString selectedNote;
    QString newUN;
    QString newPW;
    QString newName;
    QString loginUN;
    QString loginPW;
    QString storedUN;
    QString storedPW;
    QString authUser;
    QString authName;
    QStringList noteList;
    bool editOn = false;
    QRegularExpression rx;
    QValidator *validator;
    About *about;


    void showAbout(); //1.번 새로운 창 열리는 버튼

    void getNote(QString notename); //데이터베이스에서 주어진 메모를 가져옵니다.
    void pushNote(); //데이터베이스에 메모를 보냅니다.
    void editNote(); //에디트 모드로 전환
    void deleteNote(); //선택한 메모에 삭제 요청을 보냅니다.
    void showNoteList(); //받은 메모 목록을 listWidget에 추가합니다.
    void validateUsername(); //사용자 이름이 이미 사용 중인지 확인하거나 가입할 때 메모
    void createAccount(); //어카운트 등록 함수
    void loginAuth(); //로그인 버튼 누르면 동작 하는 함수
    void loginAuthAuto();//텍스트 파일에 저장된 자격 증명에 의한 자동 로그인
    void readLAuthAuto(); //loginAuthAuto()에서 보낸 네트워크 요청의 네트워크 응답을 읽습니다.
    void showAlert(QString msg); //메세지 보낼때 표시 되는 작은창
    void refresh(); //보기를 새로 고치고 데이터베이스에서 데이터를 다시 가져옵니다.
    void confirmDelete();//메모를 삭제하기 전에 확인 받기
    void confirmLogout(); //로그아웃하기 전에 확인 받기
    void logout(); // 로그아웃하고 사용자 데이터를 지웁니다.
    void readAuthFile();  //자동 로그인을 위한 파일 인증
    void setAuthFile(QStringList authstrlist); //로그인 또는 로그아웃 시 authuser.txt 파일 작성
    bool checkTitle(QString title); //사용자가 이미 주어진 Qstring 제목을 가진 메모를 가지고 있는지 확인합니다

};

#endif // MAINWINDOW_H
