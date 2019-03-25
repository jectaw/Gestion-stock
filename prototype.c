#include"Header.h"

void gotoxy(int x,int y){
COORD coo;
coo.X=x;
coo.Y=y;
HANDLE a=GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleCursorPosition(a,coo);
}
void rectangle(int x,int y,int l,int b){
int i,m;
gotoxy(x,y); printf("%c",254);
for(i=x+1;i<l-1;i++)
{
gotoxy(i,y);
printf("%c",223);
}
gotoxy(i,y); printf("%c",223);

for (m=y+1;m<b;m++)
{
gotoxy(x,m);
for(i=x;i<l;i++)
{
if(i==x||i==l-1)
{
gotoxy(i,m); printf("%c",223);
}

}

}

gotoxy(x,m); printf("%c",223);
for(i=x+1;i<l-1;i++)
{
gotoxy(i,m);
printf("%c",223);
}
gotoxy(i,m); printf("%c",223);
}

void title(){
int i;
system("cls");

rectangle(3,0,80,23);
gotoxy(32,1);
printf("GESTION COMMERCIALE");
gotoxy(5,3);
printf("Programmeur : TALHAOUY");
printf("\t\t\t\tDate : ");
_strdate(date);
date_output(date);
printf("%s",date);
_strtime(ttime);
gotoxy(30,4);printf("\t\t\t\ttime : ");
gotoxy(63,4);printf("%.5s",ttime);
gotoxy(4,5);
for(i=0;i<75;i++) printf("%c",196);

}
void _Password(){
system("cls");
rectangle(10,4,70,12);
char d[25]="Administrateur Control";
char ch,pass[10],user[10];
int i=0,j;

gotoxy(10,4);
for(j=0;j<22;j++)
{
Sleep(50);
printf("%c",223);
}
for(j=0;j<22;j++)
{
Sleep(50);
printf("%c",d[j]);
}
for(j=0;j<16;j++)
{
Sleep(50);
printf("%c",223);
}


gotoxy(15,7);
printf("Username:");
fflush(stdin);
gets(user);
gotoxy(15,9); printf("Password:");
while(ch!=13)
{
ch=getch();

if(ch!=13 && ch!=8){
putch('*');
pass[i] = ch;
i++;
}
}
pass[j] = '\0';
if(strcmp(strlwr(pass),"123456")==0 && strcmp(strlwr(user),"root")==0)
{

gotoxy(17,16);
printf("Password Correct ");
gotoxy(19,18);
printf("Tapez une touche pour  continue...");
getch();
system("cls");
}
else
{
++erreur;
if(erreur==3){exit(0);}
gotoxy(15,16);
printf("\aWarning!! Incorrect Password");
getch();
_Password();
}
connexion();

}
void bienvenue(){
int i;
char *titre,*d,*nom,*prenom;
titre="GESTION COMMERCIALE";
d="Designed and Programmed by:";
nom="TALHAOUY";
prenom="MHAMMED";
system("cls");
rectangle(0,0,80,23);
rectangle(14,4,60,15);
gotoxy(28,4);system("color b");for(i=0;titre[i]!='\0';i++){Sleep(50);printf("%c",titre[i]);}
gotoxy(25,8); for(i=0;d[i]!='\0';i++){Sleep(50);printf("%c",d[i]);}
gotoxy(25,9);for(i=0;i<27;i++){Sleep(50); printf("%c",254);}
gotoxy(33,11);for(i=0;nom[i]!='\0';i++){Sleep(50);printf("%c",nom[i]);}
gotoxy(33,13);for(i=0;prenom[i]!='\0';i++){Sleep(50);printf("%c",prenom[i]);}
gotoxy(24,20);printf("Tapez une touche pour continue...");

getch();
_Password();
}

void connexion(){
int i;
gotoxy(36,14);
printf("Connexion...");
gotoxy(30,15);
for(i=1;i<=23;i++){
Sleep(200);
printf("%c",219);
}
getch();
title();
}


/*******************************************************************************************************/
void menuClient(){
int choix,i;
do{
title();
rectangle(26,6,55,16);
gotoxy(35,6);printf("Menu Client");
gotoxy(30,8);printf("Ajouter Client   [1]");
gotoxy(30,9);printf("Affichier Client [2]");
gotoxy(30,10);printf("Modifier Client  [3]");
gotoxy(30,11);printf("Supprimer Client [4]");
gotoxy(30,12);printf("Lister Clients   [5]");
gotoxy(30,13);printf("Trier Clients    [6]");
gotoxy(30,14);printf("Commande_Client  [7]");
gotoxy(30,15);printf("Menu Principale  [0]");
gotoxy(4,17); for(i=0;i<75;i++) printf("_");
gotoxy(25,19);printf("Choix Enter [0 - 7] ");
choix=getche()-48;

switch(choix)
{
case 1:AjouterClient();break;
case 2:AffichierClient();break;
case 3:ModifierClient();break;
case 4:SupprimerClient();break;
case 5:ListerClient();break;
case 6:TrierClient();break;
case 7:CommandeClient();break;
case 0:break;
default:
putchar('\a');
}

}while(choix);

}
int taille(){
fseek(PClient,0L,2);
return ftell(PClient)/sizeof(client);

}
int ChercherClient(char *code){
int pos=-1,i;
client cl;
fseek(PClient,0L,SEEK_SET);
for(i=0;i<taille();i++){
fseek(PClient,i*sizeof(client),SEEK_SET);
fread(&cl,sizeof(client),1,PClient);
if(strcmp(code,cl.Cin)==0){
pos=i;break;
}
}

return pos;
}
void AjouterClient(){
int pos;
client cl;
title();
fseek(PClient,0L,SEEK_END);
gotoxy(25,8);printf("Entrez le Cin de client doit Ajouter:");
fflush(stdin);
gets(cl.Cin);
strcpy(cl.Cin,strlwr(cl.Cin));
pos=ChercherClient(cl.Cin);
if(pos==-1)
{ title();
gotoxy(25,7);printf("Nom Client :");fflush(stdin);gets(cl.nom);strcpy(cl.nom,strlwr(cl.nom));
gotoxy(25,8);printf("Prenom Client :");fflush(stdin);gets(cl.prenom);strcpy(cl.prenom,strlwr(cl.prenom));
gotoxy(25,9); printf("Telephone Client :");fflush(stdin);gets(cl.tele);
gotoxy(25,12);printf("Confirmer Ajouter de Client(oui/non)");
char rep[4];
scanf("%s",rep);
strlwr(rep);
    if(strcmp(rep,"oui")==0){
            fwrite(&cl,sizeof(client),1,PClient);

    gotoxy(25,14);printf("Ajouter avec succes");getch();
    }else if(strcmp(rep,"non")==0){
        gotoxy(25,14);printf("Ajouter ne pas confirmer");getch();
        }
}else AjouterClient();
}
void AffichierClient(){
int pos;
client cl;
title();
gotoxy(25,8);printf("Etrez le Cin de client doit Affichier:");
fflush(stdin);
gets(cl.Cin);strcpy(cl.Cin,strlwr(cl.Cin));
pos=ChercherClient(cl.Cin);
if(pos!=-1)

{ title();
fseek(PClient,pos*sizeof(client),0);
fread(&cl,sizeof(client),1,PClient);
gotoxy(25,7);printf("Nom Client :");printf("%s",cl.nom);
gotoxy(25,8);printf("Prenom Client :");printf("%s",cl.prenom);
gotoxy(25,9); printf("Telephone Client :");printf("%s",cl.tele);
gotoxy(25,12);printf("Tapez une touche pour continuer.....");getch();

}else AffichierClient();

}
void ListerClient(){
client cl;
int i;
title();
gotoxy(18,6);
for(i=0;i<=47;i++)
printf("%c",'*');
gotoxy(18,7);
puts("|   Cin   |    Nom    |  Prenom   | Telephone  |");
gotoxy(18,8);

for(i=0;i<=47;i++)printf("%c",'*');
for(i=0;i<taille();i++){
fseek(PClient,i*sizeof(client),SEEK_SET);
fread(&cl,sizeof(client),1,PClient);
gotoxy(18,9+i);
printf("|%9s|%11s|%11s|%12s|\n",cl.Cin,cl.nom,cl.prenom,cl.tele);

}
gotoxy(18,9+i);for(i=0;i<=47;i++)printf("%c",'*');

getch();

}
void ModifierClient(){
client cl;
int i,choix,pos;
title();
gotoxy(25,8);printf("Etrez le Cin de client doit Modifier:");
fflush(stdin);
gets(cl.Cin);strcpy(cl.Cin,strlwr(cl.Cin));
pos=ChercherClient(cl.Cin);
if(pos!=-1){
   fseek(PClient,pos*sizeof(client),0);
    fread(&cl,sizeof(client),1,PClient);
    gotoxy(25,9);printf("Nom Client :");printf("%s",cl.nom);
    gotoxy(25,10);printf("Prenom Client :");printf("%s",cl.prenom);
    gotoxy(25,11); printf("Telephone Client :");printf("%s",cl.tele);
    gotoxy(25,14);printf("Tapez une touche pour continuer.....");getch();
do{
title();
rectangle(26,6,55,13);
gotoxy(30,6);printf("Voulez-Vous Modifier:");
gotoxy(30,8);printf("Modifier Nom    [1]");
gotoxy(30,9);printf("Modifier Prenom [2]");
gotoxy(30,10);printf("Modifier phone  [3]");
gotoxy(30,11);printf("Quitter         [0]");
gotoxy(1,17); for(i=0;i<78;i++) printf("_");
gotoxy(25,19);printf("Choix Enter [0 - 3] :");
choix=getche()-48;

switch(choix)
{
case 1:{
title();
gotoxy(30,8);
fread(&cl,sizeof(client),1,PClient);
printf("Nouveau Nom :");fflush(stdin);gets(cl.nom);strcpy(cl.nom,strlwr(cl.nom));
}break;
case 2:{
title();
fread(&cl,sizeof(client),1,PClient);
gotoxy(30,8);
printf("Nouveau Prenom :");fflush(stdin);gets(cl.prenom);strcpy(cl.prenom,strlwr(cl.prenom));
}break;
case 3:{
title();
fread(&cl,sizeof(client),1,PClient);
gotoxy(30,8);
printf("Nouveau Telephone :");fflush(stdin);gets(cl.tele);
}break;
case 0:enregisterClient(cl,pos);break;
default:
putchar('\a');
}
}while(choix);

}else ModifierClient();
}
void enregisterClient(client cl,int p){
fseek(PClient,p*sizeof(client),0);
fwrite(&cl,sizeof(client),1,PClient);
}
void SupprimerClient(){
    int i,pos;
    client cl;
    title();
   gotoxy(25,8); printf("\tEntrez Cin de la Client a supprimer:");
    fflush(stdin);
    gets(cl.Cin);strcpy(cl.Cin,strlwr(cl.Cin));
    pos=ChercherClient(cl.Cin);
    if(pos!=-1){
        FILE *pf=fopen("cl.DAT","wb+");
            for(i=0;i<taille();i++){
                    if(i!=pos){
                        fseek(PClient,i*sizeof(client),SEEK_SET);
                        fread(&cl,sizeof(client),1,PClient);
                        fwrite(&cl,sizeof(client),1,pf);
                    }
            }
            fclose(pf);
            fclose(PClient);
            remove("client.DAT");
            rename("cl.DAT","client.DAT");
            free(pf);
            PClient=fopen("client.DAT","rb+");
           gotoxy(25,10);printf("Confirmer Supprission de Client(oui/non)");
char rep[4];
scanf("%s",rep);
strlwr(rep);
    if(strcmp(rep,"oui")==0){
    gotoxy(25,12);printf("Supprimer avec succes");getch();
    }else if(strcmp(rep,"non")==0){
        gotoxy(25,14);printf("Supprimer ne pas confirmer");getch();
        }
    }else SupprimerClient();


}
void TrierClient(){
int choix,i;

do{
title();
gotoxy(30,8);printf("Voulez-Vous Trier Par:");
gotoxy(30,10);printf("Nom Client    (A-->Z)   [1]");
gotoxy(30,11);printf("Prenom Client (A-->Z)   [2]");
gotoxy(30,12);printf("Retour Menu             [0]");
gotoxy(1,17); for(i=0;i<78;i++) printf("_");
gotoxy(25,19);printf("Choix Enter [0 - 2] ");
choix=getche()-48;

switch(choix)
{
case 1:Trier_Nom();break;
case 2:Trier_Prenom();break;
case 0:break;
default:
putchar('\a');
}

}while(choix);
}
void Trier_Nom(){
client cl1,cl2,cl;
int i,j;
for(j=0;j<taille();j++){
        for(i=0;i<taille()-j-1;i++){
                fseek(PClient,i*sizeof(client),SEEK_SET);
                fread(&cl1,sizeof(client),1,PClient);
                fseek(PClient,(i+1)*sizeof(client),SEEK_SET);
                fread(&cl2,sizeof(client),1,PClient);
            if(strcmp(cl1.nom,cl2.nom)==-1){
                cl=cl1;
                cl1=cl2;
                cl2=cl;

            }
enregisterClient(cl1,i+1);
enregisterClient(cl2,i);
        }

}
title();
gotoxy(18,6);
for(i=0;i<=47;i++)
printf("%c",'*');
gotoxy(18,7);
puts("|   Cin   |    Nom    |  Prenom   | Telephone  |");
gotoxy(18,8);
for(i=0;i<=47;i++)printf("%c",'*');
for(i=0;i<taille();i++){
   fseek(PClient,i*sizeof(client),SEEK_SET);
    fread(&cl1,sizeof(client),1,PClient);
gotoxy(18,9+i);
printf("|%9s|%11s|%11s|%12s|\n",cl1.Cin,cl1.nom,cl1.prenom,cl1.tele);

}
gotoxy(18,9+i);for(i=0;i<=47;i++)printf("%c",'*');

getch();

}
void Trier_Prenom(){
client cl1,cl2,cl;
int i,j;
for(j=0;j<taille();j++){
        for(i=0;i<taille()-j-1;i++){
                fseek(PClient,i*sizeof(client),SEEK_SET);
                fread(&cl1,sizeof(client),1,PClient);
                fseek(PClient,(i+1)*sizeof(client),SEEK_SET);
                fread(&cl2,sizeof(client),1,PClient);
            if(strcmp(cl1.prenom,cl2.prenom)==-1){
                cl=cl1;
                cl1=cl2;
                cl2=cl;

            }
enregisterClient(cl1,i+1);
enregisterClient(cl2,i);
        }

}
title();
gotoxy(18,6);
for(i=0;i<=47;i++)
printf("%c",'*');
gotoxy(18,7);
puts("|   Cin   |    Nom    |  Prenom   | Telephone  |");
gotoxy(18,8);
for(i=0;i<=47;i++)printf("%c",'*');
for(i=0;i<taille();i++){
   fseek(PClient,i*sizeof(client),SEEK_SET);
    fread(&cl1,sizeof(client),1,PClient);
gotoxy(18,9+i);
printf("|%9s|%11s|%11s|%12s|\n",cl1.Cin,cl1.nom,cl1.prenom,cl1.tele);

}
gotoxy(18,9+i);for(i=0;i<=47;i++)printf("%c",'*');

getch();

}
void CommandeClient(){
    title();
    client cl;
    cmd cm;
    lignecmd ligne;
    article art;
    int pc,i,j,pa;
    gotoxy(30,7);
    printf("Cin Client :");fflush(stdin);gets(cl.Cin);strcpy(cl.Cin,strlwr(cl.Cin));
    title();
    pc=ChercherClient(cl.Cin);
    if(pc!=-1){
             fseek(PClient,pc*sizeof(client),SEEK_SET);
            fread(&cl,sizeof(client),1,PClient);
        gotoxy(18,7);printf("Les Commandes de Client :");
        gotoxy(18,9);printf("Nom Client             : %s",cl.nom);
        gotoxy(18,10);printf("Prenom Client          : %s",cl.prenom);

        gotoxy(18,12);
        for(i=0;i<=30;i++)
        printf("%c",'*');
        gotoxy(18,13);
        puts("| NCmd  |  Libelle   |  Qte   |");
        gotoxy(18,14);
        for(i=0;i<=30;i++)printf("%c",'*');

      for(i=0;i<tailleC();i++){
        fseek(PCmd,i*sizeof(cmd),SEEK_SET);
        fread(&cm,sizeof(cmd),1,PCmd);
        if(strcmp(cm.cin,cl.Cin)==0){
           for(j=0;j<tailleligne();j++){
            fseek(Pligne,j*sizeof(lignecmd),SEEK_SET);
            fread(&ligne,sizeof(lignecmd),1,Pligne);
            if(ligne.Ncmd==cm.Ncmd){
                pa=ChercherArticle(&ligne.Nart);
                if(pa!=-1){
                    fseek(PArticle,pa*sizeof(article),SEEK_SET);
                    fread(&art,sizeof(article),1,PArticle);

                    gotoxy(18,15+i);printf("|%7d|%12s|%8d|\n",cm.Ncmd,art.libelle,ligne.qte);
               }
               }
               }
               }
               }
}else{CommandeClient();}
    gotoxy(18,15+i);
for(i=0;i<=30;i++)printf("%c",'*');

getch();
}
/*************************************Fonctions Pracipale***********************************/
void File(){ //les pointeurs des fichiers
PArticle=fopen("Article.DAT","rb+");
if(PArticle==NULL)
PArticle=fopen("Article.DAT","wb+");

PCmd=fopen("Cmd.DAT","rb+");
if(PCmd==NULL)
PCmd=fopen("Cmd.DAT","wb+");

PClient=fopen("client.DAT","rb+");
if(PClient==NULL)
PClient=fopen("client.DAT","wb+");

Pligne=fopen("achat.DAT","rb+");
if(Pligne==NULL)
    Pligne=fopen("achat.DAT","wb+");

}
void Menu(){
int choix,i;
File();
do{
title();
rectangle(26,6,55,16);
gotoxy(33,6);printf("Menu Principale");
gotoxy(30,9);printf("Menu Client     [1]");
gotoxy(30,10);printf("Menu Article    [2]");
gotoxy(30,11);printf("Menu Commande   [3]");
gotoxy(30,12);printf("Autre Choise    [4]");
gotoxy(30,13);printf("Quitter App     [0]");
gotoxy(4,17); for(i=0;i<75;i++) printf("_");
gotoxy(25,19);printf("Choix Enter [0 - 4] ");
choix=getche()-48;

switch(choix)
{
case 1:menuClient();break;
case 2:menuArticle();break;
case 3:menuCmd();break;
case 4:{
        int res;
        do{
        title();
gotoxy(30,9);printf("Facture Client     [1]");
gotoxy(30,10);printf("Ajouter Les Achats [2]");
gotoxy(30,11);printf("Modifier un Achat  [3]");
gotoxy(30,12);printf("Lister Les Achats  [4]");
gotoxy(30,13);printf("Retour Au Menu     [0]");
gotoxy(4,17); for(i=0;i<75;i++) printf("_");
gotoxy(25,19);printf("Choix Enter [0 - 4] ");
res=getche()-48;
switch(res){
    case 1:{system("cls");Facture();}break;
    case 4:lister_achat();break;
    case 2:Acheter_Article();break;
    case 3:Modifier_Achat();break;
    case 0:break;
    default :
        putchar('\a');
            }
      }while(res);}break;
case 0:{
    fclose(PClient);fclose(PCmd);fclose(Pligne);fclose(PArticle);
   title();
        gotoxy(25,12);printf("Confirmer quitter application(oui/non)");
char rep[4];
scanf("%s",rep);fflush(stdin);
strlwr(rep);
    if(strcmp(rep,"oui")==0){
           exit(0);

    gotoxy(25,14);printf("quitter avec succes");getch();
    }else if(strcmp(rep,"non")==0){
                getch();
        }
        }break;
default:
putchar('\a');
}

}while(choix);

}

/*************************************Article Fonctions*************************************/
void menuArticle(){
int choix,i;

do{
title();
rectangle(26,6,55,16);
gotoxy(34,6);printf("Menu Article");
gotoxy(30,8);printf("Ajouter Article    [1]");
gotoxy(30,9);printf("Affichier Article  [2]");
gotoxy(30,10);printf("Modifier Article   [3]");
gotoxy(30,11);printf("Supprimer Article  [4]");
gotoxy(30,12);printf("Lister Article     [5]");
gotoxy(30,13);printf("Trier Article(A-Z) [6]");
gotoxy(30,14);printf("Menu Principale    [0]");
gotoxy(4,17); for(i=0;i<75;i++) printf("_");
gotoxy(25,19);printf("Choix Enter [0 - 6] ");
choix=getche()-48;

switch(choix)
{
case 1:AjouterArticle();break;
case 2:AffichierArticle();break;
case 3:ModifierArticle();break;
case 4:SupprimerArticle();break;
case 5:ListerArticle();break;
case 6:trier_Article_Libelle();break;
case 0:break;
default:
putchar('\a');
}

}while(choix);

}
int ChercherArticle(int *artcode){
int pos=-1,i;
article art;
fseek(PClient,0L,SEEK_SET);
for(i=0;i<tailleA();i++){
fseek(PArticle,i*sizeof(article),SEEK_SET);
fread(&art,sizeof(article),1,PArticle);
if(*artcode==art.Nart){
pos=i;break;
}
}
return pos;
}
int tailleA(){
fseek(PArticle,0L,SEEK_END);
return ftell(PArticle)/sizeof(article);
}
void AjouterArticle(){
int pos,Cle; //article cpt automatique
article art;
fseek(PClient,0L,SEEK_END);
title();
Cle=tailleA();
++Cle;
start:
art.Nart=Cle;
pos=ChercherArticle(&art.Nart);
if(pos==-1)
{
title();
gotoxy(25,7);printf("Libelle Article :");
fflush(stdin);
gets(art.libelle);
strcpy(art.libelle,strlwr(art.libelle));
gotoxy(25,8);printf("Prix_unitaire Article (DH) :");
fflush(stdin);scanf("%f",&art.prix_U);
gotoxy(25,9); printf("Quantite En Stock Article :");
fflush(stdin);scanf("%d",&art.qtes);
gotoxy(25,12);printf("Confirmer Ajouter de Article (oui/non)");
fflush(stdin);
char rep[4];
scanf("%s",rep);
strlwr(rep);
if(strcmp(rep,"oui")==0){
        fwrite(&art,sizeof(article),1,PArticle);

    gotoxy(25,14);
    printf("Ajouter avec succes");getch();
}else{
     gotoxy(25,14);
     printf("Ajouter ne pas confirmer");getch();
     }
}else {++Cle;goto start;}
}
void ListerArticle(){
article art;
int i;
title();
gotoxy(12,6);
for(i=0;i<=58;i++)
printf("%c",'*');
gotoxy(12,7);
puts("| N_Article | Libelle | Prix_Unitaire(DH) | Quanite_Stock |");
gotoxy(12,8);

for(i=0;i<=58;i++)printf("%c",'*');
for(i=0;i<tailleA();i++){
fseek(PArticle,i*sizeof(article),SEEK_SET);
fread(&art,sizeof(article),1,PArticle);
gotoxy(12,9+i);
printf("|%10d |%9s|%19.2f|%15d|\n",art.Nart,art.libelle,art.prix_U,art.qtes);

}
gotoxy(12,9+i);for(i=0;i<=58;i++)printf("%c",'*');
getch();

}
void trier_Article_Libelle(){
article art1,art2,art;
int i,j;
for(j=0;j<tailleA();j++){
        for(i=0;i<tailleA()-j-1;i++){
                fseek(PArticle,i*sizeof(article),SEEK_SET);
                fread(&art1,sizeof(article),1,PArticle);
                fseek(PArticle,(i+1)*sizeof(article),SEEK_SET);
                fread(&art2,sizeof(article),1,PArticle);
            if(strcmp(art1.libelle,art2.libelle)==-1){
                art=art1;
                art1=art2;
                art2=art;

            }
enregisterArticle(art1,i+1);
enregisterArticle(art2,i);
        }

}
title();
gotoxy(12,6);
for(i=0;i<=58;i++)
printf("%c",'*');
gotoxy(12,7);
puts("| N_Article | Libelle | Prix_Unitaire(DH) | Quanite_Stock |");
gotoxy(12,8);

for(i=0;i<=58;i++)printf("%c",'*');
for(i=0;i<tailleA();i++){
fseek(PArticle,i*sizeof(article),SEEK_SET);
fread(&art1,sizeof(article),1,PArticle);
gotoxy(12,9+i);
printf("|%10d |%9s|%19.2f|%15d|\n",art1.Nart,art1.libelle,art1.prix_U,art1.qtes);

}
gotoxy(12,9+i);for(i=0;i<=58;i++)printf("%c",'*');
getch();



}

void AffichierArticle(){
int pos;
article art;
title();
gotoxy(25,8);printf("Entrez le Numero Article doit Affichier:");
fflush(stdin);
scanf("%d",&art.Nart);
pos=ChercherArticle(&art.Nart);
if(pos!=-1)

{ title();
fseek(PArticle,pos*sizeof(article),0);

fread(&art,sizeof(article),1,PArticle);
gotoxy(25,7);printf("Libelle Article :");printf("%s",art.libelle);
gotoxy(25,8);printf("Prix_Unitaire Article :");printf("%2.f DH",art.prix_U);
gotoxy(25,9); printf("Quantite_Stock Article :");printf("%d",art.qtes);
    gotoxy(25,13);printf("Tapez une touche pour continuer.....");getch();
}else AffichierArticle();

}
void ModifierArticle(){
article art;
int i,choix,pos;
title();
gotoxy(25,8);printf("Etrez le Numero Article doit Modifier:");
fflush(stdin);
scanf("%d",&art.Nart);
pos=ChercherArticle(&art.Nart);
if(pos!=-1){
fseek(PArticle,pos*sizeof(article),0);
fread(&art,sizeof(article),1,PArticle);
gotoxy(25,7);printf("Libelle Article :");printf("%s",art.libelle);
gotoxy(25,8);printf("Prix_Unitaire Article :");printf("%2.f DH",art.prix_U);
gotoxy(25,9); printf("Quantite_Stock Article :");printf("%d",art.qtes);
gotoxy(25,13);printf("Tapez une touche pour continuer.....");getch();

do{
title();
rectangle(26,6,60,13);
gotoxy(30,6);printf("Voulez-Vous Modifier:");
gotoxy(30,8);printf("Modifier Libelle        [1]");
gotoxy(30,9);printf("Modifier Prix_Unitaire  [2]");
gotoxy(30,10);printf("Modifier Quantite_Stock [3]");
gotoxy(30,11);printf("Quitter                 [0]");
gotoxy(1,17); for(i=0;i<78;i++) printf("_");
gotoxy(25,19);printf("Choix Enter [0 - 3] :");
choix=getche()-48;

switch(choix)
{
case 1:{
title();
gotoxy(30,8);
fread(&art,sizeof(article),1,PArticle);
printf("Nouveau Libelle :");fflush(stdin);gets(art.libelle);strcpy(art.libelle,strlwr(art.libelle));
}break;
case 2:{
title();
fread(&art,sizeof(article),1,PArticle);
gotoxy(30,8);
printf("Nouveau Prix_Unitaire :");fflush(stdin);scanf("%f",&art.prix_U);
}break;
case 3:{
title();
fread(&art,sizeof(article),1,PArticle);
gotoxy(30,8);
printf("Nouveau Quantite_Stock:");fflush(stdin);scanf("%d",&art.qtes);
}break;
case 0:enregisterArticle(art,pos);break;
default:
putchar('\a');
}
}while(choix);

}else ModifierArticle();
}
void SupprimerArticle(){
    int i,pos;
    article art;
    title();
   gotoxy(20,8); printf("\tEntrez Numero de Article a supprimer:");
   scanf("%d",&art.Nart);
    pos=ChercherArticle(&art.Nart);
    if(pos!=-1){
        FILE *pf=fopen("art.DAT","wb+");
            for(i=0;i<tailleA();i++){
                    if(i!=pos){
                        fseek(PArticle,i*sizeof(article),SEEK_SET);
                        fread(&art,sizeof(article),1,PArticle);
                        fwrite(&art,sizeof(article),1,pf);
                    }
            }
            fclose(pf);
            fclose(PArticle);
            remove("Article.DAT");
            rename("art.DAT","Article.DAT");
            free(pf);
            PArticle=fopen("Article.DAT","rb+");
           gotoxy(20,10);printf("Confirmer Supprission de Article(oui/non)");
char rep[4];
scanf("%s",rep);
strlwr(rep);
    if(strcmp(rep,"oui")==0){
    gotoxy(25,12);printf("Supprimer avec succes");getch();
    }else if(strcmp(rep,"non")==0){
        gotoxy(25,14);printf("Supprimer ne pas confirmer");getch();
        }
    }else SupprimerArticle();


}
void enregisterArticle(article art,int p){
fseek(PArticle,p*sizeof(article),0);
fwrite(&art,sizeof(article),1,PArticle);
}

/*****************************command [Date]**********************************/
char* date_input(char date[]) // jj/mm/aaa converter a mm/jj/aaaa
{
char temp[15];

temp[3]=date[0];
temp[4]=date[1];
temp[0]=date[3];
temp[1]=date[4];
temp[6]=date[8];
temp[7]=date[9];
temp[8]='\0';
temp[2]=temp[5]='/';
strcpy(date,temp);
return date;
}
char *date_output(char date[]) //mm/jj/aa converter a jj mm, aaaa
{
struct
{
int dd;
char mm[4];
int yyyy;
}_date;

char temp[15];
int mm,c,i;
_date.dd=(date[3]-48)*10+(date[4]-48);

mm=(date[0]-48)*10+(date[1]-48);
_date.yyyy=2000+(date[6]-48)*10+(date[7]-48);
switch(mm)
{
case 1: strcpy(_date.mm,"Jan"); break;
case 2: strcpy(_date.mm,"Fev"); break;
case 3: strcpy(_date.mm,"Mar"); break;
case 4: strcpy(_date.mm,"Avr"); break;
case 5: strcpy(_date.mm,"Mai"); break;
case 6: strcpy(_date.mm,"Jui"); break;
case 7: strcpy(_date.mm,"Jui"); break;
case 8: strcpy(_date.mm,"Aou"); break;
case 9: strcpy(_date.mm,"Sep"); break;
case 10: strcpy(_date.mm,"Oct"); break;
case 11: strcpy(_date.mm,"Nov"); break;
case 12: strcpy(_date.mm,"Dec"); break;
}

temp[0]=(int)(_date.dd/10)+48;
temp[1]=(int)(_date.dd%10)+48;
temp[2]=32;
temp[3]='\0';
strcat(temp,_date.mm);
temp[6]=',';
c=0;
temp[7]=32;
for(i=3;i>=0;i--)
{
temp[8+c]=(int)(_date.yyyy/pow(10,i))+48;
c++;
_date.yyyy%=(int)pow(10,i);
}
temp[12]='\0';
strcpy(date,temp);
return date;
}
int date_Verifier(char _date[]) //_date[] is in format dd/mm/yyyy
{
int err=0,mm,dd,yyyy;
if(strlen(_date)!=10) err++;
if(_date[2]!='/'||_date[5]!='/') err++;
mm=(_date[3]-48)*10+(_date[4]-48);
if (mm>12) err++;
dd=(_date[0]-48)*10+(_date[1]-48);

yyyy=(_date[6]-48)*1000+(_date[7]-48)*100+(_date[8]-48)*10+(_date[9]-48);

switch(mm)
{
case 1: if (dd>31) err++; break;
case 2:
if (dd>28) err++;
if (yyyy%4==0&&dd==29) err--;
break;
case 3: if (dd>31) err++; break;
case 4: if (dd>30) err++; break;
case 5: if (dd>31) err++; break;
case 6: if (dd>30) err++; break;
case 7: if (dd>31) err++; break;
case 8: if (dd>31) err++; break;
case 9: if (dd>30) err++; break;
case 10: if (dd>31) err++; break;
case 11: if (dd>30) err++; break;
case 12: if (dd>31) err++; break;

}

if (err==0)
return 1;
else
return 0;

}
/********************************************************************************************************/
/****************************************fonctions Commande***************************************/
void menuCmd(){
int choix,i;
do{
title();
rectangle(26,6,55,16);
gotoxy(34,6);printf("Menu Commande");

gotoxy(30,8);printf("Ajouter Commande   [1]");
gotoxy(30,9);printf("Affichier Commande [2]");
gotoxy(30,10);printf("Modifier Commande  [3]");
gotoxy(30,11);printf("Supprimer Commande [4]");
gotoxy(30,12);printf("Lister Commande    [5]");
gotoxy(30,13);printf("Menu Principale    [0]");
gotoxy(4,17); for(i=0;i<75;i++) printf("_");
gotoxy(25,19);printf("Choix Enter [0 - 5] ");
choix=getche()-48;

switch(choix)
{
case 1:AjouterCmd();break;
case 2:AffichierCmd();break;
case 3:ModifierCmd();break;
case 4:SupprimerCmd();break;
case 5:ListerCmd();break;
case 0:fclose(PCmd);break;
default:
putchar('\a');
}

}while(choix);

}
void enregisterCmd(cmd cm,int p){
fseek(PCmd,p*sizeof(cmd),0);
fwrite(&cm,sizeof(cmd),1,PCmd);
}
int ChercherCmd(int *c){
PClient=fopen("client.DAT","rb+");
int pos=-1,i;
cmd cm;
fseek(PCmd,0L,SEEK_SET);
for(i=0;i<tailleC();i++){
fseek(PCmd,i*sizeof(cmd),SEEK_SET);
fread(&cm,sizeof(cmd),1,PCmd);
if(*c==cm.Ncmd){
pos=i;break;
}
}
return pos;
}
int tailleC(){
fseek(PCmd,0L,SEEK_END);
return ftell(PCmd)/sizeof(cmd);
}
void AjouterCmd(){
int pos,cpt;
cmd cm;
fseek(PCmd,0L,SEEK_END);
title();
gotoxy(25,8);
cpt=tailleC();
++cpt;
ss:
cm.Ncmd=cpt;
pos=ChercherCmd(&cm.Ncmd);
if(pos==-1)
{
    cn:
title();

gotoxy(25,7);printf("Cin Client :");fflush(stdin);gets(cm.cin);strcpy(cm.cin,strlwr(cm.cin));
if(ChercherClient(cm.cin)!=-1){
        start:
gotoxy(25,8);printf("Date Commande (JJ/MM/AAAA) :");fflush(stdin);gets(cm.date);
if(date_Verifier(cm.date)==0)goto start;
}else goto cn;
gotoxy(25,12);printf("Confirmer Ajouter de Commande(oui/non)");
char rep[4];
scanf("%s",rep);
strlwr(rep);
if(strcmp(rep,"oui")==0){
    fwrite(&cm,sizeof(cmd),1,PCmd);
    gotoxy(25,14);printf("Ajouter avec succes");getch();
}else if(strcmp(rep,"non")==0){
     gotoxy(25,14);printf("Ajouter ne pas confirmer");getch();
}

}else{++cpt;goto ss;}


}
void ListerCmd(){
cmd cm;
int i;
title();
gotoxy(12,6);
for(i=0;i<=43;i++)
printf("%c",'*');
gotoxy(12,7);
puts("| N_Commande | Cin_Client | Date Commande |");
gotoxy(12,8);

for(i=0;i<=43;i++)printf("%c",'*');
for(i=0;i<tailleC();i++){
fseek(PCmd,i*sizeof(cmd),SEEK_SET);
fread(&cm,sizeof(cmd),1,PCmd);
gotoxy(12,9+i);
//strcpy(cm.date, date_output(date_input(cm.date)));
printf("|%12d |%12s|%15s|\n",cm.Ncmd,cm.cin,cm.date);

}
gotoxy(12,9+i);for(i=0;i<=43;i++)printf("%c",'*');

getch();

}
void AffichierCmd(){
int pos;
cmd cm;
title();
gotoxy(25,8);
printf("Entrez le Numero Commande doit Affichier:");
scanf("%d",&cm.Ncmd);
pos=ChercherCmd(&cm.Ncmd);
if(pos!=-1)
{

title();
fseek(PCmd,pos*sizeof(cmd),0);

fread(&cm,sizeof(cmd),1,PCmd);
gotoxy(25,7);printf("Cin Client :");printf("%s",cm.cin);
gotoxy(25,8);printf("Date Commande :");printf("%s",date_output(cm.date));
gotoxy(25,12);printf("Tapez une touche pour continuer.....");getch();

}else AffichierCmd();
}
void ModifierCmd(){
cmd cm;
int i,choix,pos;
char cinn[9];
title();
gotoxy(20,7);printf("Entrez le Numero Commande doit Modifier:");
scanf("%d",&cm.Ncmd);
pos=ChercherCmd(&cm.Ncmd);
if(pos!=-1){
fseek(PCmd,pos*sizeof(cmd),0);
fread(&cm,sizeof(cmd),1,PCmd);
gotoxy(25,8);printf("Cin Client :");printf("%s",cm.cin);
gotoxy(25,9);printf("Date Commande :");printf("%s",date_output(date_input(cm.date)));
    gotoxy(25,12);printf("Tapez une touche pour continuer.....");getch();

do{
title();
rectangle(26,6,60,13);
gotoxy(30,6);printf("Voulez-Vous Modifier:");
gotoxy(30,8);printf("Modifier Cin Client    [1]");
gotoxy(30,9);printf("Modifier Date Commande [2]");
gotoxy(30,10);printf("Quitter                [0]");
gotoxy(1,17); for(i=0;i<78;i++) printf("_");
gotoxy(25,19);printf("Choix Enter [0 - 2] :");
choix=getche()-48;

switch(choix)
{
case 1:{
start:
title();
gotoxy(30,8);
fseek(PCmd,pos*sizeof(cmd),0);

fread(&cm,sizeof(cmd),1,PCmd);
printf("Nouveau Cin Client :");fflush(stdin);gets(cinn);strcpy(cinn,strlwr(cinn));

if(ChercherClient(cinn)==-1){
putchar('\a');
goto start;
}else strcpy(cm.cin,cinn);
}break;
case 2:{
first:
title();
gotoxy(30,8);
fseek(PCmd,pos*sizeof(cmd),0);

fread(&cm,sizeof(cmd),1,PCmd);
printf("Nouveau Date Commande :");fflush(stdin);gets(cm.date);
if(date_Verifier(cm.date)==1){
        gotoxy(30,10);
printf("OK");getch();}else{goto first;}
}break;

case 0:enregisterCmd(cm,pos);break;
default:
putchar('\a');
}
}while(choix);

}else ModifierCmd();
}
void SupprimerCmd(){
    int i,pos;
   cmd cm;
    title();
   gotoxy(20,8); printf("\tEntrez Numero de Commande a supprimer:");
   scanf("%d",&cm.Ncmd);
    pos=ChercherCmd(&cm.Ncmd);
    if(pos!=-1){
        FILE *pf=fopen("cm.DAT","wb+");
            for(i=0;i<tailleC();i++){
                    if(i!=pos){
                        fseek(PCmd,i*sizeof(cmd),SEEK_SET);
                        fread(&cm,sizeof(cmd),1,PCmd);
                        fwrite(&cm,sizeof(cmd),1,pf);
                    }
            }
            fclose(pf);
            fclose(PCmd);
            remove("Cmd.DAT");
            rename("cm.DAT","Cmd.DAT");
            free(pf);
            PArticle=fopen("Cmd.DAT","rb+");
           gotoxy(20,10);printf("Confirmer Supprission de Commande(oui/non)");
char rep[4];
scanf("%s",rep);
strlwr(rep);
    if(strcmp(rep,"oui")==0){
    gotoxy(25,12);printf("Supprimer avec succes");getch();
    }else if(strcmp(rep,"non")==0){
        gotoxy(25,14);printf("Supprimer ne pas confirmer");getch();
        }
    }else SupprimerArticle();


}
/**********************************************les achats des articles**************************************/
void enregisterAchat(lignecmd l,int p){
fseek(Pligne,p*sizeof(lignecmd),SEEK_SET);
fwrite(&l,sizeof(lignecmd),1,Pligne);
}
int ChercherLigne(int *codecm,int *codeart){
int pos=-1,i;
lignecmd ligne;
fseek(Pligne,0L,SEEK_SET);
for(i=0;i<tailleligne();i++){
fseek(Pligne,i*sizeof(lignecmd),SEEK_SET);
fread(&ligne,sizeof(lignecmd),1,Pligne);
if(*codecm==ligne.Ncmd && *codeart==ligne.Nart){
pos=i;break;
}
}
return pos;
}
int tailleligne(){
fseek(Pligne,0L,SEEK_END);
return ftell(Pligne)/sizeof(lignecmd);
}
void Modifier_Achat(){
lignecmd ligne;
article art;
int i,choix,pos,pp,nouveau; //quantite nouveau pp article pos  lignecmd achat
title();
gotoxy(25,8);printf("Etrez le NCommande :");scanf("%d",&ligne.Ncmd);
gotoxy(25,9);printf("Etrez le NArticle  :");scanf("%d",&ligne.Nart);
pos=ChercherLigne(&ligne.Ncmd,&ligne.Nart);
if(pos!=-1){
   fseek(Pligne,pos*sizeof(lignecmd),0);
    fread(&ligne,sizeof(lignecmd),1,Pligne);
    pp=ChercherArticle(&ligne.Nart);
    if(pp!=-1){
        fseek(PArticle,pp*sizeof(article),SEEK_SET);
        fread(&art,sizeof(article),1,PArticle);

    gotoxy(25,9);printf("NCommande:");printf("%d",ligne.Ncmd);
    gotoxy(25,10);printf("Libelle :");printf("%s",art.libelle);
    gotoxy(25,11); printf("Qte_Acheter:");printf("%d",ligne.qte);
    gotoxy(25,14);printf("Tapez une touche pour continuer.....");getch();
    }
do{
title();
rectangle(26,6,60,13);
gotoxy(30,6);printf("Voulez-Vous Modifier:");
gotoxy(30,8);printf("Modifier Ncmd       [1]");
gotoxy(30,9);printf("Modifier Narticle   [2]");
gotoxy(30,10);printf("Modifier Qte_Achter [3]");
gotoxy(30,11);printf("Quitter             [0]");
gotoxy(1,17); for(i=0;i<78;i++) printf("_");
gotoxy(25,19);printf("Choix Enter [0 - 3] :");
choix=getche()-48;

switch(choix)
{
case 1:{
title();
gotoxy(30,8);
fseek(Pligne,pos*sizeof(lignecmd),0);
fread(&ligne,sizeof(lignecmd),1,Pligne);
printf("Nouveau Ncmd :");scanf("%d",&nouveau);
if(ChercherCmd(&nouveau)!=-1){
    ligne.Ncmd=nouveau;
}
}break;
case 2:{
title();
fseek(Pligne,pos*sizeof(lignecmd),0);
fread(&ligne,sizeof(lignecmd),1,Pligne);
gotoxy(30,8);
printf("Nouveau Narticle :");scanf("%d",&nouveau);
pp=ChercherArticle(&nouveau);
if(pp!=-1){
    fseek(PArticle,pp*sizeof(article),SEEK_SET);
    fread(&art,sizeof(article),1,PArticle);
    art.qtes=art.qtes-ligne.qte;
}
enregisterArticle(art,pp); // save le changement a le posiotion de article
pp=ChercherArticle(&ligne.Nart);
if(pp!=-1){
    fseek(PArticle,pp*sizeof(article),SEEK_SET);
    fread(&art,sizeof(article),1,PArticle);
    art.qtes=art.qtes+ligne.qte;
}
enregisterArticle(art,pp);
}break;
case 3:{
title();
fseek(Pligne,pos*sizeof(lignecmd),SEEK_SET);
fread(&ligne,sizeof(lignecmd),1,Pligne);

fseek(PArticle,pp*sizeof(article),SEEK_SET);
fread(&art,sizeof(article),1,PArticle);

gotoxy(30,8);
printf("Nouveau Qte_Achter :");scanf("%d",&nouveau);
if(nouveau>ligne.qte){
    nouveau=nouveau-ligne.qte;
    art.qtes=art.qtes-nouveau;
}else{
    nouveau=nouveau-ligne.qte;
art.qtes=art.qtes+abs(nouveau);

}

}break;
case 0:enregisterAchat(ligne,pos);enregisterArticle(art,pp);break;
default:
putchar('\a');
}
}while(choix);

}else Modifier_Achat();



}
void Acheter_Article(){
lignecmd ligne;
article art;
int pos,ppc,pa,Q; //ppc position cmd pos position article n nombre article acheter Q si le numero de commannde et num article exist deja la somme de quantite ancien et qte nouveau de meme produit
    ListerArticle();
    title();
    gotoxy(25,7);printf("****Les Articles Acheters****");
    gotoxy(25,10); printf("Entrez le Numero de commande:"); scanf("%d",&ligne.Ncmd);
    gotoxy(25,11); printf("Entrez le Numero de Article:"); scanf("%d",&ligne.Nart);
    pa=ChercherLigne(&ligne.Ncmd,&ligne.Nart);
       pos=ChercherArticle(&ligne.Nart);
    ppc=ChercherCmd(&ligne.Ncmd);
    if(  ppc!=-1 && pos!=-1){
    if(pa!=-1){
        fseek(Pligne,pa*sizeof(lignecmd),SEEK_SET);
        fread(&ligne,sizeof(lignecmd),1,Pligne);
        qq:
         gotoxy(25,12);  printf("La Quantiter acheter :");
                    scanf("%d",&Q);
                       fseek(PArticle,pos*sizeof(article),SEEK_SET);
                       fread(&art,sizeof(article),1,PArticle);
                       ligne.qte=ligne.qte+Q;
                       art.qtes-=Q;
if(art.qtes<0){gotoxy(25,15);printf("Cette Quantitee pas trouver dans stock");getch();system("cls");goto qq;}

        fseek(Pligne,pa*sizeof(lignecmd),SEEK_SET);
        fwrite(&ligne,sizeof(lignecmd),1,Pligne);
         enregisterArticle(art,pos);
    }else if(pa==-1){

        QTE:
      gotoxy(25,12);  printf("La Quantiter acheter :");
                    scanf("%d",&ligne.qte);
                       fseek(PArticle,pos*sizeof(article),SEEK_SET);
                       fread(&art,sizeof(article),1,PArticle);
                       art.qtes-=ligne.qte;
                       if(art.qtes<0){gotoxy(25,15);printf("Cette Quantitee pas trouver dans stock");getch();system("cls");goto QTE;}

        fseek(Pligne,0L,SEEK_END);
        fwrite(&ligne,sizeof(lignecmd),1,Pligne);
        enregisterArticle(art,pos);
}
}else Acheter_Article();
}

void lister_achat(){
    lignecmd ligne;
    int i;
    title();
    gotoxy(18,6);
for(i=0;i<=32;i++)
printf("%c",'*');
gotoxy(18,7);
puts("| NCmd | Narticle | Qte_acheter |");
gotoxy(18,8);
for(i=0;i<=32;i++)printf("%c",'*');

    for(i=0;i<tailleligne();i++){
        fseek(Pligne,i*sizeof(lignecmd),SEEK_SET);
        fread(&ligne,sizeof(lignecmd),1,Pligne);
        gotoxy(18,9+i);
printf("|%6d|%10d|%13d|\n",ligne.Ncmd,ligne.Nart,ligne.qte);

    }
     gotoxy(18,9+i);for(i=0;i<=32;i++)printf("%c",'*');

getch();
}

void Facture(){
    int cpt=tailleligne(),j,pc,num,pl,pa,i;
    //pa position article pl position client pc postion cmd
    client cl;
    cmd cm;
    lignecmd ligne;
    article art;
    float total=0;

    rectangle(10,5,70,40);
gotoxy(12,9);printf("N_Commande:");scanf("%d",&num);
pc=ChercherCmd(&num);
if(pc!=-1){

gotoxy(12,8);for(j=0;j<57;j++)printf("%c",'-');
gotoxy(50,6);printf("Date : ");
_strdate(date);
date_output(date);
printf("%s\n",date);
gotoxy(50,7);
printf("time : ");
_strtime(ttime);
printf("%s",ttime);
fseek(PCmd,pc*sizeof(cmd),SEEK_SET);
    fread(&cm,sizeof(cmd),1,PCmd);
pl=ChercherClient(cm.cin);
if(pl!=-1){
  fseek(PClient,pl*sizeof(client),SEEK_SET);
    fread(&cl,sizeof(client),1,PClient);

gotoxy(12,9);printf("Socitee:<Nom Socitee>");
gotoxy(12,12);printf("date commande: %s",date_output(date_input(cm.date)));
gotoxy(12,14);printf("N° Facture    :%d",++cpt);
gotoxy(12,16);printf("Nom Client    : %s",cl.nom);
gotoxy(12,18);printf("Prenom Client : %s",cl.prenom);
gotoxy(12,19);for(j=0;j<57;j++)printf("%c",'-');
}
gotoxy(16,20);printf("Details Commande :");
gotoxy(16,21);
for(i=0;i<43;i++)
printf("%c",'*');
gotoxy(16,22);
puts("| Libelle |  Qte_ach  | Prix_Un | Prix_HT |");
gotoxy(16,23);
for(i=0;i<43;i++)
printf("%c",'*');

    for(i=0;i<tailleligne();i++){
        fseek(Pligne,i*sizeof(lignecmd),SEEK_SET);
        fread(&ligne,sizeof(lignecmd),1,Pligne);
        if(cm.Ncmd==ligne.Ncmd){
            pa=ChercherArticle(&ligne.Nart);
            if(pa!=-1){
                fseek(PArticle,pa*sizeof(article),SEEK_SET);
                fread(&art,sizeof(article),1,PArticle);
                gotoxy(16,24+i);printf("|%9s|%10d |%9.2f|%9.2f|",art.libelle,ligne.qte,art.prix_U,ligne.qte*art.prix_U);
                total+=ligne.qte*art.prix_U;

            }

        }

    }
gotoxy(16,23+i);for(j=0;j<43;j++)printf("%c",'*');
gotoxy(37,25+i);printf("Le Total TTC Est :%2.f",total);

}else{Facture();}
getch();
}
