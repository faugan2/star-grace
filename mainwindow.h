#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "includes.h"
#include "ajouterpointdevente.h"
#include "listeusers.h"
#include "listpointvente.h"
#include "listclients.h"
#include "transfertproduits.h"
#include "depenses.h"
#include "bris.h"
#include "retrait.h"
#include "infoclient.h"
#include "infostockalerte.h"
#include "infopointdevente.h"
#include "listformat.h"
#include "ajoutcarreaux.h"
#include "ajoutautres.h"
#include "dialog.h"
#include "biz.h"
#include "remise.h"
#include "parametres.h"
#include "impaye.h"
#include "detailsvente.h"
#include "allimpayes.h"
#include "allsa.h"
#include "allprepayement.h"
#include "bon.h"
#include "facture.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QSqlDatabase db, QString id_user, QWidget *parent = 0);
    ~MainWindow();

private slots:
    //void on_pushButton_clicked();

    void on_actionFermer_triggered();

    void on_actionDeconnexion_triggered();

    void on_produits_currentIndexChanged(int index);

    void make_vente_calculation();

    void on_qte_textChanged(const QString &arg1);

    void on_pu_textChanged(const QString &arg1);

    void on_pushButton_3_clicked();

    void load_points_vente();
    void load_users();

    void on_pushButton_9_clicked();

    void on_actionListe_des_utilisateurs_triggered();

    void on_actionListe_des_points_de_vente_triggered();

    void on_actionListe_des_clients_triggered();

    void on_toolButton_12_clicked();

    void on_toolButton_13_clicked();

    void on_toolButton_10_clicked();

    void on_toolButton_11_clicked();
    void point_vente_clicked(QString id);

    void load_stock_alerte();
    void load_client_impaye();
    void load_client_pre_paye();
    void load_produits();
    void load_clients();
    void load_formats();

    void carreaux_settings();

    void stock_alerte_clicked(QString id);
    void client_impaye_clicked(QString id);
    void client_pre_paye_clicked(QString id);
    void view_all_clients_impaye(QString id);


    void on_actionCat_gories_triggered();

    void on_actionAjouter_triggered();

    void on_actionAutres_produits_triggered();



    void on_pushButton_6_clicked();
    QString espace(int);

    void on_pushButton_10_clicked();

    void on_pushButton_clicked();

    void on_produits_currentIndexChanged(const QString &arg1);

    void on_produits_currentTextChanged(const QString &arg1);

    void load_user_info();
    void load_inventaire();

    void on_inventaire_type_currentIndexChanged(int index);

    void on_inventaire_point_vente_currentIndexChanged(int index);

    void on_inventaire_utilisateurs_currentIndexChanged(int index);

    void on_inventaire_format_currentIndexChanged(int index);

    void on_inventaire_du_2_dateChanged(const QDate &date);

    void on_inventaire_au_dateChanged(const QDate &date);

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_actionParametres_triggered();

    void on_actionParam_tres_triggered();

    void on_pushButton_11_clicked();

    void on_pushButton_4_clicked();

    void load_recette();

    void on_table_recette_cellClicked(int row, int column);
    void view_all_sa();

    void on_actionClients_avec_impay_s_triggered();

    void on_actionClients_avec_pr_payements_triggered();

    void on_actionAlertes_triggered();

    void on_date_recette_dateChanged(const QDate &date);

    void on_utilisateur_recette_currentIndexChanged(int index);

    void load_droit();


    void on_bon_clicked();

public:
    void print_facture(QString token);
private:
    Ui::MainWindow *ui;
    AjouterPointDeVente *ajout_point_vente;
    ListeUsers * list_users;
    listpointvente *list_point_vente;
    listclients *list_clients;
    TransfertProduits *transfert_produit;
    Depenses *depenses;
    Bris *bris;
    Retrait *retrait;
    InfoClient *info_client;
    InfoStockAlerte *info_stock_alerte;
    InfoPointDeVente *info_point_vente;
    Listformat *list_format;
    AjoutCarreaux *ajout_carreaux;
    AjoutAutres *ajout_autres;
    Biz *biz;
    Remise *remise;
    Parametres *parametres;
    Impaye *impaye;
    DetailsVente *details_vente;
    AllImpayes *all_impayes;
    AllSa *all_sa;
    AllPrePayement *all_pre_payement;
    Facture *facture;
    Bon *bon;



     QStringList formats;
     QStringList pieces_par_m2;
     QStringList pieces_par_cartons;
     QStringList dimensions;
     QSqlDatabase db;
     QString id_user;
     QStringList user_info;

     //vente
     QStringList vente_produit;
     QStringList vente_produit_format;
     QStringList vente_qte;
     QStringList vente_qte_m2;
     QStringList vente_pu;
     QStringList vente_total;
     QStringList vente_carton;
     QString vente_client;
     bool can_update_combobox;

};

#endif // MAINWINDOW_H
