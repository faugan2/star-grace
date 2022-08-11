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
    db=QSqlDatabase::addDatabase("QMYSQL");

    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setDatabaseName("base");
    db.setPassword("");

   // db.setPassword("admin");
    db.open();

    if(db.open()){
        qDebug()<<"Le serveur est bien démarré";

    }else{
       qDebug()<<"erreur de connexion";
    }

    ui->identifiant->setText("admin");
    ui->password->setText("admin2000@");
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{


   /* QNetworkAccessManager * mgr = new QNetworkAccessManager(this);
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(onfinish(QNetworkReply*)));
    connect(mgr,SIGNAL(finished(QNetworkReply*)),mgr,SLOT(deleteLater()));

    mgr->get(QNetworkRequest(QUrl("https://ongadesco.org/test.php")));

    return;*/





    ui->alerte->setText("");
    QString identifiant=ui->identifiant->text();
    QString password=ui->password->text();

    if(identifiant.isEmpty() || password.isEmpty()){
        ui->alerte->setText("certains champs sont vides");
        return;
    }

    ui->pushButton->setEnabled(false);
    ui->pushButton->setText("Patientez...");
    QSqlQuery qr;
    qr.exec("select * from users where login='"+identifiant+"' and password='"+password+"'");
    if(qr.next()){
        this->hide();
        QString id_user=qr.value("id").toString();
        QString pv=qr.value("point_vente").toString();
        QSqlQuery qr2;
        qr2.exec("delete from user");
        qr2.exec("insert into user values('"+id_user+"','"+pv+"')");
        //qDebug()<<"insert into user values('"+id_user+"')";

        m=new MainWindow(db,id_user);
        m->showMaximized();
    }else{
       ui->alerte->setText("Identifiants erronés");
       ui->pushButton->setText("Valider");
       ui->pushButton->setEnabled(true);
    }








}

void Login::onfinish(QNetworkReply *rep)
{
    QByteArray bts = rep->readAll();
    QString str(bts);
    QMessageBox::information(this,"sal",str,"ok");

}

void Login::on_identifiant_textChanged(const QString &arg1)
{
    ui->alerte->setText("");
}

void Login::on_password_textChanged(const QString &arg1)
{
    ui->alerte->setText("");
}
