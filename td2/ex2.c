// parcour en largeur 4 2 20 0 3 12 1 7 15 6 13 14
// parcour prefixe    4 2 0 1 3 20 12 7 6 15 13 14
// parcour infixe     0 1 2 3 4 6 7 12 13 14 15 20
// parcour postefixe  1 0 3 2 6 7 14 13 15 12 20 4



#include <stdio.h>
#include <stdlib.h>

typedef struct ar
{
    int val;
    struct ar* FG;
    struct ar* FD;
}arbre;

typedef struct cel
{
    int val;
    struct cel* next;
}cell;
cell* parcour_prefixe(arbre* ar)
{
    if(ar==NULL)
    {
        return NULL;
    }
    cell* chaine = malloc(sizeof(cell));
    chaine->val = ar->val;
    chaine->next = NULL;
    cell* g = parcour_prefixe(ar->FG);
    cell* d = parcour_prefixe(ar->FD);
    if (g!=NULL)
    {
        chaine->next = g;
        cell* dernier = NULL;
        for(cell* i = g; i!=NULL; i=i->next)
        {
            dernier = i;
        }
        dernier->next = d;

    }
    else
    {
        chaine->next = d;
    }


    return chaine;
}
