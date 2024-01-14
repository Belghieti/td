#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int verifier_sign_up(char *nom_utilisateur){
    FILE* fichier_login;
    FILE* nouveau_fichier_login;
    char verifier_nom_utilisateur[20],verifier_mot_de_pass[20];
    int trouve=0;
    
    fichier_login=fopen("login_fichier.txt","r");
    if(fichier_login == NULL){
        fclose(fichier_login);
        nouveau_fichier_login=fopen("login_fichier.txt","w");
        fclose(nouveau_fichier_login);
    }
    else{
        while(fscanf(fichier_login,"%s %s\n",verifier_nom_utilisateur,verifier_mot_de_pass)==2){
            if(strcmp(verifier_nom_utilisateur,nom_utilisateur)==0)
                trouve=1;
        }
        fclose(fichier_login);
    }
    return trouve;
}

void inserer_sign_up_dans_fichier(char *nom_utilisateur,char *mot_de_pass){
    FILE* fichier_login;
    int condition;

    fichier_login=fopen("login_fichier.txt","a");
    condition=fprintf(fichier_login,"%s %s\n",nom_utilisateur,mot_de_pass);
    if(condition)
        printf("compte creer avec succes");
    fclose(fichier_login);
}

void sign_up(){
    void inserer_sign_up_dans_fichier(char *nom_utilisateur,char *mot_de_pass);
    char nom_utilisateur[20],mot_de_pass[20];
    int verification_sign_up;
    do{
        printf("Entre un nom d'utilisateur: ");
        scanf("%s",nom_utilisateur);
        verification_sign_up=verifier_sign_up(nom_utilisateur);

        if(verification_sign_up){
            printf("Ce nom d'utilisateur deja existe.\n");
        }
    }while(verification_sign_up);
    printf("Entre un mot de pass: ");
    scanf("%s",mot_de_pass);

    inserer_sign_up_dans_fichier(nom_utilisateur,mot_de_pass);

}

int verifier_login_etudiant(int code_massar,int jour,int mois,int annee){
    FILE *fichier_etudiant;
    char nom[20],prenom[20];
    int verifier_jour,verifier_mois,verifier_annee;
    int verifier_code_massar,trouve=0;
    int note[6],presence[6];

    fichier_etudiant=fopen("fichier_etudiant.txt","r");
    while(fscanf(fichier_etudiant,"%d %s %s  %d %d %d %f %f %f %f %f %f %d %d %d %d %d %d\n",
                    &verifier_code_massar,nom,prenom,&verifier_jour,&verifier_mois,&verifier_annee,
                    &note[0],&note[1],&note[2],&note[3],&note[4],&note[5],
                    &presence[0],&presence[1],&presence[2],&presence[3],&presence[4],&presence[5])==18){
        if( code_massar == verifier_code_massar && verifier_jour==jour && verifier_mois==mois && verifier_annee==annee){
            trouve=1;
            break;
        }
    }
    fclose(fichier_etudiant);

    return trouve;
}

int verifier_login_admin(char *nom_utilisateur,char *mot_de_pass){
    FILE* fichier_login;
    char verifier_nom_utilisateur[20],verifier_mot_de_pass[20];
    int trouve=0;
    
    fichier_login=fopen("login_fichier.txt","r");
    while(fscanf(fichier_login,"%s %s\n",verifier_nom_utilisateur,verifier_mot_de_pass)==2){
        if(strcmp(verifier_nom_utilisateur,nom_utilisateur)==0 && strcmp(mot_de_pass,verifier_mot_de_pass)==0)
            trouve=1;
    }
    fclose(fichier_login);

    return trouve;
}


int login_admin(){
    char nom_utilisateur[20],mot_de_pass[20],valeur;
    int verification_login;

    do
    {
        printf("\n\n\tEntre nom d'utilisateur: ");
        scanf("%s",nom_utilisateur);
        printf("\n\tEntre mot de pass: ");
        scanf("%s",mot_de_pass);
        verification_login=verifier_login_admin(nom_utilisateur,mot_de_pass);
        if(verification_login){
            system("cls");
            printf("\n\t\t\t\t      || Bienvenue %s||\n\n",nom_utilisateur);
            return 1;
        }
        else{  
            printf("\n\nInformations incorrectes, essay autre fois.\n\n");
            do{
                printf("Entre 'Y' pour reesayer, ou 'N' pour annuler :");
                scanf(" %c",&valeur);
                
                if(valeur=='N' || valeur=='n'){ 
                    system("cls");
                    return 0;
                }
                else if(valeur=='Y' || valeur=='y'){
                    system("cls");
                }
            }while (valeur!= 'n' && valeur!= 'y' && valeur!= 'N' && valeur !='Y');
        }

    } while (1);

    return 0;
    
}

int login_etudiant(){
    char valeur;
    int verification_login,nom_utilisateur;
    int jour,mois,annee; 

    do
    {
        printf("\n\tEntre nom d'utilisateur: ");
        scanf("%d",&nom_utilisateur);
        printf("\n\tEntre mot de pass (jj/mm/aaaa): ");
        scanf("%d/%d/%d", &jour , &mois , &annee );


        verification_login=verifier_login_etudiant(nom_utilisateur,jour,mois,annee);
        if(verification_login){
            system("cls");
            printf("\n\t\t\t   || Bienvenue etudiant ||\n\n");
            return nom_utilisateur;
        }
        else{  
            printf("\n\nInformations incorrectes, essay autre fois.\n\n");
            do{
                printf("Entre 'Y' pour reesayer, ou 'N' pour annuler :");
                scanf(" %c",&valeur);
                if(valeur=='N' || valeur=='n'){
                    system("cls");
                    return 0;
                }
                else if(valeur=='Y' || valeur=='y'){
                    system("cls");
                }
            }while (valeur!= 'n' && valeur!= 'y' && valeur!= 'N' && valeur !='Y');
        }
    } while (1);

    return 0;
    
}

typedef struct date_repere{
    int jour;
    int mois;
    int annee;
}date;



typedef struct etudiant_repere{
    int code_massar;
    char nom[20];
    char prenom[20];
    float note[6];
    int presence[6];
    date date_nassance;
    struct etudiant_repere *pointeur;
}etudiant;

typedef struct liste_repere{
    etudiant *tete;
    etudiant *queue;
    int taille;
}liste;

etudiant* definir_etudiant(){
    etudiant* etu;
    
    etu = (etudiant*)malloc(sizeof(etudiant)); 
    etu->pointeur=NULL;
    etu->code_massar=0;
    strcpy(etu->nom,"");  
    strcpy(etu->prenom,"");

    return etu;
}


etudiant* creer_etudiant(liste* li){
    int verifier_nom_prenom(char *nom);
    float verifier_note(int note);
    int verifier_presence(int num_presence);
    int verifier_code_massar(liste *li,int code_massar);
    int verifier_date_naissance(int jour,int mois,int annee);
    etudiant* etu;
    int code_massar,verification_code_massar,jour,mois,annee;
    int verification_date_naiss_entrer , verification_date_naiss , verification_nom_prenom ,i;
    char nom[20],prenom[20];
    
    etu = definir_etudiant();
    
    //code massar est entier
    printf("\n\n\tentrer code massar : ");
    scanf("%d",&code_massar);
    verification_code_massar=verifier_code_massar(li,code_massar);
    while(verification_code_massar){
        printf("code massar entrer deja existe, entre un autre: ");
        scanf("%d",&code_massar);
        verification_code_massar=verifier_code_massar(li,code_massar);
    }

    do
    {
        printf("\n\tEntre son nom : ");
        scanf(" %s", nom);
        verification_nom_prenom=verifier_nom_prenom(nom);
        if (!verification_nom_prenom){
            printf("\tInvalide nom d'etudiant");
        }
    } while (!verification_nom_prenom);
    

     do
    {   
        printf("\n\tEntrer son prenom : ");
        scanf(" %s", prenom);
        verification_nom_prenom=verifier_nom_prenom(prenom);
        if (!verification_nom_prenom){
            printf("\tInvalide prenom d'etudiant");
        }
    } while (!verification_nom_prenom);

  
    do
    {
        printf("\n\tEntre sa date de naissance sous la format (jj/mm/aaaa): ");
        verification_date_naiss_entrer=scanf("%d/%d/%d", &jour , &mois , &annee);
        verification_date_naiss=verifier_date_naissance(jour,mois,annee);
        if(verification_date_naiss_entrer!=3 || verification_date_naiss==0){
            printf("\tDate entrer avec format invalide.\n");  
            printf("\tEntre sa date de naissance sous la format (jj/mm/aaaa): ");     
        }

    } while (verification_date_naiss_entrer !=3 && verification_date_naiss==0);
    
    //entrer les notes
    for (i=0; i<6; i++){
        etu->note[i]=verifier_note(i+1);
    }

    printf("\n\n\t\tEntre les presences \n\t 0 pour absent ,ou 1 pour present.");
    for (i=0;i<6; i++)
    {
        etu->presence[i]=verifier_presence(i+1);
    }
    

    
    //affecter les variables a la variable etudiant
    etu->code_massar=code_massar;
    strcpy(etu->nom,nom);  
    strcpy(etu->prenom,prenom);
    etu->date_nassance.jour=jour;
    etu->date_nassance.mois=mois;
    etu->date_nassance.annee=annee;

    return etu;
}

liste*  creer_liste(){
    liste* li;
    li = (liste*)malloc(sizeof(liste));  
    li->tete = NULL;
    li->queue = NULL;
    li->taille = 0;
    return li;
}


void ajouter_etudiant(liste* li){
    etudiant* etu;
    etu = creer_etudiant(li);

    if (li->taille == 0){
        li->tete = etu;
        li->queue = etu;
    }
    else{
        etu->pointeur = li->tete;
        li->tete = etu;
    }
    li->taille++;
    printf("nombre des etudiants : %d\n",li->taille);
}

void enregistrer_donnees_dans_fichier(liste* li){
    etudiant* ptr;
    FILE* fichier;
    int i;

    fichier=fopen("fichier_etudiant.txt","w");
    if(fichier!=NULL){
        ptr=li->tete;
        

        while(ptr != NULL){
            fprintf(fichier,"%d %s %s %d %d %d",ptr->code_massar,ptr->nom,ptr->prenom,ptr->date_nassance.jour,ptr->date_nassance.mois,ptr->date_nassance.annee);
            for (i=0; i<6; i++)
                fprintf(fichier," %.2f",ptr->note[i]);
            

            for (i=0; i<6; i++)
                fprintf(fichier," %d",ptr->presence[i]);
            
            
            fprintf(fichier,"\n");
            
            ptr=ptr->pointeur;
        }
        fclose(fichier);
    }
    else
        printf("Erreur d'enregistrement des donnees.");
    
}

void modifier_etudiant(liste* li){
    int verifier_nom_prenom(char *nom);
    float verifier_note(int note);
    int verifier_presence(int num_presence);
    int verifier_code_massar(liste *li,int code_massar);
    int verifier_date_naissance(int jour,int mois,int annee);

    int Age,code_massar,verification_code_massar,jour,mois,annee;
    int verification_date_naiss_entrer , verification_date_naiss , verification_nom_prenom ,i;
    char nom[20],prenom[20],choix;
    etudiant* ptr;

    printf("Entre le code massar de l'etudiant : ");
    scanf("%d",&code_massar);

    ptr=li->tete;
    while (ptr != NULL){
        if (ptr->code_massar==code_massar){
           break;
        }
        ptr=ptr->pointeur;
        if(ptr == NULL){
            do
            {
                printf("Etudiant introuvable\n");
                printf("Entre 'O' pour ressayer ou 'N' pour annuler : ");
                scanf(" %c",&choix);
                if (choix!='O' && choix!= 'o' && choix!= 'N' && choix!= 'n'){
                    printf("Choix invalide .\n");
                }
                else if (choix=='O'||choix=='o'){
                    ptr=li->tete;
                    printf("Entre le code massar de l'etudiant : ");
                    scanf("%d",&code_massar);
                    break;
                }
                else if (choix=='N'||choix=='n')
                {
                    return;
                }
            } while (1);
            
        }
        
    }
    
    

    do
    {
        printf("\n\tEntre son nom : ");
        scanf(" %s", nom);
        verification_nom_prenom=verifier_nom_prenom(nom);
        if (!verification_nom_prenom){
            printf("\tInvalide nom d'etudiant");
        }
    } while (!verification_nom_prenom);
    

     do
    {   
        printf("\n\tEntrer son prenom : ");
        scanf(" %s", prenom);
        verification_nom_prenom=verifier_nom_prenom(prenom);
        if (!verification_nom_prenom){
            printf("\tInvalide prenom d'etudiant");
        }
    } while (!verification_nom_prenom);

  
    do
    {
        printf("\n\tEntre sa date de naissance sous la format (jj/mm/aaaa): ");
        verification_date_naiss_entrer=scanf("%d/%d/%d", &jour , &mois , &annee);
        verification_date_naiss=verifier_date_naissance(jour,mois,annee);
        if(verification_date_naiss_entrer!=3 || verification_date_naiss==0){
            printf("\tDate entrer avec format invalide.\n");  
            printf("\tEntre sa date de naissance sous la format (jj/mm/aaaa): ");     
        }

    } while (verification_date_naiss_entrer !=3 && verification_date_naiss==0);
    
    //entrer les notes
    for (i=0; i<6; i++){
        ptr->note[i]=verifier_note(i+1);
    }

    printf("\n\n\t\tEntre les presences \n\t 0 pour absent ,ou 1 pour present.");
    for (i=0;i<6; i++)
    {
        ptr->presence[i]=verifier_presence(i+1);
    }
    

    
    //affecter les variables a la variable etudiant
    ptr->code_massar=code_massar;
    strcpy(ptr->nom,nom);  
    strcpy(ptr->prenom,prenom);
    ptr->date_nassance.jour=jour;
    ptr->date_nassance.mois=mois;
    ptr->date_nassance.annee=annee;

}

void supprimer_etudiant(liste* li){
    int code,trouve=0;
    FILE* fichier;
    etudiant *ptr,*precedent,*pos;
    printf("Entre le code massar a supprimer : ");
    scanf("%d",&code);

    
    ptr = li->tete;
    pos = li->tete;
    precedent=NULL;
    
    if (li->tete->code_massar == code){
        trouve = 1;
        li->tete=li->tete->pointeur;
        free(ptr);
        li->taille--;
        printf("1");
    }
    else if(li->queue->code_massar == code){
        trouve = 1;
        while(ptr->pointeur!=NULL){
            precedent=ptr;
            ptr=ptr->pointeur;
        }
        li->queue=precedent;
        free(ptr);
        if(li->queue!=NULL){
            ptr->pointeur=NULL;
        }
        else{
            li->tete=NULL;
        }
        li->taille--;
        printf("2");
    }
    else{
        while(ptr->pointeur != NULL){
            if( ptr->pointeur->code_massar == code){
                trouve = 1;
                pos=ptr->pointeur;
                printf("massar :%d\n",ptr->code_massar);
                printf("nom: \n%s",ptr->pointeur->nom);
                printf("prenom: \n%s",ptr->pointeur->prenom);               
                ptr->pointeur=ptr->pointeur->pointeur;
                free(pos);
                li->taille--;
                break;
            }            
            ptr = ptr->pointeur;
        }
    }
    
    
    
    
    
    if(trouve){
        enregistrer_donnees_dans_fichier(li);
        printf("\n\t=================== Suppression avec succes ===================");
    }             
    else{
        printf("walo ,makayn walo");
    }
    
}

liste* recuperer_donnees(){
    FILE* fichier;
    FILE* nouveau;
    etudiant* e;
    liste* li;
    int code_massar,i;
    int jour,mois,annee;
    int presence[6];
    char nom[20],prenom[20];
    
    float note[6];
    
    li = creer_liste();
    fichier = fopen("fichier_etudiant.txt","r");
    if (fichier == NULL){
        fclose(fichier);
        nouveau=fopen("fichier_etudiant.txt","w");
        fclose(nouveau);
    }
    else{
        while(fscanf(fichier,"%d %s %s %d %d %d %f %f %f %f %f %f %d %d %d %d %d %d\n",
                    &code_massar,nom,prenom,&jour,&mois,&annee,
                    &note[0],&note[1],&note[2],&note[3],&note[4],&note[5],
                    &presence[0],&presence[1],&presence[2],&presence[3],&presence[4],&presence[5])==18){

            e = definir_etudiant();
            e->code_massar=code_massar;
            strcpy(e->nom,nom);  
            strcpy(e->prenom,prenom);
            e->date_nassance.jour=jour;
            e->date_nassance.mois=mois;
            e->date_nassance.annee=annee;
            for (i=0; i<6; i++)
            {
                e->note[i]=note[i];
                e->presence[i]=presence[i];
            }
            
            if (li->taille == 0){
                li->tete = e;
                li->queue = e;
                li->taille++; 
            }
            else{
                e->pointeur = li->tete;
                li->tete = e;
                li->taille++; 
            }
        }
        fclose(fichier);
    }
    printf("nombre des etudients : %d\n\n",li->taille);
    return li;
    
}


int verifier_nom_prenom(char *nom) {
    int i;
    for (i=0; nom[i]!='\0'; i++) {
        if (!isalpha(nom[i]) && !isspace(nom[i])) {
            return 0;
        }
    }
    return 1; 
}


float verifier_note(int num_note) {
    float note;
    do {
        printf("\n\tEntre la note numero %d : ", num_note);
        scanf("%f", &note);
        if (note < 0 || note > 20) {
            printf("\tEntre une note valide entre 0 et 20.");
        } else {
            break;
        }
    } while (1);

    return note;
}

int verifier_presence_nombre(char *jour){
    int presence;   
    do{
        printf("\n\tEnter la presence de %s : ",jour);
        scanf("%d",&presence);
        if (presence != 0 && presence != 1) {
            printf("\n\tEntre une presence valide 0 ou 1.");
            
        }
    } while (presence != 0 && presence != 1);
    return presence;
}

int verifier_presence(int num_presence){
    int presence;

    switch (num_presence)
    {
    case 1:
        presence=verifier_presence_nombre("lundi");
        break;
    case 2:
        presence=verifier_presence_nombre("mardi");
        break;        
    case 3:
        presence=verifier_presence_nombre("mercredi");
        break;   
    case 4:
        presence=verifier_presence_nombre("jeudi");
        break;
    case 5:
        presence=verifier_presence_nombre("vendredi");
        break;
    case 6:
        presence=verifier_presence_nombre("samedi");
        break;        
    
    default:
        break;
    } 

    return presence;
}

int verifier_code_massar(liste* li,int code){
    etudiant* ptr;
    int trouve=0;
    
    ptr=li->tete;    
    while(ptr!=NULL){
        if(ptr->code_massar==code)
            trouve=1;
        ptr=ptr->pointeur;
    }
    
 
        return trouve;
}

int verifier_date_naissance(int jour,int mois,int annee){
    if(annee<1943 || annee>2008){
        return 0;
    }
    else if(mois<01 || mois>12){
        return 0;
    }
    else if ((mois==1 || mois==3 || mois==5 || mois==7 || mois==8 || mois==10 || mois==12) && (jour<1 || jour>31)){
        return 0;
    }
    else if((mois==4 || mois==6 || mois==9 || mois==11) && (jour<1 || jour>30)){
        return 0;
    }
    else if(mois==2 && (jour<1 || jour>29)){
        return 0;
    }
    else{
        return 1;
    }
}


void trier_liste_par_code_massar(liste* li) {
    etudiant *i,*j,*min;
    int temp_code_massar,temp_presence[6],k,jj,mm,aaaa;
    char temp_nom[20],temp_prenom[20];
    float temp_note[6];

    if (li->tete->pointeur == NULL) //sil y a un element 
        return;

    for (i = li->tete;i->pointeur != NULL;i = i->pointeur) {
        min = i;
        for (j = i->pointeur; j != NULL; j = j->pointeur) 
            if (j->code_massar < min->code_massar) 
                min = j;

        if(min != i){
            temp_code_massar = i->code_massar;
            i->code_massar = min->code_massar;
            min->code_massar = temp_code_massar;

            strcpy(temp_nom , i->nom);
            strcpy(i->nom , min->nom);
            strcpy(min->nom , temp_nom);
            
            strcpy(temp_prenom , i->prenom);
            strcpy(i->prenom , min->prenom);
            strcpy(min->prenom , temp_prenom);

            for (k = 0; k < 6; k++)
            {
                temp_presence[k] = i->presence[k];
                i->presence[k] = min->presence[k];
                min->presence[k] = temp_presence[k];

                temp_note[k] = i->note[k];
                i->note[k] = min->note[k];
                min->note[k] = temp_note[k]; 

                jj = i->date_nassance.jour;
                mm = i->date_nassance.mois;
                aaaa = i->date_nassance.annee;

                i->date_nassance.jour = min->date_nassance.jour;
                i->date_nassance.mois = min->date_nassance.mois;
                i->date_nassance.annee = min->date_nassance.annee;

                min->date_nassance.jour = jj;
                min->date_nassance.mois = mm;
                min->date_nassance.annee = aaaa;

            }
            

                      
        }

    }
}

void trier_liste_par_nom(liste* li) {
    etudiant *i,*j,*min;
    int temp_code_massar,k,jj,mm,aaaa;
    char temp_nom[20],temp_prenom[20];
    int temp_presence[6];
    float temp_note[6];


    if (li->tete->pointeur == NULL) //sil y a un element 
        return;

    for (i = li->tete;i->pointeur != NULL;i = i->pointeur) {
        min = i;
        for (j = i->pointeur; j != NULL; j = j->pointeur) 
            if (strcmp(j->nom , min->nom) < 0)
                min = j;

        if(min != i){
            temp_code_massar = i->code_massar;
            i->code_massar = min->code_massar;
            min->code_massar = temp_code_massar;

            strcpy(temp_nom , i->nom);
            strcpy(i->nom , min->nom);
            strcpy(min->nom , temp_nom);
            
            strcpy(temp_prenom , i->prenom);
            strcpy(i->prenom , min->prenom);
            strcpy(min->prenom , temp_prenom);

            for (k = 0; k < 6; k++)
            {
                temp_presence[k] = i->presence[k];
                i->presence[k] = min->presence[k];
                min->presence[k] = temp_presence[k];

                temp_note[k] = i->note[k];
                i->note[k] = min->note[k];
                min->note[k] = temp_note[k]; 

                jj = i->date_nassance.jour;
                mm = i->date_nassance.mois;
                aaaa = i->date_nassance.annee;

                i->date_nassance.jour = min->date_nassance.jour;
                i->date_nassance.mois = min->date_nassance.mois;
                i->date_nassance.annee = min->date_nassance.annee;

                min->date_nassance.jour = jj;
                min->date_nassance.mois = mm;
                min->date_nassance.annee = aaaa;

            }      
        }

    }
}

void afficher_liste(liste* li) {
    etudiant* ptr=li->tete;
    char entrer;

    while (ptr != NULL) {
        printf("------------------------------------------------\n");
        printf(" Code Massar : %d\n",ptr->code_massar);
        printf(" Nom : %s\n",ptr->nom);
        printf(" Prenom : %s\n",ptr->prenom);
        printf(" Annee de naissance : %d/%d/%d\n\n",ptr->date_nassance.jour,ptr->date_nassance.mois,ptr->date_nassance.annee);
        printf(" note 1 : %.2f\n",ptr->note[0]);
        printf(" note 2 : %.2f\n",ptr->note[1]);
        printf(" note 3 : %.2f\n",ptr->note[2]);
        printf(" note 4 : %.2f\n",ptr->note[3]);
        printf(" note 5 : %.2f\n",ptr->note[4]);
        printf(" note 6 : %.2f\n\n",ptr->note[5]);
        printf(" Presence :\n"         );
        printf(" Lundi : %d    "   ,ptr->presence[0]);
        printf(" Mardi : %d    "   ,ptr->presence[1]);
        printf(" Mercredi : %d  \n",ptr->presence[2]);
        printf(" Jeudi : %d    "   ,ptr->presence[3]);
        printf(" Vendredi : %d    ",ptr->presence[4]);
        printf(" Samedi : %d    \n\n"  ,ptr->presence[5]);
        ptr=ptr->pointeur;
    }
    printf("------------------------------------------------\n\n");
    printf("Tape entrer pour retourner au menu.");
    entrer=getchar();
    entrer=getchar();
    system("cls");
}

void afficher_info_etudiant(int code_massar){
    FILE* fichier;
    int verifier_code_massar;
    char nom[20],prenom[20];
    int jour,mois,annee;
    int presence[6];
    float note[6];
    
    fichier = fopen("fichier_etudiant.txt","r");
        while(fscanf(fichier,"%d %s %s %d %d %d %f %f %f %f %f %f %d %d %d %d %d %d\n",
                    &verifier_code_massar,nom,prenom,&jour,&mois,&annee,
                    &note[0],&note[1],&note[2],&note[3],&note[4],&note[5],
                    &presence[0],&presence[1],&presence[2],&presence[3],&presence[4],&presence[5])==18){
        if(code_massar == verifier_code_massar){
            printf("------------------------------------------\n\n");
            printf(" Code Massar : %d\n\n",code_massar);
            printf(" Nom : %s\n",nom);
            printf(" Prenom : %s\n",prenom);
            printf(" Annee de naissance : %d/%d/%d\n\n",jour,mois,annee);

            printf(" note 1 : %.2f\n",note[0]);
            printf(" note 2 : %.2f\n",note[1]);
            printf(" note 3 : %.2f\n",note[2]);
            printf(" note 4 : %.2f\n",note[3]);
            printf(" note 5 : %.2f\n",note[4]);
            printf(" note 6 : %.2f\n\n",note[5]);

            printf(" Presence lundi : %d\n",presence[0]);
            printf(" Presence mardi: %d\n",presence[1]);
            printf(" Presence mercredi : %d\n",presence[2]);
            printf(" Presence jeudi : %d\n",presence[3]);
            printf(" Presence vemdredi : %d\n",presence[4]);
            printf(" Presence samedi : %d\n\n",presence[5]);
            printf("------------------------------------------\n");
        }
        break;
       
    }
    getchar();
    printf("Tape entrer pour retourner.");
    getchar();
    system("cls");
    fclose(fichier);
}

void admin(){
    int verification;
    char choix;
    liste* li;

    verification=login_admin();
    if(verification==0)
        return;
    
    li=recuperer_donnees();

    do{
        printf("\n\t\t===============================================================\n");
        printf("\t\t                        Menu des choix                           \n");
        printf("\t\t===============================================================\n\n");
        printf("\t\t       <1>.Ajouter un etudiant                                   \n");
        printf("\t\t       <2>.Modifier un etudiant                                  \n");
        printf("\t\t       <3>.Suppprimer un etudiant                                \n");
        printf("\t\t       <4>.enregistrer modifications                             \n");
        printf("\t\t       <5>.afficher la liste des etudiants par code massar       \n");
        printf("\t\t       <6>.afficher la liste des etudiants par nom               \n");
        printf("\t\t       <7>.quitter                                             \n\n");
        printf("\t\t===============================================================\n\n");
        printf("Entre votre choix :  ");
        scanf(" %c",&choix);
        if (li->taille ==0 && choix>'1' && choix <= '6'){
            system("cls");
            printf("\t\t\t\t  Ajoute d'abord un etudiant. \n");
        }
        else{
            switch(choix){
                case '1':system("cls");
                        ajouter_etudiant(li);
                        break;
                case '2':system("cls");
                        modifier_etudiant(li);
                        break;                        
                case '3':system("cls");
                        supprimer_etudiant(li);
                        break;
                case '4':system("cls");
                        enregistrer_donnees_dans_fichier(li);
                        break;
                case '5':system("cls");
                        trier_liste_par_code_massar(li);
                        afficher_liste(li);
                        break;    
                case '6':system("cls");
                        trier_liste_par_nom(li);
                        afficher_liste(li);
                        break;    
                case '7':system("cls");
                    printf("\n\n\t\t==========  Retoure au menu admin  =========\n\n");  
                        break;                
                default:system("cls");
                    printf("\n\n\t\t============  invalide commande  ===========\n\n");  
            }
        }
    }while(choix != '7');
}

void interface_etudiant(){
    char nom[10], prenom[10];
    int age,code_massar;
    char choix;

    code_massar = login_etudiant();
    if(code_massar == 0){
         return;
    }
       
     printf(" Code Massar : %d\n\n",code_massar);
        
    do{
        printf("\n\t\t============================================\n");
        printf("\t\t                Menu des choix                \n");
        printf("\t\t============================================\n\n");
        printf("\t\t        <1>.afficher info                     \n");
        printf("\t\t        <2>.quitter                         \n\n");
        printf("\t\t============================================\n\n");
        printf("Entre votre choix : ");
        scanf(" %c",&choix);

        switch(choix){
            case '1':system("cls");
                    afficher_info_etudiant(code_massar);
                    break;   
            case '2':system("cls");
                    printf("\n\n\t\t=========  Retoure au menu etudiant  ========\n\n");  
                    break;                
            default:system("cls");
                    printf("\n\n\t\t============  invalide commande  ===========\n\n");  
        }
        
    }while(choix != '2');
}


int menu_admin(){
    char choix_login;

    do{
        printf("\n\t\t============================================\n");
        printf("\t\t                  Menu Admin                  \n");
        printf("\t\t============================================\n\n");
        printf("\t\t       <1>.Login                              \n");
        printf("\t\t       <2>.Creer compte                       \n");
        printf("\t\t       <3>.quitter                          \n\n");
        printf("\t\t============================================\n\n");
        printf("Entre votre choix : ");
        scanf(" %c",&choix_login);
        switch(choix_login){
            case '1':system("cls");
                admin();
                break;
            case '2':system("cls");
                sign_up();
                break;
            case '3':system("cls");
                    printf("\n\n\t\t=======  Retoure au menu principale  =======\n\n");  
                break;
            default:system("cls");
                    printf("\n\n\t\t============  invalide commande  ===========\n\n");  
                break;

        }
    }while(choix_login!='3');

    return 0;
}

int menu_etudiant(){
    char choix_login;

    do{
        printf("\n\t\t============================================\n");
        printf("\t\t                Menu Etudiant                 \n");
        printf("\t\t============================================\n\n");
        printf("\t\t       <1>.Login                              \n");
        printf("\t\t       <2>.quitter                          \n\n");
        printf("\t\t============================================\n\n");
        printf("Entre votre choix : ");
        scanf(" %c",&choix_login);
        switch(choix_login){
            case '1': system("cls");
                    interface_etudiant();
                    break;
            case '2': system("cls");
                    printf("\n\n\t\t=======  Retoure au menu principale  =======\n\n");  
                    break;
            default:system("cls");
                    printf("\n\n\t\t===========  invalide commande  ===========\n\n");  
                    break;          

        }
    }while(choix_login!='2');

    return 0;
}

int main(){
    char choix_login;
    do{
        printf("\n\t\t============================================\n");
        printf("\t\t               Menu Principale                \n");
        printf("\t\t============================================\n\n");
        printf("\t\t       <1>.Je suis admin                      \n");
        printf("\t\t       <2>.Je suis etudiant                   \n");
        printf("\t\t       <3>.quitter                          \n\n");
        printf("\t\t============================================\n\n");
        printf("Entre votre choix : ");
        scanf(" %c",&choix_login);
        switch(choix_login){
            case '1':system("cls");
                   menu_admin();
                   break;
            case '2':system("cls");
                   menu_etudiant();
                   break;
            case '3':system("cls");
                   printf("\n\n\t\t================  au revoir  ================\n\n");  
                   break;
            default:system("cls");
                   printf("\n\n\t\t============  invalide commande  ===========\n\n");  
                   break;

        }
    }while(choix_login!='3');
    return 0;
}