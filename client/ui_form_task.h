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
    QLabel *horror;
    QLabel *sun;
    QPushButton *pushButton_ok;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser_task;
    QLineEdit *lineEdit;
    QLabel *egg;
    QPushButton *secret;

    void setupUi(QWidget *Form_task)
    {
        if (Form_task->objectName().isEmpty())
            Form_task->setObjectName(QString::fromUtf8("Form_task"));
        Form_task->resize(986, 323);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../../../Users/User/Documents/Temp\320\276\320\262\320\260\321\217 \321\205\321\203\320\271\320\275\321\217/easter egg.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        Form_task->setWindowIcon(icon);
        horror = new QLabel(Form_task);
        horror->setObjectName(QString::fromUtf8("horror"));
        horror->setEnabled(true);
        horror->setGeometry(QRect(630, 50, 261, 201));
        horror->setPixmap(QPixmap(QString::fromUtf8("../../../../../Users/User/Documents/Temp\320\276\320\262\320\260\321\217 \321\205\321\203\320\271\320\275\321\217/qt.png")));
        horror->setScaledContents(true);
        sun = new QLabel(Form_task);
        sun->setObjectName(QString::fromUtf8("sun"));
        sun->setEnabled(true);
        sun->setGeometry(QRect(600, 10, 381, 291));
        sun->setAutoFillBackground(false);
        sun->setStyleSheet(QString::fromUtf8(""));
        sun->setPixmap(QPixmap(QString::fromUtf8("../../../../../Users/User/Documents/Temp\320\276\320\262\320\260\321\217 \321\205\321\203\320\271\320\275\321\217/are u winning sun.jpg")));
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

        egg = new QLabel(Form_task);
        egg->setObjectName(QString::fromUtf8("egg"));
        egg->setGeometry(QRect(600, 30, 311, 241));
        egg->setPixmap(QPixmap(QString::fromUtf8("../../../../../Users/User/Documents/Temp\320\276\320\262\320\260\321\217 \321\205\321\203\320\271\320\275\321\217/easter egg.jpg")));
        egg->setScaledContents(true);
        secret = new QPushButton(Form_task);
        secret->setObjectName(QString::fromUtf8("secret"));
        secret->setEnabled(true);
        secret->setGeometry(QRect(720, 110, 81, 91));
        secret->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        egg->raise();
        horror->raise();
        sun->raise();
        pushButton_ok->raise();
        layoutWidget->raise();
        secret->raise();

        retranslateUi(Form_task);

        QMetaObject::connectSlotsByName(Form_task);
    } // setupUi

    void retranslateUi(QWidget *Form_task)
    {
        Form_task->setWindowTitle(QCoreApplication::translate("Form_task", "\320\227\320\260\320\264\320\260\320\275\320\270\320\265", nullptr));
        horror->setText(QString());
        sun->setText(QString());
        pushButton_ok->setText(QCoreApplication::translate("Form_task", "OK", nullptr));
        egg->setText(QString());
        secret->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Form_task: public Ui_Form_task {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_TASK_H
