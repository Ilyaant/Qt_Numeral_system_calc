#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int ConvertTo10(std::string num, int cs);
    QString ConvertFrom10(int, int cs);

private slots:
    void on_pushButtonEq_clicked();

private:
    Ui::MainWindow *ui;
    QString leftNum;
    int leftCs;
    QString rightNum;
    int rightCs;
    int rezNum;
    int rezCs;
};
#endif // MAINWINDOW_H
