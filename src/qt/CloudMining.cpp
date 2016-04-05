#include "CloudMining.h"
#include "ui_CloudMining.h"

CloudMining::CloudMining(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CloudMining)
{
    ui->setupUi(this);
}

CloudMining::~CloudMining()
{
    delete ui;
}

void CloudMining::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
        case QEvent::LanguageChange:
            ui->retranslateUi(this);
            break;
        default:
            break;
    }
}
