#ifndef ALUNODAO_H
#define ALUNODAO_H
#include "aluno.h"
#include <QSqlQuery>
#include <QString>


class AlunoDAO
{
public:
    bool create(Aluno aluno);
    QSqlQuery read();
    QSqlQuery read(QString where, QString value);
    Aluno read(int id);
    bool update(Aluno aluno);
    bool deletar(int id);
};

#endif // ALUNODAO_H
