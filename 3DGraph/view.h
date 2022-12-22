#ifndef VIEW_H
#define VIEW_H

#include "classes/Expression.h"
#include <QWidget>
#include <QLineEdit>
#include <QFormLayout>
#include <QLabel>
#include <QtDataVisualization/Q3DSurface>
#include <QtDataVisualization/QSurface3DSeries>
#include <QPushButton>
#include <QSlider>

using namespace QtDataVisualization;

class View : public QWidget
{
    Q_OBJECT

private:
    QHBoxLayout base_layout;
    QFormLayout controls_layout;

    QWidget* graph_container;
    Q3DSurface graph;

    QLabel label_expr;

    QPushButton test_button;

    QSlider point_X;
    QSlider point_Z;

    QSlider size_min;
    QSlider size_max;

    static const QString LABEL_EXPR;
    static const QString LABEL_SAMPLE_X;
    static const QString LABEL_SAMPLE_Z;
    static const QString LABEL_RANGE_MIN;
    static const QString LABEL_RANGE_MAX;

public:
    View(QWidget *parent = nullptr);
    ~View();

    QPushButton* getTestButton();
    QSlider* getsliderpoint_x();
    QSlider* getsliderpoint_z();
    QSlider* getslidersize_min();
    QSlider* getslidersize_max();
    static constexpr int WIDTH = 1280;
    static constexpr int HEIGHT = 900;
    static constexpr int GRAPH_STRETCH = 4;
    static constexpr int CONTROLS_STRETCH = 1;
    static QString LABEL_AXE_X;
    static QString LABEL_AXE_Y;
    static QString LABEL_AXE_Z;

public slots:
    void updateGraph(QSurface3DSeries* series);
    void updateLabelExpr(const QString& text);
};
#endif // VIEW_H
