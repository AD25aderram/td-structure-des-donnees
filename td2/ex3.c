#include <stdio.h>
#include <stdlib.h>

typedef struct ar
{
    int val;
    struct ar* FG;
    struct ar* FD;
}arbre;
int min(int a, int b)
{
    return (a<b)?a:b;
}
int smallest_value_non_arb(arbre* ar)
{
    int mini = ar->val;
    if ((ar->FD==NULL)&&(ar->FG==NULL))
    {
        return mini;
    }else if(ar->FD==NULL)
    {
        return min(mini,ar->FG->val);
    }else if (ar->FG==NULL)
    {
         return min(mini,ar->FD->val);
    }
    return min(min(smallest_value_non_arb(ar->FD),smallest_value_non_arb(ar->FG)),mini);
    
}
int smallest_value_abr(arbre* ar)
{
    int dernier = ar->val;
    arbre* i = ar;
    while(i != NULL)
    {
        dernier = i->val;
        i = i->FG;
    }
    return dernier;
}
int del_small_num(arbre* ar)
{
    int mini = smallest_value_abr(ar);
    arbre* i = ar;
    arbre* pres = NULL;
    while(i->FG != NULL)
    {
        pres = i;
        i = i->FG;

    }
    pres->FG = NULL;
    pres->FD = i->FD;
    free(i);
    return mini;
}
arbre* del_racine(arbre* ar)
{
    if(ar->FG != NULL)
    {
        int mini = del_small_num(ar);
        ar->val = mini;
        return ar;
    }else if (ar->FD != NULL)
    {
        arbre* new_r = ar->FD;
        free(ar);
        return new_r;
    }else
    {
        free(ar);
        return NULL;
    }
}
