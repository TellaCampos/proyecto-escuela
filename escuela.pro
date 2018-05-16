#-------------------------------------------------
#
# Project created by QtCreator 2018-03-13T23:32:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = escuela
TEMPLATE = app

FORMS += dialogalta.ui \
    alta.ui \
    altaprofesores.ui \
    altaalumnos.ui \
    altamateria.ui \
    agregarnota.ui
# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
QT += core gui widgets
# set(CMAKE_AUTOUIC ON)


# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        escuelaa.cpp \
    menu.cpp \
    alumnos.cpp \
    calificacion.cpp \
    horario.cpp \
    agenda.cpp \
    agepadres.cpp \
    agenmaestros.cpp \
    evento.cpp \
    materiasmaestro.cpp \
    correo.cpp \
    dialogalta.cpp \
    alta.cpp \
    altaprofesores.cpp \
    altaalumnos.cpp \
    altamateria.cpp \
    agregarnota.cpp

HEADERS += \
        escuelaa.h \
    menu.h \
    alumnos.h \
    calificacion.h \
    horario.h \
    agenda.h \
    agepadres.h \
    agenmaestros.h \
    evento.h \
    materiasmaestro.h \
    correo.h \
    dialogalta.h \
    alta.h \
    altaprofesores.h \
    altaalumnos.h \
    altamateria.h \
    agregarnota.h

FORMS += \
        escuelaa.ui \
    menu.ui \
    alumnos.ui \
    calificacion.ui \
    horario.ui \
    agenda.ui \
    agepadres.ui \
    agenmaestros.ui \
    evento.ui \
    materiasmaestro.ui \
    correo.ui \
    dialogalta.ui
