#include <stdio.h>
#include <stdlib.h>


typedef char element;

struct cellule
{
    element contenu;
    struct cellule *precedent;
};

typedef struct cellule cellule;

typedef struct 
{
    cellule* tete;
}pile_liste;

void initPile(pile_liste* p)
{
    p->tete=NULL;
}

int pileVide(pile_liste p)
{
   return(p.tete==NULL);
}

void pushPile(pile_liste* p,element valeur)
{
    cellule *q;
    q=(cellule*)malloc(sizeof(cellule));
    q->contenu=valeur;
    q->precedent=p->tete;
    p->tete=q;

}

int popPile(pile_liste *p)
{
    if(pileVide(*p)) exit;
    else
    {
        cellule *q;
        element valeurPop;
        q=p->tete;
        valeurPop=q->contenu;
        p->tete=q->precedent;
        free(q);
        return valeurPop;
    }
}
