#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h"

/* afficher toutes les categories de menu */
void showCategories(char **categ)
{

    for (int k = 1, i=0; i<6; ++i, ++k)
    {
        printf("%d.%-10s\t\t", i+1, categ[i]);
        if (k%3==0) printf("\n\n\n");
    }

}

// *********************************************************************
/* afficher les sous categories de la categorie drinks*/
void showSubCategories(char **sub_categ)
{

    printf("Juices or something else?\n");
    for (int l = 1, k=0; k<2; ++l, k++)
    {
        printf("%d.%-10s\t", k+1, sub_categ[k]);
        if (l%3==0) printf("\n\n\n");
    }
    printf("\n============================================= \n");
}

// *********************************************************************
/*afficher les elements de la categorie desserts*/
void showDesserts(char **d)
{

    for(int k = 1, j=0; j<12; ++j, ++k)
    {
        printf("%d.%-10s\t\t", j+1, d[j]);
        if (k%3==0) printf("\n\n\n");
    }
    printf("\n========================================================= \n");
    printf("Enter number of element:\n");
}

// *********************************************************************
/*afficher les elements de la categorie juices*/
void showJuices(char **j)
{
    for(int k = 1, i=0; i<12; ++i, ++k)
    {
        printf("%d.%-10s\t", i+1, j[i]);
        if (k%3==0) printf("\n\n\n");
    }
    printf("\n========================================================= \n");
    printf("Enter number of element:\n");
}

// *********************************************************************
/*afficher les elements de la categorie coeffe*/
void showCoeffes(char **c)
{
    for(int k = 1,  j=0; j<12; ++j, ++k)
    {
        printf("%d.%-10s\t\t", j+1, c[j]);
        if (k%3==0) printf("\n\n\n");
    }
    printf("\n ================================================ \n");
    printf("Enter number of element:\n");
}

// *********************************************************************
/*afficher les elements de la categorie tea*/
void showTeas(char **t)
{
    for(int k = 1, j=0; j<8; ++j, ++k)
    {
        printf("%d.%-10s\t", j+1, t[j]);
        if (k%3==0) printf("\n\n\n");
    }
    printf("\n================================================ \n");
    printf("Enter number of element:\n");
}

// *********************************************************************
/*afficher les elements de la categorie traditional*/
void showTraditionalDishes(char **td)
{

    for(int k = 1, j=0; j<9; ++j, ++k)
    {
        printf("%d.%-10s\t", j+1, td[j]);
        if (k%3==0) printf("\n\n\n");
    }
    printf("\n=============================================== \n");
    printf("Enter number of element:\n");
}

// *********************************************************************
/*afficher les elements de la categorie burger*/
void showBurgers(char **bu)
{

    for(int k = 1, j=0; j<9; ++j, ++k)
    {
        printf("%d.%-13s\t\t", j+1, bu[j]);
        if (k%3==0) printf("\n\n\n");
    }
    printf("\n================================================ \n");
    printf("Enter number of element:\n");
}

// *********************************************************************
/*afficher les elements de la categorie other*/
void showOthers(char **o)
{
    for(int k = 1, j=0; j<5; ++j, ++k)
    {
        printf("%d.%-10s\t", j+1, o[j]);
        if (k%3==0) printf("\n\n\n");
    }
    printf("\n======================================= \n");
    printf("Enter number of element:\n");
}

// *********************************************************************
void yourChoices(char **choices, int nbCommande) /* à chaque commande le programme affichera l'element choisi par le client
						  pour une verfication*/
{

    printf("%s\t\t", choices[nbCommande-1]);

    printf("\n");
}

// *********************************************************************
/* l'elemnt choisi par le client à chaque commande sera ajouté au tableau de choix pour le conservé*/
void addElements(char **choices, char **categ, int nbElement, int nbCommande)
{
    choices[nbCommande-1] = categ[nbElement-1];

}

// *********************************************************************
/* cette fontion affiche le prix total à payé par le client
et la date et l'heure de la commande et d'autres informations sous la forme d'une facture*/
void facture(char **choices, double prices[], int nbCommande)
{
    system("clear");
    printf("\t\t\t Restaurant TEAM C \n\t\t\t*******************\n");
    char curr_time[10], curr_date[12];
    strcpy(curr_date, __DATE__);
    strcpy(curr_time, __TIME__);
    printf("======== %s\t\t\t%s ========\n", curr_date, curr_time);
    printf("Facture N°:%d \t\t Client N°: %d\n", rand()%500, rand()%100);
    printf("---------------------------------------------------------\n");
    for(int i = 0; i<nbCommande; ++i)
    {
        printf("%d. %-30s\t %g  EUR\n", i+1, choices[i], prices[i]);//%g pour supprimer les zeros apres la virgule
    }


    double TTC=0;
    for(int i=0; i<nbCommande; ++i)
    {
        TTC += prices[i];
    }
    printf("---------------------------------------------------------\n");
    printf("TOTAL TTC %g EUR\n\n", TTC);
    printf("\t\t\t WIFI password: someWOORD123\n\n\n");
    printf("*************** Thanks for visiting us! *************** \n\t\t  *******************");
}

// *********************************************************************
/* le prix de chaque element choisi sera ajouté au tableau des prix pour l'utiliser
dans l'affichage de la facture et le calcul de prix total*/
void addPrices(double prices[], double categP[], int nbElement, int nbCommande)
{


    prices[nbCommande-1] = categP[nbElement-1];

}

// *********************************************************************
/* le tableau de choix est initialisé à un seul element, mais à chaque 
fois que le client fait une autre commande, ce tableau doit être élargir pour 
contient d'autre element*/
void resizeChoices(char **choices, int nbCommande)
{
    choices = malloc(1 * sizeof(*choices));
    if (choices)
    {
        char** resizeChoices_ = realloc(choices, nbCommande * sizeof(*choices));
        if (resizeChoices_)
        {
            choices = resizeChoices_;
        }

        free(choices);
    }
}

// *********************************************************************

/* la meme chose que tableau de choix */
void resizePrices(double prices[], int nbCommande)
{

    prices = malloc(1 * sizeof(double));
    if (prices)
    {
        double *resizePrices_ = realloc(prices, nbCommande * sizeof(double));
        if (resizePrices_)
        {
            prices = resizePrices_;
        }

        free(prices);
    }
}

