//
//  main.c
//  TP6-Tries
//
//  Created by Med Ayoub on 09/12/2013.
//  Copyright (c) 2013 Med Ayoub. All rights reserved.
//

//declaration des librairies

#include <stdio.h>
#include <stdlib.h>

//declaration des variables globales


//declaration des structures

typedef struct tableau{
    int info;
    struct tableau *suiv;
}tableau;

//declaration des fonctions

/* Nom de la fonction: creer_tableau
 * Entrees: une liste de type tableau
 *          un entier pour remplire la premiere cellule de la liste
 * Sorties: une liste qui contient une seule cellule
 * Description: Cette fonction nous permer de creer un creer une liste formee d'une seule cellule,
 *              initialisant son suivant a NULL
 */

void creer_tableau(tableau *tab, int val)
{
        tab->info = val;
        tab->suiv = NULL;
}

/* Nom de la fonction: ajout_tableau
 * Entrees: une liste de type tableau dans laquelle on va ajouter un element
 *          un entier a ajouter
 * Sorties: une liste
 * Description: Cette fonction nous permet d'ajouter une valeur a la fin d'une liste chainee
 */

tableau *ajout_tableau(tableau *tab, int valeur)
{
    tableau *tmp = (tableau*)malloc(sizeof(tableau));//allocation de la case memoire
    tmp->info = valeur;//creation d'une cellule
    tmp->suiv = NULL;
    
    if(!tab) return tmp;//si le tableau est vide, retourer la cellule precedement creee
    
    tableau *p = tab;//creation d'un pointeur temporair pour parcourir la liste jusaqu'a la position demandee
    while(p->suiv) p = p->suiv;
    p->suiv = tmp;//incertion de la cellule
    return tab;
}

/* Nom de la fonction: remplissage_tableau
 * Entrees: une liste chainee de type tableau a remplir
 * Sorties: une liste chainee apres remplissage
 * Description: Cette fonction nous permet de remplir une liste chainee, ceci en faisant a chaque
 *              fois appel a la fonction ajout_tableau
 */

tableau *remplissage_tableau(tableau *tab )
{
    char reponse = 'o';
    int valeur;
    printf("==========Remplissage du tableau:=========\n");
    do{
        printf("Donner une valeur:\n");
        scanf("%d",&valeur);
        getchar();
        tab = ajout_tableau(tab,valeur);
        printf("Voulez-vous ajouter une autre valeur ?! ('o'si oui)\n");
        scanf("%c",&reponse);
    }while (reponse == 'o');
    return tab ;
}

/* Nom de la fonction: affichage_tableau
 * Entrees: une liste chainee de type tableau
 * Sorties: NULL
 * Description: cette fonction nous permet d'afficher les element d'une liste un par un
 */

void affichage_tableau(tableau *tab)
{
    int i=0;
    printf("==========Affichage du tableau:=========\n");
    tableau *courant = tab;//creation d'un pointeur temporel pour le parcour de la liste chainee
    while (courant)//tant qu'on n'a pas atteint la fin de la liste, on continu
    {
        printf("tab[%d] = %d\n",i ,courant->info);
        courant = courant->suiv;//on passe au suivant
        i++;
    }
}

/* Nom de la fonction: echange
 * Entrees: Deux entiers dont les valeurs vont etre echangees
 * Sorties: NULL
 * Description: Cette fonction accepte pour arguments deux variables et echange leurs contenus
 */

void echange(int *val1 , int *val2)
{
    int tmp = *val1;
    *val1 = *val2;
    *val2 = tmp;
}

/* Nom de la fonction: tri_bulleo
 * Entrees: liste chainee d'entiers
 * Sorties: Null
 * Description: Cette fonction accepte comme argument une liste chainee d'entiers et lui applique
 *              la methode du tri a bulle, pour ordonner ses elements
 */

void tri_bulleo(tableau *tab)
{
    int f=1;
    tableau *crt;
    while(f == 1)// tant qu'on a pas fait un parcour complet sans faire d'echange, recommencer
    {
        f=0;
        crt = tab;//liste temporaire pour parcourir la liste chainee
        while( crt->suiv)//tant que crt a un suivant, faire la comparaison
        {
          if( crt->info > crt->suiv->info )//si l'element est supperieur a son suivant
            {
                echange(&crt->info , &crt->suiv->info);//faire l'echange
                f=1;
            }
            crt = crt->suiv;//passer a l'element suivant
        }
        affichage_tableau(tab);
    }
}

/* Nom de la fonction: tri_selection
 * Entrees: liste chainee d'entiers
 * Sorties: Null
 * Description: Cette fonction accepte comme argument une liste chainee d'entiers et lui applique
 *              la methode du tri par selection, pour ordonner ses elements
 */

void tri_selection(tableau *tab)
{
    int min;
    tableau *crt = tab;
    while (crt)
    {
        min = crt->info;
        tableau *tmp1 = crt->suiv;//liste temporaire pour parcourir la liste chainee
        tableau *tmp2;//liste temporaire pour enregistrer le dernier element min
        while(tmp1)//tant qu'on a pas atteint l'avant derniere posision
        {
            if(tmp1->info < min)//si la valeur actuelle est inf a min,
            {
                min = tmp1->info;//affecter min avec la valeur
                tmp2 = tmp1;//enregistrer la position, pour l'echange
            }
            tmp1 = tmp1->suiv;//passer a l'element suivant
        }
        
        if(crt->info != min) //si la valeur du min a change, on effectu l'echange
        {
            tmp2->info = crt->info;
            crt->info = min;
        }
        
        crt = crt->suiv;//passer a la comparaison de l'element suivant de la liste chainee
        affichage_tableau(tab);
    }
}

/*
 
 *
 * Nom de la fonction: ajout_ordonne_liste
 * Entrees: liste chainee d'entiers
 *          un entier a incerer dans la liste
 * Sorties: une nouvelle liste avec l'element ajoute
 * Description: Cette fonction accepte comme argument une liste chainee d'entiers et un entier et effectu
 *              l'ajout ordonne de ce dernier dans la liste avant de la retourner
 *


void ajout_ordonne_liste(tableau *tab, int val)
{
    tableau *tmp1 = *tab;
    tableau *tmp2 = malloc(sizeof(tableau));
    tableau *cell = malloc(sizeof(tableau));
    
    creer_tableau(cell, val);//creer un cellule de type liste, et y incerer val
    
    if(!tab)
    {
        *tab = cell;//si la liste est vide, retourner la cellule
        break;
    }
    
    //sinon incerer l'lement cellule
    while((tmp1) && (tmp1->info < val))//tant que le tableau n'est pas vide, et la position n'est la bonne
    {
        tmp2 = tmp1;//enregistrer la valeur courante
        tmp1 = tmp1->suiv;//passer a l'element suivant
    }
    
    cell->suiv = tmp1;//incerer l'element a la bonne position
    
    if(tmp1)  tmp2->suiv = cell;
    else *tab = cell;
}

 *
 * Nom de la fonction: tri_incertion
 * Entrees: liste chainee d'entiers
 * Sorties: Null
 * Description: Cette fonction accepte comme argument une liste chainee d'entiers et lui applique
 *              la methode du tri par selection, pour ordonner ses elements
 *


tableau *tri_incertion(tableau *tab)
{
    tableau *parcourt = tab;
    tableau *nouveau = NULL;
    
    while (parcourt) //tant qu'on a pas atteint la fin de la liste
    {
        ajout_ordonne_liste(&nouveau, parcourt->info);//on ajoute l'element
        parcourt = parcourt->suiv;//et on passe au suivant
        affichage_tableau(nouveau);
    }
    return nouveau;//retourner la nouvelle liste triee
}
 
*/

tableau *tri_incertion(tableau *liste)
{
    // Liste vide
    if((!liste) || (!liste->suiv))
        return liste;
    
    tableau *tete = NULL;
    while(liste)
    {
        tableau *courant = liste;
        liste = liste->suiv;
        if(!(tete) || (courant->info < tete->info))
        {
            // Insertion en tete
            courant->suiv = tete;
            tete = courant;
        }
        else
        {
            // Insertion au milieu
            tableau *p = tete;
            while(!p)
            {
                if((!p->suiv) || // dernier element de la liste triee
                   (courant->info < p->suiv->info)) // milieu de la liste
                {
                    courant->suiv = p->suiv;
                    p->suiv = courant;
                    break;
                }
                p = p->suiv;
            }
        }
        affichage_tableau(tete);
    }
    return tete;
}
