#ifndef ALUNO_H
#define ALUNO_H
#include "pessoa.h"

class Aluno : public Pessoa
{
    private:
        int id;

    public:
        void setId(int id);

        int getId();
};

#endif // ALUNO_H
