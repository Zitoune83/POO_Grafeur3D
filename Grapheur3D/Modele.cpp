#include "Modele.h"
#include "Constante.h"
#include "View.h"

#include <QtDataVisualization/Q3DSurface>
#include <QtCore/qmath.h>
using namespace QtDataVisualization;

const int sampleCountX = 50;
const int sampleCountZ = 50;
const float sampleMin = -18.0f;
const float sampleMax = 18.0f;

Modele::Modele(): expression(0){

};

Modele::~Modele(){

};

void Modele::Set(){};            //
void Modele::Get(){};            //
QSurface3DSeries* Modele::feedGraph(Constante c){


    float stepX = (sampleMax - sampleMin) / float(sampleCountX - 1);
    float stepZ = (sampleMax - sampleMin) / float(sampleCountZ - 1);

    QSurfaceDataArray *dataArray = new QSurfaceDataArray;
    dataArray->reserve(sampleCountZ);

    for (int i = 0 ; i < sampleCountZ ; i++) {
        QSurfaceDataRow *newRow = new QSurfaceDataRow(sampleCountX);
        // Keep values within range bounds, since just adding step can cause minor drift due
        // to the rounding errors.
        float z = qMin(sampleMax, (i * stepZ + sampleMin));

        int index = 0;
        for (int j = 0; j < sampleCountX; j++) {
            float x = qMin(sampleMax, (j * stepX + sampleMin));
            //float R = qSqrt(z * z + x * x) + 0.01f;
            //float y = (qSin(R) / R + 0.24f) * 1.61f;
            float y = c.calculer();
            (*newRow)[index++].setPosition(QVector3D(x, y, z));
        }
        *dataArray << newRow;
    }

    QSurface3DSeries *series = new QSurface3DSeries;
     series->dataProxy()->resetArray(dataArray);

    return series;

}


void Modele::SetExpression(){};  //Met à jour l' expresion






