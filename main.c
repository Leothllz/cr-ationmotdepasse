#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define L_MAX 1000

typedef struct Arbre {
    int Noeud;
    struct Arbre* G;
    struct Arbre* D;
};

Arbre* CreeNoeud(Arbre **arbre, int v) {

    Arbre* Racine;
    Arbre* RacineArbre = *arbre;

    Arbre* R = malloc(sizeof(Arbre));
    R->Noeud = Noeud;
    R->G = NULL;
    R->D = NULL;

    if (Racine)
        do{
            Racine = RacineArbre;
        if (RacineArbre->Noeud > v) {

            RacineArbre = RacineArbre->G;
            if(!RacineArbre) Racine->G = R;
        }
        else {

            RacineArbre = RacineArbre->D;
            if (!RacineArbre) Racine->D = R;
        }
        } while (RacineArbre);
    else {
        *arbre = R;
    }
}


int Menu(){
    int ChoixMenu;

    printf("---Menu Generateur de mot de passe---\n\n");
    printf("1. Mot de passe avec UNIQUEMENT des chiffres\n");
    printf("2. Mot de passe avec UNIQUEMENT des lettres\n");
    printf("3. Mot de passe avec UNIQUEMENT des caracteres speciaux\n");
    printf("4. Mot de passe avec chiffres et des lettres\n");
    printf("5. Mot de passe avec lettres et des caracteres speciaux\n");
    printf("6. Mot de passe avec chiffres et des caracteres speciaux\n");
    printf("7. Mot de passe avec tout les parametres\n");
    printf("0. Quitter l'application\n");
    printf("\n Indiquer votre Choix : \n\n");

    scanf("%d",&ChoixMenu);

    return ChoixMenu;
}

int parametreN_mdp(){
    int N_mdp;


    printf("Entrez le nombre de mot de passe a generer\n\n");
    scanf("%d",&N_mdp);

    if(N_mdp>=1){

        printf("Vous avez choisis un nombre de %d pour le/les mot(s) de passe\n\n",N_mdp);

    }else if(N_mdp<= 0){

        printf("Entrez un nombre valide de mot de passe\n\n");
        return parametreN_mdp();
    }
    return N_mdp;
}

int parametreL_mdp(){
    int L_mdp;

    printf("Entrez le nombre de caractere(chacun) pour le/les mot(s) de passe (max %d)\n\n",L_MAX);
    scanf("%d",&L_mdp);

    if(L_mdp<=0){
        L_mdp = 1;
    }

    else if (L_mdp > L_MAX){
        L_mdp = L_MAX;

    }
    printf("Vous avez choisis %d nombre de caractere(chacun) pour le/les mot de passe\n\n",L_mdp);
    return L_mdp;
}



int main(){
    int N_mdp,L_mdp,x,y,z,i,j;
    srand (time (NULL));
    char* num = "0123456789";
    char* lettre = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char* symb = "&#'}{)(-|_@][=+*%!:;.,/?<>^$£~¤";

    int Noeud;
    Arbre* Arbre = NULL;

    CreeNoeud(&Arbre, 7);
    CreeNoeud(&Arbre, 5);
    CreeNoeud(&Arbre, 6);
    CreeNoeud(&Arbre, 3);
    CreeNoeud(&Arbre, 4);
    CreeNoeud(&Arbre, 2);
    CreeNoeud(&Arbre, 1);
    CreeNoeud(&Arbre, 0);

    switch(Menu()){

        case 1 :
            printf("Vous avez choisis un Mot de passe avec UNIQUEMENT des chiffres\n\n");
            N_mdp=parametreN_mdp(N_mdp);
            L_mdp=parametreL_mdp(L_mdp);

            printf("Voici %d mot(s) de passe de %d caracteres :\n",N_mdp,L_mdp);

            for( i=1 ; i <=N_mdp ; i++){
                for( j=1 ; j<=L_mdp ; j++ ){
                    x = rand () % 10;
                    printf("%c",num[x]);
                }
                printf("\n");
            }
            break;
        case 2 :
            printf("Vous avez choisis un Mot de passe avec UNIQUEMENT des lettres\n");
            N_mdp=parametreN_mdp(N_mdp);
            L_mdp=parametreL_mdp(L_mdp);

            printf("Voici %d mot(s) de passe d'un longueur de %d caracteres :\n",N_mdp,L_mdp);

            for( i=1 ; i <=N_mdp ; i++){
                for( j=1 ; j<=L_mdp ; j++ ){
                    y = rand () % 46;
                    printf("%c",lettre[y]);
                }
                printf("\n");
            }
            break;
        case 3 :
            printf("Vous avez choisis un Mot de passe avec UNIQUEMENT des caracteres speciaux\n");
            N_mdp=parametreN_mdp(N_mdp);
            L_mdp=parametreL_mdp(L_mdp);

            printf("Voici %d mot(s) de passe de %d caracteres :\n",N_mdp,L_mdp);

            for( i=1 ; i <=N_mdp ; i++){
                for( j=1 ; j<=L_mdp ; j++ ){
                    z = rand () % 30;
                    printf("%c",symb[z]);
                }
                printf("\n");
            }
            break;
        case 4 :
            printf("Vous avez choisis un Mot de passe avec chiffres et des lettres\n");
            N_mdp=parametreN_mdp(N_mdp);
            L_mdp=parametreL_mdp(L_mdp);

            printf("Voici %d mot(s) de passe de %d caracteres(chacun) :\n",N_mdp,L_mdp);

            for( i=1 ; i <=N_mdp ; i++){
                for( j=1 ; j<=L_mdp/2 ; j++ ){

                    x = rand () % 10;
                    y = rand () % 46;
                    printf("%c%c",num[x],lettre[y]);
                }
                printf("\n");
            }

            break;
        case 5 :
            printf("Vous avez choisis un Mot de passe avec lettres et des caracteres speciaux\n");
            N_mdp=parametreN_mdp(N_mdp);
            L_mdp=parametreL_mdp(L_mdp);

            printf("Voici %d mot(s) de passe de %d caracteres(chacun) :\n",N_mdp,L_mdp);

            for( i=1 ; i <=N_mdp ; i++){
                for( j=1 ; j<=L_mdp/2 ; j++ ){
                    y = rand () % 46;
                    z = rand () % 30;
                    printf("%c%c",lettre[y],symb[z]);
                }
                printf("\n");
            }


            break;
        case 6 :
            printf("Vous avez choisis un Mot de passe avec chiffres et des caracteres speciaux\n");
            N_mdp=parametreN_mdp(N_mdp);
            L_mdp=parametreL_mdp(L_mdp);

            printf("Voici %d mot(s) de passe de %d caracteres(chacun) :\n",N_mdp,L_mdp);

            for( i=1 ; i <=N_mdp ; i++){
                for( j=1 ; j<=L_mdp/2 ; j++ ){
                    x = (rand () % 10);
                    z = (rand () % 30);
                    printf("%c%c",num[x],symb[z]);
                }
                printf("\n");
            }

            break;
        case 7 :
            printf("Vous avez choisis un Mot de passe avec tout les parametres\n");
            N_mdp=parametreN_mdp(N_mdp);
            L_mdp=parametreL_mdp(L_mdp);

            printf("Voici %d mot(s) de passe de %d caracteres(chacun) :\n",N_mdp,L_mdp);

            for( i=1 ; i <=N_mdp ; i++){
                for( j=1 ; j<=L_mdp; j++ ){
                    x = rand () % 10;
                    y = rand () % 46;
                    z = rand () % 30;
                    printf("%c%c%c",num[x],lettre[y],symb[z]);
                }
                printf("\n");
            }
            break;
        case 0 :
            printf("Vous avez choisis de quitter l'application.\n Merci et a bientot !\n");
            break;
    }
    return 0;
}
