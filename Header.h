#include <windows.h> // NULL sleep() ...
#include<stdio.h>
#include<conio.h> //getch ....
#include <stdlib.h>
#include<string.h>
#include<time.h> // date et time
#include<math.h> // abs() pow() ....
#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
typedef struct{
char Cin[9];
char nom[20];
char prenom[20];
char tele[12];
}client;

typedef struct{
int Ncmd;
char date[12];
char cin[9];
}cmd;

typedef struct{
int Ncmd;
int Nart; //numero artiicle
int qte;//qte achete
}lignecmd;

typedef struct{
int Nart; //Code article
char libelle[30];
float prix_U;
int qtes;//quantite en stock
}article;

/*******************Prototypes Des fonctions design*******************/
void rectangle(int x,int y,int l,int b);//cree un rectangle
void gotoxy(int x,int y);//aller a un postion dans le console
void connexion();//loging a se project
void bienvenue();//fonction non application...
void _password();//login password and username
void title(); //donnez la date time et le nom application
/**************************************************************/
char *date_output(char date[]);//date jj/mm/aaaa --->jj le nom de moi aet anneer
int date_Verifier(char _date[]);//validation date
char* date_input(char date[]); // jj/mm/aaa converter a mm/jj/aaaa
void File();//pointeur des fichiers
void Menu();//menu pricipale
int ChercherLigne(int *,int *);
int tailleligne();
void lister_achat();//lister les achat
void Modifier_Achat();//modiier un achat pas correct
void Facture();//facture de client
void enregisterAchat(lignecmd l,int p);
/*******************Prototypes Des fonctions Client*******************/
void menuClient();
int taille();
void AjouterClient();
void AffichierClient();
void ModifierClient();
void SupprimerClient();
void ListerClient();
void CommandeClient();
void TrierClient();
void Trier_Nom();
void Trier_Prenom();
int ChercherClient(char *);
void enregisterClient(client cl,int p);//p pos de client doit modifier
/**************************************************************/
/*******************Prototypes Des fonctions Article*******************/
void menuArticle();
int tailleA(); //calculer la taille de fcihier article
void AjouterArticle();
void AffichierArticle();
void ModifierArticle();
void trier_Article_Libelle();
void SupprimerArticle();
void ListerArticle();
int ChercherArticle(int *);
void enregisterArticle(article art,int p);//p pos de Article doit modifier
/**************************************************************/
/*******************Prototypes Des fonctions Commande*******************/
void menuCmd();
int tailleC(); //calculer la taille de fcihier Commande
void AjouterCmd();
void AffichierCmd();
void ModifierCmd();
void SupprimerCmd();
void ListerCmd();
int ChercherCmd(int *);
void enregisterCmd(cmd cm,int p);//p pos de Commande doit modifier
/**************************************************************/
void Acheter_Article();//les achat de cleint
/***********************Variable Globale***********************/
char date[13],ttime[10];
FILE *PClient,*PArticle,*PCmd,*Pligne;
static int erreur=0;
//pclient pinteur client fichier
//particle pointeur de  fichier article
//pcmd pinteur de fichier cmd
//pligne pointeur de fichier achat

/**************************************************************/

#endif // HEADER_H_INCLUDED
