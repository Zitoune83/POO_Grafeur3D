#include "View.h"

using namespace QtDataVisualization;


View::View(){

    m_graph = new Q3DSurface();
    //m_surfaceProxy = new QSurfaceDataProxy();

    container = QWidget::createWindowContainer(m_graph);

    //Size of Screen
    screenSize = m_graph->screen()->size();
    container->setMinimumSize(QSize(screenSize.width() / 3, screenSize.height() / 2));
    container->setMaximumSize(screenSize);
    container->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    container->setFocusPolicy(Qt::StrongFocus);

    //Set Widget
    widget = new QWidget;
    hLayout = new QHBoxLayout(widget);
    vLayout = new QVBoxLayout();
    hLayout->addWidget(container, 1);
    hLayout->addLayout(vLayout);
    vLayout->setAlignment(Qt::AlignTop);

    //Title frame
    widget->setWindowTitle(QStringLiteral("Expression View"));

    modelGroupBox = new QGroupBox(QStringLiteral("Model"));

    sqrtSinModelRB = new QRadioButton(widget);
    sqrtSinModelRB->setText(QStringLiteral("Sqrt && Sin"));
    sqrtSinModelRB->setChecked(false);

    C1 = new QLabel;
    C1->setText("X : Valeur                               ");
    C2 = new QLabel;
    C2->setText("Y : Valeur                               ");
    C3 = new QLabel;
    C3->setText("Z : Valeur                               ");


    modelVBox = new QVBoxLayout;
    modelVBox->addWidget(C1);
    modelVBox->addWidget(C2);
    modelVBox->addWidget(C3);
    modelVBox->addWidget(sqrtSinModelRB);
    modelGroupBox->setLayout(modelVBox);

    axisSliderX = new QSlider(Qt::Horizontal, widget);
    axisSliderX->setMinimum(0);
    axisSliderX->setMaximum(10);
    axisSliderX->setTickInterval(1);
    axisSliderX->setEnabled(true);

    axisSliderY = new QSlider(Qt::Horizontal, widget);
    axisSliderY->setMinimum(0);
    axisSliderY->setMaximum(10);
    axisSliderY->setTickInterval(1);
    axisSliderY->setEnabled(true);

    //Display on Widget

    vLayout->addWidget(modelGroupBox);
    vLayout->addWidget(new QLabel(QStringLiteral("Lim X 0..10")));
    vLayout->addWidget(axisSliderX);
    vLayout->addWidget(new QLabel(QStringLiteral("Lim Y 0..10")));
    vLayout->addWidget(axisSliderY);
    widget->show();

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
