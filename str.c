#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct str
{
    char nom[30];
    char pass[30];
    int score;
    
}joueur;

int save (joueur T[],int *taille){
    FILE *f = NULL;
    f = fopen("joueur.txt","a");
    if(f==NULL){
        printf("impossible d ouvrir le fichier");
        return 0;
    }else{
        for (int i = 0; i < *taille; i++)
        {
        if(T[i].nom[0] == '\0'){
            break;
        }
            fprintf(f,"le joueur %s a un score de %d\n",T[i].nom,T[i].score);
        }
        fclose(f);
        
    }
}

joueur *creation_joueur(){
    joueur *j= malloc(sizeof(joueur));
    if(j==NULL){
        printf("erreur d allocation\n");
        exit(0);
    }
    printf("entrer votre pseudo: ");
    scanf("%s",j->nom);
    printf("entrer votre password: ");
    scanf("%s",j->pass);
    j->score= 0;
    return j;

}
int se_connecter(joueur T[], int *taille){
        int trouve = 0;
        int j=0;
        char pseudo[30];char pass[30];
        printf("entrer votre pseudo: ");
        scanf("%s",pseudo);
        printf("entrer votre password: ");
        scanf("%s",pass);srand(time(NULL));
        for( j = 0;j<*taille; j++){
            if(T[j].nom[0] =='\0') break;
            if(strcmp(T[j].nom,pseudo)==0 && strcmp(T[j].pass,pass)==0){
                trouve = 1;
                printf("bienvenue mr %s\n",pseudo);
                while (1)
                {
                    int choix,nombre=0,nombre_genere=0;
                    const int MAX_nom=100, MIN_nom=1;
                    printf("====== BIENVENUE dans votre jeu de devinette mr %s  ====\n",pseudo);
                    printf("1) nouvelle partie.\n2)sortir\n");
                    printf("entrer votre choix: ");
                    scanf("%d",&choix);
                    switch (choix)
                    {
                    case 1:
                        nombre_genere = (rand() % (MAX_nom-MIN_nom+1))+MIN_nom;
                        printf("le nombre généré est %d\n",nombre_genere);
                        printf("entrer votre valeur devinée: ");
                        scanf("%d",&nombre);
                        if (nombre_genere == nombre) {
                            T[j].score++;
                            printf("Partie gagnée ! Score = %d\n", T[j].score);
                        } else {
                            printf("Perdu ! Score = %d\n", T[j].score);
                        }

                        break;            
                    case 2:
                        printf("merci d avoir tester notre jeu!!\n");
                        return 0;                            
                    default:
                        printf("option non disponible\n");
                        return 0;
                    }

                }
            }

        }
        if (!trouve) {
            printf("Utilisateur non trouvé, création d'un nouveau compte.\n");
            while (j < *taille && T[j].nom[0] != '\0') j++;
            if (j == *taille) {
                printf("Impossible d'ajouter un nouvel utilisateur, tableau plein.\n");
                return 0;
            }
            joueur *jo = creation_joueur();
            strcpy(T[j].nom, jo->nom);
            strcpy(T[j].pass, jo->pass);
            T[j].score = jo->score;
            free(jo);
            return 0;
        }

}
int meilleurscore(joueur T[],int *taille){
    int max = T[0].score;
    int index = 0;
    srand(time(NULL));
    for(int i = 0; i< *taille; i++){
        if(T[i].nom[0] == '\0'){
            break;
        }
        if(T[i].score > max){
            max = T[i].score;
            index = i;
        }

    }
    return index;

}


int main(int argc, char *argv[]){
            int choice,choix;
            int taille = 100;
            joueur t[100];
            for(int i = 0; i<taille;i++){
                t[i].pass[0]= '\0';
                t[i].nom[0] = '\0';
                t[i].score = 0;

            }
    while (1){    
            printf("===== Bienvenue dans votre jeu devmot ====\n");
            printf("1)creer un compte.\n2)se connecter.\n3)liste des joueur.\n4)meilleur score.\n5)quitter\n");
            printf("entrer votre choix: ");
            scanf("%d",&choice);
            int j = 0;
            if(choice==1){
                while(t[j].nom[0] != '\0' && t[j].pass[0]!='\0'){
                    j++;
                }
                joueur *jo = creation_joueur();
                strcpy(t[j].nom,jo->nom);
                strcpy(t[j].pass,jo->pass);
                t[j].score = jo->score;


            }else if(choice==2) {
            int re = se_connecter(t,&taille);
            }else if(choice==3) {
                while(t[j].nom[0] != '\0' && t[j].pass[0]!='\0'){
                    printf("%s\n",t[j].nom);
                    j++;
                }
            }else if (choice==4){
                int index = meilleurscore(t,&taille);
                printf("le meilleur score est de %d par le joueur %s\n",t[index].score , t[index].nom);
            }else if (choice==5){
                printf("aurevoir mr/mme!!");
                save(t,&taille);
                exit(0);
                break;

            }else{
                printf("option non disponible!!");

            }
            /*for(int i = 0; i<taille;i++){
                printf("%s , %d",t[i].nom ,t[i].score);

            }*/
    }



    



}





