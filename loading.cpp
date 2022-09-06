#include "loading.h"
#include "ui_loading.h"



Loading::Loading(QSqlDatabase db, QString id_user, bool auto_start, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Loading)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

    this->db=db;
    this->id_user=id_user;



    if(auto_start==true){
       // ui->btn_commencer->setEnabled(false);
       // update();
    }


}

Loading::~Loading()
{
    delete ui;
}


void Loading::update()
{
    ui->textBrowser->append("Patientez...");
    QNetworkAccessManager * mgr = new QNetworkAccessManager(this);
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(onfinish(QNetworkReply*)));
    connect(mgr,SIGNAL(finished(QNetworkReply*)),mgr,SLOT(deleteLater()));
    mgr->get(QNetworkRequest(QUrl("http://127.0.0.1/db/saving.php")));
    return;

    db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("141.136.39.52");
    db.setUserName("assitcha_star_grace");
    db.setDatabaseName("assitcha_star_grace");
    db.setPassword("faugan2000@");
    if(db.open()){
    online_bris=new QList<QStringList>();
    online_clients=new QList<QStringList>();
    online_depenses=new QList<QStringList>();
    online_droits==new QList<QStringList>();
    online_formats=new QList<QStringList>();
    online_points_vente=new QList<QStringList>();
    online_prepayements=new QList<QStringList>();
    online_retrait=new QList<QStringList>();
    online_stock=new QList<QStringList>();
    online_transfert=new QList<QStringList>();
    online_users=new QList<QStringList>();
    online_vente_options=new QList<QStringList>();
    online_mouvements=new QList<QStringList>();


    offline_bris=new QList<QStringList>();
    offline_clients=new QList<QStringList>();
    offline_depenses=new QList<QStringList>();
    offline_droits==new QList<QStringList>();
    offline_formats=new QList<QStringList>();
    offline_points_vente=new QList<QStringList>();
    offline_prepayements=new QList<QStringList>();
    offline_retrait=new QList<QStringList>();
    offline_stock=new QList<QStringList>();
    offline_transfert=new QList<QStringList>();
    offline_users=new QList<QStringList>();
    offline_vente_options=new QList<QStringList>();
    offline_mouvements=new QList<QStringList>();

    ui->textBrowser->append("Connexion au serveur distant...");

    QTimer::singleShot(2000,this,SLOT(load_bris()));
    }
}

void Loading::onfinish(QNetworkReply *rep)
{
    QByteArray bts = rep->readAll();
    QString str(bts);
    qDebug()<<"from server update"<<str;
    ui->textBrowser->append("Terminer");
    ui->btn_terminer->setEnabled(true);
}

void Loading::load_bris()
{
    QStringList cols;
    cols<<"id"<<"produit"<<"pieces_cassees"<<"lots_obtenus"<<"date"<<"user"<<"token_id";
    if(db.userName()=="root"){
         load_table_data("bris",cols,&offline_bris);
    }else{
         load_table_data("bris",cols,&online_bris);
    }

    QTimer::singleShot(2000,this,SLOT(load_clients()));
}

void Loading::load_clients()
{
    QStringList cols;
    cols<<"id"<<"sexe"<<"nom"<<"contact"<<"token_id";
    if(db.userName()=="root"){
        load_table_data("clients",cols,&offline_clients);
    }else{
        load_table_data("clients",cols,&online_clients);
    }

    QTimer::singleShot(2000,this,SLOT(load_depenses()));

}

void Loading::load_depenses()
{
    QStringList cols;
    cols<<"id"<<"titre"<<"montant"<<"detail"<<"date"<<"user"<<"token_id";
    if(db.userName()=="root"){
        load_table_data("depenses",cols,&offline_depenses);
    }else{
        load_table_data("depenses",cols,&online_depenses);
    }

    QTimer::singleShot(2000,this,SLOT(load_droit()));

}

void Loading::load_droit()
{
    QStringList cols;
    cols<<"id"<<"user"<<"transfert"<<"depenses"<<"bris"<<"retrait"<<"point_vente"<<"utilisateurs"<<"clients"<<"stock"<<"vente"<<"facture"<<"bon"<<"token_id";
    if(db.userName()=="root"){
        //offline_droits->clear();
        load_table_data("droit",cols,&offline_droits);
    }else{
        //online_droits->clear();
        load_table_data("droit",cols,&online_droits);
    }

    QTimer::singleShot(2000,this,SLOT(load_formats()));
}


void Loading::load_formats()
{
    QStringList cols;
    cols<<"id"<<"nom"<<"pieces_par_m2"<<"pieces_par_carton"<<"dimension"<<"prix"<<"token_id";
    if(db.userName()=="root"){
        load_table_data("formats",cols,&offline_formats);
    }else{
        load_table_data("formats",cols,&online_formats);
    }

    QTimer::singleShot(2000,this,SLOT(load_points_vente()));
}



void Loading::load_points_vente()
{
    QStringList cols;
    cols<<"id"<<"adresse"<<"responsable"<<"contact"<<"token_id";
    if(db.userName()=="root"){
        load_table_data("points_vente",cols,&offline_points_vente);
    }else{
        load_table_data("points_vente",cols,&online_points_vente);
    }

    QTimer::singleShot(2000,this,SLOT(load_prepayements()));
}


void Loading::load_prepayements()
{
    QStringList cols;
    cols<<"id"<<"client"<<"montant"<<"detail"<<"date"<<"token_id";
    if(db.userName()=="root"){
        load_table_data("prepayements",cols,&offline_prepayements);
    }else{
        load_table_data("prepayements",cols,&online_prepayements);
    }

    QTimer::singleShot(2000,this,SLOT(load_retrait()));
}


void Loading::load_retrait()
{
    QStringList cols;
    cols<<"id"<<"montant"<<"motif"<<"date"<<"user"<<"token_id";
    if(db.userName()=="root"){
        load_table_data("retrait",cols,&offline_retrait);
    }else{
        load_table_data("retrait",cols,&online_retrait);
    }

    QTimer::singleShot(2000,this,SLOT(load_stock()));
}

void Loading::load_stock()
{
    QStringList cols;
    cols<<"id"<<"type"<<"nom"<<"format"<<"prix_par_m2"<<"alerte"<<"token_id";
    if(db.userName()=="root"){
        load_table_data("stock",cols,&offline_stock);
    }else{
        load_table_data("stock",cols,&online_stock);
    }

    QTimer::singleShot(2000,this,SLOT(load_transfert()));
}

void Loading::load_transfert()
{
    QStringList cols;
    cols<<"id"<<"du"<<"a"<<"produit"<<"user"<<"token"<<"token_id";
    if(db.userName()=="root"){
        load_table_data("transfert",cols,&offline_transfert);
    }else{
        load_table_data("transfert",cols,&online_transfert);
    }

    QTimer::singleShot(2000,this,SLOT(load_users()));
}

void Loading::load_users()
{
    QStringList cols;
    cols<<"id"<<"nom"<<"login"<<"password"<<"type"<<"point_vente"<<"date_creation"<<"last_login"<<"token_id";
    if(db.userName()=="root"){
        load_table_data("users",cols,&offline_users);
    }else{
        load_table_data("users",cols,&online_users);
    }

    QTimer::singleShot(2000,this,SLOT(load_vente_options()));

}


void Loading::load_vente_options()
{
    QStringList cols;
    cols<<"id"<<"token"<<"biz"<<"remise"<<"impaye"<<"client"<<"non_livre"<<"token_id";
    if(db.userName()=="root"){
        load_table_data("ventes_options",cols,&offline_vente_options);
    }else{
        load_table_data("ventes_options",cols,&online_vente_options);
    }
    QTimer::singleShot(2000,this,SLOT(load_mouvements()));

}

void Loading::load_mouvements()
{
    QStringList cols;
    cols<<"id"<<"date"<<"type"<<"produit"<<"qte"<<"user"<<"point_vente"<<"nb_cartons"<<"token"<<"qte_m2"<<"prix"<<"unite"<<"token_id";
    if(db.userName()=="root"){
        load_table_data("mouvements",cols,&offline_mouvements);
    }else{
        load_table_data("mouvements",cols,&online_mouvements);
    }
    load_offline_data();
}


void Loading::load_offline_data()
{
    qDebug()<<"in loading offiline user ="<<db.userName();
    if(db.userName()=="root"){
        qDebug()<<"the user root, so local loaded";
        update_final();
        return;
    }


    QSqlDatabase::removeDatabase("QMYSQL");

    db=QSqlDatabase::addDatabase("QMYSQL");
    db.setUserName("root");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("base");
    db.setPassword("");
    db.open();
    if(db.isOpen()){
       QTimer::singleShot(2000,this,SLOT(load_bris()));
    }

}


void Loading::update_final()
{
    qDebug()<<"in update final";
    QStringList cols;

    if(db.userName()=="root"){
        cols<<"id"<<"produit"<<"pieces_cassees"<<"lots_obtenus"<<"date"<<"user"<<"token_id";
        online_to_local(online_bris,offline_bris,"bris",cols);
        cols.clear();
        qDebug()<<"done with bris";

        cols<<"id"<<"sexe"<<"nom"<<"contact"<<"token_id";
        online_to_local(online_clients,offline_clients,"clients",cols);
        cols.clear();
        qDebug()<<"done with clients";

        cols<<"id"<<"titre"<<"montant"<<"detail"<<"date"<<"user"<<"token_id";
        //online_to_local(online_depenses,offline_depenses,"depenses",cols);
        //cols.clear();

        qDebug()<<"done with depenses"<<QString::number(online_droits->length())<<QString::number(offline_droits->length());

        cols<<"id"<<"user"<<"transfert"<<"depenses"<<"bris"<<"retrait"<<"point_vente"<<"utilisateurs"<<"clients"<<"stock"<<"vente"<<"facture"<<"bon"<<"token_id";
        online_to_local(online_droits,offline_droits,"droit",cols);
        cols.clear();
        qDebug()<<"done with droit";

        cols<<"id"<<"nom"<<"pieces_par_m2"<<"pieces_par_carton"<<"dimension"<<"prix"<<"token_id";
        online_to_local(online_formats,offline_formats,"formats",cols);
        cols.clear();
        qDebug()<<"done with formats";

        cols<<"id"<<"adresse"<<"responsable"<<"contact"<<"token_id";
        online_to_local(online_points_vente,offline_points_vente,"points_vente",cols);
        cols.clear();
        qDebug()<<"done with points_vente";

        cols<<"id"<<"client"<<"montant"<<"detail"<<"date"<<"token_id";
        online_to_local(online_prepayements,offline_prepayements,"prepayements",cols);
        cols.clear();
        qDebug()<<"done with prepayements";

        cols<<"id"<<"montant"<<"motif"<<"date"<<"user"<<"token_id";
        online_to_local(online_retrait,offline_retrait,"retrait",cols);
        cols.clear();
        qDebug()<<"done with retrait";

        cols<<"id"<<"type"<<"nom"<<"format"<<"prix_par_m2"<<"alerte"<<"token_id";
        online_to_local(online_stock,offline_stock,"stock",cols);
        cols.clear();
        qDebug()<<"done with stock";

        cols<<"id"<<"du"<<"a"<<"produit"<<"user"<<"token"<<"token_id";
        online_to_local(online_transfert,offline_transfert,"transfert",cols);
        cols.clear();
        qDebug()<<"done with transfert";

        cols<<"id"<<"nom"<<"login"<<"password"<<"type"<<"point_vente"<<"date_creation"<<"last_login"<<"token_id";
        online_to_local(online_users,offline_users,"users",cols);
        cols.clear();
        qDebug()<<"done with users";

        cols<<"id"<<"token"<<"biz"<<"remise"<<"impaye"<<"client"<<"non_livre"<<"token_id";
        online_to_local(online_vente_options,offline_vente_options,"ventes_options",cols);
        cols.clear();
        qDebug()<<"done with ventes_options";

        cols<<"id"<<"date"<<"type"<<"produit"<<"qte"<<"user"<<"point_vente"<<"nb_cartons"<<"token"<<"qte_m2"<<"prix"<<"unite"<<"token_id";
        online_to_local(online_mouvements,offline_mouvements,"mouvements",cols);
        cols.clear();
        qDebug()<<"done with mouvements";

        db=QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("141.136.39.52");
        db.setUserName("assitcha_star_grace");
        db.setDatabaseName("assitcha_star_grace");
        db.setPassword("faugan2000@");
        if(db.open()){
            qDebug()<<"done with CONNECTED TO SERVER ONLINE";
            update_final();
        }

    }else{
       // ui->textBrowser->append("going to send local data online now");
        cols<<"id"<<"produit"<<"pieces_cassees"<<"lots_obtenus"<<"date"<<"user"<<"token_id";
        online_to_local(offline_bris,online_bris,"bris",cols);
        cols.clear();
        qDebug()<<"bris updated";

       // QTimer::singleShot(2000,this,SLOT(delay()));
        cols<<"id"<<"sexe"<<"nom"<<"contact"<<"token_id";
        online_to_local(offline_clients,online_clients,"clients",cols);
        cols.clear();
        qDebug()<<"client updated";

        cols<<"id"<<"titre"<<"montant"<<"detail"<<"date"<<"user"<<"token_id";
        online_to_local(offline_depenses,online_depenses,"depenses",cols);
        cols.clear();
        qDebug()<<"depenses updated";

        cols<<"id"<<"user"<<"transfert"<<"depenses"<<"bris"<<"retrait"<<"point_vente"<<"utilisateurs"<<"clients"<<"stock"<<"vente"<<"facture"<<"bon"<<"token_id";
        online_to_local(offline_droits,online_droits,"droit",cols);
        cols.clear();
        qDebug()<<"DROIT updated";

        cols<<"id"<<"nom"<<"pieces_par_m2"<<"pieces_par_carton"<<"dimension"<<"prix"<<"token_id";
        online_to_local(offline_formats,online_formats,"formats",cols);
        cols.clear();
        qDebug()<<"formats updated";

        cols<<"id"<<"adresse"<<"responsable"<<"contact"<<"token_id";
        online_to_local(offline_points_vente,online_points_vente,"points_vente",cols);
        cols.clear();

        cols<<"id"<<"client"<<"montant"<<"detail"<<"date"<<"token_id";
        online_to_local(offline_prepayements,online_prepayements,"prepayements",cols);
        cols.clear();

        cols<<"id"<<"montant"<<"motif"<<"date"<<"user"<<"token_id";
        online_to_local(offline_retrait,online_retrait,"retrait",cols);
        cols.clear();

        cols<<"id"<<"type"<<"nom"<<"format"<<"prix_par_m2"<<"alerte"<<"token_id";
        online_to_local(offline_stock,online_stock,"stock",cols);
        cols.clear();

        cols<<"id"<<"du"<<"a"<<"produit"<<"user"<<"token"<<"token_id";
        online_to_local(offline_transfert,online_transfert,"transfert",cols);
        cols.clear();

        cols<<"id"<<"nom"<<"login"<<"password"<<"type"<<"point_vente"<<"date_creation"<<"last_login"<<"token_id";
        online_to_local(offline_users,online_users,"users",cols);
        cols.clear();

        cols<<"id"<<"token"<<"biz"<<"remise"<<"impaye"<<"client"<<"non_livre"<<"token_id";
        online_to_local(offline_vente_options,online_vente_options,"ventes_options",cols);
        cols.clear();

        cols<<"id"<<"date"<<"type"<<"produit"<<"qte"<<"user"<<"point_vente"<<"nb_cartons"<<"token"<<"qte_m2"<<"prix"<<"unite"<<"token_id";
        online_to_local(offline_mouvements,online_mouvements,"mouvements",cols);
        cols.clear();

        //ui->textBrowser->append("done sending to server");
    }


    //ui->textBrowser->append("Terminé");
    ui->status->setText("Terminé");
    ui->btn_terminer->setEnabled(true);
    ui->btn_commencer->setEnabled(true);

}

void Loading::online_to_local(QList<QStringList> *from, QList<QStringList> *to, QString table, QStringList columns)
{
    if(db.userName()=="root"){
        ui->status->setText("Serveur -> Local \ "+table);
    }else{
        ui->status->setText("Local -> Serveur \ "+table);
    }


    ui->textBrowser->append(table+": from="+QString::number(from->length())+" : to="+QString::number(to->length())+" : cols "+QString::number(columns.length()));
    //qDebug()<<table+": from="+QString::number(from->length())+" : to="+QString::number(to->length())+" : cols "+QString::number(columns.length());
    ui->textBrowser->append("->"+table);
    QList<QStringList>add_to_local;
    qDebug()<<"hello"<<table;
    for(int i=0; i<from->length(); i++){
        qDebug()<<"in "<<table<<QString::number(i);
        QStringList line=from->at(i);
        QString token_id=line.at(line.length()-1);
        bool is_in=false;
        for(int j=0; j<to->length(); j++){
            QStringList line2=to->at(j);
            QString token_id2=line2.at(line2.length()-1);
            if(token_id==token_id2){
                is_in=true;
            }
        }
        if(is_in==false){
            add_to_local.append(line);
        }
    }

    qDebug()<<" we are in "<<table<<QString::number(add_to_local.length());

    for(int i=0; i<add_to_local.length(); i++){
        QStringList line=add_to_local.at(i);
        QSqlQuery qr;
        QString cols="";
        for(int c=1;c<columns.length();c++){
            if(c==columns.length()-1){
                cols+=columns.at(c);
            }else{
                cols+=columns.at(c)+",";
            }
        }
        QString values="";
        for(int v=1; v<line.length(); v++){
            if(v==line.length()-1){
                values+="'"+line.at(v)+"'";
            }else{
                 values+="'"+line.at(v)+"',";
            }
        }
        QString req="insert into "+table+"("+cols+") values("+values+")";
        qDebug()<<req;
        ui->status->setText(req);
        ui->textBrowser->append(req);
        qr.exec(req);
    }

    qDebug()<<"DONNNNNNN WITH"<<table;
    //ui->textBrowser->append("->"+table);
}

void Loading::load_table_data(QString table, QStringList cols, QList<QStringList>** storage)
{
    if(db.userName()=="root"){
        ui->status->setText("Local:\\"+table+">");
    }else{
        ui->status->setText("Serveur:\\"+table+">");
    }
    QList<QStringList> *tmp_storage=new QList<QStringList>();
    QSqlQuery qr;
    qr.exec("select * from "+table);
    while(qr.next()){

        QStringList line;
        for(int i=0; i<cols.length(); i++){
            QString value=qr.value(cols.at(i)).toString();
            ui->textBrowser->append(table+"->"+value);
            line.append(value);
        }

        tmp_storage->append(line);
    }

    *storage=tmp_storage;
    ui->textBrowser->append(table+" -> "+QString::number(tmp_storage->length())+" -> "+db.userName());
}



void Loading::on_btn_commencer_clicked()
{
    ui->btn_commencer->setEnabled(false);
     update();
}

void Loading::on_btn_terminer_clicked()
{
    QSqlDatabase::removeDatabase("QMYSQL");
    db=QSqlDatabase::addDatabase("QMYSQL");
    db.setUserName("root");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("base");
    db.setPassword("");
    if(db.open()){
        this->close();
        MainWindow *m=new MainWindow(db,id_user);
        m->showMaximized();
    }else{
        QMessageBox::warning(this,"Serveur local","Le serveur local ne semble pas être demarré");
    }

}
