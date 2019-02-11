#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <nodes/NodeData>
#include <nodes/FlowScene>
#include "NFlowView.h"
//#include <nodes/FlowView>

using QtNodes::DataModelRegistry;
using QtNodes::FlowView;
using QtNodes::FlowScene;
//static std::shared_ptr<DataModelRegistry> registerDataModels();

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    FlowScene* scene;
    NFlowView* view;
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
