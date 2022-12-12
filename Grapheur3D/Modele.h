#ifndef MODELE_H
#define MODELE_H

#include "View.h"

#include <QtDataVisualization/Q3DSurface>
using namespace QtDataVisualization;


class Modele {

private:
    int expression;
public:
    Modele();
    ~Modele();
    void Set();          //
    void Get();          //
    QSurface3DSeries* feedGraph();   //Fournit un tableau de points à l' object Q3Dsurface
    void SetExpression();//Met à jour l' expresion


};


#endif // MODELE_H
