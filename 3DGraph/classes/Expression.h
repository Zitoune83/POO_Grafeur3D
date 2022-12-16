#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <iostream>

class Expression
{
    public:
        Expression();
        virtual ~Expression();

        virtual std::string toString() = 0;
        virtual void afficher_classique(std::ostream &os = std::cout) = 0;
        virtual void afficher_npi(std::ostream &os = std::cout) = 0;
        virtual float calculer() = 0;

    protected:

    private:
};

#endif // EXPRESSION_H
