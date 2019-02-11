#ifndef NFLOWVIEW_H
#define NFLOWVIEW_H
#include <nodes/FlowView>
#include <QMouseEvent>
#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <QDropEvent>

using QtNodes::FlowView;
using QtNodes::FlowScene;

class NFlowView : public FlowView
{
public:
    NFlowView(QWidget *parent = Q_NULLPTR);
    NFlowView(FlowScene *scene, QWidget *parent = Q_NULLPTR);

    NFlowView(const FlowView&) = delete;
    NFlowView operator=(const FlowView&) = delete;

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
private:
    void insertDroppedItem(QMouseEvent *event);
};

#endif // NFLOWVIEW_H
