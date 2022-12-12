#include "widget.h"

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

using namespace QtDataVisualization;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Q3DSurface *graph = new Q3DSurface();

    QWidget *container = QWidget::createWindowContainer(graph);

    //Size of Screen
    QSize screenSize = graph->screen()->size();
    container->setMinimumSize(QSize(screenSize.width() / 2, screenSize.height() / 1.6));
    container->setMaximumSize(screenSize);
    container->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    container->setFocusPolicy(Qt::StrongFocus);

    //Set Widget
    QWidget *widget = new QWidget;
    QHBoxLayout *hLayout = new QHBoxLayout(widget);
    QVBoxLayout *vLayout = new QVBoxLayout();
    hLayout->addWidget(container, 1);
    hLayout->addLayout(vLayout);
    vLayout->setAlignment(Qt::AlignTop);

    //Title frame
    widget->setWindowTitle(QStringLiteral("Expression View"));

    QGroupBox *modelGroupBox = new QGroupBox(QStringLiteral("Model"));

    QRadioButton *sqrtSinModelRB = new QRadioButton(widget);
    sqrtSinModelRB->setText(QStringLiteral("Sqrt && Sin"));
    sqrtSinModelRB->setChecked(false);

    QVBoxLayout *modelVBox = new QVBoxLayout;
    modelVBox->addWidget(sqrtSinModelRB);
    modelGroupBox->setLayout(modelVBox);

    QSlider *axisSliderX = new QSlider(Qt::Horizontal, widget);
    axisSliderX->setMinimum(0);
    axisSliderX->setMaximum(10);
    axisSliderX->setTickInterval(1);
    axisSliderX->setEnabled(true);

    QSlider *axisSliderY = new QSlider(Qt::Horizontal, widget);
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
    return app.exec();
}
