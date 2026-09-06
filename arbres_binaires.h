

#ifndef TP_ARBRES_ARBRES_BINAIRES_H
#define TP_ARBRES_ARBRES_BINAIRES_H

#endif //TP_ARBRES_ARBRES_BINAIRES_H
typedef struct noeud Noeud , *Arbre;

Noeud *alloue_noeud(char *s);
void librer(Arbre *A);
int construit_arbre(Arbre *a);
#include <stdlib.h>
#include <string.h>

char* my_strdup(const char* s);
void cree_A_1(void);
void cree_A_2(void);
void cree_A_3(void);
