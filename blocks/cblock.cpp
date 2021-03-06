#include "cblock.h"

CBlock::CBlock()
        : _lineEdit(new QLineEdit("Default Text"))
{
    connect(_lineEdit, &QLineEdit::textEdited,
            this, &CBlock::onTextEdited);
}


unsigned int CBlock::nPorts(PortType portType) const
{
    unsigned int result = 1;

    switch (portType)
    {
    case PortType::In:
        result = 0;
        break;

    case PortType::Out:
        result = 1;

    default:
        break;
    }

    return result;
}


void CBlock::onTextEdited(QString const &string)
{
    Q_UNUSED(string);

    Q_EMIT dataUpdated(0);
}


NodeDataType CBlock::dataType(PortType, PortIndex) const
{
    return TextData().type();
}


std::shared_ptr<NodeData> CBlock::outData(PortIndex)
{
    return std::make_shared<TextData>(_lineEdit->text());
}
