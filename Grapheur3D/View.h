#ifndef VIEW_H
#define VIEW_H

#include <Q3DSurface>
using namespace QtDataVisualization;

class View{

private:
    Q3DSurface *m_graph;
    //QSurfaceDataProxy *m_surfaceProxy;

public:
    View();
    ~View();

    void update(QSurface3DSeries *serie);
    Q3DSurface* getGraph();

};

#endif // VIEW_H
