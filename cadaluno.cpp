#include "cadaluno.h"
#include "ui_cadaluno.h"
#include "aluno.h"
#include "alunodao.h"
#include <QMessageBox>

CadAluno::CadAluno(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CadAluno)
{
    ui->setupUi(this);
}

CadAluno::~CadAluno()
{
    delete ui;
}

void CadAluno::limpar() {
    ui->txtNome->setText("");
    ui->txtEndereco->setText("");
    ui->txtTelefone->setText("");
}

void CadAluno::on_btnSair_clicked()
{
    this->close();
}

void CadAluno::on_btnSalvar_clicked()
{
    Aluno aluno;
    aluno.setNome(ui->txtNome->text());
    aluno.setEndereco(ui->txtEndereco->text());
    aluno.setTelefone(ui->txtTelefone->text());

    AlunoDAO alunoDao;
    if (alunoDao.create(aluno)) {
        QMessageBox msgBox;
        msgBox.setText("Aluno inserido com sucesso.");
        msgBox.setWindowTitle("Aviso");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
    } else {
        QMessageBox msgBox;
        msgBox.setText("Ocorreu um erro ao inserir o aluno.");
        msgBox.setWindowTitle("Aviso");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
    }
}

void CadAluno::on_btnLimpar_clicked()
{
    limpar();
}
