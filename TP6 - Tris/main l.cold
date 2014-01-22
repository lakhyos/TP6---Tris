//
//  main l.c
//  TP6 - Tris
//
//  Created by Med Ayoub on 11/12/2013.
//  Copyright (c) 2013 Med Ayoub. All rights reserved.
//


//declaration des librairies

#include <stdio.h>
#include <stdlib.h>
#include "Tris listes.h"

//programme principal

int main ()
{
    int cas;
    tableau *tab = NULL;
    tab = remplissage_tableau(tab);//remplissage d'un tableau
    affichage_tableau(tab);//affichage
    printf("------Comment voulez-vous procceder pour le tri du tableau ?!------\n"
           "1 - Pour un tri a bulles.\n"
           "2 - Pour un tri par selection.\n"
           "Votre reponse:");
    scanf("%d",&cas);
    switch (cas){
        case 1:   tri_bulleo(tab);//si 1 appliquer le tri a bulle
                  break;
        /*case 2:   tab = tri_incertion(tab);//si 2 appliquer le tri par incertion
                  break;*/
        case 2:   tri_selection(tab);//si 3 appliquer le tri par selection echange
                  break;
        /*case 4: tri_rapide(tab, 0, tab->dernier_elem);
                  break; */
    }
    return 0;
}