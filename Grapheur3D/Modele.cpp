#include "Modele.h"
#include "Constante.h"
#include "View.h"

#include <QtDataVisualization/Q3DSurface>
#include <QtCore/qmath.h>
using namespace QtDataVisualization;

//const int sampleCountX = 50;
//const int sampleCountZ = 50;
//const float sampleMin = -18.0f;
//const float sampleMax = 18.0f;

Modele::Modele(): m_sampleCountX(50), m_sampleCountZ(50), m_sampleMin(-18.0f), m_sampleMax(18.0f), m_c(5.0f) {

};

Modele::~Modele(){

};

//void Modele::Set(){};            //
//void Modele::Get(){};            //


void Modele::SetSampleX(int sample){
    m_sampleCountX = sample;
}         //
void Modele::SetSampleZ(int sample){
    m_sampleCountZ = sample;
}
void Modele::SetSampleMin(float min){
    m_sampleMin = min;
}
void Modele::SetSampleMax(float max){
    m_sampleMax = max;
}

void Modele::SetConstante(Constante c){
    m_c = c;
}

QSurface3DSeries* Modele::feedGraph(){


    float stepX = (m_sampleMax - m_sampleMin) / float(m_sampleCountX - 1);
    float stepZ = (m_sampleMax - m_sampleMin) / float(m_sampleCountZ - 1);

    QSurfaceDataArray *dataArray = new QSurfaceDataArray;
    dataArray->reserve(m_sampleCountZ);

    for (int i = 0 ; i < m_sampleCountZ ; i++) {
        QSurfaceDataRow *newRow = new QSurfaceDataRow(m_sampleCountX);
        // Keep values within range bounds, since just adding step can cause minor drift due
        // to the rounding errors.
        float z = qMin(m_sampleMax, (i * stepZ + m_sampleMin));

        int index = 0;
        for (int j = 0; j < m_sampleCountX; j++) {
            float x = qMin(m_sampleMax, (j * stepX + m_sampleMin));
            //float R = qSqrt(z * z + x * x) + 0.01f;
            //float y = (qSin(R) / R + 0.24f) * 1.61f;
            //float y = c.calculer();
            //float y = x*x;
            float y = m_c.calculer();
            (*newRow)[index++].setPosition(QVector3D(x, y, z));
        }
        *dataArray << newRow;
    }

    QSurface3DSeries *series = new QSurface3DSeries;
     series->dataProxy()->resetArray(dataArray);

    return series;

}


//void Modele::SetExpression(){};  //Met à jour l' expresion






