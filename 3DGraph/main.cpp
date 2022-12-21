#include "view.h"
#include "model.h"
#include <QApplication>

void connect(Model& m, View& v)
{
    QObject::connect(&m, &Model::seriesUpdated, &v, &View::updateGraph);
    QObject::connect(&m, &Model::expressionUpdated, &v, &View::updateLabelExpr);
    QPushButton* test_button = v.getTestButton();
    QSlider* pointX = v.getsliderpoint_x();
    QSlider* pointZ = v.getsliderpoint_z();
    QSlider* size_min = v.getslidersize_min();
    QSlider* size_max = v.getslidersize_max();
    QObject::connect(test_button, &QPushButton::clicked, &m, &Model::testMemory);
    QObject::connect(pointX,&QSlider::sliderMoved,&m,&Model::setSampleX);
    QObject::connect(pointZ,&QSlider::sliderMoved,&m,&Model::setSampleZ);
    QObject::connect(size_min,&QSlider::sliderMoved,&m,&Model::setSampleMin);
    QObject::connect(size_max,&QSlider::sliderMoved,&m,&Model::setSampleMax);

    Model::setExpression(m);
}

void connect(View& v, Model& m)
{
    connect(m, v);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Model m;
    View v;
    connect(m, v);

    v.show();
    return a.exec();
}
