#include "impaye.h"
#include "ui_impaye.h"

Impaye::Impaye(float total,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Impaye)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

    ui->montant_facture->setText("Total Facture : "+QString::number(total));
    this->total=total;

    QSqlQuery qr;
    QString montant="";
    qr.exec("select * from impaye");
    if(qr.next()){
        montant=qr.value("montant").toString();
    }
    ui->a_payer->setText(montant);
}

Impaye::~Impaye()
{
    delete ui;
}

void Impaye::on_pushButton_clicked()
{
    QString a_payer=ui->a_payer->text();
    if(a_payer.isEmpty()){
        QMessageBox::warning(this,"Erreur","Renseignez le montant à regler");
        return;
    }

    QSqlQuery qr;
    qr.exec("delete from impaye");
    qr.prepare("insert into impaye(total,montant,reste) values(:total,:montant,:reste)");
    qr.bindValue(":total",QString::number(total));
    qr.bindValue(":montant",ui->a_payer->text());
    qr.bindValue(":reste",ui->reste->text());
    if(qr.exec()){
        this->close();
    }else{
        QMessageBox::warning(this,"Erreur","Une erreur est survenue");
    }

}

void Impaye::on_a_payer_textChanged(const QString &arg1)
{
    if(arg1.isEmpty()){
        ui->reste->clear();
        return;
    }
    float montant=arg1.toFloat();
    float reste=total-montant;
    ui->reste->setText(QString::number(reste));
}
