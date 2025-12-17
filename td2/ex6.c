#include <stdio.h>
#include <stdlib.h>

typedef struct ar
{
    int val;
    struct ar* FG;
    struct ar* FD;
}arbre;
arbre* creer_noeud(int val)
{
    arbre* a = malloc(sizeof(arbre));
    a->val = val;
    a->FG = NULL;
    a->FD = NULL;
    return a;
}
arbre* small_than_val(arbre* ar, int e)
{
    if(ar == NULL)
    {
        return NULL;
    }
    arbre* res = NULL;
    arbre* a = ar;
    while(a != NULL)
    {
        if(a->val >= e)
        {
            a = a->FG;
        }else
        {
            arbre* nouv = creer_noeud(a->val);
            if (a->FG != NULL)
                nouv->FG = small_than_val(a->FG, e);
            else
                nouv->FG = NULL;

            // le sous-arbre droit
            if (a->FD != NULL)
                nouv->FD = small_than_val(a->FD, e);
            else
                nouv->FD = NULL;

            res = nouv;
            break;
        }
    }
    return res;
}
int main()
{
    // Création d'un ABR simple
    arbre* racine = creer_noeud(10);
    racine->FG = creer_noeud(5);
    racine->FD = creer_noeud(15);
    racine->FG->FG = creer_noeud(2);
    racine->FG->FD = creer_noeud(8);
    racine->FD->FD = creer_noeud(20);

    int e = 9; // seuil

    // Créer un nouvel arbre avec tous les éléments < e
    arbre* nouv = small_than_val(racine, e);

    // Fonction pour afficher l'arbre (préfixe + indentation)
    void afficher_arbre(arbre* ar, int niveau)
    {
        if (ar == NULL) return;
        for (int i = 0; i < niveau; i++) printf("  ");
        printf("%d\n", ar->val);
        afficher_arbre(ar->FG, niveau + 1);
        afficher_arbre(ar->FD, niveau + 1);
    }

    printf("Arbre original:\n");
    afficher_arbre(racine, 0);

    printf("\nNouvel arbre (valeurs < %d):\n", e);
    afficher_arbre(nouv, 0);

    return 0;
}

