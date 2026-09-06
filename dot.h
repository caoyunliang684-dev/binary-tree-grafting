#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "saage.h"

typedef struct noeud{
    char *val;
    struct noeud *fg,*fd;
}Noeud,*Arbre;

Noeud *alloue_noeud(char *s);
void librer(Arbre *A);
void ecrireDebut(FILE *f);
void ecrireArbre(FILE *f, Arbre a);
void ecrireFin(FILE *f);
void dessine(FILE *f, Arbre a);
void creePDF(char *dot, char *pdf, Arbre a);
