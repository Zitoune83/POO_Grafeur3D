#ifndef VIEW_H
#define VIEW_H

#include <QWidget>
#include <QLineEdit>
#include <QFormLayout>
#include <QLabel>
#include <QtDataVisualization/Q3DSurface>

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

    static const QString LABEL_EXPR;
    static const QString LABEL_EDIT_C1;
    static const QString LABEL_EDIT_C2;
    static const QString LABEL_EDIT_C3;

public:
    View(QWidget *parent = nullptr);
    ~View();

    static constexpr int WIDTH = 1280;
    static constexpr int HEIGHT = 900;
    static constexpr int GRAPH_STRETCH = 4;
    static constexpr int CONTROLS_STRETCH = 1;

public slots:

signals:
};
#endif // VIEW_H
