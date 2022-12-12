#include "View.h"


#include <Q3DSurface>
using namespace QtDataVisualization;


View::View(){

    m_graph = new Q3DSurface();
    //m_surfaceProxy = new QSurfaceDataProxy();

}

View::~View(){

    delete m_graph;
    //delete m_surfaceProxy;

}


void View::update(QSurface3DSeries *serie){

     m_graph->addSeries(serie);

}


Q3DSurface* View::getGraph(){

    return m_graph;

}
