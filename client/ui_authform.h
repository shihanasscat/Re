/********************************************************************************
** Form generated from reading UI file 'authform.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHFORM_H
#define UI_AUTHFORM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDial>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AuthForm
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_4name;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButtonback_to_auth;
    QPushButton *pushButton_reg;
    QPushButton *pushButton_ok;
    QRadioButton *radioButton_student;
    QRadioButton *radioButton_teacher;
    QLineEdit *lineEdit_1log;
    QLineEdit *lineEdit_3email;
    QLineEdit *lineEdit_2pass;
    QLineEdit *lineEdit_5surname;
    QDial *dial;

    void setupUi(QWidget *AuthForm)
    {
        if (AuthForm->objectName().isEmpty())
            AuthForm->setObjectName(QString::fromUtf8("AuthForm"));
        AuthForm->resize(386, 271);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../../../Users/User/Documents/Temp\320\276\320\262\320\260\321\217 \321\205\321\203\320\271\320\275\321\217/easter egg.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        AuthForm->setWindowIcon(icon);
        gridLayout_2 = new QGridLayout(AuthForm);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit_4name = new QLineEdit(AuthForm);
        lineEdit_4name->setObjectName(QString::fromUtf8("lineEdit_4name"));

        gridLayout->addWidget(lineEdit_4name, 4, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        toolButtonback_to_auth = new QToolButton(AuthForm);
        toolButtonback_to_auth->setObjectName(QString::fromUtf8("toolButtonback_to_auth"));

        horizontalLayout->addWidget(toolButtonback_to_auth);

        pushButton_reg = new QPushButton(AuthForm);
        pushButton_reg->setObjectName(QString::fromUtf8("pushButton_reg"));
        pushButton_reg->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(pushButton_reg);

        pushButton_ok = new QPushButton(AuthForm);
        pushButton_ok->setObjectName(QString::fromUtf8("pushButton_ok"));
        pushButton_ok->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(pushButton_ok);


        gridLayout->addLayout(horizontalLayout, 9, 0, 1, 1);

        radioButton_student = new QRadioButton(AuthForm);
        radioButton_student->setObjectName(QString::fromUtf8("radioButton_student"));

        gridLayout->addWidget(radioButton_student, 7, 0, 1, 1);

        radioButton_teacher = new QRadioButton(AuthForm);
        radioButton_teacher->setObjectName(QString::fromUtf8("radioButton_teacher"));

        gridLayout->addWidget(radioButton_teacher, 8, 0, 1, 1);

        lineEdit_1log = new QLineEdit(AuthForm);
        lineEdit_1log->setObjectName(QString::fromUtf8("lineEdit_1log"));

        gridLayout->addWidget(lineEdit_1log, 1, 0, 1, 1);

        lineEdit_3email = new QLineEdit(AuthForm);
        lineEdit_3email->setObjectName(QString::fromUtf8("lineEdit_3email"));

        gridLayout->addWidget(lineEdit_3email, 3, 0, 1, 1);

        lineEdit_2pass = new QLineEdit(AuthForm);
        lineEdit_2pass->setObjectName(QString::fromUtf8("lineEdit_2pass"));
        lineEdit_2pass->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lineEdit_2pass, 2, 0, 1, 1);

        lineEdit_5surname = new QLineEdit(AuthForm);
        lineEdit_5surname->setObjectName(QString::fromUtf8("lineEdit_5surname"));

        gridLayout->addWidget(lineEdit_5surname, 5, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        dial = new QDial(AuthForm);
        dial->setObjectName(QString::fromUtf8("dial"));

        gridLayout_2->addWidget(dial, 0, 1, 1, 1);

        QWidget::setTabOrder(lineEdit_2pass, pushButton_ok);
        QWidget::setTabOrder(pushButton_ok, radioButton_teacher);
        QWidget::setTabOrder(radioButton_teacher, lineEdit_3email);
        QWidget::setTabOrder(lineEdit_3email, toolButtonback_to_auth);
        QWidget::setTabOrder(toolButtonback_to_auth, pushButton_reg);
        QWidget::setTabOrder(pushButton_reg, lineEdit_5surname);
        QWidget::setTabOrder(lineEdit_5surname, lineEdit_4name);
        QWidget::setTabOrder(lineEdit_4name, lineEdit_1log);

        retranslateUi(AuthForm);

        QMetaObject::connectSlotsByName(AuthForm);
    } // setupUi

    void retranslateUi(QWidget *AuthForm)
    {
        AuthForm->setWindowTitle(QCoreApplication::translate("AuthForm", "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\321\217", nullptr));
        lineEdit_4name->setText(QString());
        lineEdit_4name->setPlaceholderText(QCoreApplication::translate("AuthForm", "\320\230\320\274\321\217", nullptr));
        toolButtonback_to_auth->setText(QCoreApplication::translate("AuthForm", "  <-  ", nullptr));
        pushButton_reg->setText(QCoreApplication::translate("AuthForm", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        pushButton_ok->setText(QCoreApplication::translate("AuthForm", "OK", nullptr));
        radioButton_student->setText(QCoreApplication::translate("AuthForm", "\320\241\321\202\321\203\320\264\320\265\320\275\321\202", nullptr));
        radioButton_teacher->setText(QCoreApplication::translate("AuthForm", "\320\243\321\207\320\270\321\202\320\265\320\273\321\214", nullptr));
        lineEdit_1log->setPlaceholderText(QCoreApplication::translate("AuthForm", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        lineEdit_3email->setText(QString());
        lineEdit_3email->setPlaceholderText(QCoreApplication::translate("AuthForm", "email", nullptr));
        lineEdit_2pass->setPlaceholderText(QCoreApplication::translate("AuthForm", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        lineEdit_5surname->setPlaceholderText(QCoreApplication::translate("AuthForm", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AuthForm: public Ui_AuthForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHFORM_H
