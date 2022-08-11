#include "ajoutautres.h"
#include "ui_ajoutautres.h"

AjoutAutres::AjoutAutres(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AjoutAutres)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setFixedWidth(750);


    init();
    load_list();
    load_formats();
    ui->table_liste_point_vente->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->table_liste_point_vente->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->btn_del->setEnabled(false);
    ui->btn_edit->setEnabled(false);
    ui->btn_modif_stock->setEnabled(false);
}

AjoutAutres::~AjoutAutres()
{
    delete ui;
}



void AjoutAutres::on_pushButton_clicked()
{
        QString nom=ui->nom->text();
        QString format="-";
        QString prix_par_m2=ui->prix_par_m2->text();


        if(nom.isEmpty() || format.isEmpty() || prix_par_m2.isEmpty()){
            QMessageBox::warning(this,"Erreur","Remplissez tous champs avant de valider");
            return;
        }

        QSqlQuery qr;
        if(id_selected==""){
            qr.prepare("insert into stock (type,nom,format,prix_par_m2,alerte) values(:type,:nom,:format,:prix_par_m2,:alerte)");
            qr.bindValue(":type","2");
            qr.bindValue(":nom",nom.toUpper());
            qr.bindValue(":format",format);
            qr.bindValue(":prix_par_m2",prix_par_m2);
            qr.bindValue(":alerte","0");
            if(qr.exec()){
                init();
                load_list();
            }else{
                QMessageBox::warning(this,"Erreur","Une erreur est survenue l'ors de l'insertion");
            }
        }else{
            qr.prepare("update stock set nom=:nom, format=:format,prix_par_m2=:prix_par_m2 where id=:id");
            qr.bindValue(":nom",nom.toUpper());
            qr.bindValue(":format",format);
            qr.bindValue(":prix_par_m2",prix_par_m2);
            qr.bindValue(":id",id_selected);
            if(qr.exec()){
                init();
                load_list();
            }else{
                ui->alerte->setText("Une erreur est survenue");
            }
        }
}

void AjoutAutres::load_list()
{
    QSqlQuery qr;
    int total=0;
    qr.exec("select count(*) from stock where type='2'");
    if(qr.next()){
        total=qr.value(0).toInt();
    }
    ui->table_liste_point_vente->setRowCount(total);


    qr.exec("select * from stock where type='2'");
    int r=0;
    while(qr.next()){
        QString id=qr.value(0).toString();
        QString nom=qr.value(2).toString();
        QString format=qr.value(3).toString();
        QString prix_par_m2=qr.value(4).toString();


        ui->table_liste_point_vente->setItem(r,0,new QTableWidgetItem(nom));
        ui->table_liste_point_vente->setItem(r,1,new QTableWidgetItem(prix_par_m2));
        //ui->table_liste_point_vente->setItem(r,2,new QTableWidgetItem("0"));

        ui->table_liste_point_vente->item(r,0)->setToolTip(id);
        r++;

    }
}

void AjoutAutres::init()
{
    ui->nom->clear();
    //ui->format->setCurrentIndex(0);
    ui->prix_par_m2->clear();
    ui->pushButton->setText("Ajouter");
    ui->btn_del->setEnabled(false);
    ui->btn_edit->setEnabled(false);
    ui->btn_modif_stock->setEnabled(false);
}

void AjoutAutres::on_search_textChanged(const QString &arg1)
{
    if(arg1.isEmpty()){
            load_list();
            return;
        }
    QSqlQuery qr;
    qr.exec("select * from stock where nom like '%"+arg1+"%'  or prix_par_m2  like '%"+arg1+"%'");

    int r=0;
    //ui->table_liste_point_vente->setRowCount(0);
    while(qr.next()){
        QString id=qr.value(0).toString();
        QString type=qr.value(1).toString();
        if(type=="1"){
            continue;
        }
        QString nom=qr.value(2).toString();
        QString format=qr.value(3).toString();
        QString prix_par_m2=qr.value(4).toString();

        ui->table_liste_point_vente->setRowCount(r+1);
        ui->table_liste_point_vente->setItem(r,0,new QTableWidgetItem(nom));
        ui->table_liste_point_vente->setItem(r,1,new QTableWidgetItem(prix_par_m2));
        //ui->table_liste_point_vente->setItem(r,2,new QTableWidgetItem("0"));


        ui->table_liste_point_vente->item(r,0)->setToolTip(id);
        r++;
    }
    if(r==0){
        ui->table_liste_point_vente->setRowCount(0);
    }

}

void AjoutAutres::on_btn_edit_clicked()
{
    QSqlQuery qr;
    qr.exec("select * from stock where id='"+id_selected+"'");
    if(qr.next()){
        QString nom=qr.value("nom").toString();
        QString format=qr.value("format").toString();
        QString prix_par_m2=qr.value("prix_par_m2").toString();



        ui->nom->setText(nom);
        //ui->format->setCurrentText(format);
        ui->prix_par_m2->setText(prix_par_m2);
        ui->pushButton->setText("Modifier");
    }
}

void AjoutAutres::on_btn_del_clicked()
{
    if(id_selected!=""){
        int res=QMessageBox::question(this,"Confirmation","Voulez-vous vraiment supprimer le format ?");
        if(res==QMessageBox::Yes){
            QSqlQuery qr;
            if(qr.exec("delete from stock where id='"+id_selected+"'")){
                load_list();
                init();
            }else{
                QMessageBox::warning(this,"Erreur","Une erreur est survenue");
            }
        }


    }

}

void AjoutAutres::on_table_liste_point_vente_cellClicked(int row, int column)
{
    ui->btn_del->setEnabled(true);
    ui->btn_edit->setEnabled(true);
    ui->btn_modif_stock->setEnabled(true);
    id_selected=ui->table_liste_point_vente->item(row,0)->toolTip();
}

void AjoutAutres::load_formats()
{
    /*QSqlQuery qr;
    qr.exec("select * from formats");
    ui->format->addItem("Choisir");
    while(qr.next()){
        ui->format->addItem(qr.value("nom").toString());
    }*/

}

void AjoutAutres::on_btn_modif_stock_clicked()
{
    modif_stock=new ModifierStock(id_selected,this);
    modif_stock->setModal(true);
    modif_stock->show();
}
