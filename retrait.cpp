#include "retrait.h"
#include "ui_retrait.h"

Retrait::Retrait(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Retrait)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setFixedWidth(750);
    ui->table_liste_point_vente->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->table_liste_point_vente->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->btn_del->setEnabled(false);
    ui->btn_edit->setEnabled(false);

    ui->table_liste_point_vente->horizontalHeader()->setStretchLastSection(true);
    load_liste();

}

Retrait::~Retrait()
{
    delete ui;
}

void Retrait::on_pushButton_clicked()
{
    QString montant=ui->montant->text();
    QString motif=ui->motif->toPlainText();
    if(montant.isEmpty() || motif.isEmpty()){
        QMessageBox::warning(this,"Erreur","Le montant et le motif sont obligatoires");
        return;
    }

    QSqlQuery qr;
    QString id_user="";
    qr.exec("select * from user");
    if(qr.next()){
        id_user=qr.value(0).toString();
    }
    QString token_id=QString::number(QDateTime::currentDateTime().toTime_t());
    qr.prepare("insert into retrait(montant,motif,date,user,token_id) values(:montant,:motif,:date,:user,:token_id)");
    qr.bindValue(":montant",montant);
    qr.bindValue(":motif",motif);
    qr.bindValue(":date",QDate::currentDate());
    qr.bindValue(":user",id_user);
    qr.bindValue(":token_id",token_id);

    if(qr.exec()){
        ui->montant->clear();
        ui->motif->clear();
        load_liste();
        QMessageBox::information(this,"Success","Le retrait est bien enregistré");
    }else{
        QMessageBox::warning(this,"Erreur","Une erreur est survenue");
    }
}

void Retrait::load_liste()
{
    QSqlQuery qr;
    qr.exec("select count(*) from retrait");
    int total=0;
    if(qr.next()){
        total=qr.value(0).toInt();
    }
    ui->table_liste_point_vente->setRowCount(total);

    int row=0;
    qr.exec("select * from retrait");
    while(qr.next()){
        QString montant=qr.value("montant").toString();
        QString motif=qr.value("motif").toString();
        QString date=qr.value("date").toString();
        QString id_user=qr.value("user").toString();

        QString id_pv="";
        QString nom_pv="";

        QSqlQuery qr2;
        qr2.exec("select * from users where id='"+id_user+"'");

        if(qr2.next()){
            id_pv=qr2.value("point_vente").toString();
        }
        qr2.exec("select * from points_vente where id='"+id_pv+"'");
        if(qr2.next()){
            nom_pv=qr2.value("adresse").toString();
        }

        ui->table_liste_point_vente->setItem(row,0,new QTableWidgetItem(date));
        ui->table_liste_point_vente->setItem(row,1,new QTableWidgetItem(montant));
        ui->table_liste_point_vente->setItem(row,2,new QTableWidgetItem(motif));
        ui->table_liste_point_vente->setItem(row,3,new QTableWidgetItem(nom_pv));

        row++;
    }

}
