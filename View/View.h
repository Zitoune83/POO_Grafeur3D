#ifndef VIEW_H
#define VIEW_H

#include <Q3DSurface>

#include <QApplication>
#include <Q3DSurface>
#include <QtDataVisualization>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMessageBox>
#include <QtGui/QPainter>
#include <QtGui/QScreen>
#include <QtWidgets/QLabel>
using namespace QtDataVisualization;

class View{

private:
    Q3DSurface *m_graph;
    QSize screenSize;
    QWidget *container;
    QWidget *widget;
    QHBoxLayout *hLayout;
    QVBoxLayout *vLayout;
    QGroupBox *modelGroupBox;
    QRadioButton *sqrtSinModelRB;
    QVBoxLayout *modelVBox;
    QSlider *axisSliderX;
    QSlider *axisSliderY;
    QLabel *C1;
    QLabel *C2;
    QLabel *C3;
    //QSurfaceDataProxy *m_surfaceProxy;

public:
    View();
    ~View();

    void update(QSurface3DSeries *serie);
    Q3DSurface* getGraph();

};

#endif // VIEW_H
