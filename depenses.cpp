#include "depenses.h"
#include "ui_depenses.h"

Depenses::Depenses(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Depenses)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setFixedWidth(750);

    ui->table_liste_point_vente->horizontalHeader()->setStretchLastSection(true);

    load_liste();
}

Depenses::~Depenses()
{
    delete ui;
}

void Depenses::on_pushButton_clicked()
{
    QString titre=ui->titre->text();
    QString montant=ui->montant->text();
    QString detail=ui->detail->toPlainText();
    if(titre.isEmpty() || montant.isEmpty()){
        QMessageBox::warning(this,"Erreur","Vous devez fournir le titre et le montant");
        return;
    }
    QSqlQuery qr;
    qr.exec("select * from user");
    QString id_user="";
    if(qr.next()){
        id_user=qr.value(0).toString();
    }
    qr.prepare("insert into depenses(titre,montant,detail,date,user) values(:titre,:montant,:detail,:date,:user)");
    qr.bindValue(":titre",titre);
    qr.bindValue(":montant",montant);
    qr.bindValue(":detail",detail);
    qr.bindValue(":date",QDate::currentDate());
    qr.bindValue(":user",id_user);
    if(qr.exec()){
        QMessageBox::information(this,"Success","Dépense bien enregistrée");
        ui->titre->clear();
        ui->montant->clear();
        ui->detail->clear();
        load_liste();
    }else{
        QMessageBox::warning(this,"Erreur","Une erreur est survenue");
    }
}

void Depenses::load_liste()
{
    QSqlQuery qr;
    qr.exec("select count(*) from depenses");
    int total=0;
    if(qr.next()){
        total=qr.value(0).toInt();
    }
    ui->table_liste_point_vente->setRowCount(total);

    int row=0;
    qr.exec("select * from depenses");
    while(qr.next()){
      QString titre=qr.value("titre").toString();
      QString montant=qr.value("montant").toString();
      QString detail=qr.value("detail").toString();
      QString date=qr.value("date").toString();

      ui->table_liste_point_vente->setItem(row,0,new QTableWidgetItem(date));
      ui->table_liste_point_vente->setItem(row,1,new QTableWidgetItem(titre));
      ui->table_liste_point_vente->setItem(row,2,new QTableWidgetItem(montant));
      ui->table_liste_point_vente->setItem(row,3,new QTableWidgetItem(detail));

      ui->table_liste_point_vente->item(row,1)->setToolTip(titre);
      ui->table_liste_point_vente->item(row,3)->setToolTip(detail);

      row++;

    }
}
