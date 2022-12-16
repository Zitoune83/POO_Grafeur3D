#ifndef ADDITION_H
#define ADDITION_H

#include "OperateurBinaire.h"

class Addition : public OperateurBinaire
{
    public:
        Addition(Expression *opg, Expression *opd);
        virtual ~Addition();

        std::string toString() override;
        void afficher_classique(std::ostream &os = std::cout) override;
        void afficher_npi(std::ostream &os = std::cout) override;
        float calculer() override;
    protected:

    private:
};

#endif // ADDITION_H
