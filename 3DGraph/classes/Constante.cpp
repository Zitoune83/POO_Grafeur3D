#include "Constante.h"

Constante::Constante(float valeur) : m_valeur(valeur)
{
    //ctor
}

Constante::~Constante()
{
    //dtor
}

std::string Constante::toString()
{
    return std::to_string((int) m_valeur);
}


void Constante::afficher_classique(std::ostream &os) {
    os << m_valeur;
}

void Constante::afficher_npi(std::ostream &os) {
    os << m_valeur;
}

float Constante::calculer() {
    return m_valeur;
}
