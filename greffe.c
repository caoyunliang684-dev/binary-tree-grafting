#include "greffe.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "arbres_binaires.h"

typedef struct noeud{
    char *val;
    struct noeud *fg,*fd;
}Noeud,*Arbre;

int copie(Arbre *dest, Arbre source) {
    if (source == NULL) {
        *dest = NULL;
        return 1; 
    } else {
        *dest = (Arbre)malloc(sizeof(Noeud));
        if (*dest == NULL) {
            return 0;
        }
        (*dest)->val = my_strdup(source->val);
        if ((*dest)->val == NULL) {
            librer(dest);
            return 0;
        }
        if (!copie(&((*dest)->fg), source->fg) || !copie(&((*dest)->fd), source->fd)) {
            librer(dest);
            return 0;
        }
        return 1; 
    }
}


void insertSubtree(Arbre *node, Arbre subtree) {
    if (!*node || !subtree) {
        return; 
    }
    if (!(*node)->fg) {
        copie(&((*node)->fg), subtree->fg);
    } else {
        insertSubtree(&((*node)->fg), subtree); 
    }

    if (!(*node)->fd) {
        copie(&((*node)->fd), subtree->fd);
    } else {
        insertSubtree(&((*node)->fd), subtree); 
    }
}


void expansion(Arbre *A, Arbre B) {
    if (*A == NULL) {
        return ;
    }
        if ((*A)->fg != NULL) {
            expansion(&((*A)->fg), B);
        }
        if ((*A)->fd != NULL) {
            expansion(&((*A)->fd), B);
        } 
    if (strcmp((*A)->val, B->val) == 0) {
        Arbre G = NULL;
        copie(&G, B); 
        insertSubtree(&G,(*A));
        copie(&(*A),G);
        librer(&G);
        return ;
    }
    return ;
}
