#include "Modele.h"
#include "View.h"

#include <QtDataVisualization/Q3DSurface>
using namespace QtDataVisualization;




const int sample = 50;            //nb echantillon en X et Y
const float sampleMin = -8.0f;   //Domaine de def
const float sampleMax = 8.0f;   //Domaine de def



Modele::Modele(): expression(0){

};

Modele::~Modele(){

};

void Modele::Set(){};            //
void Modele::Get(){};            //
QSurface3DSeries* Modele::feedGraph( ){




    //OK************

    //m_graph->setFlags(m_graph->flags() ^ Qt::FramelessWindowHint);
    QSurfaceDataArray *data = new QSurfaceDataArray;
    QSurfaceDataRow *dataRow1 = new QSurfaceDataRow;
    QSurfaceDataRow *dataRow2 = new QSurfaceDataRow;

    *dataRow1 << QVector3D(0.0f, 0.1f, 0.5f) << QVector3D(1.0f, 0.5f, 0.5f);
    *dataRow2 << QVector3D(0.0f, 1.8f, 1.0f) << QVector3D(1.0f, 8.2f, 9.0f);
    *data << dataRow1 << dataRow2;


    //m_graph->addSeries(m_surfaceSeries);
    QSurface3DSeries *series = new QSurface3DSeries;
    series->dataProxy()->resetArray(data);
    return series;


};      //Fournit un tableau de points à l' object Q3Dsurface




void Modele::SetExpression(){};  //Met à jour l' expresion






