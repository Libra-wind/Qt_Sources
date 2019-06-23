#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QAction;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QAction *aboutQtAction;
    QAction *exitQtAction;
    QMenu *fileMenu;
    QToolBar *fileToolBar;
};

#endif // MAINWINDOW_H
