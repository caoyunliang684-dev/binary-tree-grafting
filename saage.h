

#ifndef TP_ARBRES_SAAGE_H
#define TP_ARBRES_SAAGE_H
#include <stdio.h>
#endif //TP_ARBRES_SAAGE_H
typedef struct noeud Noeud , *Arbre;
int serialise_aux(FILE *f, Arbre A, int depth);
int serialise(char *nom_de_ficher,Arbre A);
int deserialise_aux(FILE* f, Arbre* a);
int deserialise(char *nom_de_ficher,Arbre *A);
