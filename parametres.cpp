#include "parametres.h"
#include "ui_parametres.h"

Parametres::Parametres(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Parametres)
{
    ui->setupUi(this);
     setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

     QSqlQuery qr;
     qr.exec("select * from entete");
     if(qr.next()){
         QString ets=qr.value("ets").toString();
         QString titre1=qr.value("titre1").toString();
         QString titre2=qr.value("titre2").toString();
         QString titre3=qr.value("titre3").toString();
         QString titre4=qr.value("titre4").toString();
         QString titre5=qr.value("titre5").toString();

         ui->ets->setText(ets);
         ui->titre1->setText(titre1);
         ui->titre2->setText(titre2);
         ui->titre3->setText(titre3);
         ui->titre4->setText(titre4);
         ui->titre5->setText(titre5);
     }

     qr.exec("select * from print_config");
     QString papier="1";
     QString format="1";
     QString banner="0";
     if(qr.next()){
         papier=qr.value("papier").toString();
         format=qr.value("format").toString();
         banner=qr.value("banner").toString();
     }

    if(papier=="1"){
        ui->radioButton->setChecked(true);
    }else{
        ui->radioButton_2->setChecked(true);
    }

    if(format=="1"){
        ui->radioButton_4->setChecked(true);
    }else{
        ui->radioButton_3->setChecked(true);
    }

    if(banner=="1"){
        ui->checkBox->setChecked(true);
        QPixmap logo("./banner.jpg");
        QPixmap newPixmap = logo.scaled(QSize(150,300),  Qt::KeepAspectRatio);
        ui->label_banner->setPixmap(newPixmap);
        ui->label_banner->show();

    }else{
        ui->checkBox->setChecked(false);
        ui->label_banner->hide();

    }

}

Parametres::~Parametres()
{
    delete ui;
}

void Parametres::on_pushButton_clicked()
{
    QString ets=ui->ets->text();
    QString titre1=ui->titre1->text();
    QString titre2=ui->titre2->text();
    QString titre3=ui->titre3->text();
    QString titre4=ui->titre4->text();
    QString titre5=ui->titre5->text();

    if(ets.isEmpty() || titre1.isEmpty() || titre2.isEmpty() || titre3.isEmpty() || titre4.isEmpty() || titre5.isEmpty()){
        QMessageBox::warning(this,"Erreur","Certains champs ne sont pas renseignés");
        return;
    }
    QSqlQuery qr;
    qr.exec("delete from entete");
    qr.prepare("insert into entete(ets,titre1,titre2,titre3,titre4,titre5) values(:ets,:titre1,:titre2,:titre3,:titre4,:titre5)");
    qr.bindValue(":ets",ets);
    qr.bindValue(":titre1",titre1);
    qr.bindValue(":titre2",titre2);
    qr.bindValue(":titre3",titre3);
    qr.bindValue(":titre4",titre4);
    qr.bindValue(":titre5",titre5);
    if(qr.exec()){
        QMessageBox::information(this,"Success","Informations bien sauvegardées");
    }else{
        QMessageBox::warning(this,"Erreur","Une erreur est survenue");
    }
}

void Parametres::on_radioButton_clicked()
{
    QSqlQuery qr;
    qr.exec("update print_config set papier='1'");
}

void Parametres::on_radioButton_2_clicked()
{
    QSqlQuery qr;
    qr.exec("update print_config set papier='2'");
}

void Parametres::on_radioButton_4_clicked()
{
    QSqlQuery qr;
    qr.exec("update print_config set format='1'");
}

void Parametres::on_radioButton_3_clicked()
{
    QSqlQuery qr;
    qr.exec("update print_config set format='2'");
}

void Parametres::on_checkBox_clicked()
{
    QSqlQuery qr;
    if(ui->checkBox->isChecked()){
        QImage image();
        //image.fill(Qt::red); // A red rectangle.
        QString fileName  = QFileDialog::getOpenFileName(this,
                                                         tr("Selectionner une bannière"), ".",
                                                         tr("Fichiers Image (*.jpg *.jpeg )")
                                                         );
        if (!fileName.isEmpty())
        {
         // image.save(fileName);
            QImage pixmap(fileName);
            QFile f("banner.jpg");
            if(f.open(QIODevice::WriteOnly)){
                if(pixmap.save(&f, "JPG")){
                    qr.exec("update print_config set banner='1', image='banner.jpg'");
                    ui->checkBox->setChecked(true);
                    QPixmap logo("./banner.jpg");
                    QPixmap newPixmap = logo.scaled(QSize(150,300),  Qt::KeepAspectRatio);
                    ui->label_banner->setPixmap(newPixmap);
                    ui->label_banner->show();
                }else{
                  QMessageBox::warning(this,"Erreur","Une erreur est intervenue lors de l'enregistrement");
                }

            }else{
                QMessageBox::warning(this,"Erreur","Une erreur est intervenue lors de l'enregistrement");
            }

        }

    }else{
        qr.exec("update print_config set banner='0', image=''");
        ui->checkBox->setChecked(false);
        ui->label_banner->hide();
    }
}
