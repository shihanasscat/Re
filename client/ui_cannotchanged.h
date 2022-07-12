/********************************************************************************
** Form generated from reading UI file 'cannotchanged.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CANNOTCHANGED_H
#define UI_CANNOTCHANGED_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cannotchanged
{
public:
    QLabel *label;

    void setupUi(QWidget *cannotchanged)
    {
        if (cannotchanged->objectName().isEmpty())
            cannotchanged->setObjectName(QString::fromUtf8("cannotchanged"));
        cannotchanged->resize(288, 71);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../../../Users/User/Documents/Temp\320\276\320\262\320\260\321\217 \321\205\321\203\320\271\320\275\321\217/easter egg.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        cannotchanged->setWindowIcon(icon);
        label = new QLabel(cannotchanged);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 20, 211, 20));

        retranslateUi(cannotchanged);

        QMetaObject::connectSlotsByName(cannotchanged);
    } // setupUi

    void retranslateUi(QWidget *cannotchanged)
    {
        cannotchanged->setWindowTitle(QCoreApplication::translate("cannotchanged", "\320\222\320\275\320\270\320\274\320\260\320\275\320\270\320\265!", nullptr));
        label->setText(QCoreApplication::translate("cannotchanged", "\320\222\321\213 \320\275\320\265 \320\274\320\276\320\266\320\265\321\202\320\265 \320\270\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \321\215\321\202\321\203 \320\263\321\200\321\203\320\277\320\277\321\203!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class cannotchanged: public Ui_cannotchanged {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CANNOTCHANGED_H
