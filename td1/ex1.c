#include <stdio.h>
#include <stdlib.h>
typedef struct cel
{
    int val;
    struct cel* next;
}cell;
int val_max_it(cell* chaine)
{
    int max = 0;
    if (chaine == NULL)
    {
        return 0;
    }
    max = chaine->val;
    for (cell* p = chaine; p != NULL ; p = p->next)
    {
        if (max < p->val)
        {
            max = p->val;

        }
    }
    return max;
}
int val_max_rec(cell* chaine)
{
    if (chaine == NULL)
    {
        return 0;
    }
    if (chaine->next == NULL)
    {
        return chaine->val;
    }
    if(chaine->val >= val_max_rec(chaine->next))
    {
         return chaine->val;
    }
    else
    {
        return val_max_rec(chaine->next);
    }
}


int main()
{

    cell* c1 = malloc(sizeof(cell));
    cell* c2 = malloc(sizeof(cell));
    cell* c3 = malloc(sizeof(cell));
    cell* c4 = malloc(sizeof(cell));

    c1->val = 5;  c1->next = c2;
    c2->val = 2;  c2->next = c3;
    c3->val = 9;  c3->next = c4;
    c4->val = 3;  c4->next = NULL;

    printf("Max (iteratif) : %d\n", val_max_it(c1));
    printf("Max (recursif) : %d\n", val_max_rec(c1));

    free(c4);
    free(c3);
    free(c2);
    free(c1);

    return 0;
}


