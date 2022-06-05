#include <QApplication>
#include <QPushButton>
#include "Calc.h"
#include "./ui_CalcUI.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    CalcMainWindow window(nullptr);
    Ui::MainWindow calc;
    calc.setupUi(&window);
    window.lineEdit1 = calc.lineEdit;
    window.lineEdit2 = calc.lineEdit_2;
    window.lineEdit3 = calc.lineEdit_3;
    window.resize(340,200);
    window.show();
    return QApplication::exec();
}
