#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>

namespace Ui {
class Principal;
}

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    explicit Principal(QWidget *parent = 0);
    ~Principal();

private slots:
    void on_actionCadastrar_triggered();

    void on_actionBuscar_triggered();

    void on_actionAlterar_triggered();

private:
    Ui::Principal *ui;
};

#endif // PRINCIPAL_H
