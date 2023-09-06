#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "eleve.h"
#include "enseignant.h"
#include "authentification.h"

#include "QMessageBox"
#include <QPdfWriter>
#include <QDesktopServices>
#include <QPainter>
#include <QSqlQuery>
#include <QUrl>
#include <QFileDialog>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkAccessManager>
#include <QUrlQuery>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QtNetwork>
#include <QTextDocument>
#include <QInputDialog>
#include <QSqlError>
#include <QTableWidgetItem>
#include <QStandardItem>
#include <QtCharts>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSlice>
#include <QtCharts/QBarSeries>
#include <QSqlTableModel>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Appel à ELEVE::afficher() pour initialiser les données dans le tableau
    ui->Donnees->setModel(E.afficher());
    //ui->Donnees->resizeColumnsToContents();
    ui->Donnees->horizontalHeader()->setStretchLastSection(true);
    ui->Donnees_EN->setModel(en.afficher());
    //ui->Donnees_EN->resizeColumnsToContents();
    ui->Donnees_EN->horizontalHeader()->setStretchLastSection(true);
    ui->Donnees_UT->setModel(A.afficher());
    //ui->Donnees_UT->resizeColumnsToContents();
    ui->Donnees_UT->horizontalHeader()->setStretchLastSection(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_log_in_clicked()
{
    QString username = ui->lineEdit_username->text();
        QString password = ui->lineEdit_password->text();

        QSqlQuery query;
        query.prepare("SELECT * FROM AUTH WHERE username = ?");
        query.addBindValue(username);

        if (query.exec() && query.next()) {
            QString usernameFromDatabase = query.value("username").toString();
            QString passwordFromDatabase = query.value("password").toString();

            if (password == passwordFromDatabase) {
                if (usernameFromDatabase.endsWith("_el")) {
                    ui->stackedWidget->setCurrentIndex(1); // Page 1

                    // Enable the EL button and disable the others
                    ui->button_EL->setEnabled(true);
                    ui->button_EN->setEnabled(false);
                    ui->button_UT->setEnabled(false);
                    ui->return_1->setVisible(false);
                    ui->return_2->setVisible(false);
                    ui->return_3->setVisible(false);

                } else if (usernameFromDatabase.endsWith("_en")) {
                    ui->stackedWidget->setCurrentIndex(1); // Page 2

                    // Enable the EN button and disable the others
                    ui->button_EL->setEnabled(false);
                    ui->button_EN->setEnabled(true);
                    ui->button_UT->setEnabled(false);
                    ui->return_1->setVisible(false);
                    ui->return_2->setVisible(false);
                    ui->return_3->setVisible(false);

                } else if (usernameFromDatabase == "admin") {
                    ui->stackedWidget->setCurrentIndex(1); // Page 3

                } else {
                    QMessageBox::warning(this, "Erreur", "Nom d'utilisateur inconnu");
                }
            } else {
                QMessageBox::warning(this, "Erreur", "Mot de passe incorrect");
            }
        } else {
            QMessageBox::critical(this, "Erreur", "Erreur lors de la vérification du nom d'utilisateur");
        }
}

void MainWindow::on_logout_menu_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_forget_clicked()
{
    // Affiche une boîte de dialogue pour saisir le nom d'utilisateur
    QString username = QInputDialog::getText(this, tr("Changer le mot de passe"), tr("Nom d'utilisateur :"), QLineEdit::Normal);

    // Vérifie si le nom d'utilisateur existe dans la base de données
    QSqlQuery query;
    query.prepare("SELECT username, password FROM AUTH WHERE username = :username");
    query.bindValue(":username", username);

    if (!query.exec() || !query.next()) {
        QMessageBox::critical(nullptr, tr("Erreur d'AUTH"),
                              tr("Nom d'utilisateur incorrect ou inexistant dans la base de données"), QMessageBox::Cancel);
        return;
    }

    // Affiche une boîte de dialogue pour saisir le nouveau mot de passe
    QString newPassword = QInputDialog::getText(this, tr("Changer le mot de passe"), tr("Nouveau mot de passe :"), QLineEdit::Normal);

    //##################################- NEW PASSWORD CONTROL DE SAISIE -#############################################


    // Vérifier la longueur minimale du mot de passe
    if (newPassword.length() < 8) {
        QMessageBox::warning(this, "Erreur", "Le nouveau mot de passe doit contenir au moins 8 caractères !");
        return;
    }

    // Vérifier s'il y a au moins un chiffre
    bool containsDigit = false;
    for (QChar c : newPassword) {
        if (c.isDigit()) {
            containsDigit = true;
            break;
        }
    }

    if (!containsDigit) {
        QMessageBox::warning(this, "Erreur", "Le nouveau mot de passe doit contenir au moins un chiffre !");
        return;
    }

    // Vérifier s'il y a au moins une lettre minuscule
    bool containsLowercase = false;
    for (QChar c : newPassword) {
        if (c.isLower()) {
            containsLowercase = true;
            break;
        }
    }

    if (!containsLowercase) {
        QMessageBox::warning(this, "Erreur", "Le nouveau mot de passe doit contenir au moins une lettre minuscule !");
        return;
    }

    // Vérifier s'il y a au moins une lettre majuscule
    bool containsUppercase = false;
    for (QChar c : newPassword) {
        if (c.isUpper()) {
            containsUppercase = true;
            break;
        }
    }

    if (!containsUppercase) {
        QMessageBox::warning(this, "Erreur", "Le nouveau mot de passe doit contenir au moins une lettre majuscule !");
        return;
    }

    // Vérifier s'il y a au moins un caractère spécial (par exemple, !@#$%^&*)
    bool containsSpecialChar = false;
    for (QChar c : newPassword) {
        if (!c.isLetterOrNumber()) {
            containsSpecialChar = true;
            break;
        }
    }

    if (!containsSpecialChar) {
        QMessageBox::warning(this, "Erreur", "Le nouveau mot de passe doit contenir au moins un caractère spécial !");
        return;
    }



    // Met à jour le mot de passe dans la base de données
    query.prepare("UPDATE AUTH SET password = :newPassword WHERE username = :username");
    query.bindValue(":newPassword", newPassword);
    query.bindValue(":username", username);

    if (!query.exec()) {
        QMessageBox::critical(nullptr, tr("Erreur de mise à jour du mot de passe"),
                              tr("Impossible de mettre à jour le mot de passe dans la base de données"), QMessageBox::Cancel);
        return;
    }

    // Enregistre le nouveau mot de passe et le nom d'utilisateur dans un fichier texte sur le bureau
    QString filePath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation) + "/nouveau_mot_de_passe_reset.txt";
    QFile file(filePath);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(nullptr, tr("Erreur d'écriture dans le fichier"),
                              tr("Impossible d'écrire dans le fichier sur le bureau"), QMessageBox::Cancel);
        return;
    }

    QTextStream out(&file);
    out << "Nom d'utilisateur : " << username << "\n";
    out << "Nouveau mot de passe : " << newPassword;

    file.close();

    QMessageBox::information(nullptr, tr("Mot de passe mis à jour"),
                             tr("Le mot de passe a été mis à jour avec succès"), QMessageBox::Ok);
}

void MainWindow::on_button_EL_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->Donnees->setModel(E.afficher());
    //ui->Donnees->resizeColumnsToContents();
    ui->Donnees->horizontalHeader()->setStretchLastSection(true);
}

void MainWindow::on_ajouter_clicked()
{
    int id_el = ui->le_id->text().toInt();

        // Vérifier que tous les champs sont remplis
        if (ui->le_date->text().isEmpty() || ui->le_age->text().isEmpty() ||
            ui->le_nom->text().isEmpty() || ui->le_prenom->text().isEmpty() ||
            ui->le_classe->text().isEmpty()) {
            QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs !");
            return;
        }
        QString nom = ui->le_nom->text();
        QString prenom = ui->le_prenom->text();
        QDate naissance = ui->le_date->date();
        int age = ui->le_age->text().toInt();
        if (age < 3 || age > 18) {
            QMessageBox::warning(this, "Erreur", "L'âge doit être compris entre 3 et 18 inclusivement !");
            return;
        }
        QString classe = ui->le_classe->text();

        // Vérifier si l'identifiant existe déjà dans la base de données
        QSqlQuery verif_query;
        verif_query.prepare("SELECT COUNT(*) FROM ELEVE WHERE id_el = :id_el");
        verif_query.bindValue(":id_el", id_el);
        verif_query.exec();
        verif_query.next();
        int id_count = verif_query.value(0).toInt();

        if (id_count > 0) {
            QMessageBox::warning(this, "Erreur", "L'identifiant est déjà utilisé !");
            return;
        }

        ELEVE E(id_el, nom, prenom, naissance, age, classe);

        bool test = E.ajouter();
        if (test) {
            QMessageBox::information(this, "Succès", "Ajout réussi !");
            // Recharge les données après l'ajout
            ui->Donnees->setModel(E.afficher());
           // ui->Donnees->resizeColumnsToContents();
            ui->Donnees->horizontalHeader()->setStretchLastSection(true);
            stat();

        } else {
            QMessageBox::critical(this, "Erreur", "Ajout non effectué !");
        }

}

void MainWindow::on_modifier_clicked()
{

    int id_el = ui->le_id->text().toInt();



        // Vérifier que tous les champs sont remplis
        if (ui->le_date->text().isEmpty() || ui->le_age->text().isEmpty() ||
            ui->le_nom->text().isEmpty() || ui->le_prenom->text().isEmpty() ||
            ui->le_classe->text().isEmpty()) {
            QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs !");
            return;
        }
        QString nom = ui->le_nom->text();
        QString prenom = ui->le_prenom->text();
        QDate naissance = ui->le_date->date();
        int age = ui->le_age->text().toInt();

        if (age < 3 || age > 18) {
                QMessageBox::warning(this, "Erreur", "L'âge doit être compris entre 3 et 18 inclusivement !");
                return;
            }

        QString classe = ui->le_classe->text();

        ELEVE E(id_el, nom, prenom, naissance, age, classe);


     bool test=E.modifier(id_el, nom, prenom, naissance, age, classe);
     if(test)
     {ui->Donnees->setModel(E.afficher());
         //ui->Donnees->resizeColumnsToContents();
         ui->Donnees->horizontalHeader()->setStretchLastSection(true);
         stat();
         QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("modif successful.\n"
                                             "click OK to continue."),QMessageBox::Ok);

     }
     else QMessageBox::critical(nullptr, QObject::tr(" not OK"),
                                   QObject::tr("modif non effectue.\n"
                                               "click cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_supprimer_clicked()
{
    // Récupère la ligne sélectionnée dans le tableau
        int row = ui->Donnees->currentIndex().row();

        // Vérifie si une ligne est sélectionnée
        if (row < 0) {
            QMessageBox::warning(this, "Avertissement", "Veuillez sélectionner une ligne à supprimer.");
            return;
        }

        // Récupère l'ID de l'enregistrement sélectionné dans le tableau
        int id = ui->Donnees->model()->data(ui->Donnees->model()->index(row, 0)).toInt();


        // Affiche un message de confirmation demandant à l'utilisateur s'il est sûr de vouloir supprimer les informations de l'enregistrement sélectionné
        QMessageBox msgbox;
        msgbox.setText("Voulez-vous vraiment supprimer ces informations ?");
        msgbox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgbox.setDefaultButton(QMessageBox::No);
        int res = msgbox.exec();

        // Si l'utilisateur confirme la suppression, crée un objet Donataire et appelle la fonction "supprimer" pour supprimer l'enregistrement correspondant
        if (res == QMessageBox::Yes) {
            ELEVE E1;
            E1.setId(id);
            bool test = E1.supprimer(E1.getId());

            // Affiche un message de succès ou d'échec
            if(test) {
                QMessageBox::information(this, "Succès", "Suppression avec succès");
                ui->Donnees->setModel(E1.afficher());
                //ui->Donnees->resizeColumnsToContents();
                ui->Donnees->horizontalHeader()->setStretchLastSection(true);

            } else {
                QMessageBox::warning(this, "Échec", "Échec de suppression");
            }
        }
}

void MainWindow::on_button_UT_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    ui->Donnees_UT->setModel(A.afficher());
    //ui->Donnees_UT->resizeColumnsToContents();
    ui->Donnees_UT->horizontalHeader()->setStretchLastSection(true);


}

void MainWindow::on_ajouter_2_clicked()
{
    int id_en = ui->le_id_2->text().toInt();

        // Vérifier que tous les champs sont remplis
        if (ui->le_date_2->text().isEmpty() || ui->le_tel->text().isEmpty() ||
            ui->le_nom_2->text().isEmpty() || ui->le_prenom_2->text().isEmpty() || ui->le_spec->text().isEmpty() ||
            ui->le_email->text().isEmpty()) {
            QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs !");
            return;
        }
        QString nom = ui->le_nom_2->text();
        QString prenom = ui->le_prenom_2->text();
        QDate date_e = ui->le_date_2->date();
        QString specialite = ui->le_spec->text();
        int telephone = ui->le_tel->text().toInt();

        // controle saisie le tel 8 chiffres bedhabt
        //###############################################

        int nombreChiffres = 0;
        int temp = telephone;

        while (temp != 0) {
            temp /= 10;
            nombreChiffres++;
        }

        if (nombreChiffres != 8) {
            QMessageBox::warning(this, "Erreur", "Le numéro de téléphone doit contenir exactement 8 chiffres !");
            return;
        }

        //################################################


        QString email = ui->le_email->text();

        // Définir une expression régulière pour valider l'adresse e-mail
        QRegularExpression regex("^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,4}$");

        if (!regex.match(email).hasMatch()) {
            QMessageBox::warning(this, "Erreur", "L'adresse e-mail n'est pas valide. Elle doit être au format \"@anything.anything\".");
            return;
        }


        // Vérifier si l'identifiant existe déjà dans la base de données
        QSqlQuery verif_query;
        verif_query.prepare("SELECT COUNT(*) FROM ENSEIGNANT WHERE id_en = :id_en");
        verif_query.bindValue(":id_en", id_en);
        verif_query.exec();
        verif_query.next();
        int id_count = verif_query.value(0).toInt();

        if (id_count > 0) {
            QMessageBox::warning(this, "Erreur", "L'identifiant est déjà utilisé !");
            return;
        }

        enseignant en(id_en, nom, prenom, date_e, specialite, telephone, email);

        bool test = en.ajouter();
        if (test) {
            QMessageBox::information(this, "Succès", "Ajout réussi !");
            // Recharge les données après l'ajout
            ui->Donnees_EN->setModel(en.afficher());
           // ui->Donnees_EN->resizeColumnsToContents();
            ui->Donnees_EN->horizontalHeader()->setStretchLastSection(true);
            stat();
        } else {
            QMessageBox::critical(this, "Erreur", "Ajout non effectué !");
        }
}


void MainWindow::on_modifier_2_clicked()
{
    int id_en = ui->le_id_2->text().toInt();

        // Vérifier que tous les champs sont remplis
        if (ui->le_date_2->text().isEmpty() || ui->le_tel->text().isEmpty() ||
            ui->le_nom_2->text().isEmpty() || ui->le_prenom_2->text().isEmpty() || ui->le_spec->text().isEmpty() ||
            ui->le_email->text().isEmpty()) {
            QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs !");
            return;
        }
        QString nom = ui->le_nom_2->text();
        QString prenom = ui->le_prenom_2->text();
        QDate date_e = ui->le_date_2->date();
        QString specialite = ui->le_prenom_2->text();
        int telephone = ui->le_tel->text().toInt();
        // controle saisie le tel 8 chiffres bedhabt
        //###############################################

        int nombreChiffres = 0;
        int temp = telephone;

        while (temp != 0) {
            temp /= 10;
            nombreChiffres++;
        }

        if (nombreChiffres != 8) {
            QMessageBox::warning(this, "Erreur", "Le numéro de téléphone doit contenir exactement 8 chiffres !");
            return;
        }

        //################################################
        QString email = ui->le_email->text();
        // Définir une expression régulière pour valider l'adresse e-mail
        QRegularExpression regex("^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,4}$");

        if (!regex.match(email).hasMatch()) {
            QMessageBox::warning(this, "Erreur", "L'adresse e-mail n'est pas valide. Elle doit être au format \"@anything.anything\".");
            return;
        }

        enseignant en(id_en, nom, prenom, date_e, specialite, telephone, email);


     bool test=en.modifier(id_en, nom, prenom, date_e, specialite, telephone, email);
     if(test)
     {ui->Donnees_EN->setModel(en.afficher());
         //ui->Donnees_EN->resizeColumnsToContents();
         ui->Donnees_EN->horizontalHeader()->setStretchLastSection(true);
         stat();
         QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("modif successful.\n"
                                             "click OK to continue."),QMessageBox::Ok);

     }
     else QMessageBox::critical(nullptr, QObject::tr(" not OK"),
                                   QObject::tr("modif non effectue.\n"
                                               "click cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_supprimer_2_clicked()
{
    // Récupère la ligne sélectionnée dans le tableau
        int row = ui->Donnees_EN->currentIndex().row();

        // Vérifie si une ligne est sélectionnée
        if (row < 0) {
            QMessageBox::warning(this, "Avertissement", "Veuillez sélectionner une ligne à supprimer.");
            return;
        }

        // Récupère l'ID de l'enregistrement sélectionné dans le tableau
        int id = ui->Donnees_EN->model()->data(ui->Donnees_EN->model()->index(row, 0)).toInt();


        // Affiche un message de confirmation demandant à l'utilisateur s'il est sûr de vouloir supprimer les informations de l'enregistrement sélectionné
        QMessageBox msgbox;
        msgbox.setText("Voulez-vous vraiment supprimer ces informations ?");
        msgbox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgbox.setDefaultButton(QMessageBox::No);
        int res = msgbox.exec();

        // Si l'utilisateur confirme la suppression, crée un objet Donataire et appelle la fonction "supprimer" pour supprimer l'enregistrement correspondant
        if (res == QMessageBox::Yes) {
            enseignant en1;
            en1.setIde(id);
            bool test = en1.supprimer(en1.getIde());

            // Affiche un message de succès ou d'échec
            if(test) {
                QMessageBox::information(this, "Succès", "Suppression avec succès");
                ui->Donnees_EN->setModel(en1.afficher());
               // ui->Donnees_EN->resizeColumnsToContents();
                ui->Donnees_EN->horizontalHeader()->setStretchLastSection(true);

            } else {
                QMessageBox::warning(this, "Échec", "Échec de suppression");
            }
        }
}

void MainWindow::on_ajouter_3_clicked()
{
    if (ui->le_user->text().isEmpty() || ui->le_pass->text().isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs !");
        return;
    }

    // Check if either radio button is selected
        if (!ui->radio_el->isChecked() && !ui->radio_en->isChecked()) {
            QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un Role (S.EL/S.EN) !");
            return;
        }

    QString username = ui->le_user->text();
    QString password = ui->le_pass->text();

    //############################################
    //control de saisie password
    // Vérifier la longueur minimale du mot de passe
    if (password.length() < 8) {
        QMessageBox::warning(this, "Erreur", "Le mot de passe doit contenir au moins 8 caractères !");
        return;
    }

    // Vérifier s'il y a au moins un chiffre
    bool containsDigit = false;
    for (QChar c : password) {
        if (c.isDigit()) {
            containsDigit = true;
            break;
        }
    }

    if (!containsDigit) {
        QMessageBox::warning(this, "Erreur", "Le mot de passe doit contenir au moins un chiffre !");
        return;
    }

    // Vérifier s'il y a au moins une lettre minuscule
    bool containsLowercase = false;
    for (QChar c : password) {
        if (c.isLower()) {
            containsLowercase = true;
            break;
        }
    }

    if (!containsLowercase) {
        QMessageBox::warning(this, "Erreur", "Le mot de passe doit contenir au moins une lettre minuscule !");
        return;
    }

    // Vérifier s'il y a au moins une lettre majuscule
    bool containsUppercase = false;
    for (QChar c : password) {
        if (c.isUpper()) {
            containsUppercase = true;
            break;
        }
    }

    if (!containsUppercase) {
        QMessageBox::warning(this, "Erreur", "Le mot de passe doit contenir au moins une lettre majuscule !");
        return;
    }


    if (ui->radio_el->isChecked()) {
            username += "_el";  // Add "_el" suffix to username
        } else if (ui->radio_en->isChecked()) {
            username += "_en";  // Add "_en" suffix to username
        }

    QSqlQuery verif_query;
    verif_query.prepare("SELECT COUNT(*) FROM AUTH WHERE username = :username");
    verif_query.bindValue(":username", username);
    verif_query.exec();
    verif_query.next();
    int id_count = verif_query.value(0).toInt();

    if (id_count > 0) {
        QMessageBox::warning(this, "Erreur", "Le username est déjà utilisé !");
        return;
    }



    authentification A(username,password);

    bool test = A.ajouter();
    if (test) {
        QMessageBox::information(this, "Succès", "Ajout réussi !");
        // Recharge les données après l'ajout
        ui->Donnees_UT->setModel(A.afficher());
        //ui->Donnees_UT->resizeColumnsToContents();
        ui->Donnees_UT->horizontalHeader()->setStretchLastSection(true);
        stat();
    } else {
        QMessageBox::critical(this, "Erreur", "Ajout non effectué !");
    }

}

void MainWindow::on_supprimer_3_clicked()
{// Retrieve the selected row in the table
    int row = ui->Donnees_UT->currentIndex().row();

    // Check if a row is selected
    if (row < 0) {
        QMessageBox::warning(this, "Avertissement", "Veuillez sélectionner une ligne à supprimer.");
        return;
    }

    // Retrieve the username of the selected record in the table
    QString username = ui->Donnees_UT->model()->data(ui->Donnees_UT->model()->index(row, 0)).toString();

    // Display a confirmation message asking the user if they are sure they want to delete the selected record's information
    QMessageBox msgbox;
    msgbox.setText("Voulez-vous vraiment supprimer ces informations ?");
    msgbox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgbox.setDefaultButton(QMessageBox::No);
    int res = msgbox.exec();

    // If the user confirms deletion, create an "Authentification" object and call the "supprimer" function to delete the corresponding record
    if (res == QMessageBox::Yes) {
        authentification A1;
        A1.setuser(username);
        bool test = A1.supprimer(A1.getuser());

        // Display a success or failure message
        if(test) {
            QMessageBox::information(this, "Succès", "Suppression avec succès");
            ui->Donnees_UT->setModel(A1.afficher());
            //ui->Donnees_UT->resizeColumnsToContents();
            ui->Donnees_UT->horizontalHeader()->setStretchLastSection(true);

        } else {
            QMessageBox::warning(this, "Échec", "Échec de suppression");
        }
    }
}

void MainWindow::on_modifier_3_clicked()
{
    QString username = ui->le_user->text(); // Assuming you have an input field for username
        QString password = ui->le_pass->text(); // Assuming you have an input field for password

        // Check if all fields are filled
        if (username.isEmpty() || password.isEmpty()) {
            QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs !");
            return;
        }

        authentification auth;
        auth.setuser(username);
        auth.setpass(password);

        bool test = auth.modifier(username, password);

        if (test) {
            ui->Donnees_UT->setModel(auth.afficher());
            //ui->Donnees_UT->resizeColumnsToContents();
            ui->Donnees_UT->horizontalHeader()->setStretchLastSection(true);
            QMessageBox::information(nullptr, QObject::tr("Succès"),
                                     QObject::tr("Modification réussie.\n"
                                                 "Cliquez sur OK pour continuer."),
                                     QMessageBox::Ok);
        } else {
            QMessageBox::critical(nullptr, QObject::tr("Échec"),
                                  QObject::tr("Échec de la modification.\n"
                                              "Cliquez sur Annuler pour quitter."),
                                  QMessageBox::Cancel);
        }
}

void MainWindow::on_button_EN_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->Donnees_EN->setModel(en.afficher());
    //ui->Donnees_EN->resizeColumnsToContents();
    ui->Donnees_EN->horizontalHeader()->setStretchLastSection(true);
}

void MainWindow::on_logout_eleve_clicked()
{
    // Afficher une boîte de dialogue de confirmation
        QMessageBox::StandardButton confirmLogout;
        confirmLogout = QMessageBox::question(this, "Confirmation", "Êtes-vous sûr de vouloir vous déconnecter ?",
                                              QMessageBox::Yes | QMessageBox::No);

        if (confirmLogout == QMessageBox::Yes) {
            // L'utilisateur a confirmé la déconnexion
            this->ui->stackedWidget->setCurrentIndex(0);
        }
        // Sinon, l'utilisateur a choisi de ne pas se déconnecter
}

void MainWindow::on_logout_ens_clicked()
{
    // Afficher une boîte de dialogue de confirmation
        QMessageBox::StandardButton confirmLogout;
        confirmLogout = QMessageBox::question(this, "Confirmation", "Êtes-vous sûr de vouloir vous déconnecter ?",
                                              QMessageBox::Yes | QMessageBox::No);

        if (confirmLogout == QMessageBox::Yes) {
            // L'utilisateur a confirmé la déconnexion
            this->ui->stackedWidget->setCurrentIndex(0);
        }
        // Sinon, l'utilisateur a choisi de ne pas se déconnecter
}

void MainWindow::on_logout_ens_2_clicked()
{
    // Afficher une boîte de dialogue de confirmation
        QMessageBox::StandardButton confirmLogout;
        confirmLogout = QMessageBox::question(this, "Confirmation", "Êtes-vous sûr de vouloir vous déconnecter ?",
                                              QMessageBox::Yes | QMessageBox::No);

        if (confirmLogout == QMessageBox::Yes) {
            // L'utilisateur a confirmé la déconnexion
            this->ui->stackedWidget->setCurrentIndex(0);
        }
        // Sinon, l'utilisateur a choisi de ne pas se déconnecter
}

void MainWindow::on_return_1_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_return_2_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_return_3_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_button_stats_clicked()
{
    // Create a chart object
              QChart *chart = new QChart();

              // Set the chart title
              chart->setTitle("Type de Classes");

              // Create a pie series and add it to the chart
              QPieSeries *series = new QPieSeries();

              // Query the database to get the data for the chart
              QSqlQuery query;
              query.prepare("SELECT CLASSE, COUNT(*) FROM ELEVE GROUP BY CLASSE");
              if(query.exec())
              {
                  int total = 0;
                  while(query.next())
                  {
                      // Get the type and count for the current row
                      QString type = query.value(0).toString();
                      int count = query.value(1).toInt();

                      // Add the type and count to the series
                      series->append(type, count);

                      // Increment the total count
                      total += count;
                  }

                  // Set the series as the data source for the chart
                  chart->addSeries(series);

                  // Set the chart legend to show the percentage values
                  QPieSlice *slice;
                  foreach(slice, series->slices()) {
                      slice->setLabel(QString("%1\n%2%").arg(slice->label()).arg(100 * slice->percentage(), 0, 'f', 1));
                  }

                  // Create a chart view and set its size
                  QChartView *chartView = new QChartView(chart, this);
                  chartView->setRenderHint(QPainter::Antialiasing);
                  chartView->resize(800, 600);

                  // Create a layout for the chart view widget and add it to the frame
                  QVBoxLayout *layout = new QVBoxLayout(ui->stat_el);
                  layout->addWidget(chartView);
                  ui->stat_el->setLayout(layout);
              }
}

void MainWindow::on_refresh_stats_clicked()
{
    // Clear the existing layout from the frame
           QLayout *layout = ui->stat_el->layout();
           if (layout) {
               delete layout;
           }

           // Create a chart object
           QChart *chart = new QChart();

           // Set the chart title
           chart->setTitle("Type de Classes");

           // Create a pie series and add it to the chart
           QPieSeries *series = new QPieSeries();

           // Query the database to get the data for the chart
           QSqlQuery query;
           query.prepare("SELECT CLASSE, COUNT(*) FROM ELEVE GROUP BY CLASSE");
           if(query.exec())
           {
               int total = 0;
               while(query.next())
               {
                   // Get the type and count for the current row
                   QString type = query.value(0).toString();
                   int count = query.value(1).toInt();

                   // Add the type and count to the series
                   series->append(type, count);

                   // Increment the total count
                   total += count;
               }

               // Set the series as the data source for the chart
               chart->addSeries(series);

               // Set the chart legend to show the percentage values
               QPieSlice *slice;
               foreach(slice, series->slices()) {
                   slice->setLabel(QString("%1\n%2%").arg(slice->label()).arg(100 * slice->percentage(), 0, 'f', 1));
               }

               // Create a chart view and set its size
               QChartView *chartView = new QChartView(chart, this);
               chartView->setRenderHint(QPainter::Antialiasing);
               chartView->resize(800, 600);

               // Create a layout for the chart view widget and add it to the frame
               QVBoxLayout *layout = new QVBoxLayout(ui->stat_el);
               layout->addWidget(chartView);
               ui->stat_el->setLayout(layout);
           }
}

void MainWindow::on_button_stats_2_clicked()
{
    // Create a chart object
              QChart *chart = new QChart();

              // Set the chart title
              chart->setTitle("Type de Specialités");

              // Create a pie series and add it to the chart
              QPieSeries *series = new QPieSeries();

              // Query the database to get the data for the chart
              QSqlQuery query;
              query.prepare("SELECT SPECIALITE, COUNT(*) FROM ENSEIGNANT GROUP BY SPECIALITE");
              if(query.exec())
              {
                  int total = 0;
                  while(query.next())
                  {
                      // Get the type and count for the current row
                      QString type = query.value(0).toString();
                      int count = query.value(1).toInt();

                      // Add the type and count to the series
                      series->append(type, count);

                      // Increment the total count
                      total += count;
                  }

                  // Set the series as the data source for the chart
                  chart->addSeries(series);

                  // Set the chart legend to show the percentage values
                  QPieSlice *slice;
                  foreach(slice, series->slices()) {
                      slice->setLabel(QString("%1\n%2%").arg(slice->label()).arg(100 * slice->percentage(), 0, 'f', 1));
                  }

                  // Create a chart view and set its size
                  QChartView *chartView = new QChartView(chart, this);
                  chartView->setRenderHint(QPainter::Antialiasing);
                  chartView->resize(800, 600);

                  // Create a layout for the chart view widget and add it to the frame
                  QVBoxLayout *layout = new QVBoxLayout(ui->stat_en);
                  layout->addWidget(chartView);
                  ui->stat_en->setLayout(layout);
              }
}



void MainWindow::on_refresh_stats_2_clicked()
{
    // Clear the existing layout from the frame
           QLayout *layout = ui->stat_en->layout();
           if (layout) {
               delete layout;
           }

           // Create a chart object
           QChart *chart = new QChart();

           // Set the chart title
           chart->setTitle("Type de Specialités");

           // Create a pie series and add it to the chart
           QPieSeries *series = new QPieSeries();

           // Query the database to get the data for the chart
           QSqlQuery query;
           query.prepare("SELECT SPECIALITE, COUNT(*) FROM ENSEIGNANT GROUP BY SPECIALITE");
           if(query.exec())
           {
               int total = 0;
               while(query.next())
               {
                   // Get the type and count for the current row
                   QString type = query.value(0).toString();
                   int count = query.value(1).toInt();

                   // Add the type and count to the series
                   series->append(type, count);

                   // Increment the total count
                   total += count;
               }

               // Set the series as the data source for the chart
               chart->addSeries(series);

               // Set the chart legend to show the percentage values
               QPieSlice *slice;
               foreach(slice, series->slices()) {
                   slice->setLabel(QString("%1\n%2%").arg(slice->label()).arg(100 * slice->percentage(), 0, 'f', 1));
               }

               // Create a chart view and set its size
               QChartView *chartView = new QChartView(chart, this);
               chartView->setRenderHint(QPainter::Antialiasing);
               chartView->resize(800, 600);

               // Create a layout for the chart view widget and add it to the frame
               QVBoxLayout *layout = new QVBoxLayout(ui->stat_en);
               layout->addWidget(chartView);
               ui->stat_en->setLayout(layout);
           }
}



void MainWindow::on_PDF_el_clicked()
{
    QString dir = "C:/Users/RAOUF/Documents/garderie_scolaire";
       QDir().mkpath(dir);
       QString fileName = dir + "/Eleves.pdf";
       QPdfWriter pdf(fileName);
       QPainter painter(&pdf);
       int i = 4000;
    //painter.drawPixmap(QRect(100,100,2000,2000),QPixmap("C:/Users/RAOUF/Desktop/crewative/C++/logo equipe/logo-crewative.png"));
        painter.setPen(Qt::red);
        painter.setFont(QFont("Time New Roman", 25));
        painter.drawText(3000,1450,"Liste des Elèves");
        painter.setPen(Qt::black);
        painter.setFont(QFont("Time New Roman", 15));
        painter.drawRect(100,100,9400,2500);
        painter.drawRect(100,3000,9400,500);
        painter.setFont(QFont("Time New Roman", 10));
        painter.drawText(300,3300,"ID Elève");
        painter.drawText(1500,3300,"Nom");
        painter.drawText(3000,3300,"Prénom");
        painter.drawText(4800,3300,"Date de naissance");
        painter.drawText(6600,3300,"Age");
        painter.drawText(8400,3300,"Classe");


        painter.drawRect(100,3000,9400,10700);

        QTextDocument previewDoc;
        QString pdflist = QDate::currentDate().toString("'data_'MM_dd_yyyy'.txt'");

        QTextCursor cursor(&previewDoc);

        QSqlQuery query;
        query.prepare("SELECT * FROM ELEVE");
        query.exec();
        while (query.next())
        {
            painter.drawText(300,i,query.value(0).toString());
            painter.drawText(1500,i,query.value(1).toString());
            painter.drawText(3000,i,query.value(2).toString());
            painter.drawText(4800,i,query.value(3).toString());
            painter.drawText(6600,i,query.value(4).toString());
            painter.drawText(8400,i,query.value(5).toString());


            i = i +500;
        }

        int reponse = QMessageBox::question(this, "Générer PDF", " PDF Enregistré ! Voulez Vous Affichez Le PDF ?",
            QMessageBox::Yes|QMessageBox::No);
        if (reponse == QMessageBox::Yes)
        {
            QDesktopServices::openUrl(QUrl::fromLocalFile(dir+"/Eleves.pdf"));
            painter.end();
        }
        else
        {
             painter.end();
        }
}

void MainWindow::on_PDF_en_clicked()
{
    QString dir = "C:/Users/RAOUF/Documents/garderie_scolaire";
       QDir().mkpath(dir);
       QString fileName = dir + "/Enseignants.pdf";
       QPdfWriter pdf(fileName);
       QPainter painter(&pdf);
       int i = 4000;
    //painter.drawPixmap(QRect(100,100,2000,2000),QPixmap("C:/Users/RAOUF/Desktop/crewative/C++/logo equipe/logo-crewative.png"));
        painter.setPen(Qt::red);
        painter.setFont(QFont("Time New Roman", 25));
        painter.drawText(3000,1450,"Liste des Enseignants");
        painter.setPen(Qt::black);
        painter.setFont(QFont("Time New Roman", 15));
        painter.drawRect(100,100,9400,2500);
        painter.drawRect(100,3000,9400,500);
        painter.setFont(QFont("Time New Roman", 10));
        painter.drawText(300,3300,"ID Enseignants");
        painter.drawText(1500,3300,"Nom");
        painter.drawText(3000,3300,"Prénom");
        painter.drawText(4800,3300,"Date d'entrée");
        painter.drawText(6600,3300,"Spécialité");
        painter.drawText(8400,3300,"Telephone");
        painter.drawText(10000,3300,"Email");


        painter.drawRect(100,3000,9400,10700);

        QTextDocument previewDoc;
        QString pdflist = QDate::currentDate().toString("'data_'MM_dd_yyyy'.txt'");

        QTextCursor cursor(&previewDoc);

        QSqlQuery query;
        query.prepare("SELECT * FROM ENSEIGNANT");
        query.exec();
        while (query.next())
        {
            painter.drawText(300,i,query.value(0).toString());
            painter.drawText(1500,i,query.value(1).toString());
            painter.drawText(3000,i,query.value(2).toString());
            painter.drawText(4800,i,query.value(3).toString());
            painter.drawText(6600,i,query.value(4).toString());
            painter.drawText(8400,i,query.value(5).toString());
            //painter.drawText(10000,i,query.value(6).toString());
            //na7itha khater lezem nsalla7 el dimensions bch todhhor correcte.


            i = i +500;
        }

        int reponse = QMessageBox::question(this, "Générer PDF", " PDF Enregistré ! Voulez Vous Affichez Le PDF ?",
            QMessageBox::Yes|QMessageBox::No);
        if (reponse == QMessageBox::Yes)
        {
            QDesktopServices::openUrl(QUrl::fromLocalFile(dir+"/Enseignants.pdf"));
            painter.end();
        }
        else
        {
             painter.end();
        }
}

void MainWindow::on_PDF_ut_clicked()
{
    QString dir = "C:/Users/RAOUF/Documents/garderie_scolaire";
       QDir().mkpath(dir);
       QString fileName = dir + "/Utilisateurs.pdf";
       QPdfWriter pdf(fileName);
       QPainter painter(&pdf);
       int i = 4000;
    //painter.drawPixmap(QRect(100,100,2000,2000),QPixmap("C:/Users/RAOUF/Desktop/crewative/C++/logo equipe/logo-crewative.png"));
        painter.setPen(Qt::red);
        painter.setFont(QFont("Time New Roman", 25));
        painter.drawText(3000,1450,"Liste des Utilisateurs");
        painter.setPen(Qt::black);
        painter.setFont(QFont("Time New Roman", 15));
        painter.drawRect(100,100,9400,2500);
        painter.drawRect(100,3000,9400,500);
        painter.setFont(QFont("Time New Roman", 10));
        painter.drawText(300,3300,"Username");
        painter.drawText(1500,3300,"Password");
        //painter.drawText(3000,3300,"Prénom");
        //painter.drawText(4800,3300,"Date d'entrée");
        //painter.drawText(6600,3300,"Spécialité");
        //painter.drawText(8400,3300,"Telephone");
        //painter.drawText(10000,3300,"Email");


        painter.drawRect(100,3000,9400,10700);

        QTextDocument previewDoc;
        QString pdflist = QDate::currentDate().toString("'data_'MM_dd_yyyy'.txt'");

        QTextCursor cursor(&previewDoc);

        QSqlQuery query;
        query.prepare("SELECT * FROM AUTH");
        query.exec();
        while (query.next())
        {
            painter.drawText(300,i,query.value(0).toString());
            painter.drawText(1500,i,query.value(1).toString());


            i = i +500;
        }

        int reponse = QMessageBox::question(this, "Générer PDF", " PDF Enregistré ! Voulez Vous Affichez Le PDF ?",
            QMessageBox::Yes|QMessageBox::No);
        if (reponse == QMessageBox::Yes)
        {
            QDesktopServices::openUrl(QUrl::fromLocalFile(dir+"/Utilisateurs.pdf"));
            painter.end();
        }
        else
        {
             painter.end();
        }
}

void MainWindow::on_recherche_el_returnPressed()
{
    QString search_text = ui->recherche_el->text().trimmed();
        QString uppercase_search_text = search_text.toUpper();

        QSqlQueryModel* model = new QSqlQueryModel();
        QString query("SELECT * FROM ELEVE WHERE UPPER(ID_EL) LIKE '%' || :search_text || '%' "
                        " OR UPPER(NOM) LIKE '%' || :search_text || '%' "
                        " OR UPPER(PRENOM) LIKE '%' || :search_text || '%' "
                        " OR UPPER(NAISSANCE) LIKE '%' || :search_text || '%' "
                        " OR UPPER(AGE) LIKE '%' || :search_text || '%' "
                        " OR UPPER(CLASSE) LIKE '%' || :search_text || '%' "
                        " OR UPPER(ID_EL) LIKE '%' || :uppercase_search_text || '%' "
                        " OR UPPER(NOM) LIKE '%' || :uppercase_search_text || '%' "
                        " OR UPPER(PRENOM) LIKE '%' || :uppercase_search_text || '%' "
                        " OR UPPER(NAISSANCE) LIKE '%' || :uppercase_search_text || '%' "
                        " OR UPPER(AGE) LIKE '%' || :uppercase_search_text || '%' "
                        " OR UPPER(CLASSE) LIKE '%' || :uppercase_search_text || '%'");

        QSqlQuery sql_query;
        sql_query.prepare(query);
        sql_query.bindValue(":search_text", search_text);
        sql_query.bindValue(":uppercase_search_text", uppercase_search_text);

        if (sql_query.exec())
        {
            model->setQuery(sql_query);
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("Naissance"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("Age"));
            model->setHeaderData(5, Qt::Horizontal, QObject::tr("Classe"));

            ui->Donnees->setModel(model);
        }
        else
        {
            qDebug() << "Error executing query: " << sql_query.lastError().text();
        }
}

void MainWindow::on_recherche_en_returnPressed()
{
    QString search_text = ui->recherche_en->text().trimmed();
        QString uppercase_search_text = search_text.toUpper();

        QSqlQueryModel* model1 = new QSqlQueryModel();
        QString query("SELECT * FROM ENSEIGNANT WHERE UPPER(ID_EN) LIKE '%' || :search_text || '%' "
                        " OR UPPER(NOM) LIKE '%' || :search_text || '%' "
                        " OR UPPER(PRENOM) LIKE '%' || :search_text || '%' "
                        " OR UPPER(DATE_E) LIKE '%' || :search_text || '%' "
                        " OR UPPER(SPECIALITE) LIKE '%' || :search_text || '%' "
                        " OR UPPER(TELEPHONE) LIKE '%' || :search_text || '%' "
                        " OR UPPER(EMAIL) LIKE '%' || :search_text || '%' "
                        " OR UPPER(ID_EN) LIKE '%' || :uppercase_search_text || '%' "
                        " OR UPPER(NOM) LIKE '%' || :uppercase_search_text || '%' "
                        " OR UPPER(PRENOM) LIKE '%' || :uppercase_search_text || '%' "
                        " OR UPPER(DATE_E) LIKE '%' || :uppercase_search_text || '%' "
                        " OR UPPER(SPECIALITE) LIKE '%' || :uppercase_search_text || '%' "
                        " OR UPPER(TELEPHONE) LIKE '%' || :uppercase_search_text || '%' "
                        " OR UPPER(EMAIL) LIKE '%' || :uppercase_search_text || '%'");

        QSqlQuery sql_query;
        sql_query.prepare(query);
        sql_query.bindValue(":search_text", search_text);
        sql_query.bindValue(":uppercase_search_text", uppercase_search_text);

        if (sql_query.exec())
        {
            model1->setQuery(sql_query);
            model1->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
            model1->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
            model1->setHeaderData(3, Qt::Horizontal, QObject::tr("date_e"));
            model1->setHeaderData(4, Qt::Horizontal, QObject::tr("specialité"));
            model1->setHeaderData(5, Qt::Horizontal, QObject::tr("Num Tel"));
            model1->setHeaderData(6, Qt::Horizontal, QObject::tr("email"));

            ui->Donnees_EN->setModel(model1);
        }
        else
        {
            qDebug() << "Error executing query: " << sql_query.lastError().text();
        }
}

void MainWindow::on_recherche_ut_returnPressed()
{
    QString search_text = ui->recherche_ut->text().trimmed();
        QString uppercase_search_text = search_text.toUpper();

        QSqlQueryModel* model2 = new QSqlQueryModel();
        QString query("SELECT * FROM AUTH WHERE UPPER(USERNAME) LIKE '%' || :search_text || '%' "
                        " OR UPPER(PASSWORD) LIKE '%' || :search_text || '%' "
                        " OR UPPER(USERNAME) LIKE '%' || :uppercase_search_text || '%' "
                        " OR UPPER(PASSWORD) LIKE '%' || :uppercase_search_text || '%'");

        QSqlQuery sql_query;
        sql_query.prepare(query);
        sql_query.bindValue(":search_text", search_text);
        sql_query.bindValue(":uppercase_search_text", uppercase_search_text);

        if (sql_query.exec())
        {
            model2->setQuery(sql_query);
            model2->setHeaderData(0, Qt::Horizontal, QObject::tr("Username"));
            model2->setHeaderData(1, Qt::Horizontal, QObject::tr("Password"));

            ui->Donnees_UT->setModel(model2);
        }
        else
        {
            qDebug() << "Error executing query: " << sql_query.lastError().text();
        }
}

void MainWindow::on_combo_el_currentIndexChanged(const QString &choix_el)
{
    ELEVE E;
        if (choix_el == "Nom")
        {
            bool test = E.trie_NOM();
            if (test)
            {
                ui->Donnees->setModel(E.afficher());
                ui->Donnees->setModel(E.trie_NOM());
                QMessageBox::information(nullptr,QObject::tr("ok"),
                                         QObject::tr("tri Nom effectué \n"
                                                     "Click Cancel to exist ."), QMessageBox::Cancel);
            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("non"),
                                      QObject::tr("tri Nom failed.\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);
            }
        }
        else if (choix_el == "Classe")
        {
            bool test = E.trie_Classe();
            if (test)
            {
                ui->Donnees->setModel(E.afficher());
                ui->Donnees->setModel(E.trie_Classe());
                QMessageBox::information(nullptr,QObject::tr("ok"),
                                         QObject::tr("tri adresse effectué \n"
                                                     "Click Cancel to exist ."),QMessageBox::Cancel);
            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("non"),
                                      QObject::tr("tri adresse failed.\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);
            }
        }
        else if (choix_el == "ID")
        {
            bool test = E.trie_ID_el();
            if (test)
            {
                ui->Donnees->setModel(E.afficher());
                ui->Donnees->setModel(E.trie_ID_el());
                QMessageBox::information(nullptr,QObject::tr("ok"),
                                         QObject::tr("tri id effectué \n"
                                                     "Click Cancel to exist ."),QMessageBox::Cancel);
            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("non"),
                                      QObject::tr("tri id failed.\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);
            }
        }
}




void MainWindow::on_combo_en_currentIndexChanged(const QString &choix_en)
{
    enseignant en;
        if (choix_en == "Nom")
        {
            bool test = en.trie_Nom_en();
            if (test)
            {
                ui->Donnees_EN->setModel(en.afficher());
                ui->Donnees_EN->setModel(en.trie_Nom_en());
                QMessageBox::information(nullptr,QObject::tr("ok"),
                                         QObject::tr("tri Nom effectué \n"
                                                     "Click Cancel to exist ."), QMessageBox::Cancel);
            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("non"),
                                      QObject::tr("tri Nom failed.\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);
            }
        }
        else if (choix_en == "Classe")
        {
            bool test = en.trie_Spec();
            if (test)
            {
                ui->Donnees_EN->setModel(en.afficher());
                ui->Donnees_EN->setModel(en.trie_Spec());
                QMessageBox::information(nullptr,QObject::tr("ok"),
                                         QObject::tr("tri adresse effectué \n"
                                                     "Click Cancel to exist ."),QMessageBox::Cancel);
            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("non"),
                                      QObject::tr("tri adresse failed.\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);
            }
        }
        else if (choix_en == "ID")
        {
            bool test = en.trie_ID_en();
            if (test)
            {
                ui->Donnees_EN->setModel(en.afficher());
                ui->Donnees_EN->setModel(en.trie_ID_en());
                QMessageBox::information(nullptr,QObject::tr("ok"),
                                         QObject::tr("tri id effectué \n"
                                                     "Click Cancel to exist ."),QMessageBox::Cancel);
            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("non"),
                                      QObject::tr("tri id failed.\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);
            }
        }
}




void MainWindow::on_combo_ut_currentIndexChanged(const QString &choix_ut)
{
    authentification A;
        if (choix_ut == "Username")
        {
            bool test = A.trie_User();
            if (test)
            {
                ui->Donnees_UT->setModel(A.afficher());
                ui->Donnees_UT->setModel(A.trie_User());
                QMessageBox::information(nullptr,QObject::tr("ok"),
                                         QObject::tr("tri Nom effectué \n"
                                                     "Click Cancel to exist ."), QMessageBox::Cancel);
            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("non"),
                                      QObject::tr("tri Nom failed.\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);
            }
        }

        else if (choix_ut == "Password")
        {
            bool test = A.trie_Pass();
            if (test)
            {
                ui->Donnees_UT->setModel(A.afficher());
                ui->Donnees_UT->setModel(A.trie_Pass());
                QMessageBox::information(nullptr,QObject::tr("ok"),
                                         QObject::tr("tri id effectué \n"
                                                     "Click Cancel to exist ."),QMessageBox::Cancel);
            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("non"),
                                      QObject::tr("tri id failed.\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);
            }
        }
}
