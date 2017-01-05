#include "pessoa.h"
#include <QString>

void Pessoa::setNome(QString nome) {
    this->nome = nome;
}

void Pessoa::setEndereco(QString endereco) {
    this->endereco = endereco;
}

void Pessoa::setTelefone(QString telefone) {
    this->telefone = telefone;
}

QString Pessoa::getNome() {
    return nome;
}

QString Pessoa::getEndereco() {
    return endereco;
}

QString Pessoa::getTelefone() {
    return telefone;
}
