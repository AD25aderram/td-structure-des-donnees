#include <stdio.h>
#include <stdlib.h>
typedef struct cel
{
    int val;
    struct cel* next;
}cell;
cell * suprim_val(cell* liste, int val)
{
    while(liste!= NULL && liste->val == val)
    {
        cell* temp = liste;
        liste = liste->next;
        free(temp);
    }

    for(cell* i = liste; i!=NULL; i=i->next)
    {
        cell* p = i->next;
        if (p != NULL)
        {
            if(p->val == val)
            {
                i->next = p->next;
                free(p);
                break;
            }
        }
    }
    return liste;
}
cell* suprim_val_k_fois(cell* liste, int val, int k)
{
    int comp = 0;
    while(k>comp)
    {
        while(liste!= NULL && liste->val == val)
        {
            cell* temp = liste;
            liste = liste->next;
            free(temp);
            comp++;
        }
        for(cell* i = liste; i!=NULL; i=i->next)
        {
            cell* p = i->next;
            if(p->val == val && comp <= k)
            {
                i->next = p->next;
                free(p);
                comp++;
                break;
            }
        }
    }

    return liste;
}
cell* suprim_val_fois(cell* liste)
{
    if (liste == NULL)
    {
        return NULL;
    }
    cell* i = liste;
    while (i != NULL)
    {
        cell* prev = i;
        cell* j = i->next;

        while (j != NULL)
        {
            if (j->val == i->val)
            {

                prev->next = j->next;
                free(j);
                j = prev->next;
            }
            else
            {
                prev = j;
                j = j->next;
            }
        }

        i = i->next;
    }

    return liste;
}

int main()
{
    // Création de la liste : 1 -> 2 -> 3 -> 2 -> 4 -> 2 -> 5
    cell* c1 = malloc(sizeof(cell));
    cell* c2 = malloc(sizeof(cell));
    cell* c3 = malloc(sizeof(cell));
    cell* c4 = malloc(sizeof(cell));
    cell* c5 = malloc(sizeof(cell));
    cell* c6 = malloc(sizeof(cell));
    cell* c7 = malloc(sizeof(cell));

    c1->val = 1; c1->next = c2;
    c2->val = 2; c2->next = c3;
    c3->val = 3; c3->next = c4;
    c4->val = 2; c4->next = c5;
    c5->val = 4; c5->next = c6;
    c6->val = 2; c6->next = c7;
    c7->val = 5; c7->next = NULL;

    // Affichage avant
    printf("Liste initiale : ");
    for(cell* p = c1; p != NULL; p = p->next)
        printf("%d ", p->val);
    printf("\n");

    // -------- Test suprim_val : supprimer toutes les occurrences de 2 --------
    cell* test1 = suprim_val(c1, 2);

    printf("Apres suprim_val(2) : ");
    for(cell* p = test1; p != NULL; p = p->next)
        printf("%d ", p->val);
    printf("\n");

    // -------- Re-créer la liste pour les autres tests --------
    // (Parce que suprim_val a déjà modifié la liste)
    cell* d1 = malloc(sizeof(cell));
    cell* d2 = malloc(sizeof(cell));
    cell* d3 = malloc(sizeof(cell));
    cell* d4 = malloc(sizeof(cell));
    cell* d5 = malloc(sizeof(cell));
    cell* d6 = malloc(sizeof(cell));
    cell* d7 = malloc(sizeof(cell));

    d1->val = 1; d1->next = d2;
    d2->val = 2; d2->next = d3;
    d3->val = 3; d3->next = d4;
    d4->val = 2; d4->next = d5;
    d5->val = 4; d5->next = d6;
    d6->val = 2; d6->next = d7;
    d7->val = 5; d7->next = NULL;

    // -------- Test suprim_val_k_fois : supprimer 2 deux fois --------
    cell* test2 = suprim_val_k_fois(d1, 2, 2);

    printf("Après suprim_val_k_fois(2, 2) : ");
    for(cell* p = test2; p != NULL; p = p->next)
        printf("%d ", p->val);
    printf("\n");

    // -------- Re-créer la liste encore --------
    cell* e1 = malloc(sizeof(cell));
    cell* e2 = malloc(sizeof(cell));
    cell* e3 = malloc(sizeof(cell));
    cell* e4 = malloc(sizeof(cell));
    cell* e5 = malloc(sizeof(cell));
    cell* e6 = malloc(sizeof(cell));
    cell* e7 = malloc(sizeof(cell));

    e1->val = 1; e1->next = e2;
    e2->val = 2; e2->next = e3;
    e3->val = 3; e3->next = e4;
    e4->val = 2; e4->next = e5;
    e5->val = 4; e5->next = e6;
    e6->val = 2; e6->next = e7;
    e7->val = 5; e7->next = NULL;

    // -------- Test suprim_val_fois : supprimer les doublons --------
    cell* test3 = suprim_val_fois(e1);

    printf("Après suprim_val_fois() (supprime les doublons) : ");
    for(cell* p = test3; p != NULL; p = p->next)
        printf("%d ", p->val);
    printf("\n");

    return 0;
}


