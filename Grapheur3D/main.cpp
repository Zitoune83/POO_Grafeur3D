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

    modele.SetConstante(c);
    modele.SetSampleMax(25.0f);
    modele.SetSampleMin(-25.0f);
    modele.SetSampleX(25);
    modele.SetSampleZ(25);

    object.update(modele.feedGraph());

    container->show();

    return app.exec();


}




