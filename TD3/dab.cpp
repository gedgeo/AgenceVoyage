#include "dab.h"
#include "ui_dab.h"

dab::dab(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::dab)
{
    ui->setupUi(this);

    int index=0;
    for(int ligne=1;ligne<4;ligne++)
    {
        for(int colonne=1;colonne<6;colonne++)
        {
            places[index].setText(QString::number(index+1));
            ui->gridLayoutPlaces->addWidget(&places[index],ligne,colonne);
            index++;
        }
    }

    connect(&socketClientAgence, &QTcpSocket::connected,this,&dab::onQTcpSocket_connected);
    connect(&socketClientAgence, &QTcpSocket::disconnected,this,&dab::onQTcpSocket_disconnected);
    connect(&socketClientAgence, &QTcpSocket::readyRead,this,&dab::onQTcpSocket_ReadyRead);
    connect(&socketClientAgence, &QTcpSocket::errorOccurred,this,&dab::onQTcpSocket_errorOccured);


}

dab::~dab()
{
    delete ui;
}

void dab::onQComboBox_currentIndexChange(int index)
{

}

void dab::onQTcpSocket_connected()
{
    ui->textEditEtatConnexion->append("Connexion établie.");
}

void dab::onQTcpSocket_disconnected()
{
    ui->textEditEtatConnexion->append("disconnected.");
}

void dab::onQTcpSocket_ReadyRead()
{
    ui->textEditEtatConnexion->append("data received.");
}

void dab::onQTcpSocket_errorOccured(QAbstractSocket::SocketError SocketError)
{
    ui->textEditEtatConnexion->append("error Connexion.");
}

void dab::mettreAjourVols()
{

}

void dab::mettreAJourOccupation()
{

}

void dab::demanderPlacesDisponibles(int ref)
{

}

void dab::reserver(int ref, int place, QString nom, QString prenom, QString email)
{

}



void dab::on_pushButtonConnexion_clicked()
{
    socketClientAgence
}


void dab::on_pushButtonValider_clicked()
{

}

