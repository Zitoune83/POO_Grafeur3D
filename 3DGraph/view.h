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

    QLineEdit line_edit_c1;
    QLineEdit line_edit_c2;
    QLineEdit line_edit_c3;

    QPushButton test_button;

    static const QString LABEL_EXPR;
    static const QString LABEL_EDIT_C1;
    static const QString LABEL_EDIT_C2;
    static const QString LABEL_EDIT_C3;

public:
    View(QWidget *parent = nullptr);
    ~View();

    QPushButton* getTestButton();

    static constexpr int WIDTH = 1280;
    static constexpr int HEIGHT = 900;
    static constexpr int GRAPH_STRETCH = 4;
    static constexpr int CONTROLS_STRETCH = 1;

private slots:
    void generateExpression();

public slots:
    void updateGraph(QSurface3DSeries* series);
    void updateLabelExpr(const QString& text);

signals:
    void expressionTyped(Expression* exp);
};
#endif // VIEW_H
