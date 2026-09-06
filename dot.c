#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "saage.h"


typedef struct noeud{
    char *val;
    struct noeud *fg,*fd;
}Noeud,*Arbre;



void ecrireDebut(FILE *f){
    fprintf(f, "digraph arbre {\n   node [ shape = record , height = .1 ]\n edge [ tailclip = false , arrowtail = dot , dir = both ];\n");
}

void ecrireArbre(FILE *f, Arbre a) {
    if (!a) {
        return;
    }
    
    fprintf(f, "  n%p [ label = \" < gauche > |  < valeur > %s |  < droit > \" ];\n", (void *)a, a->val);

    if (a->fg) {
        fprintf(f, "  n%p:gauche:c -> n%p:valeur;\n", (void *)a, (void *)a->fg);
        ecrireArbre(f, a->fg);
    }

    if (a->fd) {
        fprintf(f, "  n%p:droit:c -> n%p:valeur;\n", (void *)a, (void *)a->fd);
        ecrireArbre(f, a->fd);
    }
}

void ecrireFin(FILE *f){
    fprintf(f,"}\n");
}

void dessine(FILE *f, Arbre a){
    ecrireDebut(f);
    ecrireArbre(f,a);
    ecrireFin(f);
}

void creePDF(char *dot, char *pdf, Arbre a) {
    FILE *out = fopen(dot, "w");
    if (out == NULL) {
        perror("Erreur lors de l'ouverture du fichier DOT");
        return;
    }
    dessine(out, a);
    fclose(out);

    int len = strlen(dot) + strlen(pdf) + 15; 
    char cmd[len];
    snprintf(cmd, len, "dot -Tpdf %s -o %s", dot, pdf);
    system(cmd);
}

