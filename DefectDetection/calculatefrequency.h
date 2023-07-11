#ifndef CALCULATEFREQUENCY_H
#define CALCULATEFREQUENCY_H

#include "ui_mainwindow.h"
//#include "mainwindow.h"



QT_BEGIN_NAMESPACE
namespace Ui { class CalculateFrequency; }
QT_END_NAMESPACE

class MainWindow;


class CalculateFrequency: public QWidget
{
    Q_OBJECT


public:
    explicit CalculateFrequency(Ui::MainWindow* Mainwindow_ui = nullptr, QWidget *parent = nullptr);
    ~CalculateFrequency();


    void setBallDiameter();
    void setPitchDiameter();
    void setRollerNumber();
    void setBearingSpeed();
    void setContactAngle();

    float getBPFIFrequency();
    float getBPFOFrequency();
    float getBSFFrequency();
    float getFTFFrequency();

    float CalculateBPFIFrequency(
        const float& BallDiameter,
        const float& PitchDiameter,
        const float& RollerNumber,
        const float& BearingSpeed,
        const float& ContactAngle);
    float CalculateBPFOFrequency(
        const float& BallDiameter,
        const float& PitchDiameter,
        const float& RollerNumber,
        const float& BearingSpeed,
        const float& ContactAngle);
    float CalculateBSFFrequency(
        const float& BallDiameter,
        const float& PitchDiameter,
        const float& BearingSpeed,
        const float& ContactAngle);
    float CalculateFTFFrequency(
        const float& BallDiameter,
        const float& PitchDiameter,
        const float& BearingSpeed,
        const float& ContactAngle);

public slots:
    void ShowFrequency();

private:
    Ui::MainWindow* m_ui;

    float BPFIFrequency;
    float BPFOFrequency;
    float BSFFrequency;
    float FTFFrequency;

    float BallDiameter;
    float PitchDiameter;
    float RollerNumber;
    float BearingSpeed;
    float ContactAngle;
};

#endif // CALCULATEFREQUENCY_H
