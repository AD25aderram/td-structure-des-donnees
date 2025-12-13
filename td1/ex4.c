#include <stdio.h>
#include <stdlib.h>
typedef struct cel
{
    int val;
    struct cel* next;
}cell;
cell* echanger(cell* head, cell* t, cell* v)
{
    if (t == v || head == NULL) return head;

    cell* prevT = NULL;
    cell* prevV = NULL;
    cell* curr = head;

    // Trouver les précédents de t et v
    while (curr != NULL)
    {
        if (curr->next == t) prevT = curr;
        if (curr->next == v) prevV = curr;
        curr = curr->next;
    }

    // Si t ou v est la tête
    if (head == t) prevT = NULL;
    if (head == v) prevV = NULL;


    // Si t et v sont adjacents
    if (t->next == v)
    {
        if (prevT != NULL)
            prevT->next = v;
        t->next = v->next;
        v->next = t;
    }
    else if (v->next == t)
    {
        if (prevV != NULL)
            prevV->next = t;
        v->next = t->next;
        t->next = v;
    }
    else
    {
        // Si t et v ne sont pas adjacents
        cell* temp = t->next;
        t->next = v->next;
        v->next = temp;

        if (prevT != NULL) prevT->next = v; else head = v;
        if (prevV != NULL) prevV->next = t; else head = t;
    }

    // Retourner la nouvelle tête
    if (head == t) return v;
    if (head == v) return t;
    return head;
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

    // Pointeurs à échanger : t = c2 (val = 2), v = c4 (val = 4)
    cell* t = c2;
    cell* v = c4;

    // Appel de la fonction
    cell* result = echanger(c1, t, v);

    // Affichage résultat
    printf("Liste après échange : ");
    for (cell* p = result; p != NULL; p = p->next)
        printf("%d ", p->val);
    printf("\n");

    return 0;
}


