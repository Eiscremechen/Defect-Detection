#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "calculatefrequency.h"
#include "readdata.h"
#include "envelope.h"
#include "fouriertransform.h"
#include "fouriertransform.h"

#include <QMainWindow>
#include <QList>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void handleCalculationButtonClicked();
    void handleDataSelectionButtonClicked();
    void handleDataShowTimeDomainButtonClicked();
    void handleDataShowEnvelopeButtonClicked();
    void handleDataShowFrequencyDomainButtonClicked();





public:
    Ui::MainWindow *ui;
    CalculateFrequency* calculator;
    ReadData* readdata;
    Envelope* envelope;
    FourierTransform* fouriertransform;


//    int SamplingFrequency;
//    QList<double> *SignalTimeDomain;
//    QList<double> *SignalEnvelope;


};
#endif // MAINWINDOW_H
