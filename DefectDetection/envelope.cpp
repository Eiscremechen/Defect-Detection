#include "envelope.h"

#include <cmath>
#include <QDebug>
#include <QRegExpValidator>

#include "fftw3.h"
#pragma comment(lib, "libfftw3-3.lib")

//Real and Imag
#define REAL 0
#define IMAG 1


Envelope::Envelope(Ui::MainWindow* Mainwindow_ui, QWidget *parent):
    QWidget(parent),
    m_ui(Mainwindow_ui),
    Series(nullptr),
    Chart(nullptr),
    xAxis(nullptr),
    yAxis(nullptr)
{
    m_ui->lineEdit_ShowLimit_1_Envelope->setValidator(new QRegExpValidator(QRegExp("[-+]?[0-9]*\\.?[0-9]+")));
    m_ui->lineEdit_ShowLimit_2_Envelope->setValidator(new QRegExpValidator(QRegExp("[-+]?[0-9]*\\.?[0-9]+")));
    m_ui->lineEdit_ShowLimit_3_Envelope->setValidator(new QRegExpValidator(QRegExp("[-+]?[0-9]*\\.?[0-9]+")));
    m_ui->lineEdit_ShowLimit_4_Envelope->setValidator(new QRegExpValidator(QRegExp("[-+]?[0-9]*\\.?[0-9]+")));

//    Series = new QLineSeries();
//    Chart = new QChart();
//    xAxis = new QValueAxis();
//    yAxis = new QValueAxis();

}

Envelope::~Envelope()
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

void Envelope::setSignal(const QList<double>& SignalTimeDomain)
{
    this->SignalTimeDomain = SignalTimeDomain;
}

QList<double> Envelope::getEnvelope()
{
    return SignalEnvelope;
}

void Envelope::setSamplingFrequency(const int& SamplingFrequency)
{
    this->SamplingFrequency = SamplingFrequency;
}




void Envelope::ShowEnvelope(
    QList<double> SignalEnvelope,
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

    for (int i = 0; i< SignalEnvelope.size(); i++)
    {

        Series->append((float)i/SamplingFrequency, SignalEnvelope[i]);
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



    xAxis->setTitleText(QString("Time(s)"));
    yAxis->setTitleText(QString("Amp. (m/s^2)"));

    Chart->addAxis(xAxis, Qt::AlignBottom);
    Chart->addAxis(yAxis, Qt::AlignLeft);

    Chart->removeAllSeries();
    Chart->addSeries(Series);

    Series->attachAxis(xAxis);
    Series->attachAxis(yAxis);

    Chart->setTitle("Signal in Frequency Domain");
    Chart->legend()->hide();

    m_ui->graphicsView_Envelope->setChart(Chart);
}

void Envelope::setShowLimit()
{
    minShowLimit_x_Envelope = m_ui->lineEdit_ShowLimit_1_Envelope->text().toFloat();
    maxShowLimit_x_Envelope = m_ui->lineEdit_ShowLimit_2_Envelope->text().toFloat();

    minShowLimit_y_Envelope = m_ui->lineEdit_ShowLimit_3_Envelope->text().toFloat();
    maxShowLimit_y_Envelope = m_ui->lineEdit_ShowLimit_4_Envelope->text().toFloat();
}

void Envelope::Show()
{
    setShowLimit();

//    data preprocess
    RemoveMean(SignalTimeDomain);

    HilbertTransform(SignalTimeDomain);

    ShowEnvelope(
        SignalEnvelope,
        SamplingFrequency,
        minShowLimit_x_Envelope,
        maxShowLimit_x_Envelope,
        minShowLimit_y_Envelope,
        maxShowLimit_y_Envelope);

}

void Envelope::FastFourierTransform(const QList<double> &SignalTimeDomain)
{
    SignalFrequencyDomainReal.clear();
    SignalFrequencyDomainImag.clear();

    int N = SignalTimeDomain.size();

    fftw_complex* x = new fftw_complex[N];
    fftw_complex* y = new fftw_complex[N];

    for (int i = 0; i < N; i++) {
        x[i][REAL] = SignalTimeDomain[i];
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

    for (int i = 0; i < N; i++) {
        SignalFrequencyDomainReal.append(y[i][REAL]);
        SignalFrequencyDomainImag.append(y[i][IMAG]);
    }

//    destroy actuator "plan"
    fftw_destroy_plan(plan);

    delete[] x;
    delete[] y;
}

void Envelope::InverseFastFourierTransform(
    const QList<double>& SignalFrequencyTempReal,
    const QList<double>& SignalFrequencyTempImag)
{
    int N = SignalFrequencyTempReal.size();

    fftw_complex* x = new fftw_complex[N];
    fftw_complex* y = new fftw_complex[N];

    for (int i = 0; i < N; i++) {
        x[i][REAL] = SignalFrequencyTempReal[i];
        x[i][IMAG] = SignalFrequencyTempImag[i];
    }

//    actuator: plan
//    sequence length: N,
//    input sequence: x,
//    output sequence: y,
//    transformation direction: FFTW_BACKWARD(iFFT),
//    transformation mode: FFTW_ESTIMATE
    fftw_plan plan = fftw_plan_dft_1d(N, x, y, FFTW_BACKWARD, FFTW_ESTIMATE);

    fftw_execute(plan);

    for (int i = 0; i < N; i++) {

        SignalEnvelope.append( std::sqrt( std::pow(y[i][REAL]/N ,2.0) + std::pow(y[i][IMAG]/N,2.0)  ) );
    }

    //destroy actuator "plan"
    fftw_destroy_plan(plan);

    delete[] x;
    delete[] y;
}

void Envelope::HilbertTransform(const QList<double>& SignalTimeDomain)
{

    SignalEnvelope.clear();

    FastFourierTransform(SignalTimeDomain);

    int N = SignalTimeDomain.size();
    QList<double> h;

//    Sequence of Hilbert transform coefficients h(f)
    if (N > 0 && 2 * (N / 2) == N) {
        // Even length of signal
        h.append(1.0);
        for (int i = 1; i < N / 2; i++)
        {
            h.append(2.0);
        }
        h.append(1.0);

        for (int i = N / 2 + 1; i < N ;i++)
        {
            h.append(0.0);
        }
    } else if (N > 0) {
        // Odd length of signal
        h.append(1);
        for (int i = 1; i < (N + 1) / 2; i++)
        {
            h.append(2.0);
        }

        for (int i = (N + 1) / 2  ; i < N; i++)
        {

            h.append(0.0);
        }
    }

    QList<double> SignalFrequencyTempReal;
    QList<double> SignalFrequencyTempImag;

    for(int i = 0; i < N; i++)
    {
        SignalFrequencyTempReal.append(h[i] * SignalFrequencyDomainReal[i]);
        SignalFrequencyTempImag.append(h[i] * SignalFrequencyDomainImag[i]);
    }

    InverseFastFourierTransform(SignalFrequencyTempReal,SignalFrequencyTempImag);
}

void Envelope::RemoveMean(QList<double> SignalTimeDomain)
{
//    remove the mean of signal.
    double sum = 0.0;
    for (const double& value : SignalTimeDomain) {
        sum += value;
    }
    double average = sum / SignalTimeDomain.size();

    QMutableListIterator<double> iter(SignalTimeDomain);
    while (iter.hasNext()) {
        double& value = iter.next();
        value -= average;
    }
}
