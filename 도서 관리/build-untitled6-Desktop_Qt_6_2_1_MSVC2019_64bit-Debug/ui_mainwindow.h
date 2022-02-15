/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QWidget *widget_F1;
    QLineEdit *lineEdit_F1;
    QPushButton *pushButton_F1;
    QLabel *label_F1;
    QWidget *widget_F2;
    QTextBrowser *textBrowser_F2;
    QWidget *widget_F3;
    QLineEdit *lineEdit_F3;
    QLineEdit *lineEdit_2_F3;
    QLineEdit *lineEdit_3_F3;
    QPushButton *pushButton_4;
    QLabel *label_F3;
    QWidget *tab_2;
    QPushButton *pushButton_5;
    QLabel *label_F4;
    QLineEdit *lineEdit_F4;
    QPushButton *pushButton_F4;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QWidget *tab_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 581, 341));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 91, 24));
        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(110, 10, 111, 24));
        pushButton_3 = new QPushButton(tab);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(230, 10, 111, 24));
        widget_F1 = new QWidget(tab);
        widget_F1->setObjectName(QString::fromUtf8("widget_F1"));
        widget_F1->setGeometry(QRect(10, 50, 241, 111));
        lineEdit_F1 = new QLineEdit(widget_F1);
        lineEdit_F1->setObjectName(QString::fromUtf8("lineEdit_F1"));
        lineEdit_F1->setGeometry(QRect(20, 40, 113, 23));
        pushButton_F1 = new QPushButton(widget_F1);
        pushButton_F1->setObjectName(QString::fromUtf8("pushButton_F1"));
        pushButton_F1->setGeometry(QRect(140, 40, 86, 24));
        label_F1 = new QLabel(widget_F1);
        label_F1->setObjectName(QString::fromUtf8("label_F1"));
        label_F1->setGeometry(QRect(70, 10, 64, 15));
        widget_F2 = new QWidget(tab);
        widget_F2->setObjectName(QString::fromUtf8("widget_F2"));
        widget_F2->setGeometry(QRect(280, 60, 191, 131));
        textBrowser_F2 = new QTextBrowser(widget_F2);
        textBrowser_F2->setObjectName(QString::fromUtf8("textBrowser_F2"));
        textBrowser_F2->setGeometry(QRect(10, 20, 256, 91));
        widget_F3 = new QWidget(tab);
        widget_F3->setObjectName(QString::fromUtf8("widget_F3"));
        widget_F3->setGeometry(QRect(10, 190, 321, 141));
        lineEdit_F3 = new QLineEdit(widget_F3);
        lineEdit_F3->setObjectName(QString::fromUtf8("lineEdit_F3"));
        lineEdit_F3->setGeometry(QRect(20, 10, 113, 23));
        lineEdit_2_F3 = new QLineEdit(widget_F3);
        lineEdit_2_F3->setObjectName(QString::fromUtf8("lineEdit_2_F3"));
        lineEdit_2_F3->setGeometry(QRect(20, 40, 113, 23));
        lineEdit_3_F3 = new QLineEdit(widget_F3);
        lineEdit_3_F3->setObjectName(QString::fromUtf8("lineEdit_3_F3"));
        lineEdit_3_F3->setGeometry(QRect(20, 70, 113, 23));
        pushButton_4 = new QPushButton(widget_F3);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(180, 70, 86, 24));
        label_F3 = new QLabel(widget_F3);
        label_F3->setObjectName(QString::fromUtf8("label_F3"));
        label_F3->setGeometry(QRect(190, 40, 91, 21));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        pushButton_5 = new QPushButton(tab_2);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(30, 20, 86, 24));
        label_F4 = new QLabel(tab_2);
        label_F4->setObjectName(QString::fromUtf8("label_F4"));
        label_F4->setGeometry(QRect(60, 70, 64, 15));
        lineEdit_F4 = new QLineEdit(tab_2);
        lineEdit_F4->setObjectName(QString::fromUtf8("lineEdit_F4"));
        lineEdit_F4->setGeometry(QRect(90, 120, 113, 23));
        pushButton_F4 = new QPushButton(tab_2);
        pushButton_F4->setObjectName(QString::fromUtf8("pushButton_F4"));
        pushButton_F4->setGeometry(QRect(250, 120, 86, 24));
        pushButton_6 = new QPushButton(tab_2);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(130, 20, 171, 24));
        pushButton_7 = new QPushButton(tab_2);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(310, 20, 231, 24));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        tabWidget->addTab(tab_3, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(pushButton, &QPushButton::clicked, widget_F1, qOverload<>(&QWidget::show));
        QObject::connect(pushButton_2, &QPushButton::clicked, widget_F2, qOverload<>(&QWidget::show));
        QObject::connect(pushButton_2, &QPushButton::clicked, widget_F1, qOverload<>(&QWidget::hide));
        QObject::connect(pushButton_3, &QPushButton::clicked, widget_F3, qOverload<>(&QWidget::show));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\354\236\245\353\245\264 \354\266\224\352\260\200 F1", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\354\240\204\354\262\264 \354\236\245\353\245\264\353\263\264\352\270\260 F2", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\353\217\204\354\204\234 \354\266\224\352\260\200 F3", nullptr));
        pushButton_F1->setText(QCoreApplication::translate("MainWindow", "\354\266\224\352\260\200", nullptr));
        label_F1->setText(QString());
        lineEdit_F3->setText(QCoreApplication::translate("MainWindow", "ISBN", nullptr));
        lineEdit_2_F3->setText(QCoreApplication::translate("MainWindow", "\354\236\245\353\245\264no", nullptr));
        lineEdit_3_F3->setText(QCoreApplication::translate("MainWindow", "\354\261\205 \354\240\234\353\252\251", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "\354\266\224\352\260\200", nullptr));
        label_F3->setText(QCoreApplication::translate("MainWindow", "\353\217\204\354\204\234 \354\266\224\352\260\200", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "\353\217\204\354\204\234 \354\202\255\354\240\234 F4", nullptr));
        label_F4->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pushButton_F4->setText(QCoreApplication::translate("MainWindow", "\354\266\224\352\260\200/\354\202\255\354\240\234", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "ISBN\354\234\274\353\241\234 \353\217\204\354\204\234 \343\204\261\343\205\223\343\205\201\354\203\211 F5", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "\355\212\271\354\240\225 \354\236\245\353\245\264 \353\217\204\354\204\234 \352\262\200\354\203\211 F6", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Tab 2", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Page", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
