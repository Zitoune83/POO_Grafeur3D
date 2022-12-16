#include "model.h"
#include "classes/Addition.h"
#include "classes/Multiplication.h"
#include <QtDataVisualization/Q3DSurface>
#include <QtCore/qmath.h>

using namespace QtDataVisualization;

//Modele::Modele(): m_sampleCountX(50), m_sampleCountZ(50), m_sampleMin(-18.0f), m_sampleMax(18.0f), m_c(5.0f) {
Model::Model(): QObject(), m_sampleCountX(50), m_sampleCountZ(50), m_sampleMin(-18.0f), m_sampleMax(18.0f), m_exp(nullptr) {
};

Model::~Model(){

};

void Model::init()
{
    Constante c1 = 0;
    Constante c2 = 0;
    Constante c3 = 0;
    Multiplication mul(&c2, &c3);
    Addition add(&c1, &mul);
    setExpression(&add);
}

void Model::setSampleX(int sample){
    m_sampleCountX = sample;
}         //
void Model::setSampleZ(int sample){
    m_sampleCountZ = sample;
}
void Model::setSampleMin(float min){
    m_sampleMin = min;
}
void Model::setSampleMax(float max){
    m_sampleMax = max;
}

void Model::setExpression(Expression* exp){
    m_exp = exp;
    QSurface3DSeries* series = feedGraph();
    QString text = QString::fromStdString(exp->toString());
    emit seriesUpdated(series);
    emit expressionUpdated(text);
}

QSurface3DSeries* Model::feedGraph(){

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
            //float y = z*x;
            float y = m_exp->calculer();
            (*newRow)[index++].setPosition(QVector3D(x, y, z));
        }
        *dataArray << newRow;
    }

    QSurface3DSeries *series = new QSurface3DSeries;
    series->dataProxy()->resetArray(dataArray);

    return series;

}

void Model::testMemory()
{
    return;
}
