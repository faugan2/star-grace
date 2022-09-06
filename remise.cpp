#include "remise.h"
#include "ui_remise.h"

Remise::Remise(float total,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Remise)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    this->total=total;

    ui->montant_facture->setText("Total Facture = "+QString::number(total));
    QSqlQuery qr;
    qr.exec("select * from remise");
    if(qr.next()){
        QString remise=qr.value("montant").toString();
        ui->a_payer->setText(remise);
    }else{
        ui->a_payer->setText("");
    }
}

Remise::~Remise()
{
    delete ui;
}

void Remise::on_a_payer_textChanged(const QString &arg1)
{
    if(arg1.isEmpty()){
        ui->reste->clear();
        return;
    }
    float montant=arg1.toFloat();
    float reste=total-montant;
    ui->reste->setText(QString::number(reste));
}

void Remise::on_pushButton_clicked()
{
    QString a_payer=ui->a_payer->text();
    if(a_payer.isEmpty()){
        QMessageBox::warning(this,"Erreur","Renseignez le montant à regler");
        return;
    }

    QSqlQuery qr;
    qr.exec("delete from remise");
    qr.prepare("insert into remise(total,montant,reste) values(:total,:montant,:reste)");
    qr.bindValue(":total",QString::number(total));
    qr.bindValue(":montant",ui->a_payer->text());
    qr.bindValue(":reste",ui->reste->text());
    if(qr.exec()){
        this->close();
    }else{
        QMessageBox::warning(this,"Erreur","Une erreur est survenue");
    }
}
