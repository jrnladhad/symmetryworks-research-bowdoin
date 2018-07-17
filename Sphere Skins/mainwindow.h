#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDockWidget>
#include <QtWidgets>
#include <QCloseEvent>
#include "interface.h"

class QAction;
class QActionGroup;
class QLabel;
class QMenu;

const int SCREEN_INTERFACE_MARGIN = 50;
const double SCREEN_WIDTH_MARGIN = 0.3;
const double SCREEN_HEIGHT_MARGIN = 0.15;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow();
    ~MainWindow();

    void close() {currInterface->closing();}
    
private:
    void createActions();
    void createMenus();
    void createDockWindows();
    
    QDockWidget *rightDock;
    
    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *advancedMenu;
    QMenu *helpMenu;

    QActionGroup *alignmentGroup;

    QAction *loadAct;
    QAction *saveAct;
    QAction *saveAsAct;
    QAction *exportImageAct;
    QAction *snapshotAct;
    QAction *resetImageAct;
    QAction *aboutAct;
    QAction *setOverflowColorAct;
    QAction *showImageDataGraphAct;
    QAction *undoAct;
    QAction *redoAct;
    QShortcut *undoShortcut;
    
    
    Interface *currInterface;
    HistoryDisplay *snapShotWindow;
    
    private slots:
    void updateImageActionStatus(bool status) {
        setOverflowColorAct->setEnabled(status);
        //showImageDataGraphAct->setEnabled(status);
    }
    
};

#endif
