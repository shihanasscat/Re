/********************************************************************************
** Form generated from reading UI file 'wrong_form.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WRONG_FORM_H
#define UI_WRONG_FORM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_wrong_form
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *wrong_form)
    {
        if (wrong_form->objectName().isEmpty())
            wrong_form->setObjectName(QString::fromUtf8("wrong_form"));
        wrong_form->resize(394, 139);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../../../Users/User/Documents/Temp\320\276\320\262\320\260\321\217 \321\205\321\203\320\271\320\275\321\217/easter egg.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        wrong_form->setWindowIcon(icon);
        label = new QLabel(wrong_form);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 30, 271, 31));
        pushButton = new QPushButton(wrong_form);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(70, 80, 100, 20));
        pushButton_2 = new QPushButton(wrong_form);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(200, 80, 100, 20));

        retranslateUi(wrong_form);

        QMetaObject::connectSlotsByName(wrong_form);
    } // setupUi

    void retranslateUi(QWidget *wrong_form)
    {
        wrong_form->setWindowTitle(QCoreApplication::translate("wrong_form", "\320\222\320\275\320\270\320\274\320\260\320\275\320\270\320\265!", nullptr));
        label->setText(QCoreApplication::translate("wrong_form", "\320\235\320\265\320\277\321\200\320\260\320\262\320\270\320\273\321\214\320\275\320\276\320\265 \320\270\320\274\321\217 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217 \320\270\320\273\320\270 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        pushButton->setText(QCoreApplication::translate("wrong_form", "OK", nullptr));
        pushButton_2->setText(QCoreApplication::translate("wrong_form", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class wrong_form: public Ui_wrong_form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WRONG_FORM_H
