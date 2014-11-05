#include "dialog.h"
#include <ctime>
#include <cstdlib>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    height=200;
    width=100;

    black=qRgb(0,0,0);
    white=qRgb(255,255,255);

    share1= new QImage(height,width,QImage::Format_RGB32);
    share2= new QImage(height,width,QImage::Format_RGB32);
    secret= new QImage(height,width,QImage::Format_RGB32);
    reSecret= new QImage(height,width,QImage::Format_RGB32);

    generateSecret();
    generateS1();
    generateS2();
    recoverySecret();
    saveAll();
}

Dialog::~Dialog()
{

}

void Dialog::generateS1()
{
    for(int i=0;i<height;i++)
        for(int j=0;j<width;j++)
        {
            switch(rand()%2)
            {
                case 0:
                    share1->setPixel(i,j,white);
                break;
                case 1:
                    share1->setPixel(i,j,black);
                break;
            }
        }
}

void Dialog::generateSecret()
{

    for(int i=0;i<height;i++)
        for(int j=0;j<width;j++)
            secret->setPixel(i,j,white);

    QPainter painter;
    QFont font;
    font.setPixelSize(50);
    font.setBold(true);
    font.setStyleHint(QFont::TypeWriter);
    painter.begin(secret);
    painter.setFont(font);
    painter.drawText(0,80,"ALB48");
    painter.end();
}

void Dialog::generateS2()
{
    for(int i=0;i<height;i++)
        for(int j=0;j<width;j++)
        {
            if(secret->pixel(i,j)==black && share1->pixel(i,j)==black)
            {
                share2->setPixel(i,j,black);
            }
            else if(secret->pixel(i,j)==white && share1->pixel(i,j)==black)
            {
                share2->setPixel(i,j,white);
            }
            else if(secret->pixel(i,j)==black && share1->pixel(i,j)==white)
            {
                share2->setPixel(i,j,white);
            }
            else
            {
                share2->setPixel(i,j,black);
            }

        }
}

void Dialog::recoverySecret()
{
    for(int i=0;i<height;i++)
        for(int j=0;j<width;j++)
        {
            if(share2->pixel(i,j)==black && share1->pixel(i,j)==black)
            {
                reSecret->setPixel(i,j,black);
            }
            else if(share2->pixel(i,j)==white && share1->pixel(i,j)==black)
            {
                reSecret->setPixel(i,j,white);
            }
            else if(share2->pixel(i,j)==black && share1->pixel(i,j)==white)
            {
                reSecret->setPixel(i,j,white);
            }
            else
            {
                reSecret->setPixel(i,j,black);
            }

        }
}

void Dialog::saveAll()
{
    share1->save("s1.png");
    share2->save("s2.png");
    secret->save("secret.png");
    reSecret->save("recSecret.png");
}
