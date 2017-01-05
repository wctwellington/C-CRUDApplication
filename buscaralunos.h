#ifndef BUSCARALUNOS_H
#define BUSCARALUNOS_H

#include <QDialog>

namespace Ui {
class BuscarAlunos;
}

class BuscarAlunos : public QDialog
{
    Q_OBJECT

public:
    explicit BuscarAlunos(QWidget *parent = 0);
    ~BuscarAlunos();

private slots:
    void loadTable();
    void on_btnSair_clicked();

    void on_txtPesquisar_textChanged();

    void on_cbPesquisarPor_activated();

private:
    Ui::BuscarAlunos *ui;

};

#endif // BUSCARALUNOS_H
