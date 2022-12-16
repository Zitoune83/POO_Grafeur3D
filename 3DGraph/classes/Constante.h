#ifndef CONSTANTE_H
#define CONSTANTE_H

#include "Expression.h"

class Constante : public Expression
{
    public:
        Constante(float valeur = 0);
        virtual ~Constante();

        float Getvaleur() { return m_valeur; }
        void Setvaleur(float val) { m_valeur = val; }

        std::string toString() override;
        void afficher_classique(std::ostream &os = std::cout) override;
        void afficher_npi(std::ostream &os = std::cout) override;
        float calculer() override;

    protected:

    private:
        float m_valeur;
};

#endif // CONSTANTE_H
