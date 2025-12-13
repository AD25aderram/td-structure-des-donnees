#include <stdio.h>
#include <stdlib.h>
typedef struct cel
{
    int val;
    struct cel* next;
}cell;

cell* initcell(int val)
{
    cell * e = malloc(sizeof(cell));
    e->val = val;
    e->next = NULL;
    return e;

}
cell* ajouter_prem(cell* list, cell* e)
{
    e->next = list;
    list = e;
    return list;

}
void split_liste(cell* chaine, cell** pos, cell** neg)
{
    *pos = NULL;
    *neg = NULL;

    for(cell* i = chaine;i!=NULL;i=i->next)
    {
        cell* e = initcell(i->val);
        if(i->val > 0)
        {
            *pos = ajouter_prem(*pos,e);
        }
        if(i->val < 0)
        {
            *neg = ajouter_prem(*neg,e);
        }
    }

}

int main()
{

    cell* c1 = initcell(3);
    cell* c2 = initcell(-1);
    cell* c3 = initcell(7);
    cell* c4 = initcell(-4);
    cell* c5 = initcell(0);
    cell* c6 = initcell(5);

    c1->next = c2;
    c2->next = c3;
    c3->next = c4;
    c4->next = c5;
    c5->next = c6;


    cell* pos = NULL;
    cell* neg = NULL;


    split_liste(c1, &pos, &neg);


    printf("Liste positive : ");
    for(cell* p = pos; p != NULL; p = p->next)
        printf("%d ", p->val);
    printf("\n");

    // Afficher liste negative
    printf("Liste negative : ");
    for(cell* p = neg; p != NULL; p = p->next)
        printf("%d ", p->val);
    printf("\n");

    return 0;
}

