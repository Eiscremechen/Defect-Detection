#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "calculatefrequency.h"
#include "readdata.h"
#include "envelope.h"
#include <QDebug>

#include <QList>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    calculator = new CalculateFrequency (ui,this);
    readdata = new ReadData (ui,this);
    envelope = new Envelope (ui,this);
    fouriertransform = new FourierTransform (ui,this);

    connect(ui->Button_Calculation, &QPushButton::clicked, this, &MainWindow::handleCalculationButtonClicked);
    connect(ui->Button_Dataselection, &QPushButton::clicked, this, &MainWindow::handleDataSelectionButtonClicked);
    connect(ui->Button_Show_TimeDomain, &QPushButton::clicked, this, &MainWindow::handleDataShowTimeDomainButtonClicked);
    connect(ui->Button_Show_Envelope, &QPushButton::clicked, this, &MainWindow::handleDataShowEnvelopeButtonClicked);
    connect(ui->Button_Show_FrequencyDomain, &QPushButton::clicked, this, &MainWindow::handleDataShowFrequencyDomainButtonClicked);
}

MainWindow::~MainWindow()
{
    if(ui!= nullptr)
    {
        delete ui;
        ui = nullptr;
    }

    if(calculator!= nullptr)
    {
        delete calculator;
        calculator = nullptr;
    }

    if (readdata!=nullptr)
    {
        delete readdata;
        readdata = nullptr;
    }
    if (envelope!=nullptr)
    {
        delete envelope;
        envelope = nullptr;
    }


    if (fouriertransform!=nullptr)
    {
        delete fouriertransform;
        fouriertransform = nullptr;
    }



}
void MainWindow::handleCalculationButtonClicked()
{
    calculator->ShowFrequency();
}

void MainWindow::handleDataSelectionButtonClicked()
{
    readdata->FileSelection();
}

void MainWindow::handleDataShowTimeDomainButtonClicked()
{
    readdata->Show();
}

void MainWindow::handleDataShowEnvelopeButtonClicked()
{
//    Data transfer from signal to class Envelope, to get the envelope of signal (the demodulated signal).
    QList<double> Signal = readdata->getData();
    envelope->setSignal(Signal);

    int SamplingFrequency = readdata->getSamplingFrequency();
    envelope->setSamplingFrequency(SamplingFrequency);

    envelope->Show();

}

void MainWindow::handleDataShowFrequencyDomainButtonClicked()
{
//    Data transfer from the envelope of signal to class FourierTransform, to get the domodulated signal in frequency domain.
    QList<double> SignalEnvelope = envelope->getEnvelope();
    fouriertransform->setEnvelope(SignalEnvelope);

    int SamplingFrequency = readdata->getSamplingFrequency();

    fouriertransform->setSamplingFrequency(SamplingFrequency);

    fouriertransform->Show();
}



