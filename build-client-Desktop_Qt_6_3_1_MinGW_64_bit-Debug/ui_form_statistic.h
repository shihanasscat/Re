/********************************************************************************
** Form generated from reading UI file 'form_statistic.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_STATISTIC_H
#define UI_FORM_STATISTIC_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_form_statistic
{
public:
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_task_1;
    QLabel *label_task_2;
    QLabel *label_task_3;
    QLabel *label;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_student;
    QLabel *label_teacher;
    QLabel *label_group;
    QLabel *label_7;
    QLabel *label_task_4;

    void setupUi(QWidget *form_statistic)
    {
        if (form_statistic->objectName().isEmpty())
            form_statistic->setObjectName(QString::fromUtf8("form_statistic"));
        form_statistic->resize(511, 205);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../../../Users/User/Documents/Temp\320\276\320\262\320\260\321\217 \321\205\321\203\320\271\320\275\321\217/easter egg.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        form_statistic->setWindowIcon(icon);
        horizontalLayout_2 = new QHBoxLayout(form_statistic);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        groupBox = new QGroupBox(form_statistic);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 120, 60, 20));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(180, 120, 63, 20));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(270, 120, 63, 20));
        label_task_1 = new QLabel(groupBox);
        label_task_1->setObjectName(QString::fromUtf8("label_task_1"));
        label_task_1->setGeometry(QRect(60, 140, 63, 20));
        label_task_2 = new QLabel(groupBox);
        label_task_2->setObjectName(QString::fromUtf8("label_task_2"));
        label_task_2->setGeometry(QRect(180, 140, 63, 20));
        label_task_3 = new QLabel(groupBox);
        label_task_3->setObjectName(QString::fromUtf8("label_task_3"));
        label_task_3->setGeometry(QRect(270, 140, 63, 20));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 30, 60, 20));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 55, 60, 20));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 80, 60, 20));
        label_student = new QLabel(groupBox);
        label_student->setObjectName(QString::fromUtf8("label_student"));
        label_student->setGeometry(QRect(100, 30, 141, 18));
        label_teacher = new QLabel(groupBox);
        label_teacher->setObjectName(QString::fromUtf8("label_teacher"));
        label_teacher->setGeometry(QRect(100, 55, 181, 18));
        label_group = new QLabel(groupBox);
        label_group->setObjectName(QString::fromUtf8("label_group"));
        label_group->setGeometry(QRect(90, 80, 66, 18));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(380, 120, 63, 20));
        label_task_4 = new QLabel(groupBox);
        label_task_4->setObjectName(QString::fromUtf8("label_task_4"));
        label_task_4->setGeometry(QRect(380, 140, 63, 20));

        horizontalLayout_2->addWidget(groupBox);


        retranslateUi(form_statistic);

        QMetaObject::connectSlotsByName(form_statistic);
    } // setupUi

    void retranslateUi(QWidget *form_statistic)
    {
        form_statistic->setWindowTitle(QCoreApplication::translate("form_statistic", "\320\241\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\320\260", nullptr));
        groupBox->setTitle(QCoreApplication::translate("form_statistic", "\320\241\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\320\260", nullptr));
        label_2->setText(QCoreApplication::translate("form_statistic", "\320\227\320\260\320\264\320\260\320\275\320\270\320\265 1", nullptr));
        label_3->setText(QCoreApplication::translate("form_statistic", "\320\227\320\260\320\264\320\260\320\275\320\270\320\265 2", nullptr));
        label_4->setText(QCoreApplication::translate("form_statistic", "\320\227\320\260\320\264\320\260\320\275\320\270\320\265 3", nullptr));
        label_task_1->setText(QCoreApplication::translate("form_statistic", ".", nullptr));
        label_task_2->setText(QCoreApplication::translate("form_statistic", ".", nullptr));
        label_task_3->setText(QCoreApplication::translate("form_statistic", ".", nullptr));
        label->setText(QCoreApplication::translate("form_statistic", "\320\241\321\202\321\203\320\264\320\265\320\275\321\202:", nullptr));
        label_5->setText(QCoreApplication::translate("form_statistic", "\320\243\321\207\320\270\321\202\320\265\320\273\321\214:", nullptr));
        label_6->setText(QCoreApplication::translate("form_statistic", "\320\223\321\200\321\203\320\277\320\277\320\260:", nullptr));
        label_student->setText(QCoreApplication::translate("form_statistic", "...", nullptr));
        label_teacher->setText(QCoreApplication::translate("form_statistic", "...", nullptr));
        label_group->setText(QCoreApplication::translate("form_statistic", "...", nullptr));
        label_7->setText(QCoreApplication::translate("form_statistic", "\320\227\320\260\320\264\320\260\320\275\320\270\320\265 4", nullptr));
        label_task_4->setText(QCoreApplication::translate("form_statistic", ".", nullptr));
    } // retranslateUi

};

namespace Ui {
    class form_statistic: public Ui_form_statistic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_STATISTIC_H
