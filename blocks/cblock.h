#ifndef CBLOCK_H
#define CBLOCK_H
#include <nodes/NodeDataModel>
#include <nodes/NodeData>
#include <QLineEdit>

#include <iostream>

using QtNodes::PortType;
using QtNodes::PortIndex;
using QtNodes::NodeData;
using QtNodes::NodeDataModel;
using QtNodes::NodeData;
using QtNodes::NodeDataType;

/// The class can potentially incapsulate any user data which
/// need to be transferred within the Node Editor graph
class TextData : public NodeData
{
public:

  TextData() {}

  TextData(QString const &text)
    : _text(text)
  {}

  NodeDataType type() const override
  { return NodeDataType {"text", "Text"}; }

  QString text() const { return _text; }

private:

  QString _text;
};


class CBlock : public NodeDataModel
{
    Q_OBJECT
public:
    CBlock();
    virtual ~CBlock() {}

    QString caption() const override { return QString("CBlock"); }
    bool captionVisible() const override { return true; }
    static QString Name() { return QString("CBlock"); }
    QString name() const override { return CBlock::Name(); }

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
