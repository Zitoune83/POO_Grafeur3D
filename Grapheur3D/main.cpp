#include "widget.h"

#include <QApplication>

#include <QtDataVisualization/Q3DSurface>
#include <Modele.h>
#include <View.h>

using namespace QtDataVisualization;


int main(int argc, char *argv[])
{

    //! [0]
    QApplication app(argc, argv);
    Modele modele;
    View object;
    QWidget *container = QWidget::createWindowContainer(object.getGraph());
    Constante c(10);




    //modele.SetConstante(c);
    modele.SetExpression(&c);
    modele.SetSampleMax(100.0f);
    modele.SetSampleMin(-100.0f);
    modele.SetSampleX(50);
    modele.SetSampleZ(50);

  //  QObject::connect(axisMinSliderX, &QSlider::valueChanged,
   //                  modele, &Modele::SetSampleMax);
    object.update(modele.feedGraph());

    container->show();

    return app.exec();


}




