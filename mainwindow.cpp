#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <nodes/DataModelRegistry>
#include "examples/TextDisplayDataModel.hpp"
#include "examples/TextSourceDataModel.hpp"
#include <nodes/NodeStyle>
#include <nodes/FlowViewStyle>
#include <nodes/ConnectionStyle>
#include "blocks/cblock.h"

using QtNodes::FlowViewStyle;
using QtNodes::NodeStyle;
using QtNodes::ConnectionStyle;

static void setNodeeditorStyle()
{
  FlowViewStyle::setStyle(
  R"(
  {
    "FlowViewStyle": {
      "BackgroundColor": [0, 43, 135],
      "FineGridColor": "grey",
      "CoarseGridColor": [235, 235, 220]
    }
  }
  )");

  NodeStyle::setNodeStyle(
  R"(
  {
    "NodeStyle": {
      "NormalBoundaryColor": "darkgray",
      "SelectedBoundaryColor": "deepskyblue",
      "GradientColor0": "mintcream",
      "GradientColor1": "mintcream",
      "GradientColor2": "mintcream",
      "GradientColor3": "mintcream",
      "ShadowColor": [200, 200, 200],
      "FontColor": [10, 10, 10],
      "FontColorFaded": [100, 100, 100],
      "ConnectionPointColor": "white",
      "PenWidth": 2.0,
      "HoveredPenWidth": 2.5,
      "ConnectionPointDiameter": 10.0,
      "Opacity": 1.0
    }
  }
  )");

  ConnectionStyle::setConnectionStyle(
  R"(
  {
    "ConnectionStyle": {
      "ConstructionColor": "gray",
      "NormalColor": [0,0,0,5],
      "SelectedColor": "gray",
      "SelectedHaloColor": "deepskyblue",
      "HoveredColor": "deepskyblue",

      "LineWidth": 3.0,
      "ConstructionLineWidth": 2.0,
      "PointDiameter": 10.0,

      "UseDataDefinedColors": false
    }
  }
  )");
}

static std::shared_ptr<DataModelRegistry> registerDataModels()
{
    auto ret = std::make_shared<DataModelRegistry>();
    ret->registerModel<TextSourceDataModel>();
    ret->registerModel<TextDisplayDataModel>();
    ret->registerModel<CBlock>();
    return ret;
}

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    setNodeeditorStyle();
    scene = new FlowScene(registerDataModels());

    view = new NFlowView(scene, this);

    ui->tabWidget->addTab(view,"Main");
    QIcon icon;
    icon.addFile(QString::fromUtf8(":/res/images/qtlogo.png"), QSize(), QIcon::Normal, QIcon::On);

    for (auto const &assoc : scene->registry().registeredModelsCategoryAssociation())
    {
      auto item   = new QListWidgetItem(ui->listWidget);
      item->setText(assoc.first);
      item->setData(Qt::UserRole, assoc.first);
      item->setIcon(icon);
    }

//    QListWidgetItem*  item = new QListWidgetItem("TextDisplayDataModel",ui->listWidget);
//    item->setData(Qt::UserRole, QVariant("TextDisplayDataModel"));

//    item = new QListWidgetItem("TextSourceDataModel",ui->listWidget);
//    item->setIcon(icon);
//    item->setData(Qt::UserRole, QVariant("TextSourceDataModel"));


}

MainWindow::~MainWindow()
{
    delete ui;
}
