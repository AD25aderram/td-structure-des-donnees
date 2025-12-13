#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct cel
{
    int val;
    struct cel* next;
}cell;
typedef struct
{
    cell* rear;
    cell* front;
}file;

cell* ajouter_prem(cell* chaine, cell* e)
{
    e->next = chaine;
    return e;
}

cell* reverseplie(cell* top)
{
    cell * chaine = NULL;
    for(cell* i = top; i != NULL; i = i->next)
    {
        cell* e = malloc(sizeof(cell));
        e->val = i->val;
        e->next = NULL;
        chaine = ajouter_prem(chaine,e);

    }
    return chaine;
}

file* reversefile(file* q)
{
    file* qinv = malloc(sizeof(file));
    qinv->front = NULL;
    qinv->rear = NULL;
    cell* chaine = NULL;
    cell* fr = q->front;
    while(fr != NULL)
    {
        cell* e = malloc(sizeof(cell));
        e->val = fr->val;
        e->next = NULL;
        chaine = ajouter_prem(chaine,e);
        fr = fr->next;
    }
    cell*  i = chaine;
    while(i->next != NULL)
    {
        i = i->next;
    }
    qinv->rear = i;
    qinv->front = chaine;
    return qinv;
}

int main()
{
    // ---------------- Test reverseplie ----------------
    // Création d'une pile : 1 -> 2 -> 3
    cell* top = malloc(sizeof(cell));
    cell* c2 = malloc(sizeof(cell));
    cell* c3 = malloc(sizeof(cell));

    top->val = 1; top->next = c2;
    c2->val = 2; c2->next = c3;
    c3->val = 3; c3->next = NULL;

    // Inversion de la pile
    cell* reversed_stack = reverseplie(top);

    // Affichage pile inversée
    printf("Pile inversée : ");
    for(cell* p = reversed_stack; p != NULL; p = p->next)
        printf("%d ", p->val);
    printf("\n");

    // ---------------- Test reversefile ----------------
    // Création d'une file : 1 -> 2 -> 3
    file* f = malloc(sizeof(file));
    cell* f1 = malloc(sizeof(cell));
    cell* f2 = malloc(sizeof(cell));
    cell* f3 = malloc(sizeof(cell));

    f1->val = 1; f1->next = f2;
    f2->val = 2; f2->next = f3;
    f3->val = 3; f3->next = NULL;

    f->front = f1;
    f->rear = f3;

    // Inversion de la file
    file* reversed_queue = reversefile(f);

    // Affichage file inversée
    printf("File inversée : ");
    for(cell* p = reversed_queue->front; p != NULL; p = p->next)
        printf("%d ", p->val);
    printf("\n");

    return 0;
}
