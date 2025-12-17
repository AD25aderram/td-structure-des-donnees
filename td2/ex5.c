#include <stdio.h>
#include <stdlib.h>

typedef struct ar
{
    int val;
    struct ar* FD;
    struct ar* FG;
}arbre;
typedef struct cel
{
    int val;
    struct cel* next;
}cell;

cell* liste_non_div(arbre * ar, cell* liste)
{
    if(ar == NULL)
    {
        return liste;
    }
    if(ar->FD != NULL)
    {
        if(ar->FD->val % ar->val != 0)
        {
            cell* e = malloc(sizeof(cell));
            e->val = ar->FD->val;
            e->next = liste;
            liste = e;
        }
    }
    if(ar->FG != NULL)
    {
        if(ar->FG->val % ar->val != 0)
        {
            cell* g = malloc(sizeof(cell));
            g->val = ar->FG->val;
            g->next = liste;
            liste = g;
        }
    }
    liste = liste_non_div(ar->FD, liste);
    liste = liste_non_div(ar->FG, liste);
    return liste;
}
arbre* creer_noeud(int val)
{
    arbre* a = malloc(sizeof(arbre));
    a->val = val;
    a->FG = NULL;
    a->FD = NULL;
    return a;
}

void afficher_liste(cell* l)
{
    while (l != NULL)
    {
        printf("%d -> ", l->val);
        l = l->next;
    }
    printf("NULL\n");
}

int main()
{
    // Construction de l'arbre
    arbre* racine = creer_noeud(6);
    racine->FG = creer_noeud(3);
    racine->FD = creer_noeud(4);
    racine->FG->FG = creer_noeud(2);
    racine->FG->FD = creer_noeud(5);

    cell* liste = NULL;

    // Appel de la fonction
    liste = liste_non_div(racine, liste);

    // Affichage du résultat
    printf("Liste des fils non divisibles par leur parent :\n");
    afficher_liste(liste);

    return 0;
}

