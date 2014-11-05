#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QImage>
#include <QPainter>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();

    void generateS1();
    void generateSecret();
    void generateS2();
    void recoverySecret();
    void saveAll();

private:
    QRgb black;
    QRgb white;
    int height;
    int width;
    QImage* share1;
    QImage* share2;
    QImage* secret;
    QImage* reSecret;

};

#endif // DIALOG_H
