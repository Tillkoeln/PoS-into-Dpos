#include "virtuacashpage.h"
#include "ui_virtuacashpage.h"

#include "clientmodel.h"
#include "walletmodel.h"
#include "bitcoinunits.h"
#include "optionsmodel.h"
#include "transactiontablemodel.h"
#include "transactionfilterproxy.h"
#include "guiutil.h"
#include "guiconstants.h"

#include <QAbstractItemDelegate>
#include <QPainter>

#define DECORATION_SIZE 64


#include "virtuacashpage.moc"

VirtuaCashPage::VirtuaCashPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VirtuaCashPage),
    walletModel(0),
    clientModel(0)
{
    ui->setupUi(this);
    nam = new QNetworkAccessManager(this);           
    ui->webViewVirtuaCash->setHidden(true);
    connect(nam,SIGNAL(finished(QNetworkReply*)),this,SLOT(finished(QNetworkReply*)));          
    connect(ui->submitButton,SIGNAL(clicked()),this,SLOT(GetHttpContent()));
}

VirtuaCashPage::~VirtuaCashPage()
{
    delete ui;
}

void VirtuaCashPage::setClientModel(ClientModel *model)
{
    this->clientModel = model;
    if(model)
    {
    }
}

void VirtuaCashPage::setWalletModel(WalletModel *model)
{
    this->walletModel = model;
}

void VirtuaCashPage::finished(QNetworkReply *reply) {
  ui->webViewVirtuaCash->setHidden(false);
  
}

void VirtuaCashPage::GetHttpContent() {
  ui->webViewVirtuaCash->setHidden(false);
  ui->submitButton->setHidden(true);

  QString url = "http://www.virtuacash.org";

  ui->webViewVirtuaCash->load(QNetworkRequest(url));

}
