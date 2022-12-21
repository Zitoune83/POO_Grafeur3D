#include "view.h"

const QString View::LABEL_EXPR = QString::fromStdString("Expr = ");
const QString View::LABEL_SAMPLE_X = QString::fromStdString("Sample on X: ");
const QString View::LABEL_SAMPLE_Z = QString::fromStdString("Sample on Z: ");
const QString View::LABEL_RANGE_MIN = QString::fromStdString("Minimum range: ");
const QString View::LABEL_RANGE_MAX = QString::fromStdString("Maximum range: ");


View::View(QWidget *parent)
    : QWidget(parent),
      base_layout(this),
      point_X(Qt::Horizontal),
      point_Z(Qt::Horizontal),
      size_min(Qt::Horizontal),
      size_max(Qt::Horizontal)

{
    graph_container = createWindowContainer(&graph);

    label_expr.setText(QString::fromStdString(""));

    controls_layout.addRow(View::LABEL_EXPR, &label_expr);

    point_X.setMinimum(2);
    point_X.setMaximum(50);
    point_X.setTickInterval(1);
    controls_layout.addRow(View::LABEL_SAMPLE_X, &point_X);

    point_Z.setMinimum(2);
    point_Z.setMaximum(50);
    point_Z.setTickInterval(1);
    controls_layout.addRow(View::LABEL_SAMPLE_Z, &point_Z);

    size_min.setMinimum(-50);
    size_min.setMaximum(0);
    size_min.setTickInterval(1);
    controls_layout.addRow(View::LABEL_RANGE_MIN, &size_min);

    size_max.setMinimum(0);
    size_max.setMaximum(50);
    size_max.setTickInterval(1);
    controls_layout.addRow(View::LABEL_RANGE_MAX, &size_max);


    base_layout.addWidget(graph_container, View::GRAPH_STRETCH);
    base_layout.addLayout(&controls_layout, View::CONTROLS_STRETCH);

    resize(View::WIDTH, View::HEIGHT);

}

View::~View()
{
}

QSlider* View::getsliderpoint_x()
{
    return &point_X;
}

QSlider* View::getsliderpoint_z()
{
    return &point_Z;
}
QSlider* View::getslidersize_min()
{
    return &size_min;
}
QSlider* View::getslidersize_max()
{
    return &size_max;
}

void View::updateGraph(QSurface3DSeries* series)
{
    if (!graph.seriesList().isEmpty())
        graph.removeSeries(graph.seriesList().constFirst());
    graph.addSeries(series);
}

void View::updateLabelExpr(const QString& text)
{
    label_expr.setText(text);
}

QPushButton* View::getTestButton()
{
    return &test_button;
}
