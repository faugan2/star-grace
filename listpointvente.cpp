#include "listpointvente.h"
#include "ui_listpointvente.h"

listpointvente::listpointvente(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::listpointvente)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setFixedWidth(750);
    load_list();
    init();
}

listpointvente::~listpointvente()
{
    delete ui;
}

void listpointvente::on_pushButton_clicked()
{
    QString adresse=ui->adresse->text();
    QString responsable=ui->responsable->text();
    QString contact=ui->contact->text();
    if(adresse.isEmpty() || responsable.isEmpty() || contact.isEmpty()){
        QMessageBox::warning(this,"Erreur","Vous devez saisir tous les champs");
        return;
    }

    QSqlQuery qr;
    if(id_selected==""){
        qr.prepare("insert into points_vente(adresse,responsable,contact) values(:adresse,:responsable,:contact)");
        qr.bindValue(":adresse",adresse.toUpper());
        qr.bindValue(":responsable",responsable.toUpper());
        qr.bindValue(":contact",contact);
        if(qr.exec()){
            init();
            load_list();
        }else{
            ui->alerte->setText("Une erreur est survenue");
        }
    }else{
        qr.prepare("update points_vente set adresse=:adresse, responsable=:responsable,contact=:contact where id=:id");
               qr.bindValue(":adresse",adresse.toUpper());
               qr.bindValue(":responsable",responsable.toUpper());
               qr.bindValue(":contact",contact);
               qr.bindValue(":id",id_selected);
               if(qr.exec()){
                   init();
                   load_list();
               }else{
                   ui->alerte->setText("Une erreur est survenue");
               }
    }

}

void listpointvente::load_list()
{
    QSqlQuery qr;
        int total=0;
        qr.exec("select count(*) from points_vente");
        if(qr.next()){
            total=qr.value(0).toInt();
        }
        ui->table_liste_point_vente->setRowCount(total);


        qr.exec("select * from points_vente");
        int r=0;
        while(qr.next()){
            QString id=qr.value(0).toString();
            QString adresse=qr.value(1).toString();
            QString responsable=qr.value(2).toString();
            QString contact=qr.value(3).toString();


            ui->table_liste_point_vente->setItem(r,0,new QTableWidgetItem(adresse));
            ui->table_liste_point_vente->setItem(r,1,new QTableWidgetItem(responsable));
            ui->table_liste_point_vente->setItem(r,2,new QTableWidgetItem(contact));



            ui->table_liste_point_vente->item(r,0)->setToolTip(id);
            r++;

        }

}

void listpointvente::init()
{

    ui->btn_del->setEnabled(false);
    ui->btn_edit->setEnabled(false);
    ui->adresse->clear();
    ui->responsable->clear();
    ui->contact->clear();
}

void listpointvente::on_table_liste_point_vente_cellClicked(int row, int column)
{
    ui->btn_del->setEnabled(true);
    ui->btn_edit->setEnabled(true);
    id_selected=ui->table_liste_point_vente->item(row,0)->toolTip();
}

void listpointvente::on_btn_edit_clicked()
{
    QSqlQuery qr;
        qr.exec("select * from points_vente where id='"+id_selected+"'");
        if(qr.next()){
            QString adresse=qr.value(1).toString();
            QString responsable=qr.value(2).toString();
            QString contact=qr.value(3).toString();



            ui->adresse->setText(adresse);
            ui->responsable->setText(responsable);
            ui->contact->setText(contact);
            ui->pushButton->setText("Modifier");
        }
}

void listpointvente::on_btn_del_clicked()
{
    if(id_selected!=""){
            int res=QMessageBox::question(this,"Confirmation","Voulez-vous vraiment supprimer le format ?");
            if(res==QMessageBox::Yes){
                QSqlQuery qr;
                if(qr.exec("delete from points_vente where id='"+id_selected+"'")){
                    load_list();
                    init();
                }else{
                    QMessageBox::warning(this,"Erreur","Une erreur est survenue");
                }
            }


        }
}

void listpointvente::on_search_textChanged(const QString &arg1)
{
    if(arg1.isEmpty()){
            load_list();
            return;
        }
    QSqlQuery qr;
    qr.exec("select * from points_vente where adresse like '%"+arg1+"%' or responsable  like '%"+arg1+"%' or contact  like '%"+arg1+"%'");
    int r=0;
    //ui->table_liste_point_vente->setRowCount(0);
    while(qr.next()){
        QString id=qr.value(0).toString();
        QString adresse=qr.value(1).toString();
        QString responsable=qr.value(2).toString();
        QString contact=qr.value(3).toString();


        ui->table_liste_point_vente->setRowCount(r+1);
        ui->table_liste_point_vente->setItem(r,0,new QTableWidgetItem(adresse));
        ui->table_liste_point_vente->setItem(r,1,new QTableWidgetItem(responsable));
        ui->table_liste_point_vente->setItem(r,2,new QTableWidgetItem(contact));



        ui->table_liste_point_vente->item(r,0)->setToolTip(id);
        r++;
    }
    if(r==0){
        ui->table_liste_point_vente->setRowCount(0);
    }
}
