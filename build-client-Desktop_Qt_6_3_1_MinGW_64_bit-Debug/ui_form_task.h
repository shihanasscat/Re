/********************************************************************************
** Form generated from reading UI file 'form_task.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_TASK_H
#define UI_FORM_TASK_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_task
{
public:
    QPushButton *pushButton_ok;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser_task;
    QLineEdit *lineEdit;
    QPushButton *secret;
    QLabel *ester;
    QLabel *sunraise;
    QLabel *task;

    void setupUi(QWidget *Form_task)
    {
        if (Form_task->objectName().isEmpty())
            Form_task->setObjectName(QString::fromUtf8("Form_task"));
        Form_task->resize(986, 323);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../Users/User/Documents/Temp\320\276\320\262\320\260\321\217 \321\205\321\203\320\271\320\275\321\217/easter egg.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        Form_task->setWindowIcon(icon);
        pushButton_ok = new QPushButton(Form_task);
        pushButton_ok->setObjectName(QString::fromUtf8("pushButton_ok"));
        pushButton_ok->setGeometry(QRect(240, 260, 75, 24));
        layoutWidget = new QWidget(Form_task);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 30, 521, 221));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        textBrowser_task = new QTextBrowser(layoutWidget);
        textBrowser_task->setObjectName(QString::fromUtf8("textBrowser_task"));

        verticalLayout->addWidget(textBrowser_task);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        secret = new QPushButton(Form_task);
        secret->setObjectName(QString::fromUtf8("secret"));
        secret->setEnabled(true);
        secret->setGeometry(QRect(720, 120, 81, 91));
        secret->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        ester = new QLabel(Form_task);
        ester->setObjectName(QString::fromUtf8("ester"));
        ester->setGeometry(QRect(650, 30, 241, 241));
        ester->setPixmap(QPixmap(QString::fromUtf8("easter_egg.jpg")));
        ester->setScaledContents(true);
        sunraise = new QLabel(Form_task);
        sunraise->setObjectName(QString::fromUtf8("sunraise"));
        sunraise->setGeometry(QRect(610, 20, 291, 281));
        sunraise->setPixmap(QPixmap(QString::fromUtf8("are_u_winning_sun.jpg")));
        sunraise->setScaledContents(true);
        task = new QLabel(Form_task);
        task->setObjectName(QString::fromUtf8("task"));
        task->setGeometry(QRect(640, 30, 241, 241));
        task->setPixmap(QPixmap(QString::fromUtf8("qt.png")));
        task->setScaledContents(true);
        task->raise();
        ester->raise();
        pushButton_ok->raise();
        layoutWidget->raise();
        sunraise->raise();
        secret->raise();

        retranslateUi(Form_task);

        QMetaObject::connectSlotsByName(Form_task);
    } // setupUi

    void retranslateUi(QWidget *Form_task)
    {
        Form_task->setWindowTitle(QCoreApplication::translate("Form_task", "\320\227\320\260\320\264\320\260\320\275\320\270\320\265", nullptr));
        pushButton_ok->setText(QCoreApplication::translate("Form_task", "OK", nullptr));
        secret->setText(QString());
        ester->setText(QString());
        sunraise->setText(QString());
        task->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Form_task: public Ui_Form_task {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_TASK_H
