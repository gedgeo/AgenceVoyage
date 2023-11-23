#ifndef DAB_H
#define DAB_H

#include <QWidget>
#include <QTcpSocket>
#include <QComboBox>
#include <QRadioButton>

QT_BEGIN_NAMESPACE
namespace Ui { class dab; }
QT_END_NAMESPACE

class dab : public QWidget
{
    Q_OBJECT

public:
    dab(QWidget *parent = nullptr);
    ~dab();

private slots:


    void onQComboBox_currentIndexChange(int index);
    void onQTcpSocket_connected();
    void onQTcpSocket_disconnected();
    void onQTcpSocket_ReadyRead();
    void onQTcpSocket_errorOccured(QAbstractSocket::SocketError SocketError);
    void mettreAjourVols();
    void mettreAJourOccupation();
    void demanderPlacesDisponibles(int ref);
    void reserver(int ref,int place,QString nom, QString prenom,QString email);

    void on_pushButtonConnexion_clicked();

    void on_pushButtonValider_clicked();

private:
    Ui::dab *ui;
    QRadioButton places[15];
    QTcpSocket socketClientAgence;

};
#endif // DAB_H
