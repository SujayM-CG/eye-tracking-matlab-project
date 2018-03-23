#ifndef CALIBRATIONDIALOG_H
#define CALIBRATIONDIALOG_H

#include <QDialog>
#include <QColor>
#include <tobii/sdk/cpp/EyeTracker.hpp>

namespace tetio = tobii::sdk::cpp;

namespace Ui {
//This class will be generated by Qt
class CalibrationDialog;
}

//Class for visualization of the calibration procedure.
class CalibrationDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit CalibrationDialog(QWidget *parent = 0);
    ~CalibrationDialog();

    void drawCalibrationPoint(tetio::Point2d point);
    void clearCalibrationPoint();
    tetio::Point2d getCalibrationPoint();
    
private: signals:
    void calibrationDialogLoaded();

private:
    void paintEvent(QPaintEvent *event);
    void showEvent(QShowEvent *event);

private:
    const int m_pixelRadius;
    tetio::Point2d m_calibrationPoint;
    QColor m_pointColor;

    Ui::CalibrationDialog *ui;
};



#endif // CALIBRATIONDIALOG_H