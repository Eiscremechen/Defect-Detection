#ifndef READDATA_H
#define READDATA_H

#include "ui_mainwindow.h"

#include <QMainWindow>
#include <QString>

#include <QFile>
#include <QList>
#include <QValueAxis>
#include <QtCharts/QLineSeries>

QT_CHARTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE
namespace Ui { class ReadData; }
QT_END_NAMESPACE

class MainWindow;

class ReadData : public QWidget
{
    Q_OBJECT
public:
    explicit ReadData(Ui::MainWindow* Mainwindow_ui = nullptr, QWidget *parent = nullptr);
    ~ReadData();

public:
    QString getFileName(const QString& FileName);

    void setSamplingFrequency();

    int getSamplingFrequency();

//    show the filename in the edit line.
    void showFileName(const QString& FileName);

//    the data of the file is acquired.
    void setData(const QString& filePath);

//    Interface for data output
    QList<double> getData();


//    show the signal in time domain
    void ShowTimeDomain (
        QList<double> SignalTimeDomain,
        const int& SamplingFrequency,
        const float& minShowLimit_x,
        const float& maxShowLimit_x,
        const float& minShowLimit_y,
        const float& maxShowLimit_y);

//    zoom in or zoom out
    void setShowLimit();



public slots:
    void FileSelection();
    void Show();




private:
    Ui::MainWindow* m_ui;

    QString FilePath;

    QList<double> SignalTimeDomain;

//    zone for diagramm
    QChart *Chart;

    int SamplingFrequency;

    float minShowLimit_x_Orignal;
    float maxShowLimit_x_Orignal;
    float minShowLimit_y_Orignal;
    float maxShowLimit_y_Orignal;

//    data
    QLineSeries* Series;
    QValueAxis* xAxis;
    QValueAxis* yAxis;
};

#endif // READDATA_H
