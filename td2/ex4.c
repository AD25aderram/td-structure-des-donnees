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
float moyenne_arb(arbre* ar)
{
    cell* l =  parcour_prefixe(ar);
    float sum = 0;
    float comp = 0;
    for(cell* i = l;i!=NULL;i=i->next)
    {
        if(i->val >= 0)
        {
            sum += i->val;
            comp++;
        }
    }
    return sum / comp ;
}
