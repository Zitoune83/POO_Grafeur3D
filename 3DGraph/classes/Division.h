#ifndef DIVISION_H
#define DIVISION_H

#include "OperateurBinaire.h"

class Division : public OperateurBinaire
{
    public:
        Division(Expression *opg, Expression *opd);
        virtual ~Division();

        std::string toString() override;
        void afficher_classique(std::ostream &os = std::cout) override;
        void afficher_npi(std::ostream &os = std::cout) override;
        float calculer() override;

    protected:

    private:
};

#endif // DIVISION_H
