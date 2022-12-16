#pragma once
#include "Expression.h"
#include <map>

using namespace std;

class Variable :
    public Expression
{

public:
    Variable(string nom, map<string, float>& liste_variables, float valeur);
    virtual ~Variable();

    float get_valeur();
    void set_valeur(float val);
    static map<string, float> &init();  //fonction à faire au début du main, qui crée et renvoie un dico

    //flux en paramètre pour pouvoir choisir ou l'afficher (cout, IHM)
    std::string toString() override;
    void afficher_classique(ostream& os = cout) override;
    void afficher_npi(ostream& os = cout) override;
    float calculer() override;

protected:

private:
    string m_nom;
    map <string, float> &m_listeVariables;  //pointeur de map, comme ca qd on crée une variable, plusieurs peuvent pointer vers la meme map
};
