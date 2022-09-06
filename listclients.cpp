#include "listclients.h"
#include "ui_listclients.h"

listclients::listclients(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::listclients)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setFixedWidth(750);
    init();
    load_list();
}

listclients::~listclients()
{
    delete ui;
}


void listclients::on_pushButton_clicked()
{
    QString nom=ui->nom->text();
    QString sexe=ui->sexe->currentText();
    QString contact=ui->contact->text();


    if(nom.isEmpty()  || contact.isEmpty() ){
        QMessageBox::warning(this,"Erreur","Remplissez tous champs avant de valider");
        return;
    }
    QString token_id=QString::number(QDateTime::currentDateTime().toTime_t());

    QSqlQuery qr;
    if(id_selected==""){
        qr.prepare("insert into clients (sexe,nom,contact,token_id) values(:sexe,:nom,:contact,:token)");
        qr.bindValue(":sexe",sexe);
        qr.bindValue(":nom",nom.toUpper());
        qr.bindValue(":contact",contact);
        qr.bindValue(":token",token_id);

        if(qr.exec()){
            init();
            load_list();
        }else{
            QMessageBox::warning(this,"Erreur","Une erreur est survenue l'ors de l'insertion");
        }
    }else{
        qr.prepare("update clients set nom=:nom, sexe=:sexe,contact=:contact where token_id=:id");
        qr.bindValue(":sexe",sexe);
        qr.bindValue(":nom",nom);
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

void listclients::load_list()
{
    QSqlQuery qr;
    int total=0;
    qr.exec("select count(*) from clients");
    if(qr.next()){
        total=qr.value(0).toInt();
    }
    ui->table_liste_point_vente->setRowCount(total);


    qr.exec("select * from clients");
    int r=0;
    while(qr.next()){
        QString id=qr.value("token_id").toString();
        QString sexe=qr.value(1).toString();
        QString nom=qr.value(2).toString();
        QString contact=qr.value(3).toString();


        ui->table_liste_point_vente->setItem(r,0,new QTableWidgetItem(sexe));
        ui->table_liste_point_vente->setItem(r,1,new QTableWidgetItem(nom));
        ui->table_liste_point_vente->setItem(r,2,new QTableWidgetItem(contact));



        ui->table_liste_point_vente->item(r,0)->setToolTip(id);
        r++;

    }
}

void listclients::init()
{
    ui->nom->clear();
    ui->sexe->setCurrentIndex(0);
    ui->contact->clear();

    ui->pushButton->setText("Ajouter");
    ui->btn_del->setEnabled(false);
    ui->btn_edit->setEnabled(false);
}

void listclients::on_btn_del_clicked()
{
    if(id_selected!=""){
        int res=QMessageBox::question(this,"Confirmation","Voulez-vous vraiment supprimer le format ?");
        if(res==QMessageBox::Yes){
            QSqlQuery qr;
            if(qr.exec("delete from clients where token_id='"+id_selected+"'")){
                load_list();
                init();
            }else{
                QMessageBox::warning(this,"Erreur","Une erreur est survenue");
            }
        }


    }
}

void listclients::on_table_liste_point_vente_clicked(const QModelIndex &index)
{

}

void listclients::on_table_liste_point_vente_cellClicked(int row, int column)
{
    ui->btn_del->setEnabled(true);
    ui->btn_edit->setEnabled(true);
    id_selected=ui->table_liste_point_vente->item(row,0)->toolTip();
}

void listclients::on_search_textChanged(const QString &arg1)
{
    if(arg1.isEmpty()){
        load_list();
        return;
    }
    QSqlQuery qr;
    qr.exec("select * from clients where nom like '%"+arg1+"%' or sexe  like '%"+arg1+"%' or contact  like '%"+arg1+"%'");

    int r=0;
    //ui->table_liste_point_vente->setRowCount(0);
    while(qr.next()){
        QString id=qr.value("token_id").toString();
        QString sexe=qr.value(1).toString();
        QString nom=qr.value(2).toString();
        QString contact=qr.value(3).toString();


        ui->table_liste_point_vente->setRowCount(r+1);
        ui->table_liste_point_vente->setItem(r,0,new QTableWidgetItem(sexe));
        ui->table_liste_point_vente->setItem(r,1,new QTableWidgetItem(nom));
        ui->table_liste_point_vente->setItem(r,2,new QTableWidgetItem(contact));



        ui->table_liste_point_vente->item(r,0)->setToolTip(id);
        r++;
    }
    if(r==0){
        ui->table_liste_point_vente->setRowCount(0);
    }
}

void listclients::on_btn_edit_clicked()
{
    QSqlQuery qr;
    qr.exec("select * from clients where token_id='"+id_selected+"'");
    if(qr.next()){
        QString sexe=qr.value("sexe").toString();
        QString nom=qr.value("nom").toString();
        QString contact=qr.value("contact").toString();



        ui->sexe->setCurrentText(sexe);
        ui->nom->setText(nom);
        ui->contact->setText(contact);
        ui->pushButton->setText("Modifier");
    }
}
