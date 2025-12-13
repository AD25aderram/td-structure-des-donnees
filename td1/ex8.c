#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct cel
{
    int val;
    struct cel* next;
}cell;
cell* initcell(int vall)
{
    cell* e = malloc(sizeof(cell));
    e->val = vall;
    e->next = NULL;
    return e;
}
cell* ajouter_prem(cell* liste, cell* e)
{
    e->next = liste;
    return e;
}
cell* fournir_le_polynome(int n)
{
    cell* chaine = NULL;
    cell* e;
    for (int i = 0; i<n;i++)
    {
        int vall;
        printf("entrer le coificent : \n");
        scanf("%d", &vall);
        e = initcell(vall);
        chaine = ajouter_prem(chaine,e);
    }
    return chaine;
}
int value_pol(cell* chaine, int vll)
{
    int res = 0;
    for(cell* i = chaine; i!=NULL; i = i->next)
    {
        res += pow(vll, i->val);
    }
    return res;
}

int main()
{
    int n;
    printf("Donner le nombre de coefficients du polynome : ");
    scanf("%d", &n);

    // Construire la liste des coefficients
    cell* poly = fournir_le_polynome(n);

    int x;
    printf("Donner la valeur de x : ");
    scanf("%d", &x);

    int resultat = value_pol(poly, x);

    printf("La valeur du polynome en x = %d est : %d\n", x, resultat);

    return 0;
}

