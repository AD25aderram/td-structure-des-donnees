#include <stdio.h>
#include <stdlib.h>
typedef struct cel
{
    int val;
    struct cel* next;
}cell;

cell* pose_en_premier(cell* chaine, cell* e)
{
    e->next = chaine;
    return e;
}
cell* reverse_it(cell* chaine)
{
    cell* curr = chaine;
    cell* next = NULL;
    cell* prev = NULL;

    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
cell* reverse_recursive(cell* chaine)
{
    if (chaine == NULL || chaine->next == NULL)
    {
        return chaine;
    }
    cell * j = reverse_recursive(chaine->next);
    chaine->next->next = chaine;
    chaine->next = NULL;

    return j;
}

int main()
{
    // Création d'une liste : 1 -> 2 -> 3 -> 4 -> 5
    cell* c1 = malloc(sizeof(cell));
    cell* c2 = malloc(sizeof(cell));
    cell* c3 = malloc(sizeof(cell));
    cell* c4 = malloc(sizeof(cell));
    cell* c5 = malloc(sizeof(cell));

    c1->val = 1; c1->next = c2;
    c2->val = 2; c2->next = c3;
    c3->val = 3; c3->next = c4;
    c4->val = 4; c4->next = c5;
    c5->val = 5; c5->next = NULL;

    printf("Liste originale : ");
    for (cell* p = c1; p != NULL; p = p->next)
        printf("%d ", p->val);
    printf("\n");

    // -------- Test reverse_it --------
    cell* r_it = reverse_it(c1);

    printf("Après reverse_it : ");
    for (cell* p = r_it; p != NULL; p = p->next)
        printf("%d ", p->val);
    printf("\n");

    // Comme reverse_it a déjà modifié la liste, on recrée une liste pour le test récursif
    cell* d1 = malloc(sizeof(cell));
    cell* d2 = malloc(sizeof(cell));
    cell* d3 = malloc(sizeof(cell));
    cell* d4 = malloc(sizeof(cell));
    cell* d5 = malloc(sizeof(cell));

    d1->val = 1; d1->next = d2;
    d2->val = 2; d2->next = d3;
    d3->val = 3; d3->next = d4;
    d4->val = 4; d4->next = d5;
    d5->val = 5; d5->next = NULL;

    // -------- Test reverse_recursive --------
    cell* r_rec = reverse_recursive(d1);

    printf("Après reverse_recursive : ");
    for (cell* p = r_rec; p != NULL; p = p->next)
        printf("%d ", p->val);
    printf("\n");

    return 0;
}

