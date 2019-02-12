#-------------------------------------------------
#
# Project created by QtCreator 2019-02-07T21:08:34
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NMLE2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++14

INCLUDEPATH += ./nodeeditor/include
INCLUDEPATH += ./nodeeditor/include/nodes/internal

QMAKE_CXXFLAGS += -DNODE_EDITOR_STATIC

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    nodeeditor/src/Connection.cpp \
    nodeeditor/src/ConnectionBlurEffect.cpp \
    nodeeditor/src/ConnectionGeometry.cpp \
    nodeeditor/src/ConnectionGraphicsObject.cpp \
    nodeeditor/src/ConnectionPainter.cpp \
    nodeeditor/src/ConnectionState.cpp \
    nodeeditor/src/ConnectionStyle.cpp \
    nodeeditor/src/DataModelRegistry.cpp \
    nodeeditor/src/FlowScene.cpp \
    nodeeditor/src/FlowView.cpp \
    nodeeditor/src/FlowViewStyle.cpp \
    nodeeditor/src/Node.cpp \
    nodeeditor/src/NodeConnectionInteraction.cpp \
    nodeeditor/src/NodeDataModel.cpp \
    nodeeditor/src/NodeGeometry.cpp \
    nodeeditor/src/NodeGraphicsObject.cpp \
    nodeeditor/src/NodePainter.cpp \
    nodeeditor/src/NodeState.cpp \
    nodeeditor/src/NodeStyle.cpp \
    nodeeditor/src/Properties.cpp \
    nodeeditor/src/StyleCollection.cpp \
    blocks/cblock.cpp \
    examples/TextDisplayDataModel.cpp \
    examples/TextSourceDataModel.cpp \
    NFlowView.cpp

HEADERS += \
        mainwindow.h \
    nodeeditor/include/nodes/internal/Compiler.hpp \
    nodeeditor/include/nodes/internal/Connection.hpp \
    nodeeditor/include/nodes/internal/ConnectionGeometry.hpp \
    nodeeditor/include/nodes/internal/ConnectionGraphicsObject.hpp \
    nodeeditor/include/nodes/internal/ConnectionState.hpp \
    nodeeditor/include/nodes/internal/ConnectionStyle.hpp \
    nodeeditor/include/nodes/internal/DataModelRegistry.hpp \
    nodeeditor/include/nodes/internal/Export.hpp \
    nodeeditor/include/nodes/internal/FlowScene.hpp \
    nodeeditor/include/nodes/internal/FlowView.hpp \
    nodeeditor/include/nodes/internal/FlowViewStyle.hpp \
    nodeeditor/include/nodes/internal/memory.hpp \
    nodeeditor/include/nodes/internal/Node.hpp \
    nodeeditor/include/nodes/internal/NodeData.hpp \
    nodeeditor/include/nodes/internal/NodeDataModel.hpp \
    nodeeditor/include/nodes/internal/NodeGeometry.hpp \
    nodeeditor/include/nodes/internal/NodeGraphicsObject.hpp \
    nodeeditor/include/nodes/internal/NodePainterDelegate.hpp \
    nodeeditor/include/nodes/internal/NodeState.hpp \
    nodeeditor/include/nodes/internal/NodeStyle.hpp \
    nodeeditor/include/nodes/internal/OperatingSystem.hpp \
    nodeeditor/include/nodes/internal/PortType.hpp \
    nodeeditor/include/nodes/internal/QStringStdHash.hpp \
    nodeeditor/include/nodes/internal/QUuidStdHash.hpp \
    nodeeditor/include/nodes/internal/Serializable.hpp \
    nodeeditor/include/nodes/internal/Style.hpp \
    nodeeditor/include/nodes/internal/TypeConverter.hpp \
    nodeeditor/include/nodes/Connection \
    nodeeditor/include/nodes/ConnectionStyle \
    nodeeditor/include/nodes/DataModelRegistry \
    nodeeditor/include/nodes/FlowScene \
    nodeeditor/include/nodes/FlowView \
    nodeeditor/include/nodes/FlowViewStyle \
    nodeeditor/include/nodes/Node \
    nodeeditor/include/nodes/NodeData \
    nodeeditor/include/nodes/NodeDataModel \
    nodeeditor/include/nodes/NodeGeometry \
    nodeeditor/include/nodes/NodePainterDelegate \
    nodeeditor/include/nodes/NodeState \
    nodeeditor/include/nodes/NodeStyle \
    nodeeditor/include/nodes/TypeConverter \
    nodeeditor/src/ConnectionBlurEffect.hpp \
    nodeeditor/src/ConnectionPainter.hpp \
    nodeeditor/src/NodeConnectionInteraction.hpp \
    nodeeditor/src/NodePainter.hpp \
    nodeeditor/src/Properties.hpp \
    nodeeditor/src/StyleCollection.hpp \
    blocks/cblock.h \
    examples/TextData.hpp \
    examples/TextDisplayDataModel.hpp \
    examples/TextSourceDataModel.hpp \
    NFlowView.h

FORMS += \
        mainwindow.ui
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    nodeeditor/resources/resources.qrc \
    res.qrc \
    styles/darkorange/darkorange.qrc
