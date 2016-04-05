#ifndef CLOUDMINING_H
#define CLOUDMINING_H

#include <QWidget>

namespace Ui {
    class CloudMining;
}

class CloudMining : public QWidget
{
        Q_OBJECT

    public:
        explicit CloudMining(QWidget *parent = 0);
        ~CloudMining();

    protected:
        void changeEvent(QEvent *e);

    private:
        Ui::CloudMining *ui;
};

#endif // CLOUDMINING_H
