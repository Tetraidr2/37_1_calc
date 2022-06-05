//
// Created by gigtorus on 05.06.2022.
//

#ifndef INC_37_1_CALC_CALC_H
#define INC_37_1_CALC_CALC_H

#include <QMainWindow>
#include <QtWidgets/QLineEdit>
#include <tuple>
#include <string>

class CalcMainWindow : public QMainWindow{
    Q_OBJECT
public:
    QLineEdit* lineEdit1 = nullptr;
    QLineEdit* lineEdit2 = nullptr;
    QLineEdit* lineEdit3 = nullptr;
    CalcMainWindow(QWidget* parent = nullptr): QMainWindow(parent){}

    auto getNumPol(){
        bool f1;
        double num1 = lineEdit1->text().toDouble(&f1);
        bool f2;
        double num2 = lineEdit2->text().toDouble(&f2);
        return std::tuple<bool, double, bool, double>(f1,num1,f2,num2);
    }

public slots:
    void ButtonPlus(){
        auto tup = getNumPol();
        if(std::get<0>(tup) && std::get<2>(tup)){
            auto sum = std::get<1>(tup) + std::get<3>(tup);
            std::string s = std::to_string(sum);
            lineEdit3->setText(QString(s.c_str()));
            return;
        }
        lineEdit3->setText("ERROR!");
    };
    void ButtonMinus(){
        auto tup = getNumPol();
        if(std::get<0>(tup) && std::get<2>(tup)){
            auto sum = std::get<1>(tup) - std::get<3>(tup);
            std::string s = std::to_string(sum);
            lineEdit3->setText(QString(s.c_str()));
            return;
        }
        lineEdit3->setText("ERROR!");

    };
    void ButtonUmn(){
        auto tup = getNumPol();
        if(std::get<0>(tup) && std::get<2>(tup)){
            auto sum = std::get<1>(tup) * std::get<3>(tup);
            std::string s = std::to_string(sum);
            lineEdit3->setText(QString(s.c_str()));
            return;
        }
        lineEdit3->setText("ERROR!");

    };
    void ButtonDel(){
        auto tup = getNumPol();
        if(std::get<0>(tup) && std::get<2>(tup) && std::get<3>(tup)!=0){
            auto sum = std::get<1>(tup) / std::get<3>(tup);
            std::string s = std::to_string(sum);
            lineEdit3->setText(QString(s.c_str()));
            return;
        }
        lineEdit3->setText("ERROR!");

    };

};

#endif //INC_37_1_CALC_CALC_H
