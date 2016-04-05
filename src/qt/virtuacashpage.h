#ifndef VIRTUACASHPAGE_H
#define VIRTUACASHPAGE_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QByteArray>
#include <QTimer>

namespace Ui {
    class VirtuaCashPage;
}
class ClientModel;
class WalletModel;

QT_BEGIN_NAMESPACE
class QModelIndex;
QT_END_NAMESPACE

/** VirtuaCash page widget */
class VirtuaCashPage : public QWidget
{
    Q_OBJECT

public:
    explicit VirtuaCashPage(QWidget *parent = 0);
    ~VirtuaCashPage();

    void setClientModel(ClientModel *clientModel);
    void setWalletModel(WalletModel *walletModel);

public slots:

signals:

private:
    Ui::VirtuaCashPage *ui;
    ClientModel *clientModel;
    WalletModel *walletModel;

    QNetworkAccessManager *nam;

private slots:
    void finished(QNetworkReply *reply);
    void GetHttpContent();
};

#endif // VIRTUACASHPAGE_H
