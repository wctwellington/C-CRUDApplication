#include "principal.h"
#include "ui_principal.h"
#include "cadaluno.h"
#include "buscaralunos.h"
#include "alteraraluno.h"
#include <QDebug>
#include <QRect>
#include <QDesktopWidget>

Principal::Principal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Principal)
{
    ui->setupUi(this);
    QRect position = frameGeometry();
    position.moveCenter(QDesktopWidget().availableGeometry().center());
    move(position.topLeft());
}

Principal::~Principal()
{
    delete ui;
}

void Principal::on_actionCadastrar_triggered()
{
    CadAluno cadAluno;
    cadAluno.exec();
}

void Principal::on_actionBuscar_triggered()
{
    BuscarAlunos buscarAlunos;
    buscarAlunos.exec();
}

void Principal::on_actionAlterar_triggered()
{
    AlterarAluno alterarAluno;
    alterarAluno.exec();
}
