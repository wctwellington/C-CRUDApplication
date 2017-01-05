#-------------------------------------------------
#
# Project created by QtCreator 2017-01-03T19:14:15
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AppCrud
TEMPLATE = app


SOURCES += main.cpp\
        principal.cpp \
    cadaluno.cpp \
    pessoa.cpp \
    aluno.cpp \
    connectionfactory.cpp \
    alunodao.cpp \
    buscaralunos.cpp \
    alteraraluno.cpp

HEADERS  += principal.h \
    cadaluno.h \
    pessoa.h \
    aluno.h \
    connectionfactory.h \
    alunodao.h \
    buscaralunos.h \
    alteraraluno.h

FORMS    += principal.ui \
    cadaluno.ui \
    buscaralunos.ui \
    alteraraluno.ui

RESOURCES += \
    imagens.qrc
