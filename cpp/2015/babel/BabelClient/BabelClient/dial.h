#ifndef DIAL_H
#define DIAL_H

#include <QWidget>

namespace Ui {
class Dial;
}

class Dial : public QWidget
{
    Q_OBJECT
    
public:
    explicit Dial(QWidget *parent = 0);
    ~Dial();

    void clearScreen(void);
    void printScreen(void);
    void setLogin(QString);
    void connection(void);
    
private slots:
    void hangOut(void);

private:
    Ui::Dial *ui;
};

#endif // DIAL_H
