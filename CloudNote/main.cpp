#include "mainwindow.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //아이콘 설정
    a.setWindowIcon(QIcon(":/img/res/img/appicon.ico"));

    //스타일 시트 설정
    QFile stylefile(":/style/res/style/cloudnotestyle.qss");
    stylefile.open(QFile::ReadOnly);
    QString stylesheet = QLatin1String(stylefile.readAll());
    a.setStyleSheet(stylesheet);

    //윈도우 시작
    MainWindow w;
    w.setWindowTitle("클라우드 노트");
    w.show();

    return a.exec();
}
