#ifndef SOUSTRACTION_H
#define SOUSTRACTION_H

#include "OperateurBinaire.h"

class Soustraction : public OperateurBinaire
{
    public:
        Soustraction(Expression *opg, Expression *opd);
        virtual ~Soustraction();

        std::string toString() override;
        void afficher_classique(std::ostream &os = std::cout) override;
        void afficher_npi(std::ostream &os = std::cout) override;
        float calculer() override;

    protected:

    private:
};

#endif // SOUSTRACTION_H
