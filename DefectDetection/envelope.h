#ifndef ENVELOPE_H
#define ENVELOPE_H
#include "ui_mainwindow.h"

#include <QMainWindow>

#include <QList>
#include <QValueAxis>
#include <QtCharts/QLineSeries>

QT_CHARTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE
namespace Ui { class Envelope; }
QT_END_NAMESPACE


class MainWindow;

class Envelope : public QWidget
{
    Q_OBJECT
public:
    explicit Envelope(Ui::MainWindow* Mainwindow_ui = nullptr, QWidget *parent = nullptr);
    ~Envelope();

    void setSignal(const QList<double>& SignalTimeDomain);
    QList<double> getEnvelope();

    void setSamplingFrequency(const int &SamplingFrequency);



    void ShowEnvelope(
        QList<double> SignalEnvelope,
        const int& SamplingFrequency,
        const float& minShowLimit_x,
        const float& maxShowLimit_x,
        const float& minShowLimit_y,
        const float& maxShowLimit_y);

    void setShowLimit();

//    third-party software library: FFTW
    void FastFourierTransform(const QList<double>& SignalTimeDomain);
    void InverseFastFourierTransform (
        const QList<double>& SignalFrequencyDomainReal,
        const QList<double>& SignalFrequencyDomainImag);

//    Hilbert Transform is utilized to demodulation.
    void HilbertTransform(const QList<double>& SignalTimeDomain);

    void RemoveMean(QList<double> SignalTimeDomain);

public slots:
    void Show();




private:
    Ui::MainWindow* m_ui;
    QList<double> SignalTimeDomain;
    QList<double> SignalEnvelope;
    QList<double> SignalFrequencyDomainReal;
    QList<double> SignalFrequencyDomainImag;

    int SamplingFrequency;

    QChart *Chart;

    float minShowLimit_x_Envelope;
    float maxShowLimit_x_Envelope;
    float minShowLimit_y_Envelope;
    float maxShowLimit_y_Envelope;

    QLineSeries* Series;
    QValueAxis* xAxis;

    QValueAxis* yAxis;
};

#endif // ENVELOPE_H
