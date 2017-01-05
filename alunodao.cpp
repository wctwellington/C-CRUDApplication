#include "alunodao.h"
#include "connectionfactory.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QSqlTableModel>

bool AlunoDAO::create(Aluno aluno) {
    ConnectionFactory conn;
    conn.openConnection();

    QSqlQuery query;
    query.prepare("INSERT INTO aluno (nome, endereco, telefone) values (?, ?, ?)");
    query.addBindValue(aluno.getNome());
    query.addBindValue(aluno.getEndereco());
    query.addBindValue(aluno.getTelefone());

    if (query.exec()) {
        return true;
    } else {
        qDebug() << query.lastError();
        return false;
    }
}

QSqlQuery AlunoDAO::read() {
    ConnectionFactory conn;
    conn.openConnection();

    QSqlQuery query;
    query.prepare("SELECT * FROM aluno");
    if (query.exec()) {
        return query;
    } else {
        return query;
    }
}

QSqlQuery AlunoDAO::read(QString where, QString value) {
    ConnectionFactory conn;
    conn.openConnection();

    QSqlQuery query;
    query.prepare("SELECT * FROM aluno WHERE CAST(" + where + " AS TEXT) ILIKE ? ORDER BY id");

    query.addBindValue(value + "%");

    if (query.exec()) {
        return query;
    } else {
        return query;
    }
}

Aluno AlunoDAO::read(int id) {
    ConnectionFactory conn;
    conn.openConnection();

    QSqlQuery query;
    query.prepare("SELECT * FROM aluno WHERE id = ?");
    query.addBindValue(id);

    Aluno aluno;

    if (query.exec()) {
        if (query.next()) {
            aluno.setId(id);
            aluno.setNome(query.value(1).toString());
            aluno.setEndereco(query.value(2).toString());
            aluno.setTelefone(query.value(3).toString());
        }
    }

    return aluno;
}

bool AlunoDAO::update(Aluno aluno) {
    ConnectionFactory conn;
    conn.openConnection();

    QSqlQuery query;
    query.prepare("UPDATE aluno SET nome = ?, endereco = ?, telefone = ? WHERE id = ?");
    query.addBindValue(aluno.getNome());
    query.addBindValue(aluno.getEndereco());
    query.addBindValue(aluno.getTelefone());
    query.addBindValue(aluno.getId());

    if (query.exec()) {
        return true;
    } else {
        return false;
    }

}

bool AlunoDAO::deletar(int id) {
    ConnectionFactory conn;
    conn.openConnection();

    QSqlQuery query;
    query.prepare("DELETE FROM aluno WHERE id = ?");
    query.addBindValue(id);

    if (query.exec()) {
        return true;
    } else {
        return false;
    }

}

