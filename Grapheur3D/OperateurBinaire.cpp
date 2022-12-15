#include "OperateurBinaire.h"

OperateurBinaire::OperateurBinaire(Expression *opg, Expression *opd)
{
    this->m_OperandeGauche = opg;
    this->m_OperandeDroit = opd;
}

OperateurBinaire::~OperateurBinaire()
{

}
