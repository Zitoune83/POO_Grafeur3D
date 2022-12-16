#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

#include "OperateurBinaire.h"

class Multiplication : public OperateurBinaire
{
    public:
        Multiplication(Expression *opg, Expression *opd);
        virtual ~Multiplication();

        std::string toString() override;
        void afficher_classique(std::ostream &os = std::cout) override;
        void afficher_npi(std::ostream &os = std::cout) override;
        float calculer() override;

    protected:

    private:
};

#endif // MULTIPLICATION_H
