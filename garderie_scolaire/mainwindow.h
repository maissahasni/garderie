#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts>

#include "eleve.h"
#include "enseignant.h"
#include "authentification.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_log_in_clicked();

    void on_logout_menu_clicked();

    void on_forget_clicked();

    void on_button_EN_clicked();


    void on_ajouter_clicked();

    void on_modifier_clicked();

    void on_supprimer_clicked();

    void on_button_UT_clicked();

    void on_ajouter_2_clicked();

    void on_button_EL_clicked();

    void on_modifier_2_clicked();

    void on_supprimer_2_clicked();


    void on_ajouter_3_clicked();

    void on_supprimer_3_clicked();

    void on_modifier_3_clicked();

    void on_logout_eleve_clicked();

    void on_logout_ens_clicked();

    void on_logout_ens_2_clicked();

    void on_return_1_clicked();

    void on_return_2_clicked();

    void on_return_3_clicked();

    void on_button_stats_clicked();

    void on_refresh_stats_clicked();

    void on_button_stats_2_clicked();

    void on_refresh_stats_2_clicked();

    void on_PDF_el_clicked();

    void on_PDF_en_clicked();

    void on_PDF_ut_clicked();

    void on_recherche_el_returnPressed();

    void on_recherche_en_returnPressed();

    void on_recherche_ut_returnPressed();

    void on_combo_el_currentIndexChanged(const QString &choix_el);

    void on_combo_en_currentIndexChanged(const QString &choix_en);

    void on_combo_ut_currentIndexChanged(const QString &choix_ut);

private:
    Ui::MainWindow *ui;

    QChart *chart;

    ELEVE E;
    enseignant en;
    authentification A;
};
#endif // MAINWINDOW_H
