#include "view.h"

const QString View::LABEL_EXPR = QString::fromStdString("Expr = ");
const QString View::LABEL_EDIT_C1 = QString::fromStdString("C1 = ");
const QString View::LABEL_EDIT_C2 = QString::fromStdString("C2 = ");
const QString View::LABEL_EDIT_C3 = QString::fromStdString("C3 = ");

View::View(QWidget *parent)
    : QWidget(parent),
      base_layout(this)
{
    graph_container = createWindowContainer(&graph);

    label_expr.setText(QString::fromStdString("C1 + C2 * C3"));

    controls_layout.addRow(View::LABEL_EXPR, &label_expr);
    controls_layout.addRow(View::LABEL_EDIT_C1, &line_edit_c1);
    controls_layout.addRow(View::LABEL_EDIT_C2, &line_edit_c2);
    controls_layout.addRow(View::LABEL_EDIT_C3, &line_edit_c3);

    base_layout.addWidget(graph_container, View::GRAPH_STRETCH);
    base_layout.addLayout(&controls_layout, View::CONTROLS_STRETCH);

    resize(View::WIDTH, View::HEIGHT);
}

View::~View()
{
}
