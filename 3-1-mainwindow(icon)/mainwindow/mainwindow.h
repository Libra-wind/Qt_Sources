#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>

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
public slots:
    void newfile();

private:
    Ui::MainWindow *ui;

    QAction *aboutQtAction;
    QAction *exitQtAction;
    QAction *fileNewAction;
    QMenu *fileMenu;
    QToolBar *fileToolBar;
    QLabel *locationLabel;
    QLabel * formulaLabel;
    bool okTocontinue();
};

#endif // MAINWINDOW_H
