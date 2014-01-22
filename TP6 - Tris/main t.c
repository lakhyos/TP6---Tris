//
//  main1.c
//  TP6 - Tris
//
//  Created by Med Ayoub on 10/12/2013.
//  Copyright (c) 2013 Med Ayoub. All rights reserved.
//

//declaration des librairies

#include <stdio.h>
#include <stdlib.h>
#include "Tris tableaux.h"

//programme principal

int main ()
{
    int cas,reponse = 1;
    tableau *tab, *tab1, *tab2, *tab3, *tab4, *tab5;
    tab = creer_tableau();//creation d'un tableau
    tab1 = creer_tableau();
    tab2 = creer_tableau();
    tab3 = creer_tableau();
    tab4 = creer_tableau();
    tab5 = creer_tableau();
    remplissage_tableau(tab);//remplissage d'un tableau
    tab1=copie(tab, tab1);
    tab2=copie(tab, tab2);
    tab3=copie(tab, tab3);
    tab4=copie(tab, tab4);
    tab5=copie(tab, tab5);
    affichage_tableau(tab);//affichage
    while (reponse == 1)
    {
    reponse = 0;
    printf("\n------Comment voulez-vous procceder pour le tri du tableau"
           " ?!------\n"
           "1 - Pour un tri a bulles.\n"
           "2 - Pour un tri par insertion.\n"
           "3 - Pour un tri par selection.\n"
           "4 - Pour un tri rapide.\n"
           "5 - Pour un tri par tas.\n"
           "Votre reponse: \n");
    scanf("%d",&cas);
    switch (cas)
       {
        case 1:  printf("\ntri a bulles:\n");
                 affichage_tableau2(tab1);
                 tri_bulleo(tab1);//si 1 appliquer le tri a bulle
                 break;
        case 2:  printf("\ntri par insertion:\n");
                 affichage_tableau2(tab2);
                 tri_incertion(tab2);//si 2 appliquer le tri par incertion
                 break;
        case 3:  printf("\ntri par selection:\n");
                 affichage_tableau2(tab3);
                 tri_selection(tab3);//si 3 appliquer le tri par selection
                 break;
        case 4:  printf("\ntri rapide (Qsort):\n");
                 affichage_tableau2(tab4);//tri rapide (QSort)
                 tri_rapide(tab4, 0, tab4->dernier_elem);
                 break;
        case 5:  printf("\ntri par tas (Hsort):\n");
                 affichage_tableau2(tab5);//tri rapide (QSort)
                 tri_par_tas(tab5);
                 affichage_tableau2(tab5);
                 break;
       
       }
    printf("\nVoulez-vous retrier le tableau differament (0/1) ?!");
    scanf("%d",&reponse);
    }
    return 0;
}