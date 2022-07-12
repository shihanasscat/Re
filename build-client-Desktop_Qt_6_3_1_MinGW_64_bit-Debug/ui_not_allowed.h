/********************************************************************************
** Form generated from reading UI file 'not_allowed.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOT_ALLOWED_H
#define UI_NOT_ALLOWED_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_not_allowed
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *not_allowed)
    {
        if (not_allowed->objectName().isEmpty())
            not_allowed->setObjectName(QString::fromUtf8("not_allowed"));
        not_allowed->resize(257, 111);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../../../Users/User/Documents/Temp\320\276\320\262\320\260\321\217 \321\205\321\203\320\271\320\275\321\217/easter egg.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        not_allowed->setWindowIcon(icon);
        label = new QLabel(not_allowed);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 20, 81, 21));
        label_2 = new QLabel(not_allowed);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 70, 261, 18));
        label_3 = new QLabel(not_allowed);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 50, 381, 20));

        retranslateUi(not_allowed);

        QMetaObject::connectSlotsByName(not_allowed);
    } // setupUi

    void retranslateUi(QWidget *not_allowed)
    {
        not_allowed->setWindowTitle(QCoreApplication::translate("not_allowed", "\320\222\320\275\320\270\320\274\320\260\320\275\320\270\320\265!", nullptr));
        label->setText(QCoreApplication::translate("not_allowed", "\320\235\320\265\321\202 \320\264\320\276\321\201\321\202\321\203\320\277\320\260!", nullptr));
        label_2->setText(QCoreApplication::translate("not_allowed", "\320\277\321\200\320\276\320\262\320\265\321\200\321\214\321\202\320\265 \320\277\321\200\320\260\320\262\320\270\320\273\321\214\320\275\320\276\321\201\321\202\321\214 \320\262\320\262\320\265\320\264\320\265\320\275\320\275\321\213\321\205 \320\264\320\260\320\275\320\275\321\213\321\205", nullptr));
        label_3->setText(QCoreApplication::translate("not_allowed", "\320\224\320\273\321\217 \321\203\321\207\320\270\321\202\320\265\320\273\321\217: \321\215\321\202\320\276\320\271 \320\263\321\200\321\203\320\277\320\277\321\213 \320\275\320\265 \321\201\321\203\321\211\320\265\321\201\321\202\320\262\321\203\320\265\321\202, ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class not_allowed: public Ui_not_allowed {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOT_ALLOWED_H
