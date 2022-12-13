#ifndef MODELE_H
#define MODELE_H

#include "View.h"
#include "Constante.h"

#include <QtDataVisualization/Q3DSurface>
using namespace QtDataVisualization;


class Modele {

private:
    int m_sampleCountX;
    int m_sampleCountZ;
    float m_sampleMin;
    float m_sampleMax;
    Constante m_c;

public:
    Modele();
    ~Modele();


    void SetSampleX(int sample);          //
    void SetSampleZ(int sample);
    void SetSampleMin(float min);
    void SetSampleMax(float max);
    void SetConstante(Constante c);
    //void Get();          //
    QSurface3DSeries* feedGraph();   //Fournit un tableau de points à l' object Q3Dsurface
//    void SetExpression();//Met à jour l' expresion


};


#endif // MODELE_H
