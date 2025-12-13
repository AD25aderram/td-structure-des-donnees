#include <stdio.h>
#include <stdlib.h>

typedef struct cel
{
    int val;
    struct cel* next;
}cell;

cell* inverse_boucle(cell* head)
{
    if (head == NULL || head->next == head)
        return head;

    cell* prev = head;
    cell* curr = head->next;
    cell* next = NULL;

    while (curr != head)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head->next = prev; // nouveau dernier pointe vers le nouveau head
    return prev;       // prev est le nouveau head
}

int main()
{
    // Création d'une liste circulaire : 1 -> 2 -> 3 -> 4 -> 1
    cell* c1 = malloc(sizeof(cell));
    cell* c2 = malloc(sizeof(cell));
    cell* c3 = malloc(sizeof(cell));
    cell* c4 = malloc(sizeof(cell));

    c1->val = 1; c1->next = c2;
    c2->val = 2; c2->next = c3;
    c3->val = 3; c3->next = c4;
    c4->val = 4; c4->next = c1; // boucle

    // Affichage avant inversion (1 tour)
    printf("Liste avant inversion (1 tour) : ");
    cell* p = c1;
    do {
        printf("%d ", p->val);
        p = p->next;
    } while (p != c1);
    printf("\n");

    // Inversion de la boucle
    cell* inv = inverse_boucle(c1);

    // Affichage après inversion (1 tour)
    printf("Liste apres inversion (1 tour) : ");
    p = inv;
    do {
        printf("%d ", p->val);
        p = p->next;
    } while (p != inv);
    printf("\n");

    return 0;
}



