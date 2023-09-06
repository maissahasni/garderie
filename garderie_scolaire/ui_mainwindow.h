/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *login;
    QLabel *label;
    QLineEdit *lineEdit_username;
    QLabel *label_2;
    QLineEdit *lineEdit_password;
    QPushButton *log_in;
    QPushButton *forget;
    QLabel *label_16;
    QLabel *background;
    QWidget *menu;
    QLabel *background2;
    QPushButton *button_EL;
    QPushButton *button_EN;
    QPushButton *logout_menu;
    QPushButton *button_UT;
    QWidget *Gestion_eleve;
    QLabel *background3;
    QFrame *frame;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *le_id;
    QLineEdit *le_nom;
    QLineEdit *le_prenom;
    QLineEdit *le_age;
    QLineEdit *le_classe;
    QDateEdit *le_date;
    QPushButton *modifier;
    QPushButton *supprimer;
    QPushButton *ajouter;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTableView *Donnees;
    QPushButton *PDF_el;
    QLabel *recherche;
    QLabel *tri;
    QComboBox *combo_el;
    QLineEdit *recherche_el;
    QWidget *tab_2;
    QFrame *stat_el;
    QPushButton *button_stats;
    QPushButton *refresh_stats;
    QPushButton *logout_eleve;
    QPushButton *return_1;
    QWidget *gestion_enseignant;
    QFrame *frame_2;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLineEdit *le_id_2;
    QLineEdit *le_nom_2;
    QLineEdit *le_prenom_2;
    QLineEdit *le_spec;
    QLineEdit *le_tel;
    QDateEdit *le_date_2;
    QPushButton *modifier_2;
    QPushButton *supprimer_2;
    QPushButton *ajouter_2;
    QLabel *label_17;
    QLineEdit *le_email;
    QTabWidget *tabWidget_2;
    QWidget *tab_3;
    QTableView *Donnees_EN;
    QPushButton *PDF_en;
    QLineEdit *recherche_en;
    QComboBox *combo_en;
    QLabel *tri_2;
    QLabel *recherche_2;
    QWidget *tab_4;
    QFrame *stat_en;
    QPushButton *button_stats_2;
    QPushButton *refresh_stats_2;
    QPushButton *logout_ens;
    QPushButton *return_2;
    QLabel *label_9;
    QWidget *gestion_utilisateur;
    QLabel *label_18;
    QFrame *frame_3;
    QLabel *label_20;
    QLabel *label_21;
    QLineEdit *le_user;
    QLineEdit *le_pass;
    QPushButton *modifier_3;
    QPushButton *supprimer_3;
    QPushButton *ajouter_3;
    QLabel *label_22;
    QRadioButton *radio_el;
    QRadioButton *radio_en;
    QTabWidget *tabWidget_3;
    QWidget *tab_5;
    QTableView *Donnees_UT;
    QPushButton *PDF_ut;
    QLabel *recherche_3;
    QLineEdit *recherche_ut;
    QLabel *tri_3;
    QComboBox *combo_ut;
    QPushButton *logout_ens_2;
    QPushButton *return_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1329, 701);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 1331, 671));
        stackedWidget->setAutoFillBackground(true);
        login = new QWidget();
        login->setObjectName(QStringLiteral("login"));
        label = new QLabel(login);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(580, 230, 71, 16));
        label->setStyleSheet(QLatin1String("color: white;\n"
"background: transparent;\n"
""));
        lineEdit_username = new QLineEdit(login);
        lineEdit_username->setObjectName(QStringLiteral("lineEdit_username"));
        lineEdit_username->setGeometry(QRect(580, 270, 191, 31));
        lineEdit_username->setStyleSheet(QLatin1String("QLineEdit {\n"
"    \n"
"    border:none;\n"
"    padding: 0 8px;\n"
"    background: transparent;\n"
"	color: white;\n"
"	border-bottom: 2px solid white;\n"
"}\n"
"QLineEdit:Focus{\n"
"\n"
"	border: 2px solid white;\n"
"	border-radius: 10px;\n"
"\n"
"}"));
        lineEdit_username->setPlaceholderText(QStringLiteral(""));
        label_2 = new QLabel(login);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(580, 330, 71, 16));
        label_2->setStyleSheet(QLatin1String("color: white;\n"
"background: transparent;"));
        lineEdit_password = new QLineEdit(login);
        lineEdit_password->setObjectName(QStringLiteral("lineEdit_password"));
        lineEdit_password->setGeometry(QRect(580, 370, 191, 31));
        lineEdit_password->setStyleSheet(QLatin1String("QLineEdit {\n"
"    \n"
"    border:none;\n"
"    padding: 0 8px;\n"
"    background: transparent;\n"
"	color: white;\n"
"	border-bottom: 2px solid white;\n"
"}\n"
"QLineEdit:Focus{\n"
"\n"
"	border: 2px solid white;\n"
"	border-radius: 10px;\n"
"\n"
"}"));
        lineEdit_password->setEchoMode(QLineEdit::Password);
        log_in = new QPushButton(login);
        log_in->setObjectName(QStringLiteral("log_in"));
        log_in->setGeometry(QRect(630, 500, 101, 41));
        log_in->setStyleSheet(QLatin1String("QPushButton {\n"
"   background-color: #fff;\n"
"   border: 2px solid white;\n"
"   color: #333;\n"
"   padding: 0 8px;\n"
"   text-align: center;\n"
"   text-decoration: none;\n"
"   display: inline-block;\n"
"   font-size: 14px;\n"
"   margin: 4px 2px;\n"
"   cursor: pointer;\n"
"   border-radius: 10px;\n"
"\n"
"\n"
"\n"
"    \n"
" \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"   background-color: #00FF00;\n"
"}\n"
"\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"	background-color: #EF829B;\n"
"\n"
"}"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/ico/icons/log-in.svg"), QSize(), QIcon::Normal, QIcon::Off);
        log_in->setIcon(icon);
        log_in->setIconSize(QSize(20, 20));
        forget = new QPushButton(login);
        forget->setObjectName(QStringLiteral("forget"));
        forget->setGeometry(QRect(610, 460, 141, 21));
        forget->setStyleSheet(QLatin1String("QPushButton {\n"
"   background-color: transparent;\n"
"\n"
"   color: white;\n"
"\n"
"   text-align: center;\n"
"   \n"
"   display: inline-block;\n"
"   font-size: 14px;\n"
"   margin: 4px 2px;\n"
"   cursor: pointer;\n"
"   border-radius: 10px;\n"
"\n"
"\n"
"\n"
"    \n"
" \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: transparent;\n"
"	color: #EF829B;\n"
"	\n"
"}\n"
"\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"	background-color: #EF829B;\n"
"\n"
"}"));
        forget->setIconSize(QSize(20, 20));
        label_16 = new QLabel(login);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(500, 50, 361, 101));
        label_16->setStyleSheet(QLatin1String("QLabel{\n"
"\n"
"color:white;\n"
"font:40pt;\n"
"\n"
"}"));
        background = new QLabel(login);
        background->setObjectName(QStringLiteral("background"));
        background->setGeometry(QRect(0, 0, 1331, 671));
        background->setPixmap(QPixmap(QString::fromUtf8("../background.jpg")));
        stackedWidget->addWidget(login);
        background->raise();
        label->raise();
        lineEdit_username->raise();
        label_2->raise();
        lineEdit_password->raise();
        log_in->raise();
        forget->raise();
        label_16->raise();
        menu = new QWidget();
        menu->setObjectName(QStringLiteral("menu"));
        background2 = new QLabel(menu);
        background2->setObjectName(QStringLiteral("background2"));
        background2->setGeometry(QRect(0, 0, 1331, 671));
        background2->setPixmap(QPixmap(QString::fromUtf8("../background.jpg")));
        button_EL = new QPushButton(menu);
        button_EL->setObjectName(QStringLiteral("button_EL"));
        button_EL->setGeometry(QRect(450, 170, 471, 51));
        button_EL->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color:#7286A0 ; \n"
"   border: none;\n"
"   color: white;\n"
"   padding: 10px 20px;\n"
"   text-align: center;\n"
"   text-decoration: none;\n"
"   display: inline-block;\n"
"   font-size: 14px;\n"
"   margin: 4px 2px;\n"
"   cursor: pointer;\n"
"   border-radius: 16px;\n"
"border : 3px solid white; \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"   background-color: #EF829B;\n"
"font-color: white ; \n"
"\n"
"}"));
        button_EL->setIconSize(QSize(30, 30));
        button_EN = new QPushButton(menu);
        button_EN->setObjectName(QStringLiteral("button_EN"));
        button_EN->setGeometry(QRect(450, 250, 471, 51));
        button_EN->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color:#7286A0 ; \n"
"   border: none;\n"
"   color: white;\n"
"   padding: 10px 20px;\n"
"   text-align: center;\n"
"   text-decoration: none;\n"
"   display: inline-block;\n"
"   font-size: 14px;\n"
"   margin: 4px 2px;\n"
"   cursor: pointer;\n"
"   border-radius: 16px;\n"
"border : 3px solid white; \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"   background-color: #EF829B;\n"
"font-color: white ; \n"
"\n"
"}"));
        button_EN->setIconSize(QSize(30, 30));
        logout_menu = new QPushButton(menu);
        logout_menu->setObjectName(QStringLiteral("logout_menu"));
        logout_menu->setGeometry(QRect(630, 450, 121, 41));
        logout_menu->setStyleSheet(QLatin1String("QPushButton {\n"
"   background-color: #fff;\n"
"   border: 2px solid white;\n"
"   color: #333;\n"
"   padding: 0 8px;\n"
"   text-align: center;\n"
"   text-decoration: none;\n"
"   display: inline-block;\n"
"   font-size: 14px;\n"
"   margin: 4px 2px;\n"
"   cursor: pointer;\n"
"   border-radius: 10px;\n"
"\n"
"\n"
"\n"
"    \n"
" \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"   background-color: #ec4c4c;\n"
"}\n"
"\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"	background-color: #ec4c4c;\n"
"\n"
"}"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/ico/icons/log-out.svg"), QSize(), QIcon::Normal, QIcon::Off);
        logout_menu->setIcon(icon1);
        logout_menu->setIconSize(QSize(20, 20));
        button_UT = new QPushButton(menu);
        button_UT->setObjectName(QStringLiteral("button_UT"));
        button_UT->setGeometry(QRect(450, 330, 471, 51));
        button_UT->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color:#7286A0 ; \n"
"   border: none;\n"
"   color: white;\n"
"   padding: 10px 20px;\n"
"   text-align: center;\n"
"   text-decoration: none;\n"
"   display: inline-block;\n"
"   font-size: 14px;\n"
"   margin: 4px 2px;\n"
"   cursor: pointer;\n"
"   border-radius: 16px;\n"
"border : 3px solid white; \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"   background-color: #EF829B;\n"
"font-color: white ; \n"
"\n"
"}"));
        button_UT->setIconSize(QSize(30, 30));
        stackedWidget->addWidget(menu);
        Gestion_eleve = new QWidget();
        Gestion_eleve->setObjectName(QStringLiteral("Gestion_eleve"));
        background3 = new QLabel(Gestion_eleve);
        background3->setObjectName(QStringLiteral("background3"));
        background3->setGeometry(QRect(0, 0, 1331, 671));
        background3->setPixmap(QPixmap(QString::fromUtf8("../background.jpg")));
        frame = new QFrame(Gestion_eleve);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(30, 30, 321, 601));
        frame->setStyleSheet(QLatin1String("QFrame {\n"
"border : 2px solid white ;\n"
" border-radius: 16px;\n"
"}\n"
"QLabel {\n"
"border : none;\n"
"color : white;\n"
"}\n"
"QDateEdit {\n"
"background : transparent;\n"
"color : white;\n"
"}\n"
"QPushButton {\n"
"   background-color: #fff;\n"
"   border: none;\n"
"   color: #333;\n"
"   padding: 10px 20px;\n"
"   text-align: center;\n"
"   text-decoration: none;\n"
"   display: inline-block;\n"
"   font-size: 14px;\n"
"   margin: 4px 2px;\n"
"   cursor: pointer;\n"
"   border-radius: 16px;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"   background-color: #F8B7C6;\n"
"}\n"
"\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"	background-color: #EF829B;\n"
"\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 50, 56, 16));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 110, 56, 16));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 170, 71, 16));
        label_6 = new QLabel(frame);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(30, 230, 81, 16));
        label_7 = new QLabel(frame);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(30, 290, 56, 16));
        label_8 = new QLabel(frame);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(30, 350, 56, 16));
        le_id = new QLineEdit(frame);
        le_id->setObjectName(QStringLiteral("le_id"));
        le_id->setGeometry(QRect(120, 30, 151, 31));
        le_id->setStyleSheet(QLatin1String("QLineEdit {\n"
"    \n"
"    border:none;\n"
"    padding: 0 8px;\n"
"    background: transparent;\n"
"	color: white;\n"
"	border-bottom: 2px solid white;\n"
"}\n"
"QLineEdit:Focus{\n"
"\n"
"	border: 2px solid white;\n"
"	border-radius: 10px;\n"
"\n"
"}"));
        le_nom = new QLineEdit(frame);
        le_nom->setObjectName(QStringLiteral("le_nom"));
        le_nom->setGeometry(QRect(120, 90, 151, 31));
        le_nom->setStyleSheet(QLatin1String("QLineEdit {\n"
"    \n"
"    border:none;\n"
"    padding: 0 8px;\n"
"    background: transparent;\n"
"	color: white;\n"
"	border-bottom: 2px solid white;\n"
"}\n"
"QLineEdit:Focus{\n"
"\n"
"	border: 2px solid white;\n"
"	border-radius: 10px;\n"
"\n"
"}"));
        le_prenom = new QLineEdit(frame);
        le_prenom->setObjectName(QStringLiteral("le_prenom"));
        le_prenom->setGeometry(QRect(120, 150, 151, 31));
        le_prenom->setStyleSheet(QLatin1String("QLineEdit {\n"
"    \n"
"    border:none;\n"
"    padding: 0 8px;\n"
"    background: transparent;\n"
"	color: white;\n"
"	border-bottom: 2px solid white;\n"
"}\n"
"QLineEdit:Focus{\n"
"\n"
"	border: 2px solid white;\n"
"	border-radius: 10px;\n"
"\n"
"}"));
        le_age = new QLineEdit(frame);
        le_age->setObjectName(QStringLiteral("le_age"));
        le_age->setGeometry(QRect(120, 270, 151, 31));
        le_age->setStyleSheet(QLatin1String("QLineEdit {\n"
"    \n"
"    border:none;\n"
"    padding: 0 8px;\n"
"    background: transparent;\n"
"	color: white;\n"
"	border-bottom: 2px solid white;\n"
"}\n"
"QLineEdit:Focus{\n"
"\n"
"	border: 2px solid white;\n"
"	border-radius: 10px;\n"
"\n"
"}"));
        le_classe = new QLineEdit(frame);
        le_classe->setObjectName(QStringLiteral("le_classe"));
        le_classe->setGeometry(QRect(120, 330, 151, 31));
        le_classe->setStyleSheet(QLatin1String("QLineEdit {\n"
"    \n"
"    border:none;\n"
"    padding: 0 8px;\n"
"    background: transparent;\n"
"	color: white;\n"
"	border-bottom: 2px solid white;\n"
"}\n"
"QLineEdit:Focus{\n"
"\n"
"	border: 2px solid white;\n"
"	border-radius: 10px;\n"
"\n"
"}"));
        le_date = new QDateEdit(frame);
        le_date->setObjectName(QStringLiteral("le_date"));
        le_date->setGeometry(QRect(120, 221, 151, 31));
        le_date->setStyleSheet(QLatin1String("QDateEdit {\n"
"background : transparent;\n"
"color : white;\n"
"}"));
        modifier = new QPushButton(frame);
        modifier->setObjectName(QStringLiteral("modifier"));
        modifier->setGeometry(QRect(130, 460, 61, 51));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/ico/icons/edit-3.svg"), QSize(), QIcon::Normal, QIcon::Off);
        modifier->setIcon(icon2);
        modifier->setIconSize(QSize(22, 22));
        supprimer = new QPushButton(frame);
        supprimer->setObjectName(QStringLiteral("supprimer"));
        supprimer->setGeometry(QRect(230, 460, 61, 51));
        supprimer->setStyleSheet(QStringLiteral(""));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/ico/icons/minus.svg"), QSize(), QIcon::Normal, QIcon::Off);
        supprimer->setIcon(icon3);
        supprimer->setIconSize(QSize(22, 22));
        ajouter = new QPushButton(frame);
        ajouter->setObjectName(QStringLiteral("ajouter"));
        ajouter->setGeometry(QRect(30, 460, 61, 51));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/ico/icons/plus.svg"), QSize(), QIcon::Normal, QIcon::Off);
        ajouter->setIcon(icon4);
        ajouter->setIconSize(QSize(22, 22));
        tabWidget = new QTabWidget(Gestion_eleve);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(430, 70, 881, 571));
        tabWidget->setAutoFillBackground(false);
        tabWidget->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: transparent; /* Rendre le fond transparent */\n"
"}\n"
"\n"
"/* Le cadre du widget d'onglet */\n"
"QTabWidget::pane {\n"
"    border-top: 2px solid #C2C7CB;\n"
"    background-color: transparent; /* Rendre le milieu transparent */\n"
"}\n"
"\n"
"/* La barre d'onglet */\n"
"QTabWidget::tab-bar {\n"
"    alignment: center;\n"
"    background-color: #003e46;\n"
"    border-top-left-radius: 5px;\n"
"    border-top-right-radius: 5px;\n"
"}\n"
"\n"
"/* Les onglets non s\303\251lectionn\303\251s */\n"
"QTabBar::tab {\n"
"    font-weight: bold;\n"
"    border: 2px solid white;\n"
"    border-top-left-radius: 5px;\n"
"    border-top-right-radius: 5px;\n"
"    padding: 6px;\n"
"    color: white;\n"
"    height: 25px;\n"
"    width: 120px;\n"
"    background: transparent; /* Rendre le fond transparent */\n"
"}\n"
"\n"
"/* L'onglet s\303\251lectionn\303\251 */\n"
"QTabBar::tab:selected {\n"
"    background-color: white;\n"
"    color: #003e46;\n"
"}\n"
"\n"
"/* L'onglet non s\303\251lec"
                        "tionn\303\251 au survol */\n"
"QTabBar::tab:!selected:hover {\n"
"    background-color: #FCB0B3;\n"
"}\n"
"\n"
""));
        tabWidget->setUsesScrollButtons(true);
        tabWidget->setTabBarAutoHide(false);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        Donnees = new QTableView(tab);
        Donnees->setObjectName(QStringLiteral("Donnees"));
        Donnees->setGeometry(QRect(30, 80, 821, 371));
        Donnees->setStyleSheet(QLatin1String("QTableView {\n"
"  background-color: #bca0B3;\n"
"  color: white;\n"
"  border-radius: 10px;\n"
"}\n"
"\n"
"QTableView::item {\n"
"  padding: 4px;\n"
"  border: none;\n"
"}\n"
"\n"
"QTableView::item:selected {\n"
"  background-color: #19666f;\n"
"  color: white;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"  background-color: #003e46;\n"
"  color: white;\n"
"  padding: 4px;\n"
"  border: none;\n"
"}"));
        PDF_el = new QPushButton(tab);
        PDF_el->setObjectName(QStringLiteral("PDF_el"));
        PDF_el->setGeometry(QRect(390, 460, 91, 51));
        PDF_el->setStyleSheet(QLatin1String("QPushButton {\n"
"   background-color: #fff;\n"
"   border: none;\n"
"   color: #333;\n"
"   padding: 10px 20px;\n"
"   text-align: center;\n"
"   text-decoration: none;\n"
"   display: inline-block;\n"
"   font-size: 14px;\n"
"   margin: 4px 2px;\n"
"   cursor: pointer;\n"
"   border-radius: 16px;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"   background-color: #F8B7C6;\n"
"}\n"
"\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"	background-color: #EF829B;\n"
"}"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/ico/icons/download.svg"), QSize(), QIcon::Normal, QIcon::Off);
        PDF_el->setIcon(icon5);
        PDF_el->setIconSize(QSize(22, 22));
        recherche = new QLabel(tab);
        recherche->setObjectName(QStringLiteral("recherche"));
        recherche->setGeometry(QRect(40, 10, 56, 16));
        recherche->setStyleSheet(QLatin1String("background : transparent;\n"
"color : white ;\n"
""));
        tri = new QLabel(tab);
        tri->setObjectName(QStringLiteral("tri"));
        tri->setGeometry(QRect(240, 10, 81, 16));
        tri->setStyleSheet(QLatin1String("background : transparent;\n"
"color : white;"));
        combo_el = new QComboBox(tab);
        combo_el->setObjectName(QStringLiteral("combo_el"));
        combo_el->setGeometry(QRect(40, 40, 101, 22));
        recherche_el = new QLineEdit(tab);
        recherche_el->setObjectName(QStringLiteral("recherche_el"));
        recherche_el->setGeometry(QRect(240, 40, 141, 22));
        recherche_el->setStyleSheet(QLatin1String("border: 2px solid white;\n"
"	border-radius: 10px;\n"
"color : white ;"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        stat_el = new QFrame(tab_2);
        stat_el->setObjectName(QStringLiteral("stat_el"));
        stat_el->setGeometry(QRect(30, 70, 811, 371));
        stat_el->setFrameShape(QFrame::StyledPanel);
        stat_el->setFrameShadow(QFrame::Raised);
        button_stats = new QPushButton(tab_2);
        button_stats->setObjectName(QStringLiteral("button_stats"));
        button_stats->setGeometry(QRect(360, 10, 151, 51));
        button_stats->setStyleSheet(QLatin1String("QPushButton {\n"
"   background-color: #fff;\n"
"   border: none;\n"
"   color: #333;\n"
"   padding: 10px 20px;\n"
"   text-align: center;\n"
"   text-decoration: none;\n"
"   display: inline-block;\n"
"   font-size: 14px;\n"
"   margin: 4px 2px;\n"
"   cursor: pointer;\n"
"   border-radius: 16px;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"   background-color: #F8B7C6;\n"
"}\n"
"\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"	background-color: #EF829B;\n"
"}"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/ico/icons/trending-up.svg"), QSize(), QIcon::Normal, QIcon::Off);
        button_stats->setIcon(icon6);
        button_stats->setIconSize(QSize(22, 22));
        refresh_stats = new QPushButton(tab_2);
        refresh_stats->setObjectName(QStringLiteral("refresh_stats"));
        refresh_stats->setGeometry(QRect(30, 20, 41, 41));
        refresh_stats->setStyleSheet(QLatin1String("QPushButton {\n"
"   background-color: #fff;\n"
"   border: none;\n"
"   color: #333;\n"
"   padding: 10px 20px;\n"
"   text-align: center;\n"
"   text-decoration: none;\n"
"   display: inline-block;\n"
"   font-size: 14px;\n"
"   margin: 4px 2px;\n"
"   cursor: pointer;\n"
"   border-radius: 16px;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"   background-color: #EF829B;\n"
"}\n"
"\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"	background-color: #EF829B;\n"
"\n"
"}"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/ico/icons/refresh-ccw.svg"), QSize(), QIcon::Normal, QIcon::Off);
        refresh_stats->setIcon(icon7);
        refresh_stats->setIconSize(QSize(20, 20));
        tabWidget->addTab(tab_2, QString());
        logout_eleve = new QPushButton(Gestion_eleve);
        logout_eleve->setObjectName(QStringLiteral("logout_eleve"));
        logout_eleve->setGeometry(QRect(1270, 10, 41, 41));
        logout_eleve->setStyleSheet(QLatin1String("QPushButton {\n"
"   background-color: #fff;\n"
"   border: 2px solid white;\n"
"   color: #333;\n"
"   padding: 0 8px;\n"
"   text-align: center;\n"
"   text-decoration: none;\n"
"   display: inline-block;\n"
"   font-size: 14px;\n"
"   margin: 4px 2px;\n"
"   cursor: pointer;\n"
"   border-radius: 10px;\n"
"\n"
"\n"
"\n"
"    \n"
" \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"   background-color: #ec4c4c;\n"
"}\n"
"\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"	background-color: #ec4c4c;\n"
"\n"
"}"));
        logout_eleve->setIcon(icon1);
        logout_eleve->setIconSize(QSize(20, 20));
        return_1 = new QPushButton(Gestion_eleve);
        return_1->setObjectName(QStringLiteral("return_1"));
        return_1->setGeometry(QRect(1220, 10, 41, 41));
        return_1->setStyleSheet(QLatin1String("QPushButton {\n"
"   background-color: #fff;\n"
"   border: 2px solid white;\n"
"   color: #333;\n"
"   padding: 0 8px;\n"
"   text-align: center;\n"
"   text-decoration: none;\n"
"   display: inline-block;\n"
"   font-size: 14px;\n"
"   margin: 4px 2px;\n"
"   cursor: pointer;\n"
"   border-radius: 10px;\n"
"\n"
"\n"
"\n"
"    \n"
" \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"   background-color: #ec4c4c;\n"
"}\n"
"\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"	background-color: #ec4c4c;\n"
"\n"
"}"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/ico/icons/arrow-left.svg"), QSize(), QIcon::Normal, QIcon::Off);
        return_1->setIcon(icon8);
        return_1->setIconSize(QSize(20, 20));
        stackedWidget->addWidget(Gestion_eleve);
        gestion_enseignant = new QWidget();
        gestion_enseignant->setObjectName(QStringLiteral("gestion_enseignant"));
        frame_2 = new QFrame(gestion_enseignant);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(30, 30, 321, 601));
        frame_2->setStyleSheet(QLatin1String("QFrame {\n"
"border : 2px solid white ;\n"
" border-radius: 16px;\n"
"}\n"
"QLabel {\n"
"border : none;\n"
"color : white;\n"
"}\n"
"QDateEdit {\n"
"background : transparent;\n"
"color : white;\n"
"}\n"
"QPushButton {\n"
"   background-color: #fff;\n"
"   border: none;\n"
"   color: #333;\n"
"   padding: 10px 20px;\n"
"   text-align: center;\n"
"   text-decoration: none;\n"
"   display: inline-block;\n"
"   font-size: 14px;\n"
"   margin: 4px 2px;\n"
"   cursor: pointer;\n"
"   border-radius: 16px;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"   background-color: #F8B7C6;\n"
"}\n"
"\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"	background-color: #EF829B;\n"
"\n"
"}"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_10 = new QLabel(frame_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(30, 50, 56, 16));
        label_11 = new QLabel(frame_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(30, 110, 56, 16));
        label_12 = new QLabel(frame_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(30, 170, 71, 16));
        label_13 = new QLabel(frame_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(30, 230, 91, 16));
        label_14 = new QLabel(frame_2);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(30, 290, 71, 16));
        label_15 = new QLabel(frame_2);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(30, 350, 71, 16));
        le_id_2 = new QLineEdit(frame_2);
        le_id_2->setObjectName(QStringLiteral("le_id_2"));
        le_id_2->setGeometry(QRect(120, 30, 151, 31));
        le_id_2->setStyleSheet(QLatin1String("QLineEdit {\n"
"    \n"
"    border:none;\n"
"    padding: 0 8px;\n"
"    background: transparent;\n"
"	color: white;\n"
"	border-bottom: 2px solid white;\n"
"}\n"
"QLineEdit:Focus{\n"
"\n"
"	border: 2px solid white;\n"
"	border-radius: 10px;\n"
"\n"
"}"));
        le_nom_2 = new QLineEdit(frame_2);
        le_nom_2->setObjectName(QStringLiteral("le_nom_2"));
        le_nom_2->setGeometry(QRect(120, 90, 151, 31));
        le_nom_2->setStyleSheet(QLatin1String("QLineEdit {\n"
"    \n"
"    border:none;\n"
"    padding: 0 8px;\n"
"    background: transparent;\n"
"	color: white;\n"
"	border-bottom: 2px solid white;\n"
"}\n"
"QLineEdit:Focus{\n"
"\n"
"	border: 2px solid white;\n"
"	border-radius: 10px;\n"
"\n"
"}"));
        le_prenom_2 = new QLineEdit(frame_2);
        le_prenom_2->setObjectName(QStringLiteral("le_prenom_2"));
        le_prenom_2->setGeometry(QRect(120, 150, 151, 31));
        le_prenom_2->setStyleSheet(QLatin1String("QLineEdit {\n"
"    \n"
"    border:none;\n"
"    padding: 0 8px;\n"
"    background: transparent;\n"
"	color: white;\n"
"	border-bottom: 2px solid white;\n"
"}\n"
"QLineEdit:Focus{\n"
"\n"
"	border: 2px solid white;\n"
"	border-radius: 10px;\n"
"\n"
"}"));
        le_spec = new QLineEdit(frame_2);
        le_spec->setObjectName(QStringLiteral("le_spec"));
        le_spec->setGeometry(QRect(120, 270, 151, 31));
        le_spec->setStyleSheet(QLatin1String("QLineEdit {\n"
"    \n"
"    border:none;\n"
"    padding: 0 8px;\n"
"    background: transparent;\n"
"	color: white;\n"
"	border-bottom: 2px solid white;\n"
"}\n"
"QLineEdit:Focus{\n"
"\n"
"	border: 2px solid white;\n"
"	border-radius: 10px;\n"
"\n"
"}"));
        le_tel = new QLineEdit(frame_2);
        le_tel->setObjectName(QStringLiteral("le_tel"));
        le_tel->setGeometry(QRect(120, 330, 151, 31));
        le_tel->setStyleSheet(QLatin1String("QLineEdit {\n"
"    \n"
"    border:none;\n"
"    padding: 0 8px;\n"
"    background: transparent;\n"
"	color: white;\n"
"	border-bottom: 2px solid white;\n"
"}\n"
"QLineEdit:Focus{\n"
"\n"
"	border: 2px solid white;\n"
"	border-radius: 10px;\n"
"\n"
"}"));
        le_date_2 = new QDateEdit(frame_2);
        le_date_2->setObjectName(QStringLiteral("le_date_2"));
        le_date_2->setGeometry(QRect(120, 221, 151, 31));
        le_date_2->setStyleSheet(QLatin1String("QDateEdit {\n"
"background : transparent;\n"
"color : white;\n"
"}"));
        modifier_2 = new QPushButton(frame_2);
        modifier_2->setObjectName(QStringLiteral("modifier_2"));
        modifier_2->setGeometry(QRect(130, 460, 61, 51));
        modifier_2->setIcon(icon2);
        modifier_2->setIconSize(QSize(22, 22));
        supprimer_2 = new QPushButton(frame_2);
        supprimer_2->setObjectName(QStringLiteral("supprimer_2"));
        supprimer_2->setGeometry(QRect(230, 460, 61, 51));
        supprimer_2->setStyleSheet(QStringLiteral(""));
        supprimer_2->setIcon(icon3);
        supprimer_2->setIconSize(QSize(22, 22));
        ajouter_2 = new QPushButton(frame_2);
        ajouter_2->setObjectName(QStringLiteral("ajouter_2"));
        ajouter_2->setGeometry(QRect(30, 460, 61, 51));
        ajouter_2->setIcon(icon4);
        ajouter_2->setIconSize(QSize(22, 22));
        label_17 = new QLabel(frame_2);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(30, 400, 71, 16));
        le_email = new QLineEdit(frame_2);
        le_email->setObjectName(QStringLiteral("le_email"));
        le_email->setGeometry(QRect(120, 380, 151, 31));
        le_email->setStyleSheet(QLatin1String("QLineEdit {\n"
"    \n"
"    border:none;\n"
"    padding: 0 8px;\n"
"    background: transparent;\n"
"	color: white;\n"
"	border-bottom: 2px solid white;\n"
"}\n"
"QLineEdit:Focus{\n"
"\n"
"	border: 2px solid white;\n"
"	border-radius: 10px;\n"
"\n"
"}"));
        tabWidget_2 = new QTabWidget(gestion_enseignant);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(430, 70, 881, 561));
        tabWidget_2->setAutoFillBackground(false);
        tabWidget_2->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: transparent; /* Rendre le fond transparent */\n"
"}\n"
"\n"
"/* Le cadre du widget d'onglet */\n"
"QTabWidget::pane {\n"
"    border-top: 2px solid #C2C7CB;\n"
"    background-color: transparent; /* Rendre le milieu transparent */\n"
"}\n"
"\n"
"/* La barre d'onglet */\n"
"QTabWidget::tab-bar {\n"
"    alignment: center;\n"
"    background-color: #003e46;\n"
"    border-top-left-radius: 5px;\n"
"    border-top-right-radius: 5px;\n"
"}\n"
"\n"
"/* Les onglets non s\303\251lectionn\303\251s */\n"
"QTabBar::tab {\n"
"    font-weight: bold;\n"
"    border: 2px solid white;\n"
"    border-top-left-radius: 5px;\n"
"    border-top-right-radius: 5px;\n"
"    padding: 6px;\n"
"    color: white;\n"
"    height: 25px;\n"
"    width: 120px;\n"
"    background: transparent; /* Rendre le fond transparent */\n"
"}\n"
"\n"
"/* L'onglet s\303\251lectionn\303\251 */\n"
"QTabBar::tab:selected {\n"
"    background-color: white;\n"
"    color: #003e46;\n"
"}\n"
"\n"
"/* L'onglet non s\303\251lec"
                        "tionn\303\251 au survol */\n"
"QTabBar::tab:!selected:hover {\n"
"    background-color: #FCB0B3;\n"
"}"));
        tabWidget_2->setUsesScrollButtons(true);
        tabWidget_2->setTabBarAutoHide(false);
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        Donnees_EN = new QTableView(tab_3);
        Donnees_EN->setObjectName(QStringLiteral("Donnees_EN"));
        Donnees_EN->setGeometry(QRect(30, 80, 821, 371));
        Donnees_EN->setStyleSheet(QLatin1String("QTableView {\n"
"  background-color: #bca0B3;\n"
"  color: white;\n"
"  border-radius: 10px;\n"
"}\n"
"\n"
"QTableView::item {\n"
"  padding: 4px;\n"
"  border: none;\n"
"}\n"
"\n"
"QTableView::item:selected {\n"
"  background-color: #19666f;\n"
"  color: white;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"  background-color: #003e46;\n"
"  color: white;\n"
"  padding: 4px;\n"
"  border: none;\n"
"}"));
        PDF_en = new QPushButton(tab_3);
        PDF_en->setObjectName(QStringLiteral("PDF_en"));
        PDF_en->setGeometry(QRect(390, 460, 91, 51));
        PDF_en->setStyleSheet(QLatin1String("QPushButton {\n"
"   background-color: #fff;\n"
"   border: none;\n"
"   color: #333;\n"
"   padding: 10px 20px;\n"
"   text-align: center;\n"
"   text-decoration: none;\n"
"   display: inline-block;\n"
"   font-size: 14px;\n"
"   margin: 4px 2px;\n"
"   cursor: pointer;\n"
"   border-radius: 16px;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"   background-color: #F8B7C6;\n"
"}\n"
"\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"	background-color: #EF829B;\n"
"}"));
        PDF_en->setIcon(icon5);
        PDF_en->setIconSize(QSize(22, 22));
        recherche_en = new QLineEdit(tab_3);
        recherche_en->setObjectName(QStringLiteral("recherche_en"));
        recherche_en->setGeometry(QRect(240, 40, 141, 22));
        recherche_en->setStyleSheet(QLatin1String("border: 2px solid white;\n"
"	border-radius: 10px;"));
        combo_en = new QComboBox(tab_3);
        combo_en->setObjectName(QStringLiteral("combo_en"));
        combo_en->setGeometry(QRect(40, 40, 101, 22));
        tri_2 = new QLabel(tab_3);
        tri_2->setObjectName(QStringLiteral("tri_2"));
        tri_2->setGeometry(QRect(240, 10, 81, 16));
        tri_2->setStyleSheet(QLatin1String("background : transparent;\n"
"color : white;"));
        recherche_2 = new QLabel(tab_3);
        recherche_2->setObjectName(QStringLiteral("recherche_2"));
        recherche_2->setGeometry(QRect(40, 10, 56, 16));
        recherche_2->setStyleSheet(QLatin1String("background : transparent;\n"
"color : white ;\n"
""));
        tabWidget_2->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        stat_en = new QFrame(tab_4);
        stat_en->setObjectName(QStringLiteral("stat_en"));
        stat_en->setGeometry(QRect(30, 70, 811, 371));
        stat_en->setFrameShape(QFrame::StyledPanel);
        stat_en->setFrameShadow(QFrame::Raised);
        button_stats_2 = new QPushButton(tab_4);
        button_stats_2->setObjectName(QStringLiteral("button_stats_2"));
        button_stats_2->setGeometry(QRect(360, 10, 151, 51));
        button_stats_2->setStyleSheet(QLatin1String("QPushButton {\n"
"   background-color: #fff;\n"
"   border: none;\n"
"   color: #333;\n"
"   padding: 10px 20px;\n"
"   text-align: center;\n"
"   text-decoration: none;\n"
"   display: inline-block;\n"
"   font-size: 14px;\n"
"   margin: 4px 2px;\n"
"   cursor: pointer;\n"
"   border-radius: 16px;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"   background-color: #F8B7C6;\n"
"}\n"
"\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"	background-color: #EF829B;\n"
"}"));
        button_stats_2->setIcon(icon6);
        button_stats_2->setIconSize(QSize(22, 22));
        refresh_stats_2 = new QPushButton(tab_4);
        refresh_stats_2->setObjectName(QStringLiteral("refresh_stats_2"));
        refresh_stats_2->setGeometry(QRect(30, 20, 41, 41));
        refresh_stats_2->setStyleSheet(QLatin1String("QPushButton {\n"
"   background-color: #fff;\n"
"   border: none;\n"
"   color: #333;\n"
"   padding: 10px 20px;\n"
"   text-align: center;\n"
"   text-decoration: none;\n"
"   display: inline-block;\n"
"   font-size: 14px;\n"
"   margin: 4px 2px;\n"
"   cursor: pointer;\n"
"   border-radius: 16px;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"   background-color: #EF829B;\n"
"}\n"
"\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"	background-color: #EF829B;\n"
"\n"
"}"));
        refresh_stats_2->setIcon(icon7);
        refresh_stats_2->setIconSize(QSize(20, 20));
        tabWidget_2->addTab(tab_4, QString());
        logout_ens = new QPushButton(gestion_enseignant);
        logout_ens->setObjectName(QStringLiteral("logout_ens"));
        logout_ens->setGeometry(QRect(1270, 10, 41, 41));
        logout_ens->setStyleSheet(QLatin1String("QPushButton {\n"
"   background-color: #fff;\n"
"   border: 2px solid white;\n"
"   color: #333;\n"
"   padding: 0 8px;\n"
"   text-align: center;\n"
"   text-decoration: none;\n"
"   display: inline-block;\n"
"   font-size: 14px;\n"
"   margin: 4px 2px;\n"
"   cursor: pointer;\n"
"   border-radius: 10px;\n"
"\n"
"\n"
"\n"
"    \n"
" \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"   background-color: #ec4c4c;\n"
"}\n"
"\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"	background-color: #ec4c4c;\n"
"\n"
"}"));
        logout_ens->setIcon(icon1);
        logout_ens->setIconSize(QSize(20, 20));
        return_2 = new QPushButton(gestion_enseignant);
        return_2->setObjectName(QStringLiteral("return_2"));
        return_2->setGeometry(QRect(1220, 10, 41, 41));
        return_2->setStyleSheet(QLatin1String("QPushButton {\n"
"   background-color: #fff;\n"
"   border: 2px solid white;\n"
"   color: #333;\n"
"   padding: 0 8px;\n"
"   text-align: center;\n"
"   text-decoration: none;\n"
"   display: inline-block;\n"
"   font-size: 14px;\n"
"   margin: 4px 2px;\n"
"   cursor: pointer;\n"
"   border-radius: 10px;\n"
"\n"
"\n"
"\n"
"    \n"
" \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"   background-color: #ec4c4c;\n"
"}\n"
"\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"	background-color: #ec4c4c;\n"
"\n"
"}"));
        return_2->setIcon(icon8);
        return_2->setIconSize(QSize(20, 20));
        label_9 = new QLabel(gestion_enseignant);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(0, 0, 1331, 671));
        label_9->setPixmap(QPixmap(QString::fromUtf8("../background.jpg")));
        stackedWidget->addWidget(gestion_enseignant);
        label_9->raise();
        frame_2->raise();
        tabWidget_2->raise();
        logout_ens->raise();
        return_2->raise();
        gestion_utilisateur = new QWidget();
        gestion_utilisateur->setObjectName(QStringLiteral("gestion_utilisateur"));
        label_18 = new QLabel(gestion_utilisateur);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(0, 0, 1331, 671));
        label_18->setPixmap(QPixmap(QString::fromUtf8("../background.jpg")));
        frame_3 = new QFrame(gestion_utilisateur);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(30, 30, 321, 601));
        frame_3->setStyleSheet(QLatin1String("QFrame {\n"
"border : 2px solid white ;\n"
" border-radius: 16px;\n"
"}\n"
"QLabel {\n"
"border : none;\n"
"color : white;\n"
"}\n"
"QDateEdit {\n"
"background : transparent;\n"
"color : white;\n"
"}\n"
"QPushButton {\n"
"   background-color: #fff;\n"
"   border: none;\n"
"   color: #333;\n"
"   padding: 10px 20px;\n"
"   text-align: center;\n"
"   text-decoration: none;\n"
"   display: inline-block;\n"
"   font-size: 14px;\n"
"   margin: 4px 2px;\n"
"   cursor: pointer;\n"
"   border-radius: 16px;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"   background-color: #F8B7C6;\n"
"}\n"
"\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"	background-color: #EF829B;\n"
"\n"
"}\n"
"QRadioButton {\n"
"\n"
"color : white ;\n"
"\n"
"}\n"
"QRadioButton::indicator {\n"
"\n"
"background: transparent;\n"
"border: 2px solid white;\n"
"border-radius : 8px ;\n"
"\n"
"} \n"
"QRadioButton::indicator:checked {\n"
"\n"
"background: white;\n"
"\n"
"\n"
"}"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        label_20 = new QLabel(frame_3);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(30, 110, 71, 16));
        label_21 = new QLabel(frame_3);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(30, 190, 71, 16));
        le_user = new QLineEdit(frame_3);
        le_user->setObjectName(QStringLiteral("le_user"));
        le_user->setGeometry(QRect(120, 90, 151, 31));
        le_user->setStyleSheet(QLatin1String("QLineEdit {\n"
"    \n"
"    border:none;\n"
"    padding: 0 8px;\n"
"    background: transparent;\n"
"	color: white;\n"
"	border-bottom: 2px solid white;\n"
"}\n"
"QLineEdit:Focus{\n"
"\n"
"	border: 2px solid white;\n"
"	border-radius: 10px;\n"
"\n"
"}"));
        le_pass = new QLineEdit(frame_3);
        le_pass->setObjectName(QStringLiteral("le_pass"));
        le_pass->setGeometry(QRect(120, 170, 151, 31));
        le_pass->setStyleSheet(QLatin1String("QLineEdit {\n"
"    \n"
"    border:none;\n"
"    padding: 0 8px;\n"
"    background: transparent;\n"
"	color: white;\n"
"	border-bottom: 2px solid white;\n"
"}\n"
"QLineEdit:Focus{\n"
"\n"
"	border: 2px solid white;\n"
"	border-radius: 10px;\n"
"\n"
"}"));
        modifier_3 = new QPushButton(frame_3);
        modifier_3->setObjectName(QStringLiteral("modifier_3"));
        modifier_3->setGeometry(QRect(130, 400, 61, 51));
        modifier_3->setIcon(icon2);
        modifier_3->setIconSize(QSize(22, 22));
        supprimer_3 = new QPushButton(frame_3);
        supprimer_3->setObjectName(QStringLiteral("supprimer_3"));
        supprimer_3->setGeometry(QRect(230, 400, 61, 51));
        supprimer_3->setStyleSheet(QStringLiteral(""));
        supprimer_3->setIcon(icon3);
        supprimer_3->setIconSize(QSize(22, 22));
        ajouter_3 = new QPushButton(frame_3);
        ajouter_3->setObjectName(QStringLiteral("ajouter_3"));
        ajouter_3->setGeometry(QRect(30, 400, 61, 51));
        ajouter_3->setIcon(icon4);
        ajouter_3->setIconSize(QSize(22, 22));
        label_22 = new QLabel(frame_3);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(30, 260, 71, 16));
        radio_el = new QRadioButton(frame_3);
        radio_el->setObjectName(QStringLiteral("radio_el"));
        radio_el->setGeometry(QRect(120, 260, 141, 21));
        radio_el->setStyleSheet(QStringLiteral(""));
        radio_en = new QRadioButton(frame_3);
        radio_en->setObjectName(QStringLiteral("radio_en"));
        radio_en->setGeometry(QRect(120, 300, 171, 21));
        radio_en->setStyleSheet(QStringLiteral(""));
        tabWidget_3 = new QTabWidget(gestion_utilisateur);
        tabWidget_3->setObjectName(QStringLiteral("tabWidget_3"));
        tabWidget_3->setGeometry(QRect(430, 70, 881, 561));
        tabWidget_3->setAutoFillBackground(false);
        tabWidget_3->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: transparent; /* Rendre le fond transparent */\n"
"}\n"
"\n"
"/* Le cadre du widget d'onglet */\n"
"QTabWidget::pane {\n"
"    border-top: 2px solid #C2C7CB;\n"
"    background-color: transparent; /* Rendre le milieu transparent */\n"
"}\n"
"\n"
"/* La barre d'onglet */\n"
"QTabWidget::tab-bar {\n"
"    alignment: center;\n"
"    background-color: #003e46;\n"
"    border-top-left-radius: 5px;\n"
"    border-top-right-radius: 5px;\n"
"}\n"
"\n"
"/* Les onglets non s\303\251lectionn\303\251s */\n"
"QTabBar::tab {\n"
"    font-weight: bold;\n"
"    border: 2px solid white;\n"
"    border-top-left-radius: 5px;\n"
"    border-top-right-radius: 5px;\n"
"    padding: 6px;\n"
"    color: white;\n"
"    height: 25px;\n"
"    width: 120px;\n"
"    background: transparent; /* Rendre le fond transparent */\n"
"}\n"
"\n"
"/* L'onglet s\303\251lectionn\303\251 */\n"
"QTabBar::tab:selected {\n"
"    background-color: white;\n"
"    color: #003e46;\n"
"}\n"
"\n"
"/* L'onglet non s\303\251lec"
                        "tionn\303\251 au survol */\n"
"QTabBar::tab:!selected:hover {\n"
"    background-color: #FCB0B3;\n"
"}"));
        tabWidget_3->setUsesScrollButtons(true);
        tabWidget_3->setTabBarAutoHide(false);
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        Donnees_UT = new QTableView(tab_5);
        Donnees_UT->setObjectName(QStringLiteral("Donnees_UT"));
        Donnees_UT->setGeometry(QRect(30, 80, 821, 371));
        Donnees_UT->setStyleSheet(QLatin1String("QTableView {\n"
"  background-color: #bca0B3;\n"
"  color: white;\n"
"  border-radius: 10px;\n"
"}\n"
"\n"
"QTableView::item {\n"
"  padding: 4px;\n"
"  border: none;\n"
"}\n"
"\n"
"QTableView::item:selected {\n"
"  background-color: #19666f;\n"
"  color: white;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"  background-color: #003e46;\n"
"  color: white;\n"
"  padding: 4px;\n"
"  border: none;\n"
"}"));
        PDF_ut = new QPushButton(tab_5);
        PDF_ut->setObjectName(QStringLiteral("PDF_ut"));
        PDF_ut->setGeometry(QRect(390, 460, 91, 51));
        PDF_ut->setStyleSheet(QLatin1String("QPushButton {\n"
"   background-color: #fff;\n"
"   border: none;\n"
"   color: #333;\n"
"   padding: 10px 20px;\n"
"   text-align: center;\n"
"   text-decoration: none;\n"
"   display: inline-block;\n"
"   font-size: 14px;\n"
"   margin: 4px 2px;\n"
"   cursor: pointer;\n"
"   border-radius: 16px;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"   background-color: #F8B7C6;\n"
"}\n"
"\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"	background-color: #EF829B;\n"
"}"));
        PDF_ut->setIcon(icon5);
        PDF_ut->setIconSize(QSize(22, 22));
        recherche_3 = new QLabel(tab_5);
        recherche_3->setObjectName(QStringLiteral("recherche_3"));
        recherche_3->setGeometry(QRect(40, 10, 56, 16));
        recherche_3->setStyleSheet(QLatin1String("background : transparent;\n"
"color : white ;\n"
""));
        recherche_ut = new QLineEdit(tab_5);
        recherche_ut->setObjectName(QStringLiteral("recherche_ut"));
        recherche_ut->setGeometry(QRect(240, 40, 141, 22));
        recherche_ut->setStyleSheet(QLatin1String("border: 2px solid white;\n"
"	border-radius: 10px;"));
        tri_3 = new QLabel(tab_5);
        tri_3->setObjectName(QStringLiteral("tri_3"));
        tri_3->setGeometry(QRect(240, 10, 81, 16));
        tri_3->setStyleSheet(QLatin1String("background : transparent;\n"
"color : white;"));
        combo_ut = new QComboBox(tab_5);
        combo_ut->setObjectName(QStringLiteral("combo_ut"));
        combo_ut->setGeometry(QRect(40, 40, 101, 22));
        tabWidget_3->addTab(tab_5, QString());
        logout_ens_2 = new QPushButton(gestion_utilisateur);
        logout_ens_2->setObjectName(QStringLiteral("logout_ens_2"));
        logout_ens_2->setGeometry(QRect(1270, 10, 41, 41));
        logout_ens_2->setStyleSheet(QLatin1String("QPushButton {\n"
"   background-color: #fff;\n"
"   border: 2px solid white;\n"
"   color: #333;\n"
"   padding: 0 8px;\n"
"   text-align: center;\n"
"   text-decoration: none;\n"
"   display: inline-block;\n"
"   font-size: 14px;\n"
"   margin: 4px 2px;\n"
"   cursor: pointer;\n"
"   border-radius: 10px;\n"
"\n"
"\n"
"\n"
"    \n"
" \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"   background-color: #ec4c4c;\n"
"}\n"
"\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"	background-color: #ec4c4c;\n"
"\n"
"}"));
        logout_ens_2->setIcon(icon1);
        logout_ens_2->setIconSize(QSize(20, 20));
        return_3 = new QPushButton(gestion_utilisateur);
        return_3->setObjectName(QStringLiteral("return_3"));
        return_3->setGeometry(QRect(1220, 10, 41, 41));
        return_3->setStyleSheet(QLatin1String("QPushButton {\n"
"   background-color: #fff;\n"
"   border: 2px solid white;\n"
"   color: #333;\n"
"   padding: 0 8px;\n"
"   text-align: center;\n"
"   text-decoration: none;\n"
"   display: inline-block;\n"
"   font-size: 14px;\n"
"   margin: 4px 2px;\n"
"   cursor: pointer;\n"
"   border-radius: 10px;\n"
"\n"
"\n"
"\n"
"    \n"
" \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"   background-color: #ec4c4c;\n"
"}\n"
"\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"	background-color: #ec4c4c;\n"
"\n"
"}"));
        return_3->setIcon(icon8);
        return_3->setIconSize(QSize(20, 20));
        stackedWidget->addWidget(gestion_utilisateur);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1329, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);
        tabWidget_3->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Username", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Password", Q_NULLPTR));
        log_in->setText(QApplication::translate("MainWindow", "LOGIN", Q_NULLPTR));
        forget->setText(QApplication::translate("MainWindow", "Mot de passe oubli\303\251 ?", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", "BIENVENUE", Q_NULLPTR));
        background->setText(QString());
        background2->setText(QString());
        button_EL->setText(QApplication::translate("MainWindow", "Gestion Des El\303\251ves", Q_NULLPTR));
        button_EN->setText(QApplication::translate("MainWindow", "Gestion Des Enseignants", Q_NULLPTR));
        logout_menu->setText(QApplication::translate("MainWindow", "LOGOUT", Q_NULLPTR));
        button_UT->setText(QApplication::translate("MainWindow", "Gestion Des Utilisateurs", Q_NULLPTR));
        background3->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "ID :", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Nom :", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Prenom :", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Naissance :", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Age :", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Classe :", Q_NULLPTR));
        modifier->setText(QString());
        supprimer->setText(QString());
        ajouter->setText(QString());
        PDF_el->setText(QApplication::translate("MainWindow", "PDF", Q_NULLPTR));
        recherche->setText(QApplication::translate("MainWindow", "Tri :", Q_NULLPTR));
        tri->setText(QApplication::translate("MainWindow", "Recherche :", Q_NULLPTR));
        combo_el->clear();
        combo_el->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "ID", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Nom", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Classe", Q_NULLPTR)
        );
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Donn\303\251es", Q_NULLPTR));
        button_stats->setText(QApplication::translate("MainWindow", "Statistiques", Q_NULLPTR));
        refresh_stats->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Statistiques", Q_NULLPTR));
        logout_eleve->setText(QString());
        return_1->setText(QString());
        label_10->setText(QApplication::translate("MainWindow", "ID :", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "Nom :", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "Prenom :", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "Date d'entr\303\251e :", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "Specialit\303\251 :", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "Telephone :", Q_NULLPTR));
        modifier_2->setText(QString());
        supprimer_2->setText(QString());
        ajouter_2->setText(QString());
        label_17->setText(QApplication::translate("MainWindow", "Email :", Q_NULLPTR));
        PDF_en->setText(QApplication::translate("MainWindow", "PDF", Q_NULLPTR));
        combo_en->clear();
        combo_en->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "ID", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Nom", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Specialit\303\251", Q_NULLPTR)
        );
        tri_2->setText(QApplication::translate("MainWindow", "Recherche :", Q_NULLPTR));
        recherche_2->setText(QApplication::translate("MainWindow", "Tri :", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QApplication::translate("MainWindow", "Donn\303\251es", Q_NULLPTR));
        button_stats_2->setText(QApplication::translate("MainWindow", "Statistiques", Q_NULLPTR));
        refresh_stats_2->setText(QString());
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("MainWindow", "Statistiques", Q_NULLPTR));
        logout_ens->setText(QString());
        return_2->setText(QString());
        label_9->setText(QString());
        label_18->setText(QString());
        label_20->setText(QApplication::translate("MainWindow", "Username :", Q_NULLPTR));
        label_21->setText(QApplication::translate("MainWindow", "Password :", Q_NULLPTR));
        modifier_3->setText(QString());
        supprimer_3->setText(QString());
        ajouter_3->setText(QString());
        label_22->setText(QApplication::translate("MainWindow", "Role :", Q_NULLPTR));
        radio_el->setText(QApplication::translate("MainWindow", "Superviseur El\303\251ves", Q_NULLPTR));
        radio_en->setText(QApplication::translate("MainWindow", "Superviseur Enseignants", Q_NULLPTR));
        PDF_ut->setText(QApplication::translate("MainWindow", "PDF", Q_NULLPTR));
        recherche_3->setText(QApplication::translate("MainWindow", "Tri :", Q_NULLPTR));
        tri_3->setText(QApplication::translate("MainWindow", "Recherche :", Q_NULLPTR));
        combo_ut->clear();
        combo_ut->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Username", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Password", Q_NULLPTR)
        );
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_5), QApplication::translate("MainWindow", "Donn\303\251es", Q_NULLPTR));
        logout_ens_2->setText(QString());
        return_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
