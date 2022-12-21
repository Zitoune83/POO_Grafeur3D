#ifndef MODEL_H
#define MODEL_H

#include "classes/Expression.h"
#include <QtDataVisualization/Q3DSurface>
#include <QObject>

using namespace QtDataVisualization;

class Model : public QObject
{

    Q_OBJECT

private:
    int m_sampleCountX;
    int m_sampleCountZ;
    float m_sampleMin;
    float m_sampleMax;
    Expression* m_exp;
    std::map<std::string, float>* var_map;

public:
    Model();
    ~Model();

    void setExpression();
    QSurface3DSeries* feedGraph();   //Fournit un tableau de points à l' object Q3Dsurface


public slots:
    void setSampleX(int sample);
    void setSampleZ(int sample);
    void setSampleMin(float min);
    void setSampleMax(float max);
    void testMemory();

signals:
    void seriesUpdated(QSurface3DSeries* series);
    void expressionUpdated(const QString& text);
};


#endif // MODEL_H
