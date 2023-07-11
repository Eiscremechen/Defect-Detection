#ifndef FOURIERTRANSFORM_H
#define FOURIERTRANSFORM_H

#include "ui_mainwindow.h"

#include <QMainWindow>

#include <QList>
#include <QValueAxis>
#include <QtCharts/QLineSeries>

QT_CHARTS_USE_NAMESPACE


QT_BEGIN_NAMESPACE
namespace Ui { class FourierTransform; }
QT_END_NAMESPACE

class MainWindow;

class FourierTransform : public QWidget
{
    Q_OBJECT
public:
    explicit FourierTransform(Ui::MainWindow* Mainwindow_ui = nullptr, QWidget *parent = nullptr);
    ~FourierTransform();

    void setEnvelope(const QList<double> SignalEnvelope);

    void setSamplingFrequency(const int &SamplingFrequency);

    void setShowLimit();


    void FastFourierTransform(const QList<double>& SignalEnvelope);
    void ShowFrequencyDomain(
        QList<double> SignalFrequencyDomain,
        const int& SamplingFrequency,
        const float& minShowLimit_x,
        const float& maxShowLimit_x,
        const float& minShowLimit_y,
        const float& maxShowLimit_y);


public slots:
    void Show();


private:
    Ui::MainWindow* m_ui;

    QList<double> SignalEnvelope;
    QList<double> SignalFrequencyDomain;


    int SamplingFrequency;

    QChart *Chart;

    float minShowLimit_x_Frequency;
    float maxShowLimit_x_Frequency;
    float minShowLimit_y_Frequency;
    float maxShowLimit_y_Frequency;

    QLineSeries* Series;
    QValueAxis* xAxis;

    QValueAxis* yAxis;



};

#endif // FOURIERTRANSFORM_H
