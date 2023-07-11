/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>
#include <qchartview.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QLineEdit *lineEdit_BallDiamater;
    QLineEdit *lineEdit_PitchDiameter;
    QLineEdit *lineEdit_RollerNumber;
    QLineEdit *lineEdit_BearingSpeed;
    QLineEdit *lineEdit_ContactAngle;
    QPushButton *Button_Calculation;
    QLabel *label_BPFO;
    QLabel *label_BPFI;
    QLabel *label_FTF;
    QLabel *label_BSF;
    QLabel *label_BallDiameter;
    QLabel *label_PitchDiameter;
    QLabel *label_RollerNumber;
    QLabel *label_BearingSpeed;
    QLabel *label_ContactAngle;
    QTextBrowser *textBrowser_BPFO;
    QTextBrowser *textBrowser_BPFI;
    QTextBrowser *textBrowser_FTF;
    QTextBrowser *textBrowser_BSF;
    QFrame *frame_2;
    QLabel *label_DataPath;
    QLineEdit *lineEdit_SamplingFrequency;
    QLabel *label_SamplingFrequency;
    QPushButton *Button_Dataselection;
    QTextBrowser *textBrowser_DataPath;
    QtCharts::QChartView *graphicsView_TimeDomain;
    QLabel *label_ShowLimit_x_Orignal;
    QLineEdit *lineEdit_ShowLimit_1_Orignal;
    QLineEdit *lineEdit_ShowLimit_2_Orignal;
    QPushButton *Button_Show_TimeDomain;
    QLineEdit *lineEdit_ShowLimit_3_Orignal;
    QLineEdit *lineEdit_ShowLimit_4_Orignal;
    QLabel *label_ShowLimit_y_Orignal;
    QFrame *frame_3;
    QLineEdit *lineEdit_ShowLimit_4_Envelope;
    QLineEdit *lineEdit_ShowLimit_3_Envelope;
    QLineEdit *lineEdit_ShowLimit_2_Envelope;
    QtCharts::QChartView *graphicsView_Envelope;
    QLineEdit *lineEdit_ShowLimit_1_Envelope;
    QLabel *label_ShowLimit_x_Envelope;
    QPushButton *Button_Show_Envelope;
    QLabel *label_ShowLimit_y_Envelope;
    QFrame *frame_4;
    QPushButton *Button_Show_FrequencyDomain;
    QLineEdit *lineEdit_ShowLimit_3_FrequencyDomain;
    QtCharts::QChartView *graphicsView_FrequencyDomain;
    QLineEdit *lineEdit_ShowLimit_4_FrequencyDomain;
    QLabel *label_ShowLimit_x_FrequencyDomain;
    QLabel *label_ShowLimit_y_FrequencyDomain;
    QLineEdit *lineEdit_ShowLimit_2_FrequencyDomain;
    QLineEdit *lineEdit_ShowLimit_1_FrequencyDomain;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 950);
        MainWindow->setMinimumSize(QSize(800, 950));
        MainWindow->setMaximumSize(QSize(800, 950));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 10, 390, 440));
        frame->setMinimumSize(QSize(390, 440));
        frame->setMaximumSize(QSize(390, 440));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        lineEdit_BallDiamater = new QLineEdit(frame);
        lineEdit_BallDiamater->setObjectName(QString::fromUtf8("lineEdit_BallDiamater"));
        lineEdit_BallDiamater->setGeometry(QRect(190, 10, 60, 30));
        lineEdit_BallDiamater->setMinimumSize(QSize(60, 30));
        lineEdit_BallDiamater->setMaximumSize(QSize(60, 30));
        lineEdit_PitchDiameter = new QLineEdit(frame);
        lineEdit_PitchDiameter->setObjectName(QString::fromUtf8("lineEdit_PitchDiameter"));
        lineEdit_PitchDiameter->setGeometry(QRect(190, 60, 60, 30));
        lineEdit_PitchDiameter->setMinimumSize(QSize(60, 30));
        lineEdit_PitchDiameter->setMaximumSize(QSize(60, 30));
        lineEdit_RollerNumber = new QLineEdit(frame);
        lineEdit_RollerNumber->setObjectName(QString::fromUtf8("lineEdit_RollerNumber"));
        lineEdit_RollerNumber->setGeometry(QRect(190, 110, 60, 30));
        lineEdit_RollerNumber->setMinimumSize(QSize(60, 30));
        lineEdit_RollerNumber->setMaximumSize(QSize(60, 30));
        lineEdit_BearingSpeed = new QLineEdit(frame);
        lineEdit_BearingSpeed->setObjectName(QString::fromUtf8("lineEdit_BearingSpeed"));
        lineEdit_BearingSpeed->setGeometry(QRect(190, 164, 60, 30));
        lineEdit_BearingSpeed->setMinimumSize(QSize(60, 30));
        lineEdit_BearingSpeed->setMaximumSize(QSize(60, 30));
        lineEdit_ContactAngle = new QLineEdit(frame);
        lineEdit_ContactAngle->setObjectName(QString::fromUtf8("lineEdit_ContactAngle"));
        lineEdit_ContactAngle->setGeometry(QRect(190, 220, 60, 30));
        lineEdit_ContactAngle->setMinimumSize(QSize(60, 30));
        lineEdit_ContactAngle->setMaximumSize(QSize(60, 30));
        Button_Calculation = new QPushButton(frame);
        Button_Calculation->setObjectName(QString::fromUtf8("Button_Calculation"));
        Button_Calculation->setGeometry(QRect(10, 260, 100, 30));
        Button_Calculation->setMinimumSize(QSize(100, 30));
        Button_Calculation->setMaximumSize(QSize(100, 30));
        label_BPFO = new QLabel(frame);
        label_BPFO->setObjectName(QString::fromUtf8("label_BPFO"));
        label_BPFO->setGeometry(QRect(10, 300, 100, 30));
        label_BPFO->setMinimumSize(QSize(100, 30));
        label_BPFO->setMaximumSize(QSize(100, 30));
        label_BPFI = new QLabel(frame);
        label_BPFI->setObjectName(QString::fromUtf8("label_BPFI"));
        label_BPFI->setGeometry(QRect(10, 360, 100, 30));
        label_BPFI->setMinimumSize(QSize(100, 30));
        label_BPFI->setMaximumSize(QSize(100, 30));
        label_FTF = new QLabel(frame);
        label_FTF->setObjectName(QString::fromUtf8("label_FTF"));
        label_FTF->setGeometry(QRect(140, 300, 100, 30));
        label_FTF->setMinimumSize(QSize(100, 30));
        label_BSF = new QLabel(frame);
        label_BSF->setObjectName(QString::fromUtf8("label_BSF"));
        label_BSF->setGeometry(QRect(140, 360, 100, 30));
        label_BSF->setMinimumSize(QSize(100, 30));
        label_BSF->setMaximumSize(QSize(100, 30));
        label_BallDiameter = new QLabel(frame);
        label_BallDiameter->setObjectName(QString::fromUtf8("label_BallDiameter"));
        label_BallDiameter->setGeometry(QRect(10, 10, 180, 30));
        label_BallDiameter->setMinimumSize(QSize(180, 30));
        label_BallDiameter->setMaximumSize(QSize(180, 30));
        label_BallDiameter->setAlignment(Qt::AlignCenter);
        label_PitchDiameter = new QLabel(frame);
        label_PitchDiameter->setObjectName(QString::fromUtf8("label_PitchDiameter"));
        label_PitchDiameter->setGeometry(QRect(10, 60, 180, 30));
        label_PitchDiameter->setMinimumSize(QSize(180, 30));
        label_PitchDiameter->setMaximumSize(QSize(180, 30));
        label_PitchDiameter->setAlignment(Qt::AlignCenter);
        label_RollerNumber = new QLabel(frame);
        label_RollerNumber->setObjectName(QString::fromUtf8("label_RollerNumber"));
        label_RollerNumber->setGeometry(QRect(10, 110, 180, 30));
        label_RollerNumber->setMinimumSize(QSize(180, 30));
        label_RollerNumber->setMaximumSize(QSize(180, 30));
        label_RollerNumber->setAlignment(Qt::AlignCenter);
        label_BearingSpeed = new QLabel(frame);
        label_BearingSpeed->setObjectName(QString::fromUtf8("label_BearingSpeed"));
        label_BearingSpeed->setGeometry(QRect(10, 164, 180, 30));
        label_BearingSpeed->setMinimumSize(QSize(180, 30));
        label_BearingSpeed->setMaximumSize(QSize(180, 30));
        label_BearingSpeed->setAlignment(Qt::AlignCenter);
        label_ContactAngle = new QLabel(frame);
        label_ContactAngle->setObjectName(QString::fromUtf8("label_ContactAngle"));
        label_ContactAngle->setGeometry(QRect(10, 220, 180, 30));
        label_ContactAngle->setMinimumSize(QSize(180, 30));
        label_ContactAngle->setMaximumSize(QSize(180, 30));
        label_ContactAngle->setAlignment(Qt::AlignCenter);
        textBrowser_BPFO = new QTextBrowser(frame);
        textBrowser_BPFO->setObjectName(QString::fromUtf8("textBrowser_BPFO"));
        textBrowser_BPFO->setGeometry(QRect(10, 330, 100, 30));
        textBrowser_BPFO->setMinimumSize(QSize(100, 30));
        textBrowser_BPFO->setMaximumSize(QSize(100, 30));
        textBrowser_BPFI = new QTextBrowser(frame);
        textBrowser_BPFI->setObjectName(QString::fromUtf8("textBrowser_BPFI"));
        textBrowser_BPFI->setGeometry(QRect(10, 390, 100, 30));
        textBrowser_BPFI->setMinimumSize(QSize(100, 30));
        textBrowser_BPFI->setMaximumSize(QSize(100, 30));
        textBrowser_FTF = new QTextBrowser(frame);
        textBrowser_FTF->setObjectName(QString::fromUtf8("textBrowser_FTF"));
        textBrowser_FTF->setGeometry(QRect(140, 330, 100, 30));
        textBrowser_FTF->setMinimumSize(QSize(100, 30));
        textBrowser_FTF->setMaximumSize(QSize(100, 30));
        textBrowser_BSF = new QTextBrowser(frame);
        textBrowser_BSF->setObjectName(QString::fromUtf8("textBrowser_BSF"));
        textBrowser_BSF->setGeometry(QRect(140, 390, 100, 30));
        textBrowser_BSF->setMinimumSize(QSize(100, 30));
        textBrowser_BSF->setMaximumSize(QSize(100, 30));
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(10, 450, 390, 490));
        frame_2->setMinimumSize(QSize(390, 490));
        frame_2->setMaximumSize(QSize(390, 490));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_DataPath = new QLabel(frame_2);
        label_DataPath->setObjectName(QString::fromUtf8("label_DataPath"));
        label_DataPath->setGeometry(QRect(160, 10, 150, 30));
        label_DataPath->setAlignment(Qt::AlignCenter);
        lineEdit_SamplingFrequency = new QLineEdit(frame_2);
        lineEdit_SamplingFrequency->setObjectName(QString::fromUtf8("lineEdit_SamplingFrequency"));
        lineEdit_SamplingFrequency->setGeometry(QRect(210, 90, 100, 30));
        lineEdit_SamplingFrequency->setToolTipDuration(-1);
        label_SamplingFrequency = new QLabel(frame_2);
        label_SamplingFrequency->setObjectName(QString::fromUtf8("label_SamplingFrequency"));
        label_SamplingFrequency->setGeometry(QRect(10, 90, 200, 30));
        label_SamplingFrequency->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        Button_Dataselection = new QPushButton(frame_2);
        Button_Dataselection->setObjectName(QString::fromUtf8("Button_Dataselection"));
        Button_Dataselection->setGeometry(QRect(10, 10, 150, 30));
        Button_Dataselection->setMinimumSize(QSize(150, 30));
        Button_Dataselection->setMaximumSize(QSize(150, 30));
        textBrowser_DataPath = new QTextBrowser(frame_2);
        textBrowser_DataPath->setObjectName(QString::fromUtf8("textBrowser_DataPath"));
        textBrowser_DataPath->setGeometry(QRect(10, 50, 300, 30));
        graphicsView_TimeDomain = new QtCharts::QChartView(frame_2);
        graphicsView_TimeDomain->setObjectName(QString::fromUtf8("graphicsView_TimeDomain"));
        graphicsView_TimeDomain->setGeometry(QRect(10, 210, 370, 270));
        graphicsView_TimeDomain->setMinimumSize(QSize(370, 270));
        graphicsView_TimeDomain->setMaximumSize(QSize(370, 270));
        label_ShowLimit_x_Orignal = new QLabel(frame_2);
        label_ShowLimit_x_Orignal->setObjectName(QString::fromUtf8("label_ShowLimit_x_Orignal"));
        label_ShowLimit_x_Orignal->setGeometry(QRect(10, 130, 120, 30));
        label_ShowLimit_x_Orignal->setMinimumSize(QSize(120, 30));
        label_ShowLimit_x_Orignal->setMaximumSize(QSize(120, 30));
        lineEdit_ShowLimit_1_Orignal = new QLineEdit(frame_2);
        lineEdit_ShowLimit_1_Orignal->setObjectName(QString::fromUtf8("lineEdit_ShowLimit_1_Orignal"));
        lineEdit_ShowLimit_1_Orignal->setGeometry(QRect(140, 130, 40, 30));
        lineEdit_ShowLimit_1_Orignal->setMinimumSize(QSize(40, 30));
        lineEdit_ShowLimit_1_Orignal->setMaximumSize(QSize(40, 30));
        lineEdit_ShowLimit_2_Orignal = new QLineEdit(frame_2);
        lineEdit_ShowLimit_2_Orignal->setObjectName(QString::fromUtf8("lineEdit_ShowLimit_2_Orignal"));
        lineEdit_ShowLimit_2_Orignal->setGeometry(QRect(190, 130, 40, 30));
        lineEdit_ShowLimit_2_Orignal->setMinimumSize(QSize(40, 30));
        lineEdit_ShowLimit_2_Orignal->setMaximumSize(QSize(40, 30));
        Button_Show_TimeDomain = new QPushButton(frame_2);
        Button_Show_TimeDomain->setObjectName(QString::fromUtf8("Button_Show_TimeDomain"));
        Button_Show_TimeDomain->setGeometry(QRect(240, 130, 70, 70));
        lineEdit_ShowLimit_3_Orignal = new QLineEdit(frame_2);
        lineEdit_ShowLimit_3_Orignal->setObjectName(QString::fromUtf8("lineEdit_ShowLimit_3_Orignal"));
        lineEdit_ShowLimit_3_Orignal->setGeometry(QRect(140, 170, 40, 30));
        lineEdit_ShowLimit_3_Orignal->setMinimumSize(QSize(40, 30));
        lineEdit_ShowLimit_3_Orignal->setMaximumSize(QSize(40, 30));
        lineEdit_ShowLimit_4_Orignal = new QLineEdit(frame_2);
        lineEdit_ShowLimit_4_Orignal->setObjectName(QString::fromUtf8("lineEdit_ShowLimit_4_Orignal"));
        lineEdit_ShowLimit_4_Orignal->setGeometry(QRect(190, 170, 40, 30));
        lineEdit_ShowLimit_4_Orignal->setMinimumSize(QSize(40, 30));
        lineEdit_ShowLimit_4_Orignal->setMaximumSize(QSize(40, 30));
        label_ShowLimit_y_Orignal = new QLabel(frame_2);
        label_ShowLimit_y_Orignal->setObjectName(QString::fromUtf8("label_ShowLimit_y_Orignal"));
        label_ShowLimit_y_Orignal->setGeometry(QRect(10, 170, 120, 30));
        label_ShowLimit_y_Orignal->setMinimumSize(QSize(120, 30));
        label_ShowLimit_y_Orignal->setMaximumSize(QSize(120, 30));
        frame_3 = new QFrame(centralwidget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(400, 10, 390, 440));
        frame_3->setMinimumSize(QSize(390, 440));
        frame_3->setMaximumSize(QSize(390, 440));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        lineEdit_ShowLimit_4_Envelope = new QLineEdit(frame_3);
        lineEdit_ShowLimit_4_Envelope->setObjectName(QString::fromUtf8("lineEdit_ShowLimit_4_Envelope"));
        lineEdit_ShowLimit_4_Envelope->setGeometry(QRect(190, 70, 40, 30));
        lineEdit_ShowLimit_4_Envelope->setMinimumSize(QSize(40, 30));
        lineEdit_ShowLimit_4_Envelope->setMaximumSize(QSize(40, 30));
        lineEdit_ShowLimit_3_Envelope = new QLineEdit(frame_3);
        lineEdit_ShowLimit_3_Envelope->setObjectName(QString::fromUtf8("lineEdit_ShowLimit_3_Envelope"));
        lineEdit_ShowLimit_3_Envelope->setGeometry(QRect(140, 70, 40, 30));
        lineEdit_ShowLimit_3_Envelope->setMinimumSize(QSize(40, 30));
        lineEdit_ShowLimit_3_Envelope->setMaximumSize(QSize(40, 30));
        lineEdit_ShowLimit_2_Envelope = new QLineEdit(frame_3);
        lineEdit_ShowLimit_2_Envelope->setObjectName(QString::fromUtf8("lineEdit_ShowLimit_2_Envelope"));
        lineEdit_ShowLimit_2_Envelope->setGeometry(QRect(190, 20, 40, 30));
        lineEdit_ShowLimit_2_Envelope->setMinimumSize(QSize(40, 30));
        lineEdit_ShowLimit_2_Envelope->setMaximumSize(QSize(40, 30));
        graphicsView_Envelope = new QtCharts::QChartView(frame_3);
        graphicsView_Envelope->setObjectName(QString::fromUtf8("graphicsView_Envelope"));
        graphicsView_Envelope->setGeometry(QRect(10, 130, 370, 270));
        graphicsView_Envelope->setMinimumSize(QSize(370, 270));
        graphicsView_Envelope->setMaximumSize(QSize(370, 270));
        lineEdit_ShowLimit_1_Envelope = new QLineEdit(frame_3);
        lineEdit_ShowLimit_1_Envelope->setObjectName(QString::fromUtf8("lineEdit_ShowLimit_1_Envelope"));
        lineEdit_ShowLimit_1_Envelope->setGeometry(QRect(140, 20, 40, 30));
        lineEdit_ShowLimit_1_Envelope->setMinimumSize(QSize(40, 30));
        lineEdit_ShowLimit_1_Envelope->setMaximumSize(QSize(40, 30));
        label_ShowLimit_x_Envelope = new QLabel(frame_3);
        label_ShowLimit_x_Envelope->setObjectName(QString::fromUtf8("label_ShowLimit_x_Envelope"));
        label_ShowLimit_x_Envelope->setGeometry(QRect(10, 20, 120, 30));
        label_ShowLimit_x_Envelope->setMinimumSize(QSize(120, 30));
        label_ShowLimit_x_Envelope->setMaximumSize(QSize(120, 30));
        Button_Show_Envelope = new QPushButton(frame_3);
        Button_Show_Envelope->setObjectName(QString::fromUtf8("Button_Show_Envelope"));
        Button_Show_Envelope->setGeometry(QRect(250, 20, 120, 80));
        Button_Show_Envelope->setMinimumSize(QSize(120, 80));
        Button_Show_Envelope->setMaximumSize(QSize(120, 80));
        label_ShowLimit_y_Envelope = new QLabel(frame_3);
        label_ShowLimit_y_Envelope->setObjectName(QString::fromUtf8("label_ShowLimit_y_Envelope"));
        label_ShowLimit_y_Envelope->setGeometry(QRect(10, 70, 120, 30));
        label_ShowLimit_y_Envelope->setMinimumSize(QSize(120, 30));
        label_ShowLimit_y_Envelope->setMaximumSize(QSize(120, 30));
        frame_4 = new QFrame(centralwidget);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(400, 450, 390, 490));
        frame_4->setMinimumSize(QSize(390, 490));
        frame_4->setMaximumSize(QSize(390, 490));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        Button_Show_FrequencyDomain = new QPushButton(frame_4);
        Button_Show_FrequencyDomain->setObjectName(QString::fromUtf8("Button_Show_FrequencyDomain"));
        Button_Show_FrequencyDomain->setGeometry(QRect(250, 120, 120, 80));
        Button_Show_FrequencyDomain->setMinimumSize(QSize(120, 80));
        Button_Show_FrequencyDomain->setMaximumSize(QSize(120, 80));
        lineEdit_ShowLimit_3_FrequencyDomain = new QLineEdit(frame_4);
        lineEdit_ShowLimit_3_FrequencyDomain->setObjectName(QString::fromUtf8("lineEdit_ShowLimit_3_FrequencyDomain"));
        lineEdit_ShowLimit_3_FrequencyDomain->setGeometry(QRect(140, 170, 40, 30));
        lineEdit_ShowLimit_3_FrequencyDomain->setMinimumSize(QSize(40, 30));
        lineEdit_ShowLimit_3_FrequencyDomain->setMaximumSize(QSize(40, 30));
        graphicsView_FrequencyDomain = new QtCharts::QChartView(frame_4);
        graphicsView_FrequencyDomain->setObjectName(QString::fromUtf8("graphicsView_FrequencyDomain"));
        graphicsView_FrequencyDomain->setGeometry(QRect(10, 210, 370, 270));
        graphicsView_FrequencyDomain->setMinimumSize(QSize(370, 270));
        graphicsView_FrequencyDomain->setMaximumSize(QSize(370, 270));
        lineEdit_ShowLimit_4_FrequencyDomain = new QLineEdit(frame_4);
        lineEdit_ShowLimit_4_FrequencyDomain->setObjectName(QString::fromUtf8("lineEdit_ShowLimit_4_FrequencyDomain"));
        lineEdit_ShowLimit_4_FrequencyDomain->setGeometry(QRect(190, 170, 40, 30));
        lineEdit_ShowLimit_4_FrequencyDomain->setMinimumSize(QSize(40, 30));
        lineEdit_ShowLimit_4_FrequencyDomain->setMaximumSize(QSize(40, 30));
        label_ShowLimit_x_FrequencyDomain = new QLabel(frame_4);
        label_ShowLimit_x_FrequencyDomain->setObjectName(QString::fromUtf8("label_ShowLimit_x_FrequencyDomain"));
        label_ShowLimit_x_FrequencyDomain->setGeometry(QRect(10, 130, 120, 30));
        label_ShowLimit_x_FrequencyDomain->setMinimumSize(QSize(120, 30));
        label_ShowLimit_x_FrequencyDomain->setMaximumSize(QSize(120, 30));
        label_ShowLimit_y_FrequencyDomain = new QLabel(frame_4);
        label_ShowLimit_y_FrequencyDomain->setObjectName(QString::fromUtf8("label_ShowLimit_y_FrequencyDomain"));
        label_ShowLimit_y_FrequencyDomain->setGeometry(QRect(10, 170, 120, 30));
        label_ShowLimit_y_FrequencyDomain->setMinimumSize(QSize(120, 30));
        label_ShowLimit_y_FrequencyDomain->setMaximumSize(QSize(120, 30));
        lineEdit_ShowLimit_2_FrequencyDomain = new QLineEdit(frame_4);
        lineEdit_ShowLimit_2_FrequencyDomain->setObjectName(QString::fromUtf8("lineEdit_ShowLimit_2_FrequencyDomain"));
        lineEdit_ShowLimit_2_FrequencyDomain->setGeometry(QRect(190, 130, 40, 30));
        lineEdit_ShowLimit_2_FrequencyDomain->setMinimumSize(QSize(40, 30));
        lineEdit_ShowLimit_2_FrequencyDomain->setMaximumSize(QSize(40, 30));
        lineEdit_ShowLimit_1_FrequencyDomain = new QLineEdit(frame_4);
        lineEdit_ShowLimit_1_FrequencyDomain->setObjectName(QString::fromUtf8("lineEdit_ShowLimit_1_FrequencyDomain"));
        lineEdit_ShowLimit_1_FrequencyDomain->setGeometry(QRect(140, 130, 40, 30));
        lineEdit_ShowLimit_1_FrequencyDomain->setMinimumSize(QSize(40, 30));
        lineEdit_ShowLimit_1_FrequencyDomain->setMaximumSize(QSize(40, 30));
        MainWindow->setCentralWidget(centralwidget);
        QWidget::setTabOrder(lineEdit_BallDiamater, lineEdit_PitchDiameter);
        QWidget::setTabOrder(lineEdit_PitchDiameter, lineEdit_RollerNumber);
        QWidget::setTabOrder(lineEdit_RollerNumber, lineEdit_BearingSpeed);
        QWidget::setTabOrder(lineEdit_BearingSpeed, lineEdit_ContactAngle);
        QWidget::setTabOrder(lineEdit_ContactAngle, Button_Calculation);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        lineEdit_BallDiamater->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lineEdit_PitchDiameter->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lineEdit_RollerNumber->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lineEdit_BearingSpeed->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lineEdit_ContactAngle->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        Button_Calculation->setText(QCoreApplication::translate("MainWindow", "Calculation", nullptr));
        label_BPFO->setText(QCoreApplication::translate("MainWindow", "BPFO (Hz)", nullptr));
        label_BPFI->setText(QCoreApplication::translate("MainWindow", "BPFI (Hz)", nullptr));
        label_FTF->setText(QCoreApplication::translate("MainWindow", "FTF (Hz)", nullptr));
        label_BSF->setText(QCoreApplication::translate("MainWindow", "BSF(Hz)", nullptr));
        label_BallDiameter->setText(QCoreApplication::translate("MainWindow", "Ball Diameter (mm)", nullptr));
        label_PitchDiameter->setText(QCoreApplication::translate("MainWindow", "Pitch Diameter (mm)", nullptr));
        label_RollerNumber->setText(QCoreApplication::translate("MainWindow", "Roller Number", nullptr));
        label_BearingSpeed->setText(QCoreApplication::translate("MainWindow", "Bearing Speed (rev/s)", nullptr));
        label_ContactAngle->setText(QCoreApplication::translate("MainWindow", "Contact Angle (deg)", nullptr));
        label_DataPath->setText(QCoreApplication::translate("MainWindow", "Data Path", nullptr));
        lineEdit_SamplingFrequency->setText(QString());
        label_SamplingFrequency->setText(QCoreApplication::translate("MainWindow", "Sampling Frequency (Hz)", nullptr));
        Button_Dataselection->setText(QCoreApplication::translate("MainWindow", "Data selection", nullptr));
        label_ShowLimit_x_Orignal->setText(QCoreApplication::translate("MainWindow", "x-Limit (s)", nullptr));
        lineEdit_ShowLimit_1_Orignal->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lineEdit_ShowLimit_2_Orignal->setText(QCoreApplication::translate("MainWindow", "10", nullptr));
        Button_Show_TimeDomain->setText(QCoreApplication::translate("MainWindow", "Show", nullptr));
        lineEdit_ShowLimit_3_Orignal->setText(QCoreApplication::translate("MainWindow", "-5", nullptr));
        lineEdit_ShowLimit_4_Orignal->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        label_ShowLimit_y_Orignal->setText(QCoreApplication::translate("MainWindow", "y-Limit (s)", nullptr));
        lineEdit_ShowLimit_4_Envelope->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        lineEdit_ShowLimit_3_Envelope->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lineEdit_ShowLimit_2_Envelope->setText(QCoreApplication::translate("MainWindow", "10", nullptr));
        lineEdit_ShowLimit_1_Envelope->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_ShowLimit_x_Envelope->setText(QCoreApplication::translate("MainWindow", "x-Limit (s)", nullptr));
        Button_Show_Envelope->setText(QCoreApplication::translate("MainWindow", "Show Envelope", nullptr));
        label_ShowLimit_y_Envelope->setText(QCoreApplication::translate("MainWindow", "y-Limit (s)", nullptr));
        Button_Show_FrequencyDomain->setText(QCoreApplication::translate("MainWindow", "Show \n"
"Frequency \n"
"Domain", nullptr));
        lineEdit_ShowLimit_3_FrequencyDomain->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lineEdit_ShowLimit_4_FrequencyDomain->setText(QCoreApplication::translate("MainWindow", "0.5", nullptr));
        label_ShowLimit_x_FrequencyDomain->setText(QCoreApplication::translate("MainWindow", "x-Limit (s)", nullptr));
        label_ShowLimit_y_FrequencyDomain->setText(QCoreApplication::translate("MainWindow", "y-Limit (s)", nullptr));
        lineEdit_ShowLimit_2_FrequencyDomain->setText(QCoreApplication::translate("MainWindow", "500", nullptr));
        lineEdit_ShowLimit_1_FrequencyDomain->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
