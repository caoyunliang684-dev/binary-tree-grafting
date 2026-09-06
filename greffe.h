#ifndef TP_ARBRES_ARBRES_BINAIRES_H
#define TP_ARBRES_ARBRES_BINAIRES_H
#endif //TP_ARBRES_ARBRES_BINAIRES_H

typedef struct noeud Noeud , *Arbre;
int copie(Arbre *dest,Arbre source);
void expansion(Arbre *A,Arbre B);
void insertSubtree(Arbre *node, Arbre subtree);

