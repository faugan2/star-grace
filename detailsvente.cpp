#include "detailsvente.h"
#include "ui_detailsvente.h"

DetailsVente::DetailsVente(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DetailsVente)
{
    ui->setupUi(this);
     setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

     QSqlQuery qr;
     qr.exec("select * from token");
     QString token="";
     if(qr.next()){
         token=qr.value(0).toString();
         qDebug()<<token;
     }
     this->token_facture=token;

     qr.exec("select count(*) from mouvements where token='"+token+"'");
     int total=0;
     if(qr.next()){
         total=qr.value(0).toInt();
     }
     ui->table_vente->setRowCount(total);

     qr.exec("select * from mouvements where token='"+token+"'");
     int row=0;
     float valeur_total=0;
     while(qr.next()){
         QString id_produit=qr.value("produit").toString();
         QString qte=qr.value("total_m2").toString().replace('-',"");
         QString pu=qr.value("prix").toString();
         QString unite=qr.value("unite").toString();
         if(unite!="m2" && unite!=""){
             unite+="(s)";
         }


         QSqlQuery qr2;
         qr2.exec("select * from stock where token_id='"+id_produit+"'");
         QString nom_produit="";
         float prix=0;
         if(qr2.next()){
             nom_produit=qr2.value("nom").toString();
             if(pu.isEmpty()){
                 pu=qr2.value("prix_par_m2").toString();
             }
             //prix=qr2.value("prix_par_m2").toFloat();
         }
         prix=pu.toFloat();
         float qte_int=qte.toFloat();

         float total=qte_int*prix;

         ui->table_vente->setItem(row,0,new QTableWidgetItem(nom_produit));
         ui->table_vente->setItem(row,1,new QTableWidgetItem(qte+" "+unite));
         ui->table_vente->setItem(row,2,new QTableWidgetItem(QString::number(prix)));
         ui->table_vente->setItem(row,3,new QTableWidgetItem(QString::number(total)));

         ui->table_vente->item(row,0)->setTextAlignment(Qt::AlignCenter);
         ui->table_vente->item(row,1)->setTextAlignment(Qt::AlignCenter);
         ui->table_vente->item(row,2)->setTextAlignment(Qt::AlignCenter);
         ui->table_vente->item(row,3)->setTextAlignment(Qt::AlignCenter);




         row++;
         valeur_total+=total;
     }

     ui->valeur_total->setText("Total Facture : "+ QString::number(valeur_total)+" FCFA");

     qr.exec("select * from ventes_options where token='"+token+"'");
     if(qr.next()){
         QString biz=qr.value("biz").toString();
         QString remise=qr.value("remise").toString();
         QString impaye=qr.value("impaye").toString();
         QString non_livre=qr.value("non_livre").toString();
         if(non_livre=="1"){
             ui->non_livre->show();
         }else{
             ui->non_livre->hide();
         }

         if(!remise.isEmpty()){
             remise=remise.split('#').at(1);
             ui->remise->setText(remise);
         }

         if(!impaye.isEmpty()){
             impaye=impaye.split("#").at(2);
             ui->impaye->setText(impaye);
         }

         if(!biz.isEmpty()){
             QStringList all_biz=biz.split("$");
             //ui->table_biz->setRowCount(all_biz.length());

             for(int i=0; i<all_biz.length(); i++){
                 QString line=all_biz.at(i);
                 if(!line.isEmpty()){
                     QStringList line2=line.split("#");
                     QString produit_biz=line2.at(0);
                     QString qte_biz=line2.at(1);
                     QString prix_biz=line2.at(2);
                     QString total_biz=line2.at(3);

                     QSqlQuery qr3;
                     qr3.exec("select * from stock where token_id='"+produit_biz+"'");
                     QString nom_produit_biz="";
                     if(qr3.next()){
                         nom_produit_biz=qr3.value("nom").toString();
                     }

                     ui->table_biz->setRowCount(i+1);

                     ui->table_biz->setItem(i,0,new QTableWidgetItem(nom_produit_biz));
                     ui->table_biz->setItem(i,1,new QTableWidgetItem(qte_biz));
                     ui->table_biz->setItem(i,2,new QTableWidgetItem(prix_biz));
                     ui->table_biz->setItem(i,3,new QTableWidgetItem(total_biz));

                     ui->table_biz->item(i,0)->setTextAlignment(Qt::AlignCenter);
                     ui->table_biz->item(i,1)->setTextAlignment(Qt::AlignCenter);
                     ui->table_biz->item(i,2)->setTextAlignment(Qt::AlignCenter);
                     ui->table_biz->item(i,3)->setTextAlignment(Qt::AlignCenter);

                     ui->table_biz->setColumnWidth(1,50);
                     ui->table_biz->setColumnWidth(2,60);
                     ui->table_biz->setColumnWidth(3,60);

                 }
             }
         }else{
             //ui->table_biz->hide();
         }
     }

     qr.exec("select * from user");
     if(qr.next()){
         QString id_user=qr.value(0).toString();
         QSqlQuery qr2;
         qr2.exec("select * from droit where user='"+id_user+"'");
         if(qr2.next()){
             QString print_facture=qr2.value("facture").toString();
             QString print_bon=qr2.value("bon").toString();

             if(print_facture=="0"){
                 ui->pushButton->hide();
             }

             if(print_bon=="0"){
                 ui->bon->hide();
             }
         }
     }
}

DetailsVente::~DetailsVente()
{
    delete ui;
}

void DetailsVente::on_pushButton_clicked()
{
    QSqlQuery qr;
    qr.exec("select * from token");
    QString token="";
    if(qr.next()){
        token=qr.value(0).toString();
    }
    print_facture(token);
}

void DetailsVente::print_facture(QString token)
{


    QSqlQuery qr;
    bool bon2=false;
    qr.exec("select * from bon");
    if(qr.next()){
        bon2=true;
    }

    QString papier="";
    QString format="";

    qr.exec("select * from print_config");
    if(qr.next()){
        papier=qr.value("papier").toString();
        format=qr.value("format").toString();
    }


     QPrinter printer;
     if(papier=="1"){
          printer.setPaperSize(QPrinter::A4);
     }else{
          printer.setPaperSize(QPrinter::A5);
     }

     if(format=="2"){
         printer.setOrientation(QPrinter::Portrait);
     }else{
         printer.setOrientation(QPrinter::Landscape);
     }

     facture=new Facture(token,this);
     bon=new Bon(token,this);


     facture->setFixedWidth(printer.pageRect().width());

     QPainter painter;
     painter.begin(&printer);
     double xscale = printer.pageRect().width()/double(facture->width());
     double yscale = printer.pageRect().height()/double(facture->height());
     double scale = qMin(xscale, yscale);


     facture->render(&painter);
     printer.newPage();
     facture->render(&painter);
     printer.newPage();
     bon->render(&painter);
     painter.end();
     /*if(bon2){
         printer.newPage();
         bon->render(&painter);
     }*/

     qr.exec("delete from bon");


}

void DetailsVente::on_bon_clicked()
{
    bool v=ui->bon->isChecked();
    QSqlQuery qr;
    qr.exec("delete from bon");
    if(v){
        qr.exec("insert into bon values('1')");
    }
}

void DetailsVente::on_pushButton_2_clicked()
{
    QSqlQuery qr;

    int res=QMessageBox::question(this,"Confirmation","Voulez-vous vraiment marquer cette vente comme livré ?");
    if(res==QMessageBox::Yes){
        if(qr.exec("update ventes_options set non_livre='0' where token='"+token_facture+"'")){
            QMessageBox::information(this,"Success","Opération bien effectuée");
            ui->non_livre->hide();
        }else{
            QMessageBox::warning(this,"Erreur","Une erreur est survenue");
        }
    }
}

void DetailsVente::on_pushButton_3_clicked()
{
    apercu_facture_with_token=new ApercuFactureWithToken(token_facture,this);
    apercu_facture_with_token->setModal(true);
    apercu_facture_with_token->show();
}
