#ifndef PESSOA_H
#define PESSOA_H
#include <QString>

class Pessoa
{
private:
    QString nome;
    QString endereco;
    QString telefone;

public:
    void setNome(QString nome);
    void setEndereco(QString endereco);
    void setTelefone(QString telefone);

    QString getNome();
    QString getEndereco();
    QString getTelefone();

};

#endif // PESSOA_H
