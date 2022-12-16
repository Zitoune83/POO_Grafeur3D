#include "Division.h"

Division::Division(Expression *opg, Expression *opd) : OperateurBinaire(opg, opd)
{
    //ctor
}

Division::~Division()
{
    //dtor
}

std::string Division::toString()
{
    return m_OperandeGauche->toString() + " / " + m_OperandeDroit->toString();
}


void Division::afficher_classique(std::ostream &os) {
    m_OperandeGauche->afficher_classique();
    os << " / ";
    m_OperandeDroit->afficher_classique();
}

void Division::afficher_npi(std::ostream &os) {
    m_OperandeGauche->afficher_npi();
    os << " ";
    m_OperandeDroit->afficher_npi();
    os << " / ";
}


float Division::calculer() {
    return m_OperandeGauche->calculer() / m_OperandeDroit->calculer();
}
