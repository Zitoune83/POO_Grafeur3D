#include "view.h"
#include "model.h"
#include <QApplication>

void connect(Model& m, View& v)
{
    QObject::connect(&m, &Model::seriesUpdated, &v, &View::updateGraph);
    QObject::connect(&m, &Model::expressionUpdated, &v, &View::updateLabelExpr);
    QObject::connect(&v, &View::expressionTyped, &m, &Model::setExpression);
    QPushButton* test_button = v.getTestButton();
    QObject::connect(test_button, &QPushButton::clicked, &m, &Model::testMemory);
    m.init();
}

void connect(View& v, Model& m)
{
    connect(m, v);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Model m;
    View v;
    connect(m, v);

    v.show();
    return a.exec();
}
