#include "Addition.h"

Addition::Addition(Expression *opg, Expression *opd) : OperateurBinaire(opg, opd)
{
    //ctor
}

Addition::~Addition()
{
    //dtor
}

std::string Addition::toString()
{
    return "( " + m_OperandeGauche->toString() + " + " + m_OperandeDroit->toString() + " )";
}

void Addition::afficher_classique(std::ostream &os) {
    os << "( ";
    m_OperandeGauche->afficher_classique();
    os << " + ";
    m_OperandeDroit->afficher_classique();
    os << " )";
}

void Addition::afficher_npi(std::ostream &os) {
    m_OperandeGauche->afficher_npi();
    os << " ";
    m_OperandeDroit->afficher_npi();
    os << " + ";
}

float Addition::calculer() {
    return m_OperandeGauche->calculer() + m_OperandeDroit->calculer();
}
