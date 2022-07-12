QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


# aaaaaa


SOURCES += \
    addgroup.cpp \
    authform.cpp \
    cannotchanged.cpp \
    client.cpp \
    exists_form.cpp \
    form_statistic.cpp \
    form_statistic_teacher.cpp \
    form_task.cpp \
    main.cpp \
    mainwindow.cpp \
    not_allowed.cpp \
    serverfunctions.cpp \
    unittest.cpp \
    wrong_form.cpp

HEADERS += \
    addgroup.h \
    authform.h \
    cannotchanged.h \
    client.h \
    exists_form.h \
    form_statistic.h \
    form_statistic_teacher.h \
    form_task.h \
    mainwindow.h \
    not_allowed.h \
    serverfunctions.h \
    unittest.h \
    wrong_form.h

FORMS += \
    addgroup.ui \
    authform.ui \
    cannotchanged.ui \
    exists_form.ui \
    form_statistic.ui \
    form_statistic_teacher.ui \
    form_task.ui \
    mainwindow.ui \
    not_allowed.ui \
    wrong_form.ui


# Default rules for deployment.

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
