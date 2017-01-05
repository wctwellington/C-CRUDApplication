#include "alteraraluno.h"
#include "alunodao.h"
#include "ui_alteraraluno.h"
#include <QMessageBox>
#include <QDebug>

AlterarAluno::AlterarAluno(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AlterarAluno)
{
    ui->setupUi(this);
    bloquearCampos(true);
}

void AlterarAluno::bloquearCampos(bool opcao) {
    if (opcao == true) {
        ui->txtId->setEnabled(true);
        ui->btnBuscar->setVisible(true);
        ui->txtNome->setEnabled(false);
        ui->txtEndereco->setEnabled(false);
        ui->txtTelefone->setEnabled(false);
        ui->btnAlterar->setVisible(false);
        ui->btnLimpar->setVisible(false);
        ui->btnCancelar->setVisible(false);
        ui->btnRemover->setVisible(false);

    } else {
        ui->txtId->setEnabled(false);
        ui->txtNome->setEnabled(true);
        ui->txtEndereco->setEnabled(true);
        ui->txtTelefone->setEnabled(true);
        ui->btnAlterar->setVisible(true);
        ui->btnLimpar->setVisible(true);
        ui->btnCancelar->setVisible(true);
        ui->btnBuscar->setVisible(false);
        ui->btnRemover->setVisible(true);
    }
}

void AlterarAluno::limpar() {
    ui->txtNome->setText("");
    ui->txtEndereco->setText("");
    ui->txtTelefone->setText("");
}

AlterarAluno::~AlterarAluno()
{
    delete ui;
}

void AlterarAluno::on_btnSair_clicked()
{
    this->close();
}

void AlterarAluno::on_btnCancelar_clicked()
{
    limpar();
    ui->txtId->setText("");
    bloquearCampos(true);
}

void AlterarAluno::on_btnLimpar_clicked()
{
    limpar();
}

void AlterarAluno::on_btnBuscar_clicked()
{
    Aluno aluno;
    AlunoDAO alunoDao;
    aluno = alunoDao.read(ui->txtId->text().toInt());

    ui->txtNome->setText(aluno.getNome());
    ui->txtEndereco->setText(aluno.getEndereco());
    ui->txtTelefone->setText(aluno.getTelefone());
    bloquearCampos(false);
}

void AlterarAluno::on_btnAlterar_clicked()
{
    Aluno aluno;
    AlunoDAO alunoDao;

    aluno.setId(ui->txtId->text().toInt());
    aluno.setNome(ui->txtNome->text());
    aluno.setEndereco(ui->txtEndereco->text());
    aluno.setTelefone(ui->txtTelefone->text());

    if (alunoDao.update(aluno)) {
        QMessageBox msgBox;
        msgBox.setText("Aluno alterado com sucesso.");
        msgBox.setWindowTitle("Aviso");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
    } else {
        QMessageBox msgBox;
        msgBox.setText("Ocorreu um erro ao alterar o aluno.");
        msgBox.setWindowTitle("Aviso");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
    }
}

void AlterarAluno::on_btnRemover_clicked()
{
        QMessageBox msgBox;
        msgBox.setText("Tem certeza que deseja remover este aluno?.");
        msgBox.setWindowTitle("Confirmação");
        msgBox.setIcon(QMessageBox::Question);
        msgBox.setStandardButtons(QMessageBox::Yes);
        msgBox.addButton(QMessageBox::No);
        msgBox.setButtonText(QMessageBox::Yes, trUtf8("Sim"));
        msgBox.setButtonText(QMessageBox::No, trUtf8("Não"));
        msgBox.setDefaultButton(QMessageBox::No);

        AlunoDAO alunoDao;
        if (msgBox.exec() == QMessageBox::Yes) {
            if (alunoDao.deletar(ui->txtId->text().toInt())) {
                QMessageBox msgBox;
                msgBox.setText("Aluno removido com sucesso.");
                msgBox.setWindowTitle("Aviso");
                msgBox.setIcon(QMessageBox::Information);
                msgBox.setStandardButtons(QMessageBox::Ok);
                msgBox.exec();
                bloquearCampos(true);
                limpar();
                ui->txtId->setText("");
            } else {
                QMessageBox msgBox;
                msgBox.setText("Ocorreu um erro ao remover o aluno.");
                msgBox.setWindowTitle("Aviso");
                msgBox.setIcon(QMessageBox::Critical);
                msgBox.setStandardButtons(QMessageBox::Ok);
                msgBox.exec();
            }
        }
}
