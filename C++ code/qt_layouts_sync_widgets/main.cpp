#include <QApplication>
#include <QHBoxLayout> // help determine size and position of widgets (can do in design too)
#include <QSlider>
#include <QSpinBox>

int main(int argc, char *argv[])
{
    // QApplication class manages the GUI application's control flow and main settings
    QApplication a(argc, argv);

    // main window widget (container for other 2 widgets)
    QWidget *mainWindow = new QWidget;
    mainWindow->setWindowTitle("How many chicken wings?");

    // spinner and slider widgets
    QSpinBox *spinner = new QSpinBox;
    QSlider *slider = new QSlider(Qt::Horizontal); // type of slider in constructor
    spinner->setRange(1,50); // same values since connecting
    slider->setRange(1,50);

    // connection functions (widget source, signal action, target, target action)
    QObject::connect(spinner, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));
    QObject::connect(slider, SIGNAL(valueChanged(int)), spinner, SLOT(setValue(int)));
    // set default spinner value (optional)
    spinner->setValue(10);

    // create layout (determines size and position of widgets [we're using QHBoxLayout])
    QHBoxLayout *layout = new QHBoxLayout;
    // add widgets to the layout
    layout->addWidget(slider);
    layout->addWidget(spinner);
    // tell main window to use this layout
    mainWindow->setLayout(layout);
    // display main window
    mainWindow->show();


    return a.exec();
}
