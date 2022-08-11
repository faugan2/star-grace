#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

QString Dialog::get_printing_headers()
{
   /* info2+="<h2>Reçu de paiement N° 5685<span>"+espace(15)+d.currentDate().toString("dd MMM yyyy")+"</span></h2>";
    info2+="<div>Ministère de la santé</div>";
    info2+="<div>Direction préfectorale "+espace(60)+"<span>"+nom_centre+"</span> "+espace(60)+"</div>";
    info2+="<div>"+espace(100)+"Tel: "+tel+"</div><br>";
    info2+="<div>Profession: "+current_pat_prof+espace(60)+"Caissier: "+caissier+"</div>";
    info2+="<div>Patient: "+current_pat_nom+" "+current_pat_prenom+"</div>";
    info2+="<div>"+espace(180)+"Age: "+current_pat_age+espace(20)+"Sex: "+current_pat_sex+"</div><br>";*/
}
