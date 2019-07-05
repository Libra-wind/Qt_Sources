#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QAction;
class Spreadsheet;
class QLabel;
class FindDialog;
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow();

    void setCurFile(const QString &filename);
    QString strippedName(const QString &fullFileName);
private:
    FindDialog *findDialog;
    Spreadsheet *spreadsheet;
    QLabel *locationLabel;
    QLabel *formulaLabel;

    QMenu *fileMenu;
    QAction* newAction;
    QAction* openAction;
    QAction* exitAction;
    QAction* saveAction;
    QAction* saveasAction;


    QMenu* toolMenu;
    QAction* recAction;
    QAction* sortAction;

    QMenu *helpMenu;
    QAction *aboutAction;
    QAction *aboutQtAction;



    QMenu* editMenu;

    QAction* cutAction;
    QAction* copyAction;
    QAction* pasteAction;
    QAction* delAction;
//    QAction* selAction;
    QAction* findAction;
    QAction* go2cellAction;

    QMenu* selSubMenu;
    QAction* selRowAction;
    QAction* selColAction;
    QAction* selAllAction;

    QMenu* optMenu;
    QAction* showGridAction;
    QAction* autoRclAction;

    enum{MaxRecentFiles = 5};
    QAction* recentFileActions[MaxRecentFiles];
    QAction* separatorAction;



    bool okTocontinue();
    void updateRecentFileActions();
protected:
    void closeEvent(QCloseEvent *event);
private:
    QString curFile;
    QStringList recentFiles;
    //bool findDialog;
    bool loadFile(const QString &fileName);
    void writeSettings();
    void readSettings();
private slots:
    void spreadsheetModified();
    void updateStatusBar();
    void newFile();
    void open();
    bool save();
    bool saveFile(const QString &filename);
    bool saveAs();
    void openRecentFile();
    void find();
    void gotoCell();
};

#endif // MAINWINDOW_H
