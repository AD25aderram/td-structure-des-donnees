#include <stdio.h>
#include <stdlib.h>
typedef struct cel
{
    int val;
    struct cel* next;
}cell;
cell * init(int val)
{
    cell* e = malloc(sizeof(cell));
    e->val = val;
    e->next = NULL;
    return e;
}
cell* ajouter_prem(cell* list, cell* e)
{
    e->next = list;
    return e;
}
cell* ordone(int tableau[],int n)
{
    cell* chaine = NULL;
    while(n>0)
    {
        int min = tableau[0];
        int j = 0;
        cell* v = NULL;
        for (int i = 0; i < n; i = i+1)
        {
            if (min > tableau[i])
            {
                min = tableau[i];
                j = i;
            }

        }
        v = init(min);
        chaine = ajouter_prem(chaine,v);

        for(int el = j; el < n-1;el = el+1)
        {
            tableau[el] = tableau[el+1];
        }
        n--;

    }
    return chaine;

}
int main()
{
    int n;
    printf("Donner le nombre d'elements du tableau : ");
    scanf("%d", &n);

    int tableau[n];
    for(int i = 0; i < n; i++)
    {
        printf("Element %d : ", i+1);
        scanf("%d", &tableau[i]);
    }

    // Tri et conversion en liste
    cell* liste = ordone(tableau, n);

    // Affichage de la liste triée
    printf("Liste triee : ");
    for(cell* p = liste; p != NULL; p = p->next)
    {
        printf("%d ", p->val);
    }
    printf("\n");

    return 0;
}

