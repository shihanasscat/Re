/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_task1;
    QPushButton *pushButton_task2;
    QPushButton *pushButton_task3;
    QPushButton *pushButton_task4;
    QPushButton *pushButton_new_group;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_stat;
    QPushButton *pushButton_exit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(469, 187);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../../../Users/User/Documents/Temp\320\276\320\262\320\260\321\217 \321\205\321\203\320\271\320\275\321\217/easter egg.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(30, 20, 403, 143));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_task1 = new QPushButton(verticalLayoutWidget_2);
        pushButton_task1->setObjectName(QString::fromUtf8("pushButton_task1"));

        horizontalLayout->addWidget(pushButton_task1);

        pushButton_task2 = new QPushButton(verticalLayoutWidget_2);
        pushButton_task2->setObjectName(QString::fromUtf8("pushButton_task2"));

        horizontalLayout->addWidget(pushButton_task2);

        pushButton_task3 = new QPushButton(verticalLayoutWidget_2);
        pushButton_task3->setObjectName(QString::fromUtf8("pushButton_task3"));

        horizontalLayout->addWidget(pushButton_task3);

        pushButton_task4 = new QPushButton(verticalLayoutWidget_2);
        pushButton_task4->setObjectName(QString::fromUtf8("pushButton_task4"));

        horizontalLayout->addWidget(pushButton_task4);


        verticalLayout_3->addLayout(horizontalLayout);

        pushButton_new_group = new QPushButton(verticalLayoutWidget_2);
        pushButton_new_group->setObjectName(QString::fromUtf8("pushButton_new_group"));

        verticalLayout_3->addWidget(pushButton_new_group);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton_stat = new QPushButton(verticalLayoutWidget_2);
        pushButton_stat->setObjectName(QString::fromUtf8("pushButton_stat"));

        verticalLayout->addWidget(pushButton_stat);

        pushButton_exit = new QPushButton(verticalLayoutWidget_2);
        pushButton_exit->setObjectName(QString::fromUtf8("pushButton_exit"));

        verticalLayout->addWidget(pushButton_exit);


        verticalLayout_3->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\234\320\265\320\275\321\216", nullptr));
        pushButton_task1->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\320\275\320\270\320\265 1", nullptr));
        pushButton_task2->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\320\275\320\270\320\265 2", nullptr));
        pushButton_task3->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\320\275\320\270\320\265 3", nullptr));
        pushButton_task4->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\320\275\320\270\320\265 4", nullptr));
        pushButton_new_group->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\275\320\276\320\262\321\203\321\216 \320\263\321\200\321\203\320\277\320\277\321\203", nullptr));
        pushButton_stat->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\320\260", nullptr));
        pushButton_exit->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
