#ifndef ALTERARALUNO_H
#define ALTERARALUNO_H

#include <QDialog>

namespace Ui {
class AlterarAluno;
}

class AlterarAluno : public QDialog
{
    Q_OBJECT

public:
    explicit AlterarAluno(QWidget *parent = 0);
    ~AlterarAluno();

private slots:
    void on_btnSair_clicked();

    void on_btnCancelar_clicked();

    void on_btnLimpar_clicked();

    void on_btnBuscar_clicked();

    void on_btnAlterar_clicked();

    void on_btnRemover_clicked();

private:
    Ui::AlterarAluno *ui;
    void bloquearCampos(bool opcao);
    void limpar();
};

#endif // ALTERARALUNO_H
