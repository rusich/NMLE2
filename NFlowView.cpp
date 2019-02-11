#include "NFlowView.h"
#include <QDebug>
#include <nodes/FlowScene>
#include <nodes/Node>
#include <QMimeData>
#include <QMetaProperty>
#include <QListWidgetItem>
#include <QObjectUserData>


NFlowView::NFlowView(QWidget *parent)
        : FlowView (parent)
{
    setAcceptDrops(true);
}

NFlowView::NFlowView(QtNodes::FlowScene *scene, QWidget *parent)
        : NFlowView (parent)
{
    setScene(scene);
}

void NFlowView::mousePressEvent(QMouseEvent *event)
{
    FlowView::mousePressEvent(event);
}

void NFlowView::dragEnterEvent(QDragEnterEvent *event)
{
    if(event->mimeData()->hasFormat("application/x-qabstractitemmodeldatalist"))
            event->accept();
    this->update();
}

void NFlowView::dragMoveEvent(QDragMoveEvent *event)
{
    if(event->mimeData()->hasFormat("application/x-qabstractitemmodeldatalist"))
            event->accept();
    this->update();
}

void NFlowView::dropEvent(QDropEvent *event)
{
    qDebug()<<event->pos();

    if (itemAt(event->pos()))
    {
        qDebug()<<"There is an item!";
        return;
    }
    const QMimeData *mimedata = event->mimeData();

    QString modelName = "notset";
    if(mimedata->hasFormat("application/x-qabstractitemmodeldatalist")){
        // https://stackoverflow.com/questions/1723989/how-to-decode-application-x-qabstractitemmodeldatalist-in-qt-for-drag-and-drop
        QByteArray encoded = mimedata->data("application/x-qabstractitemmodeldatalist");
        QDataStream stream(&encoded, QIODevice::ReadOnly);
        while (!stream.atEnd()) {
            int row, col;
            QMap<int,  QVariant> roleDataMap;
            stream >> row >> col >> roleDataMap;
            if(roleDataMap.contains(Qt::UserRole)){
                modelName = roleDataMap[Qt::UserRole].toString();
                break;
            }
        }
    }

    auto type = this->scene()->registry().create(modelName);

    if (type)
    {
        auto& node = this->scene()->createNode(std::move(type));

        QPoint pos = event->pos();

        QPointF posView = this->mapToScene(pos);

        node.nodeGraphicsObject().setPos(posView);

        this->scene()->nodePlaced(node);
    }
    else
    {
        qDebug() << "Model not found";
    }

}

