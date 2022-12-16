#include "Variable.h"

Variable::Variable(string nom, map<string, float>& liste_variables, float valeur): m_listeVariables(liste_variables) {
    m_nom = nom;
    set_valeur(valeur);
}


Variable::~Variable()
{
    //dtor
}

float Variable::get_valeur() {
     return m_listeVariables[m_nom];
}

void Variable::set_valeur(float val) {
    if (m_listeVariables.count(m_nom)) // si il y a une variable nommée 'nom'
    {
        m_listeVariables[m_nom] = val;
    }
    else
    {
        m_listeVariables.insert(pair<string, float>(m_nom, val));
    }
}

map<string, float> &Variable::init() {
    return *(new map<string, float>);   //return l'adresse de la map
}

std::string Variable::toString()
{
    return std::to_string(get_valeur());
}

void Variable::afficher_classique(ostream& os) {
    os << m_nom;
}

void Variable::afficher_npi(ostream& os) {
    os << m_nom;
}

float Variable::calculer() {
    return get_valeur();
}
