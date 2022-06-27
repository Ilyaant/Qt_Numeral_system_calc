// БПМ-19-2 Антонов Илья и Панин Григорий

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <stack>
#include <cmath>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::ConvertTo10(std::string num, int cs)
{
    std::stack<int> st;
    for (unsigned int i = 0; i < num.size(); ++i){
        if (num[i] == 'A') st.push(10);
        else if (num[i] == 'B') st.push(11);
        else if (num[i] == 'C') st.push(12);
        else if (num[i] == 'D') st.push(13);
        else if (num[i] == 'E') st.push(14);
        else if (num[i] == 'F') st.push(15);
        else if (num[i] == 'G') st.push(16);
        else if (num[i] == 'H') st.push(17);
        else if (num[i] == 'I') st.push(18);
        else if (num[i] == 'J') st.push(19);
        else if (num[i] == 'K') st.push(20);
        else if (num[i] == 'L') st.push(21);
        else if (num[i] == 'M') st.push(22);
        else if (num[i] == 'N') st.push(23);
        else if (num[i] == 'O') st.push(24);
        else if (num[i] == 'P') st.push(25);
        else if (num[i] == 'Q') st.push(26);
        else if (num[i] == 'R') st.push(27);
        else if (num[i] == 'S') st.push(28);
        else if (num[i] == 'T') st.push(29);
        else if (num[i] == 'U') st.push(30);
        else if (num[i] == 'V') st.push(31);
        else if (num[i] == 'W') st.push(32);
        else if (num[i] == 'X') st.push(33);
        else if (num[i] == 'Y') st.push(34);
        else if (num[i] == 'Z') st.push(35);
        else st.push(num[i] - '0');
    }
    int i = 0;
    int rez = 0;
    while(!st.empty()){
        rez += st.top()*std::pow(cs, i);
        st.pop();
        ++i;
    }
    return rez;
}

QString MainWindow::ConvertFrom10(int num, int cs)
{
    std::stack<int> st;
    while(num > cs - 1){
        st.push(num % cs);
        num /= cs;
    }
    st.push(num);
    QString rez;
    while (!st.empty()){
        if (st.top() == 10) rez += "A";
        else if (st.top() == 11) rez += "B";
        else if (st.top() == 12) rez += "C";
        else if (st.top() == 13) rez += "D";
        else if (st.top() == 14) rez += "E";
        else if (st.top() == 15) rez += "F";
        else if (st.top() == 16) rez += "G";
        else if (st.top() == 17) rez += "H";
        else if (st.top() == 18) rez += "I";
        else if (st.top() == 19) rez += "J";
        else if (st.top() == 20) rez += "K";
        else if (st.top() == 21) rez += "L";
        else if (st.top() == 22) rez += "M";
        else if (st.top() == 23) rez += "N";
        else if (st.top() == 24) rez += "O";
        else if (st.top() == 25) rez += "P";
        else if (st.top() == 26) rez += "Q";
        else if (st.top() == 27) rez += "R";
        else if (st.top() == 28) rez += "S";
        else if (st.top() == 29) rez += "T";
        else if (st.top() == 30) rez += "U";
        else if (st.top() == 31) rez += "V";
        else if (st.top() == 32) rez += "W";
        else if (st.top() == 33) rez += "X";
        else if (st.top() == 34) rez += "Y";
        else if (st.top() == 35) rez += "Z";
        else rez += QString::number(st.top());
        st.pop();
    }
    return rez;
}

void MainWindow::on_pushButtonEq_clicked()
{
    leftNum = ui->tleftNum->text();
    rightNum = ui->trightNum->text();
    leftCs = ui->tleftCS->text().toInt();
    rightCs = ui->trightCS->text().toInt();
    rezCs = ui->trezCS_in->text().toInt();

    int leftNum10 = ConvertTo10(leftNum.toStdString(), leftCs);
    int rightNum10 = ConvertTo10(rightNum.toStdString(), rightCs);

    if (ui->comboOps->currentText() == "+") rezNum = leftNum10 + rightNum10;
    if (ui->comboOps->currentText() == "-") rezNum = leftNum10 - rightNum10;
    if (ui->comboOps->currentText() == "*") rezNum = leftNum10 * rightNum10;
    if (ui->comboOps->currentText() == "/") rezNum = leftNum10 / rightNum10;


    QString qrezNum = ConvertFrom10(rezNum, rezCs);
    ui->trezNum->setText(qrezNum);
    ui->trezCS_out->setText(QString::number(rezCs));
}
