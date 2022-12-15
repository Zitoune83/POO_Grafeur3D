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
    object.update(modele.feedGraph());

    return app.exec();


}




