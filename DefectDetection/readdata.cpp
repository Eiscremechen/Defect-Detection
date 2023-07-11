#include "readdata.h"

//#include "mainwindow.h"
//#include "ui_mainwindow.h"

#include <QString>
#include <QFileDialog>
#include <QLineEdit>
#include <QDebug>
#include <QFile>
#include <QIODevice>

#include <QRegExpValidator>
#include <QTextStream>




ReadData::ReadData(Ui::MainWindow* Mainwindow_ui, QWidget *parent):
    QWidget(parent),
    m_ui(Mainwindow_ui),
    FilePath(QString("0")),
    SamplingFrequency(0),
    Series(nullptr),
    Chart(nullptr),
    xAxis(nullptr),
    yAxis(nullptr)
{
    m_ui->lineEdit_ShowLimit_1_Orignal->setValidator(new QRegExpValidator(QRegExp("[-+]?[0-9]*\\.?[0-9]+")));
    m_ui->lineEdit_ShowLimit_2_Orignal->setValidator(new QRegExpValidator(QRegExp("[-+]?[0-9]*\\.?[0-9]+")));
    m_ui->lineEdit_ShowLimit_3_Orignal->setValidator(new QRegExpValidator(QRegExp("[-+]?[0-9]*\\.?[0-9]+")));
    m_ui->lineEdit_ShowLimit_4_Orignal->setValidator(new QRegExpValidator(QRegExp("[-+]?[0-9]*\\.?[0-9]+")));
    m_ui->lineEdit_SamplingFrequency->setValidator(new QRegExpValidator(QRegExp("^[1-9]+[0-9]*$")));

//    Series = new QLineSeries();
//    Chart = new QChart();
//    xAxis = new QValueAxis();
//    yAxis = new QValueAxis();

//    Series = nullptr;
//    Chart = nullptr;
//    xAxis = nullptr;
//    yAxis = nullptr;

}

ReadData::~ReadData()
{
    if(Series != nullptr)
    {
        delete Series;
        Series = nullptr;
    }
    if(xAxis !=nullptr)
    {
        delete xAxis;
        xAxis = nullptr;
    }

    if(yAxis !=nullptr)
    {
        delete yAxis;
        yAxis = nullptr;
    }

//When deleting the Chart, the Series, xAxis and yAxis must be deleted first, otherwise an error will be reported.
    if(Chart !=nullptr)
    {
        delete Chart;
        Chart=nullptr;
    }
}



QString ReadData::getFileName(const QString &FileName)
{
    return FileName;
}


void ReadData::setSamplingFrequency()
{
    this->SamplingFrequency = m_ui->lineEdit_SamplingFrequency->text().toInt();
}


int ReadData::getSamplingFrequency()
{
    return SamplingFrequency;
}

void ReadData::showFileName(const QString& FileName)
{
    m_ui->textBrowser_DataPath->setText(FileName);
}

void ReadData::setData(const QString& filePath)
{
    SignalTimeDomain.clear();

    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        while (!in.atEnd())
        {
            QString line = in.readLine().trimmed();
            bool ok;
            float value = line.toFloat(&ok);
            if (ok)
            {
                SignalTimeDomain.append(value);
            }
            else
            {
                qDebug() << "Invalid float value:" << line;
            }
        }

        file.close();
    }
    else
    {
        qDebug() << "Failed to open file:" << file.errorString();
    }

}

QList<double> ReadData::getData()
{
    return SignalTimeDomain;
}

void ReadData::ShowTimeDomain(
    QList<double> SignalTimeDomain,
    const int& SamplingFrequency,
    const float& minShowLimit_x,
    const float& maxShowLimit_x,
    const float& minShowLimit_y,
    const float& maxShowLimit_y)
{

//    Series->clear();

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



    for (int i = 0; i< SignalTimeDomain.size(); i++)
    {
        Series->append((float)i/SamplingFrequency,SignalTimeDomain[i]);
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


    Chart->addAxis(yAxis, Qt::AlignLeft);
    Chart->addAxis(xAxis, Qt::AlignBottom);

    Chart->removeAllSeries();
    Chart->addSeries(Series);

    Series->attachAxis(xAxis);
    Series->attachAxis(yAxis);

    Chart->setTitle("Signal in time Domain");
    Chart->legend()->hide();

    m_ui->graphicsView_TimeDomain->setChart(Chart);

}

void ReadData::setShowLimit()
{
    minShowLimit_x_Orignal = m_ui->lineEdit_ShowLimit_1_Orignal->text().toFloat();
    maxShowLimit_x_Orignal = m_ui->lineEdit_ShowLimit_2_Orignal->text().toFloat();

    minShowLimit_y_Orignal = m_ui->lineEdit_ShowLimit_3_Orignal->text().toFloat();
    maxShowLimit_y_Orignal = m_ui->lineEdit_ShowLimit_4_Orignal->text().toFloat();
}

void ReadData::FileSelection()
{
//    Only files in .txt format can be read.
    FilePath =  QFileDialog::getOpenFileName(
        this,
        "Data selection",
        "/home",
        tr("Data (*.txt)"));

    showFileName(FilePath);
}

void ReadData::Show()
{

//    FilePath = QString("D:/OneDrive/Project/Defect Detection/Test Data/Data from CWRU/IR/Test.txt");
//    FilePath = QString("D:/OneDrive/Project/Defect Detection/Test Data/Data from CWRU/IR/DE_105_IR_1778_1797_12k.txt");

    setData(FilePath);

    setShowLimit();
    setSamplingFrequency();


//    qDebug()<<"SamplingFrequency:"<<this->SamplingFrequency;

    ShowTimeDomain(
        SignalTimeDomain,
        SamplingFrequency,
        minShowLimit_x_Orignal,
        maxShowLimit_x_Orignal,
        minShowLimit_y_Orignal,
        maxShowLimit_y_Orignal);

}




