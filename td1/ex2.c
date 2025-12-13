#include <stdio.h>
#include <stdlib.h>
typedef struct cel
{
    int val;
    struct cel* next;
}cell;
cell* concatener_chaine(cell* L1, cell* L2)
{
    if (L1 == NULL)
    {
        return L2;
    }
    if (L2 == NULL)
    {
        return L1;
    }
    cell * p = L1;
    while(p->next!=NULL)
    {
        p = p->next;
    }
    p->next = L2;

    return L1;
}
int main()
{
    // Création de la première liste : 1 -> 2 -> 3
    cell* a1 = malloc(sizeof(cell));
    cell* a2 = malloc(sizeof(cell));
    cell* a3 = malloc(sizeof(cell));

    a1->val = 1;  a1->next = a2;
    a2->val = 2;  a2->next = a3;
    a3->val = 3;  a3->next = NULL;

    // Création de la deuxième liste : 4 -> 5
    cell* b1 = malloc(sizeof(cell));
    cell* b2 = malloc(sizeof(cell));

    b1->val = 4;  b1->next = b2;
    b2->val = 5;  b2->next = NULL;

    // Concaténation
    cell* result = concatener_chaine(a1, b1);

    // Affichage du résultat
    printf("Liste concaténée : ");
    cell* p = result;
    while (p != NULL)
    {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");

    return 0;
}


