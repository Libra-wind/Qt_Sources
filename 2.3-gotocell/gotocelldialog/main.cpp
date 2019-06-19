#include <QApplication>
#include "gotocelldialog.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    GoToCellDialog dialog;
    //GotoCellDialog *dialog = new GotoCellDialog;
    dialog.show();

    return app.exec();

}
