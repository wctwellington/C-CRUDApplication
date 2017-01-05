#ifndef CADALUNO_H
#define CADALUNO_H

#include <QDialog>

namespace Ui {
class CadAluno;
}

class CadAluno : public QDialog
{
    Q_OBJECT

public:
    explicit CadAluno(QWidget *parent = 0);
    ~CadAluno();

private slots:
    void on_btnSair_clicked();

    void on_btnSalvar_clicked();

    void on_btnLimpar_clicked();

private:
    Ui::CadAluno *ui;
    void limpar();
};

#endif // CADALUNO_H
