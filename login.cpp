#include "login.h"
#include "ui_login.h"
#include "includes.h"


using namespace std;

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setFixedSize(this->sizeHint());

    QPixmap logo(":/img/logo-removebg-preview.png");
    QPixmap newPixmap = logo.scaled(QSize(150,150),  Qt::KeepAspectRatio);
    ui->label_2->setPixmap(newPixmap);

    close_db();
    db=QSqlDatabase::addDatabase("QMYSQL");


    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setDatabaseName("base");
    db.setPassword("");

    db.open();

    if(db.open()){
        qDebug()<<"Le serveur est bien démarré";
    }else{
       qDebug()<<"erreur de connexion";
    }



    ui->identifiant->setText("admin");
    ui->password->setText("admin2000@");

    load_server();


}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{


   /*QNetworkAccessManager * mgr = new QNetworkAccessManager(this);
   connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(onfinish(QNetworkReply*)));
   connect(mgr,SIGNAL(finished(QNetworkReply*)),mgr,SLOT(deleteLater()));
   mgr->get(QNetworkRequest(QUrl("http://127.0.0.1/db/saving.php")));
   return;*/





    ui->alerte->setText("");
    QString identifiant=ui->identifiant->text();
    QString password=ui->password->text();

    if(identifiant.isEmpty() || password.isEmpty()){
        ui->alerte->setText("certains champs sont vides");
        return;
    }


    ui->pushButton->setStyleSheet("background-color:silver;padding:8px;border:none;color:black");

    ui->pushButton->setEnabled(false);
    ui->pushButton->setText("Patientez...");
    ui->alerte->setText("Connexion en cours...");
    ui->serveur_distant->setEnabled(false);

    QSqlQuery qr;
    qr.exec("select * from users where login='"+identifiant+"' and password='"+password+"'");
    if(qr.next()){

        QString id_user=qr.value("token_id").toString();
        QString pv=qr.value("point_vente").toString();


        if(db.userName()!="root"){
            close_db();
            qDebug()<<"we are online with"<<id_user<<pv;
            db=QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("127.0.0.1");
            db.setUserName("root");
            db.setDatabaseName("base");
            db.setPassword("");
            if(db.open()){
                qDebug()<<"Local server is up";
            }

        }

        QSqlQuery qr2;
        qr2.exec("delete from user");
        qr2.exec("insert into user values('"+id_user+"','"+pv+"')");
        //qDebug()<<"insert into user values('"+id_user+"')";



        this->close();
        if(db.userName()=="root"){
            qDebug()<<"local ooura";

            MainWindow *m=new MainWindow(db,id_user);
            m->showMaximized();
            //QDesktopServices::openUrl(QUrl("http://localhost/db/saving.php"));
        }else{
            qDebug()<<"online oura";
            Loading *loading=new Loading(db,id_user,false,this);
            loading->show();
        }


      //  this->close();

    }else{
       ui->alerte->setText("Identifiants erronés");
       ui->pushButton->setText("Valider");
       ui->pushButton->setEnabled(true);
       ui->pushButton->setStyleSheet("background-color:white;padding:8px;border:none;color:black");
       ui->serveur_distant->setEnabled(true);
    }








}

void Login::onfinish(QNetworkReply *rep)
{
    QByteArray bts = rep->readAll();
    QString str(bts);
    qDebug()<<"from server update"<<str;

}

void Login::on_identifiant_textChanged(const QString &arg1)
{
    ui->alerte->setText("");
}

void Login::on_password_textChanged(const QString &arg1)
{
    ui->alerte->setText("");
}

void Login::on_serveur_distant_clicked()
{

    ui->alerte->setText("");
    close_db();
    QFile config("serveur.txt");
    config.open(QIODevice::WriteOnly);
    QTextStream stream(&config);


    if(ui->serveur_distant->isChecked()){
        db=QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("141.136.39.52");
        db.setUserName("assitcha_star_grace");
        db.setDatabaseName("assitcha_star_grace");
        db.setPassword("faugan2000@");
        if(db.open()){
            qDebug()<<"Remove server is up";
            stream<<0;
            config.close();
        }
    }else{
        db=QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("127.0.0.1");
        db.setUserName("root");
        db.setDatabaseName("base");
        db.setPassword("");
        if(db.open()){
            qDebug()<<"Local server is up";
            stream<<0;
            config.close();
        }
    }

}

void Login::close_db()
{
    QSqlDatabase::removeDatabase("QMYSQL");
    QString connection;
    connection=db.connectionName();
    db.close();
    db=QSqlDatabase();
    db.removeDatabase(connection);
}

void Login::load_server()
{
    QFile server("serveur.txt");
    if(!server.exists()){
        qDebug()<<"ok dakor server.txt does not exist";
        ui->serveur_distant->setChecked(false);
        return;
    }
    server.open(QIODevice::ReadOnly);
    QTextStream stream(&server);
    QString local_server=stream.readLine();
    server.close();
    if(local_server=="0"){
       // ui->serveur_distant->setChecked(false);
        qDebug()<<"serveur loacal is up";
    }else{
        //ui->serveur_distant->setChecked(true);
        qDebug()<<"serveur distant is up";
    }
}
