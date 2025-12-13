#include <stdio.h>
#include <stdlib.h>
typedef struct ar
{
    int val;
    struct ar* FG;
    struct ar* FD;
}arbre;
int max(int a, int b)
{
    return (a > b) ? a : b;
}
arbre* empty()
{
    arbre* p = malloc(sizeof(arbre));
    p->val = 0;
    p->FD = NULL;
    p->FG = NULL;
    return p;
}
int is_empty(arbre* p)
{
    if(p==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
arbre* sad(arbre* ar)
{
    if (is_empty(ar))
    {
        return NULL;
    }
    else
    {
        return ar->FD;
    }
}
arbre* sag(arbre* ar)
{
    if (is_empty(ar))
    {
        return NULL;
    }
    else
    {
        return ar->FG;
    }
}
int taille(arbre* ar)
{
    if(is_empty(ar))
    {
        return 0;
    }
    return 1 + taille(ar->FD) + taille(ar->FG);
}
int hauteur(arbre* ar)
{
    if(is_empty(ar))
    {
        return 0;
    }
    return 1 + max(hauteur(ar->FD),hauteur(ar->FG));
}
int nest_pas_filiforme(arbre* ar)
{
    if(is_empty(ar))
    {
        return 0;
    }
    else
    {
        if (ar->FD != NULL && ar->FG != NULL)
        {
            return 1;
        }
        else
        {
            return max(nest_pas_filiforme(ar->FD),nest_pas_filiforme(ar->FG));
        }
    }

}
int est_filforme(arbre* ar)
{
    return !nest_pas_filiforme(ar);
}
arbre* peigne(int n)
{
    if(n<=0)
    {
        return NULL;
    }
    arbre* a = empty();
    a->FG = peigne(n-1);
    return a;
}
int main()
{

    printf("\n=== TEST 1 : peigne(5) ===\n");
    arbre* p = peigne(5);

    printf("is_empty(p) = %d\n", is_empty(p));
    printf("taille(p) = %d\n", taille(p));
    printf("hauteur(p) = %d\n", hauteur(p));
    printf("est_filforme(p) = %d\n", est_filforme(p));

    printf("\n=== TEST 2 : peigne(1) ===\n");
    arbre* q = peigne(1);

    printf("taille(q) = %d\n", taille(q));
    printf("hauteur(q) = %d\n", hauteur(q));
    printf("est_filforme(q) = %d\n", est_filforme(q));

    return 0;
}
