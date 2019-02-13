#ifndef CBLOCK_H
#define CBLOCK_H
#include <nodes/NodeDataModel>
#include <nodes/NodeData>
#include <QLineEdit>
#include <iostream>
#include "examples/TextData.hpp"

using QtNodes::PortType;
using QtNodes::PortIndex;
using QtNodes::NodeData;
using QtNodes::NodeDataModel;
using QtNodes::NodeData;
using QtNodes::NodeDataType;

class CBlock : public NodeDataModel
{
    Q_OBJECT
public:
    CBlock();
    virtual ~CBlock() {}

    QString caption() const override { return QString("CBlock Caption"); }
    bool captionVisible() const override { return true; }
    bool portCaptionVisible(PortType, PortIndex) const override { return true; }
    static QString Name() { return QString("CBlock - базовый блок"); }
    QString name() const override { return QString("CBlockBase"); }

public:
    unsigned int nPorts(PortType portType) const override;
    NodeDataType dataType(PortType portType, PortIndex portIndex) const override;
    std::shared_ptr<NodeData> outData(PortIndex port) override;
    void setInData(std::shared_ptr<NodeData>, int) override { }
    QWidget * embeddedWidget() override { return _lineEdit; }

private Q_SLOTS:
    void onTextEdited(QString const &string);

private:
    QLineEdit * _lineEdit;
};

#endif // CBLOCK_H
