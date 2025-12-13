#include <stdio.h>
#include <stdlib.h>
typedef struct cel
{
    int val;
    struct cel* next;
}cell;

cell* trans_lineriare_to_circulaire(cell* chaine)
{
    if (chaine == NULL) return NULL;
    cell* dernier = NULL;
    for(cell* i = chaine; i!= NULL; i = i->next)
    {
        dernier = i;
    }
    dernier->next = chaine;
    return chaine;
}

int main()
{
    // Création d'une liste linéaire : 1 -> 2 -> 3 -> 4
    cell* c1 = malloc(sizeof(cell));
    cell* c2 = malloc(sizeof(cell));
    cell* c3 = malloc(sizeof(cell));
    cell* c4 = malloc(sizeof(cell));

    c1->val = 1; c1->next = c2;
    c2->val = 2; c2->next = c3;
    c3->val = 3; c3->next = c4;
    c4->val = 4; c4->next = NULL;

    // Transformation en circulaire
    cell* circ = trans_lineriare_to_circulaire(c1);

    // Affichage limité à 2 tours pour éviter boucle infinie
    printf("Liste circulaire (2 tours) : ");

    cell* p = circ;
    int tours = 2;
    int compteur = 0;

    if (p != NULL)
    {
        do {
            printf("%d ", p->val);
            p = p->next;

            if (p == circ)  // on a fait un tour
                compteur++;

        } while (compteur < tours);
    }

    printf("\n");
    return 0;
}
