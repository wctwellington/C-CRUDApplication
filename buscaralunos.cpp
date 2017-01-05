#include "buscaralunos.h"
#include "ui_buscaralunos.h"
#include <QtGui>
#include "alunodao.h"

QStandardItemModel *model;

BuscarAlunos::BuscarAlunos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BuscarAlunos)
{
    ui->setupUi(this);
    model = new QStandardItemModel();

    model->setHorizontalHeaderItem(0, new QStandardItem(QString("ID")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QString("Nome")));
    model->setHorizontalHeaderItem(2, new QStandardItem(QString("Endereço")));
    model->setHorizontalHeaderItem(3, new QStandardItem(QString("Telefone")));

    ui->tableAlunos->setModel(model);
    ui->tableAlunos->setColumnWidth(0, 80);
    ui->tableAlunos->setColumnWidth(1, 190);
    ui->tableAlunos->setColumnWidth(2, 267);
    ui->tableAlunos->setColumnWidth(3, 160);

    QHeaderView *verticalHeader = ui->tableAlunos->verticalHeader();
    verticalHeader->setSectionResizeMode(QHeaderView::Fixed);
    verticalHeader->setDefaultSectionSize(20);

    loadTable();
}

BuscarAlunos::~BuscarAlunos()
{
    delete ui;
}

void BuscarAlunos::loadTable() {

    AlunoDAO alunoDAO;

    QSqlQuery query;

    if (ui->cbPesquisarPor->currentText() == "ID") {
        query = alunoDAO.read("id", ui->txtPesquisar->text());
    } else if (ui->cbPesquisarPor->currentText() == "Nome") {
        query = alunoDAO.read("nome", ui->txtPesquisar->text());
    } else if (ui->cbPesquisarPor->currentText() == "Endereço") {
        query = alunoDAO.read("endereco", ui->txtPesquisar->text());
    } else if (ui->cbPesquisarPor->currentText() == "Telefone") {
        query = alunoDAO.read("telefone", ui->txtPesquisar->text());
    }

    model->setRowCount(0);

    for (int i=0; i<query.size(); i++) {
        query.next();
        for (int j=0; j<4; j++) {
            QStandardItem *item = new QStandardItem(query.value(j).toString());
            model->setItem(i, j, item);
        }
    }
}

void BuscarAlunos::on_txtPesquisar_textChanged()
{
    loadTable();
}

void BuscarAlunos::on_cbPesquisarPor_activated()
{
    loadTable();
}

void BuscarAlunos::on_btnSair_clicked()
{
    this->close();
}
