#include "Soustraction.h"

Soustraction::Soustraction(Expression *opg, Expression *opd) : OperateurBinaire(opg, opd)
{
    //ctor
}

Soustraction::~Soustraction()
{
    //dtor
}

std::string Soustraction::toString()
{
    return "( " + m_OperandeGauche->toString() + " - " + m_OperandeDroit->toString() + " )";
}

void Soustraction::afficher_classique(std::ostream &os) {
    os << "( ";
    m_OperandeGauche->afficher_classique();
    os << " - ";
    m_OperandeDroit->afficher_classique();
    os << " )";
}

void Soustraction::afficher_npi(std::ostream &os) {
    m_OperandeGauche->afficher_npi();
    os << " ";
    m_OperandeDroit->afficher_npi();
    os << " - ";
}

float Soustraction::calculer() {
    return m_OperandeGauche->calculer() - m_OperandeDroit->calculer();
}
