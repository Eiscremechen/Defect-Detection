#include "calculatefrequency.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLineEdit>
#include <QTextBrowser>
#include <cmath>
#include <QRegExpValidator>

#include <QDebug>


#define _USE_MATH_DEFINES
#include "math.h"


CalculateFrequency::CalculateFrequency(Ui::MainWindow* Mainwindow_ui, QWidget *parent):
    QWidget(parent),
    m_ui(Mainwindow_ui),
    BallDiameter (0.0),
    PitchDiameter (0.0),
    RollerNumber (0.0),
    BearingSpeed (0.0),
    ContactAngle (0.0),
    BPFIFrequency (0.0),
    BPFOFrequency (0.0),
    BSFFrequency (0.0),
    FTFFrequency (0.0)
{

//   only numbers are allowed to enter in the lineEdit
    m_ui->lineEdit_BallDiamater->setValidator(new QRegExpValidator(QRegExp("[0-9]*\\.?[0-9]+")));
    m_ui->lineEdit_PitchDiameter->setValidator(new QRegExpValidator(QRegExp("[0-9]*\\.?[0-9]+")));
    m_ui->lineEdit_RollerNumber->setValidator(new QRegExpValidator(QRegExp("[0-9]*\\.?[0-9]+")));
    m_ui->lineEdit_BearingSpeed->setValidator(new QRegExpValidator(QRegExp("[0-9]*\\.?[0-9]+")));
    m_ui->lineEdit_ContactAngle->setValidator(new QRegExpValidator(QRegExp("[0-9]*\\.?[0-9]+")));

}


CalculateFrequency::~CalculateFrequency()
{

}


void CalculateFrequency::setBallDiameter()
{
    BallDiameter = m_ui->lineEdit_BallDiamater->text().toDouble();
}
void CalculateFrequency::setPitchDiameter()
{
    PitchDiameter = m_ui->lineEdit_PitchDiameter->text().toDouble();
}

void CalculateFrequency::setRollerNumber()
{
    RollerNumber = m_ui->lineEdit_RollerNumber->text().toDouble();
}
void CalculateFrequency::setBearingSpeed()
{
    BearingSpeed = m_ui->lineEdit_BearingSpeed->text().toDouble();
}
void CalculateFrequency::setContactAngle()
{
    ContactAngle = m_ui->lineEdit_ContactAngle->text().toDouble() * M_PI / 180;
}




float CalculateFrequency::CalculateBPFIFrequency(
    const float& BallDiameter,
    const float& PitchDiameter,
    const float& RollerNumber,
    const float& BearingSpeed,
    const float& ContactAngle)
{
    BPFIFrequency = 0.5 * RollerNumber * BearingSpeed * (1+(BallDiameter/PitchDiameter)* std::cos(ContactAngle));
    return BPFIFrequency;

}

float CalculateFrequency::CalculateBPFOFrequency(
    const float& BallDiameter,
    const float& PitchDiameter,
    const float& RollerNumber,
    const float& BearingSpeed,
    const float& ContactAngle)
{

    BPFOFrequency = 0.5 * RollerNumber * BearingSpeed * (1-(BallDiameter/PitchDiameter)* std::cos(ContactAngle));
    return BPFOFrequency;


}

float CalculateFrequency::CalculateBSFFrequency(
    const float& BallDiameter,
    const float& PitchDiameter,
    const float& BearingSpeed,
    const float& ContactAngle)
{
    BSFFrequency = 0.5 * (PitchDiameter/BallDiameter) * BearingSpeed *
            (1 - std::pow((BallDiameter/PitchDiameter) * std::cos(ContactAngle),2));
    return BSFFrequency;
}

float CalculateFrequency::CalculateFTFFrequency(
    const float& BallDiameter,
    const float& PitchDiameter,
    const float& BearingSpeed,
    const float& ContactAngle)
{
    FTFFrequency = 0.5 * BearingSpeed * (1- (BallDiameter/PitchDiameter) * std::cos(ContactAngle));
    return FTFFrequency;
}

float CalculateFrequency::getBPFIFrequency()
{
    return BPFIFrequency;
}

float CalculateFrequency::getBPFOFrequency()
{
    return BPFOFrequency;
}

float CalculateFrequency::getBSFFrequency()
{
    return BSFFrequency;
}

float CalculateFrequency::getFTFFrequency()
{
    return FTFFrequency;
}

void CalculateFrequency::ShowFrequency()
{

    setBallDiameter();
    setPitchDiameter();
    setRollerNumber();
    setBearingSpeed();
    setContactAngle();

    BPFIFrequency = CalculateBPFIFrequency(
        BallDiameter,
        PitchDiameter,
        RollerNumber,
        BearingSpeed,
        ContactAngle);

    BPFOFrequency = CalculateBPFOFrequency(
        BallDiameter,
        PitchDiameter,
        RollerNumber,
        BearingSpeed,
        ContactAngle);

    BSFFrequency = CalculateBSFFrequency(
        BallDiameter,
        PitchDiameter,
        BearingSpeed,
        ContactAngle);

    FTFFrequency = CalculateFTFFrequency(
        BallDiameter,
        PitchDiameter,
        BearingSpeed,
        ContactAngle);

    m_ui->textBrowser_BPFI->setText(QString::number(BPFIFrequency));
    m_ui->textBrowser_BPFO->setText(QString::number(BPFOFrequency));
    m_ui->textBrowser_BSF->setText(QString::number(BSFFrequency));
    m_ui->textBrowser_FTF->setText(QString::number(FTFFrequency));
}
