#include "listeusers.h"
#include "ui_listeusers.h"

ListeUsers::ListeUsers(QSqlDatabase db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListeUsers)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setFixedWidth(750);
    this->db=db;

    //ui->table_liste_users->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->table_liste_users->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->btn_del->setEnabled(false);
    ui->btn_edit->setEnabled(false);
    ui->btn_droit->setEnabled(false);
    load_list();
    load_type();
    load_point_vente();

}

ListeUsers::~ListeUsers()
{
    delete ui;
}

void ListeUsers::load_list()
{
    QSqlQuery qr;
    int total=0;
    qr.exec("select count(*) from users where point_vente<>'-'");
    if(qr.next()){
        total=qr.value(0).toInt();
    }
    ui->table_liste_users->setRowCount(total);


    qr.exec("select * from users where point_vente<>'-'");
    int r=0;
    while(qr.next()){
        QString id=qr.value("token_id").toString();
        QString nom=qr.value(1).toString();
        QString login=qr.value(2).toString();
        QString password=qr.value(3).toString();
        QString type=qr.value(4).toString();
        QString point_vente=qr.value(5).toString();
        if(point_vente=="-"){
            continue;
        }
        QString point_vente_nom="";
        QSqlQuery qr2;
        qr2.exec("select * from points_vente where token_id='"+point_vente+"'");
        if(qr2.next()){
            point_vente_nom=qr2.value("adresse").toString();
        }
        ui->table_liste_users->setItem(r,0,new QTableWidgetItem(nom));
        ui->table_liste_users->setItem(r,1,new QTableWidgetItem(type));
        ui->table_liste_users->setItem(r,2,new QTableWidgetItem(point_vente_nom));
        ui->table_liste_users->setItem(r,3,new QTableWidgetItem(login));
        ui->table_liste_users->setItem(r,4,new QTableWidgetItem(password));

        ui->table_liste_users->item(r,0)->setToolTip(id);
        r++;

    }
}

void ListeUsers::load_type()
{
    ui->type->addItem("Choisir");
    QSqlQuery qr;
    qr.exec("select * from type");
    while(qr.next()){
        ui->type->addItem(qr.value(1).toString());
    }
}

void ListeUsers::load_point_vente()
{
    ui->point_vente->addItem("Choisir");
    QSqlQuery qr;
    qr.exec("select * from points_vente");
    while(qr.next()){
        ui->point_vente->addItem(qr.value(1).toString(),qr.value("token_id"));
    }
}

void ListeUsers::init()
{
    id_selected_user="";
    ui->btn_del->setEnabled(false);
    ui->btn_edit->setEnabled(false);
    ui->btn_droit->setEnabled(false);
    ui->pushButton->setText("Ajouter");
    ui->nom->clear();
    ui->login->clear();
    ui->password->clear();
    ui->type->setCurrentIndex(0);
    ui->point_vente->setCurrentIndex(0);
    ui->alerte->setText("");
}

void ListeUsers::on_pushButton_clicked()
{
    QString type=ui->type->currentText();
    QString point_vente=ui->point_vente->currentText();
    QString id_point_vente=ui->point_vente->currentData().toString();
    QString nom=ui->nom->text();
    QString login=ui->login->text();
    QString password=ui->password->text();

    if(ui->type->currentIndex()==0 || ui->point_vente->currentIndex()==0
        || nom.isEmpty()
        || login.isEmpty()
        || password.isEmpty()
      ){
        ui->alerte->setText("Remplissez tous les champs");
        return;
    }
     QSqlQuery qr;
     QString token_id=QString::number(QDateTime::currentDateTime().toTime_t());
    if(id_selected_user.isEmpty()){

        qr.prepare("insert into users(nom,login,password,type,point_vente,date_creation,last_login,token_id) values(:nom,:login,:password,:type,:point_vente,:date_creation,:last_login,:token_id)");
        qr.bindValue(":nom",nom.toUpper());
        qr.bindValue(":login",login);
        qr.bindValue(":password",password);
        qr.bindValue(":type",type);
        qr.bindValue(":point_vente",id_point_vente.toUpper());
        qr.bindValue(":date_creation",QDateTime::currentDateTime());
        qr.bindValue(":last_login",QDateTime::currentDateTime());
        qr.bindValue(":token_id",token_id);

        if(qr.exec()){
            init();
            load_list();
        }else{
            ui->alerte->setText("Une erreur est survenue");
        }
    }else{
        qr.prepare("update users set nom=:nom,login=:login,password=:password,type=:type,point_vente=:point_vente where token_id=:id");
        qr.bindValue(":nom",nom.toUpper());
        qr.bindValue(":login",login);
        qr.bindValue(":password",password);
        qr.bindValue(":type",type);
        qr.bindValue(":point_vente",id_point_vente.toUpper());
        qr.bindValue(":id",id_selected_user);
        if(qr.exec()){
            init();
            load_list();
        }else{
            ui->alerte->setText("Une erreur est survenue");
        }

    }


}

void ListeUsers::on_table_liste_users_cellClicked(int row, int column)
{
    ui->btn_del->setEnabled(true);
    ui->btn_edit->setEnabled(true);
    ui->btn_droit->setEnabled(true);
    id_selected_user=ui->table_liste_users->item(row,0)->toolTip();
}

void ListeUsers::on_btn_del_clicked()
{
    if(id_selected_user!=""){
        int row=ui->table_liste_users->selectedItems().at(0)->row();

        int res=QMessageBox::question(this,"Confirmation","Voulez-vous vraiment supprimer l'utilisateur ?");
        if(res==QMessageBox::Yes){
            QSqlQuery qr;
            if(qr.exec("delete from users where token_id='"+id_selected_user+"'")){
                load_list();
                init();
            }else{
                QMessageBox::warning(this,"Erreur","Une erreur est survenue");
            }
        }


    }
}

void ListeUsers::on_btn_edit_clicked()
{
    QSqlQuery qr;
    qr.exec("select * from users where token_id='"+id_selected_user+"'");
    if(qr.next()){
        QString nom=qr.value("nom").toString();
        QString login=qr.value("login").toString();
        QString password=qr.value("password").toString();
        QString type=qr.value("type").toString();
        QString point_vente=qr.value("point_vente").toString();

        QString point_vente_nom="";
        QSqlQuery qr2;
        qr2.exec("select * from points_vente where token_id='"+point_vente+"'");
        if(qr2.next()){
            point_vente_nom=qr2.value("adresse").toString();
        }
        qDebug()<<"select * from points_vente where token_id='"+point_vente+"'="<<point_vente_nom;

        ui->nom->setText(nom);
        ui->login->setText(login);
        ui->password->setText(password);
        ui->type->setCurrentText(type);
        ui->point_vente->setCurrentText(point_vente_nom);
        ui->pushButton->setText("Modifier");
    }
}

void ListeUsers::on_search_textChanged(const QString &arg1)
{

    if(arg1.isEmpty()){
        load_list();
        return;
    }
    QSqlQuery qr;
    qr.exec("select * from users where nom like '%"+arg1+"%' or type  like '%"+arg1+"%' or point_vente  like '%"+arg1+"%'");
    int r=0;
    while(qr.next()){
        QString id=qr.value("token_id").toString();
        QString nom=qr.value(1).toString();
        QString login=qr.value(2).toString();
        QString password=qr.value(3).toString();
        QString type=qr.value(4).toString();
        QString point_vente=qr.value(5).toString();
        if(point_vente=="-"){
            continue;
        }

        QString point_vente_nom="";
        QSqlQuery qr2;
        qr2.exec("select * from points_vente where token_id='"+point_vente+"'");
        if(qr2.next()){
            point_vente_nom=qr2.value("adresse").toString();
        }
        ui->table_liste_users->setRowCount(r+1);
        ui->table_liste_users->setItem(r,0,new QTableWidgetItem(nom));
        ui->table_liste_users->setItem(r,1,new QTableWidgetItem(type));
        ui->table_liste_users->setItem(r,2,new QTableWidgetItem(point_vente_nom));
        ui->table_liste_users->setItem(r,3,new QTableWidgetItem(login));
        ui->table_liste_users->setItem(r,4,new QTableWidgetItem(password));

        ui->table_liste_users->item(r,0)->setToolTip(id);
        r++;
    }
    if(r==0){
        ui->table_liste_users->setRowCount(0);
    }
}

void ListeUsers::on_btn_droit_clicked()
{
    int row=ui->table_liste_users->selectedItems().at(0)->row();
    QString id_user=ui->table_liste_users->item(row,0)->toolTip();

    droits=new Droits(id_user,this);
    droits->setModal(true);
    droits->show();
}
