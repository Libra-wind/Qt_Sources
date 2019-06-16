#include <QApplication>
#include <QObject>
#include <QHBoxLayout>
#include <QSpinBox>
#include <QSlider>
#include <QWidget>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    QWidget w;
    w.setWindowTitle("Enter Your Age");
    QSpinBox spinbox;
    QSlider slider(Qt::Horizontal);

    spinbox.setRange(0,130);
    slider.setRange(0,130);

    QObject::connect(&slider, SIGNAL(valueChanged(int)), &spinbox, SLOT(setValue(int)));
    QObject::connect(&spinbox, SIGNAL(valueChanged(int)), &slider, SLOT(setValue(int)));

    QHBoxLayout layout;

    layout.addWidget(&spinbox);
    layout.addWidget(&slider);

    w.setLayout(&layout);

    w.show();
    return app.exec();
}
