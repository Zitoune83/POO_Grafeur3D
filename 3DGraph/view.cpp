#include "view.h"
#include "classes/Constante.h"
#include "classes/Addition.h"
#include "classes/Multiplication.h"

const QString View::LABEL_EXPR = QString::fromStdString("Expr = ");
const QString View::LABEL_EDIT_C1 = QString::fromStdString("C1 = ");
const QString View::LABEL_EDIT_C2 = QString::fromStdString("C2 = ");
const QString View::LABEL_EDIT_C3 = QString::fromStdString("C3 = ");


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
    line_edit_c1.setText(QString::fromStdString("0"));
    line_edit_c2.setText(QString::fromStdString("0"));
    line_edit_c3.setText(QString::fromStdString("0"));

    controls_layout.addRow(View::LABEL_EXPR, &label_expr);
    controls_layout.addRow(View::LABEL_EDIT_C1, &line_edit_c1);
    controls_layout.addRow(View::LABEL_EDIT_C2, &line_edit_c2);
    controls_layout.addRow(View::LABEL_EDIT_C3, &line_edit_c3);

    point_X.setMinimum(2);
    point_X.setMaximum(50);
    point_X.setTickInterval(1);
    controls_layout.addWidget(&point_X);

    point_Z.setMinimum(2);
    point_Z.setMaximum(50);
    point_Z.setTickInterval(1);
    controls_layout.addWidget(&point_Z);

    size_min.setMinimum(-50);
    size_min.setMaximum(0);
    size_min.setTickInterval(1);
    controls_layout.addWidget(&size_min);

    size_max.setMinimum(0);
    size_max.setMaximum(50);
    size_max.setTickInterval(1);
    controls_layout.addWidget(&size_max);


    base_layout.addWidget(graph_container, View::GRAPH_STRETCH);
    base_layout.addLayout(&controls_layout, View::CONTROLS_STRETCH);

    resize(View::WIDTH, View::HEIGHT);

    QObject::connect(&line_edit_c1, &QLineEdit::returnPressed, this, &View::generateExpression);
    QObject::connect(&line_edit_c2, &QLineEdit::returnPressed, this, &View::generateExpression);
    QObject::connect(&line_edit_c3, &QLineEdit::returnPressed, this, &View::generateExpression);
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
void View::generateExpression()
{
    Constante c1 = line_edit_c1.text().toFloat();
    Constante c2 = line_edit_c2.text().toFloat();
    Constante c3 = line_edit_c3.text().toFloat();
    Multiplication mul(&c2, &c3);
    Addition add(&c1, &mul);
    emit expressionTyped(&add);
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
