#include <iostream>

using namespace std;

#include "Constante.h"
#include "Addition.h"
#include "Soustraction.h"
#include "Division.h"
#include "Multiplication.h"


int main(void) {

	Constante c1(20.0);

	// Cas d'utilisation : création
	c1.afficher_classique();
	cout << endl;

	Constante c2(30.0);
	Addition add1(&c1, &c2);
	add1.afficher_classique(cout);
	cout << endl;

	Constante c3(34.0);
	Multiplication m1(&c3, &add1);
	m1.afficher_classique(cout);
	cout << endl;
	add1.afficher_npi(cout);
	cout << endl;

	cout << c1.calculer() << endl;
	cout << add1.calculer() << endl;
	cout << m1.calculer() << endl;

	return 0;
}

