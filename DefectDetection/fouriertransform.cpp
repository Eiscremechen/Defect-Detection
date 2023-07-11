#include "fouriertransform.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <cmath>
#include <QDebug>
#include <QRegExpValidator>

#include "fftw3.h"
#pragma comment(lib, "libfftw3-3.lib")

//Real and Imag
#define REAL 0
#define IMAG 1

FourierTransform::FourierTransform(Ui::MainWindow* Mainwindow_ui, QWidget *parent):
    QWidget(parent),
    m_ui(Mainwindow_ui),
    Series(nullptr),
    Chart(nullptr),
    xAxis(nullptr),
    yAxis(nullptr)
{
    m_ui->lineEdit_ShowLimit_1_FrequencyDomain->setValidator(new QRegExpValidator(QRegExp("[-+]?[0-9]*\\.?[0-9]+")));
    m_ui->lineEdit_ShowLimit_2_FrequencyDomain->setValidator(new QRegExpValidator(QRegExp("[-+]?[0-9]*\\.?[0-9]+")));
    m_ui->lineEdit_ShowLimit_3_FrequencyDomain->setValidator(new QRegExpValidator(QRegExp("[-+]?[0-9]*\\.?[0-9]+")));
    m_ui->lineEdit_ShowLimit_4_FrequencyDomain->setValidator(new QRegExpValidator(QRegExp("[-+]?[0-9]*\\.?[0-9]+")));

//    Series = new QLineSeries();
//    Chart = new QChart();
//    xAxis = new QValueAxis();
//    yAxis = new QValueAxis();
}

FourierTransform::~FourierTransform()
{
    if(Series != nullptr)
    {
        delete Series;
        Series = nullptr;
    }


    if(xAxis!=nullptr)
    {
        delete xAxis;
        xAxis = nullptr;
    }

    if(yAxis!=nullptr)
    {
        delete yAxis;
        yAxis = nullptr;
    }

    if(Chart!=nullptr)
    {
        delete Chart;
        Chart=nullptr;
    }
}

void FourierTransform::setEnvelope(const QList<double> SignalEnvelope)
{
    this->SignalEnvelope = SignalEnvelope;
}

void FourierTransform::setSamplingFrequency(const int &SamplingFrequency)
{
    this->SamplingFrequency = SamplingFrequency;
}



void FourierTransform::setShowLimit()
{
    minShowLimit_x_Frequency = m_ui->lineEdit_ShowLimit_1_FrequencyDomain->text().toFloat();
    maxShowLimit_x_Frequency = m_ui->lineEdit_ShowLimit_2_FrequencyDomain->text().toFloat();

    minShowLimit_y_Frequency = m_ui->lineEdit_ShowLimit_3_FrequencyDomain->text().toFloat();
    maxShowLimit_y_Frequency = m_ui->lineEdit_ShowLimit_4_FrequencyDomain->text().toFloat();
}

void FourierTransform::ShowFrequencyDomain(
    QList<double> SignalFrequencyDomain,
    const int& SamplingFrequency,
    const float& minShowLimit_x,
    const float& maxShowLimit_x,
    const float& minShowLimit_y,
    const float& maxShowLimit_y)
{
//    Create object after deletion, to avoid data accumulation problems.
    if (Series != nullptr) {
        delete Series;
        Series = nullptr;
    }
    if (xAxis!= nullptr)
    {
        delete xAxis;
        xAxis = nullptr;

    }
    if (yAxis != nullptr)
    {
        delete yAxis;
        yAxis = nullptr;
    }

    if(xAxis == nullptr)
    {
        xAxis = new QValueAxis();
    }
    if(yAxis == nullptr)
    {
        yAxis = new QValueAxis();
    }
    if (Series==nullptr)
    {
        Series = new QLineSeries();
    }
    if(Chart == nullptr)
    {
        Chart = new QChart();
    }



//    N is the length of the original signal.
//    After the Fourier transform, the signal length is truncated by half,
//    so it must be multiplied by 2 to restore the original length.
    int N = 2 * SignalFrequencyDomain.size();

    QList<float> FrequencySeries;

    for (int i = 0; i< 0.5 * N; i++)
    {
        FrequencySeries.append((SamplingFrequency * i)/N);
    }
    for (int i = 0; i< 0.5 *N; i++)
    {

        Series->append(FrequencySeries [i], SignalFrequencyDomain[i]);
    }

    if (minShowLimit_x < maxShowLimit_x)
    {
        xAxis->setRange(qreal(minShowLimit_x), qreal(maxShowLimit_x));
    }
    else
    {
        xAxis->setRange(qreal(maxShowLimit_x), qreal(minShowLimit_x));
    }
    if (minShowLimit_y < maxShowLimit_y)
    {
        yAxis->setRange(qreal(minShowLimit_y), qreal(maxShowLimit_y));
    }
    else
    {
        yAxis->setRange(qreal(maxShowLimit_y), qreal(minShowLimit_y));
    }



    xAxis->setTitleText(QString("Frequency(Hz)"));
    yAxis->setTitleText(QString("Amp. (m/s^2)"));

    Chart->addAxis(xAxis, Qt::AlignBottom);
    Chart->addAxis(yAxis, Qt::AlignLeft);

    Chart->removeAllSeries();
    Chart->addSeries(Series);

    Series->attachAxis(xAxis);
    Series->attachAxis(yAxis);

    Chart->setTitle("Signal in Frequency Domain");
    Chart->legend()->hide();

    m_ui->graphicsView_FrequencyDomain->setChart(Chart);
}

void FourierTransform::FastFourierTransform(const QList<double> &SignalEnvelope)
{

    int N = SignalEnvelope.size();

    fftw_complex* x = new fftw_complex[N];
    fftw_complex* y = new fftw_complex[N];

    QList<double> SignalFrequencyTemp;

    for (int i = 0; i < N; i++) {
        x[i][REAL] = SignalEnvelope[i];
        x[i][IMAG] = 0;
    }

//    actuator: plan
//    sequence length: N,
//    input sequence: x,
//    output sequence: y,
//    transformation direction: FFTW_FORWARD(FFT),
//    transformation mode: FFTW_ESTIMATE
    fftw_plan plan = fftw_plan_dft_1d(N, x, y, FFTW_FORWARD, FFTW_ESTIMATE);

    fftw_execute(plan);

    for (int i = 0; i < N; i++)
    {
        SignalFrequencyTemp.append( std::sqrt( std::pow(y[i][REAL]/N ,2.0) + std::pow(y[i][IMAG]/N,2.0)  ) );
    }

    SignalFrequencyDomain = SignalFrequencyTemp.mid(0, N/2);

    for (int i = 1; i < SignalFrequencyDomain.size() - 1; i++)
    {
        SignalFrequencyDomain[i] = 2 * SignalFrequencyDomain[i];
    }

//    destroy actuator "plan"
    fftw_destroy_plan(plan);

    delete[] x;
    delete[] y;
}

void FourierTransform::Show()
{
    setShowLimit();

    FastFourierTransform(SignalEnvelope);

    ShowFrequencyDomain(
        SignalFrequencyDomain,
        SamplingFrequency,
        minShowLimit_x_Frequency,
        maxShowLimit_x_Frequency,
        minShowLimit_y_Frequency,
        maxShowLimit_y_Frequency);


}
