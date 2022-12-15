#include "Multiplication.h"

Multiplication::Multiplication(Expression *opg, Expression *opd) : OperateurBinaire(opg, opd)
{
    //ctor
}

Multiplication::~Multiplication()
{
    //dtor
}

void Multiplication::afficher_classique(ostream &os) {
    m_OperandeGauche->afficher_classique();
    os << " * ";
    m_OperandeDroit->afficher_classique();
}

void Multiplication::afficher_npi(ostream &os) {
    m_OperandeGauche->afficher_npi();
    os << " ";
    m_OperandeDroit->afficher_npi();
    os << " * ";
}

float Multiplication::calculer() {
    return m_OperandeGauche->calculer() * m_OperandeDroit->calculer();
}
