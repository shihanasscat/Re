/********************************************************************************
** Form generated from reading UI file 'exists_form.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXISTS_FORM_H
#define UI_EXISTS_FORM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_exists_form
{
public:
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *exists_form)
    {
        if (exists_form->objectName().isEmpty())
            exists_form->setObjectName(QString::fromUtf8("exists_form"));
        exists_form->resize(300, 115);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../../../Users/User/Documents/Temp\320\276\320\262\320\260\321\217 \321\205\321\203\320\271\320\275\321\217/easter egg.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        exists_form->setWindowIcon(icon);
        label = new QLabel(exists_form);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 20, 211, 20));
        pushButton = new QPushButton(exists_form);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(110, 60, 83, 29));

        retranslateUi(exists_form);

        QMetaObject::connectSlotsByName(exists_form);
    } // setupUi

    void retranslateUi(QWidget *exists_form)
    {
        exists_form->setWindowTitle(QCoreApplication::translate("exists_form", "\320\222\320\275\320\270\320\274\320\260\320\275\320\270\320\265!", nullptr));
        label->setText(QCoreApplication::translate("exists_form", "\320\255\321\202\320\276\321\202 \320\273\320\276\320\263\320\270\320\275 \321\203\320\266\320\265 \320\270\321\201\320\277\320\276\320\273\321\214\320\267\321\203\320\265\321\202\321\201\321\217!", nullptr));
        pushButton->setText(QCoreApplication::translate("exists_form", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class exists_form: public Ui_exists_form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXISTS_FORM_H
