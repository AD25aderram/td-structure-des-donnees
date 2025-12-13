#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct cel
{
    int val;
    struct cel* next;
}cell;


cell* nouvellePile(int val)
{
    cell* e = malloc(sizeof(cell));
    e->val = val;
    e->next = NULL;
    return e;
}

int estPileVide(cell* pile)
{
    if (pile == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
cell* empiler(cell*p ,int val)
{
    //meme comme ajouter en premier
    cell* e =malloc(sizeof(cell));
    e->val = val;
    e->next = p;
    p = e;
    return p;
}
int depiler(cell** p)
{
    int v = (*p)->val;
    cell* l = *p;
    (*p) = (*p)->next;
    free(l);
    return v;
}
int somme_pile(int n)
{
    cell*p = nouvellePile(1);
    for (int i = 2; i<=n; i++)
    {
        p = empiler(p,i);
    }
    int some = 0;
    while(!estPileVide(p))
    {
        some += depiler(&p);
    }
    return some;
}
int somme_recur(int n)
{
    if(n==0)
    {
        return 0;
    }
    return n + somme_recur(n-1);
}


int main()
{
    int n = 5;

    int sum_stack = somme_pile(n);
    printf("Somme avec pile : %d\n", sum_stack);

    int sum_rec = somme_recur(n);
    printf("Somme recursive : %d\n", sum_rec);

    return 0;
}

