#include "Constante.h"

Constante::Constante(float valeur) : m_valeur(valeur)
{
    //ctor
}

Constante::~Constante()
{
    //dtor
}



void Constante::afficher_classique(ostream &os) {
    os << m_valeur;
}

void Constante::afficher_npi(ostream &os) {
    os << m_valeur;
}

float Constante::calculer() {
    return m_valeur;
}
