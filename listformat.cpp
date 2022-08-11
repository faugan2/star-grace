#include "listformat.h"
#include "ui_listformat.h"

Listformat::Listformat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Listformat)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setFixedWidth(750);

    load_list();
}

Listformat::~Listformat()
{
    delete ui;
}

void Listformat::on_pushButton_clicked()
{
    QString nom=ui->nom->text();
    QString pieces_par_m2=ui->pieces_par_m2->text();
    QString pieces_par_carton=ui->pieces_par_cartons->text();
    QString dimension=ui->dimension->text();
    QString prix=ui->prix->text();

    if(nom.isEmpty() || pieces_par_m2.isEmpty() || pieces_par_carton.isEmpty() || dimension.isEmpty() || prix.isEmpty()){
        QMessageBox::warning(this,"Erreur","Remplissez tous champs avant de valider");
        return;
    }

    QSqlQuery qr;
    if(id_selected==""){
        qr.prepare("insert into formats (nom,pieces_par_m2,pieces_par_carton,dimension,prix) values(:nom,:pieces_par_m2,:pieces_par_carton,:dimension,:prix)");
        qr.bindValue(":nom",nom.toUpper());
        qr.bindValue(":pieces_par_m2",pieces_par_m2);
        qr.bindValue(":pieces_par_carton",pieces_par_carton);
        qr.bindValue(":dimension",dimension);
        qr.bindValue(":prix",prix);
        if(qr.exec()){
            ui->nom->clear();
            ui->pieces_par_cartons->clear();
            ui->pieces_par_m2->clear();
            ui->dimension->clear();
            load_list();
        }else{
            QMessageBox::warning(this,"Erreur","Une erreur est survenue l'ors de l'insertion");
        }
    }else{
        qr.prepare("update formats set nom=:nom, pieces_par_m2=:pieces_par_m2,pieces_par_carton=:pieces_par_carton,dimension=:dimension,prix=:prix where id=:id");
        qr.bindValue(":nom",nom.toUpper());
        qr.bindValue(":pieces_par_m2",pieces_par_m2);
        qr.bindValue(":pieces_par_carton",pieces_par_carton);
        qr.bindValue(":dimension",dimension);
        qr.bindValue(":id",id_selected);
        qr.bindValue(":prix",prix);
        if(qr.exec()){
            init();
            load_list();
        }else{
            ui->alerte->setText("Une erreur est survenue");
        }
    }

}

void Listformat::load_list()
{
    QSqlQuery qr;
    int total=0;
    qr.exec("select count(*) from formats");
    if(qr.next()){
        total=qr.value(0).toInt();
    }
    ui->table_liste_point_vente->setRowCount(total);


    qr.exec("select * from formats");
    int r=0;
    while(qr.next()){
        QString id=qr.value(0).toString();
        QString nom=qr.value(1).toString();
        QString pieces_par_m2=qr.value(2).toString();
        QString pieces_par_carton=qr.value(3).toString();
        QString dimension=qr.value(4).toString();
        QString prix=qr.value("prix").toString();

        ui->table_liste_point_vente->setItem(r,0,new QTableWidgetItem(nom));
        ui->table_liste_point_vente->setItem(r,1,new QTableWidgetItem(pieces_par_m2));
        ui->table_liste_point_vente->setItem(r,2,new QTableWidgetItem(pieces_par_carton));
        ui->table_liste_point_vente->setItem(r,3,new QTableWidgetItem(dimension));
        ui->table_liste_point_vente->setItem(r,4,new QTableWidgetItem(prix));


        ui->table_liste_point_vente->item(r,0)->setToolTip(id);
        r++;

    }
}

void Listformat::init()
{
    ui->nom->clear();
    ui->pieces_par_cartons->clear();
    ui->pieces_par_m2->clear();
    ui->dimension->clear();
    ui->prix->clear();
    ui->pushButton->setText("Ajouter");
    ui->btn_del->setEnabled(false);
    ui->btn_edit->setEnabled(false);
}

void Listformat::on_btn_del_clicked()
{
    if(id_selected!=""){
        int res=QMessageBox::question(this,"Confirmation","Voulez-vous vraiment supprimer le format ?");
        if(res==QMessageBox::Yes){
            QSqlQuery qr;
            if(qr.exec("delete from formats where id='"+id_selected+"'")){
                load_list();
                init();
            }else{
                QMessageBox::warning(this,"Erreur","Une erreur est survenue");
            }
        }


    }
}

void Listformat::on_table_liste_point_vente_clicked(const QModelIndex &index)
{

}

void Listformat::on_table_liste_point_vente_cellClicked(int row, int column)
{
    ui->btn_del->setEnabled(true);
    ui->btn_edit->setEnabled(true);
    id_selected=ui->table_liste_point_vente->item(row,0)->toolTip();
}

void Listformat::on_search_textChanged(const QString &arg1)
{
    if(arg1.isEmpty()){
        load_list();
        return;
    }
    QSqlQuery qr;
    qr.exec("select * from formats where nom like '%"+arg1+"%' or pieces_par_m2  like '%"+arg1+"%' or pieces_par_carton  like '%"+arg1+"%' or dimension like '%"+arg1+"%'");

    qDebug()<<"select * from formats where nom like '%"+arg1+"%' or pieces_par_m2  like '%"+arg1+"%' or pieces_par_carton  like '%"+arg1+"%' or dimension like '%"+arg1+"%'";
    int r=0;
    //ui->table_liste_point_vente->setRowCount(0);
    while(qr.next()){
        QString id=qr.value(0).toString();
        QString nom=qr.value(1).toString();
        QString pieces_par_m2=qr.value(2).toString();
        QString pieces_par_carton=qr.value(3).toString();
        QString dimension=qr.value(4).toString();
        QString prix=qr.value("prix").toString();

        ui->table_liste_point_vente->setRowCount(r+1);
        ui->table_liste_point_vente->setItem(r,0,new QTableWidgetItem(nom));
        ui->table_liste_point_vente->setItem(r,1,new QTableWidgetItem(pieces_par_m2));
        ui->table_liste_point_vente->setItem(r,2,new QTableWidgetItem(pieces_par_carton));
        ui->table_liste_point_vente->setItem(r,3,new QTableWidgetItem(dimension));
        ui->table_liste_point_vente->setItem(r,4,new QTableWidgetItem(prix));

        ui->table_liste_point_vente->item(r,0)->setToolTip(id);
        r++;
    }
}

void Listformat::on_btn_edit_clicked()
{
    QSqlQuery qr;
    qr.exec("select * from formats where id='"+id_selected+"'");
    if(qr.next()){
        QString nom=qr.value("nom").toString();
        QString pieces_par_m2=qr.value("pieces_par_m2").toString();
        QString pieces_par_carton=qr.value("pieces_par_carton").toString();
        QString dimension=qr.value("dimension").toString();
        QString prix=qr.value("prix").toString();

        ui->nom->setText(nom);
        ui->pieces_par_m2->setText(pieces_par_m2);
        ui->pieces_par_cartons->setText(pieces_par_carton);
        ui->dimension->setText(dimension);
        ui->prix->setText(prix);
        ui->pushButton->setText("Modifier");
    }
}
