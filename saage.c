
#include "saage.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "arbres_binaires.h"

typedef struct noeud{
    char *val;
    struct noeud *fg,*fd;
}Noeud,*Arbre;

int serialise_aux(FILE *f, Arbre A, int depth) {
    for (int i = 0; i < depth; ++i) {
        fprintf(f, "    ");
    }
    if (A == NULL) {
        fprintf(f, "Valeur : NULL\n");
        return 1;
    }
    fprintf(f, "Valeur : %s\n", A->val);

    for (int i = 0; i < depth; ++i) {
        fprintf(f, "    ");
    }
    if (A->fg) {
        fprintf(f, "Gauche : \n");
        if (!serialise_aux(f, A->fg, depth + 1)) return 0;
    } else {
        fprintf(f, "Gauche : NULL\n");
    }
    for (int i = 0; i < depth; ++i) {
        fprintf(f, "    ");
    }
    if (A->fd) {
        fprintf(f, "Droite : \n");
        if (!serialise_aux(f, A->fd, depth + 1)) return 0;
    } else {
        fprintf(f, "Droite : NULL\n");
    }

    return 1;
}


int serialise(char *nom_de_fichier, Arbre A) {
    FILE *f = fopen(nom_de_fichier, "w");  
    if (f == NULL) {
        return 0; 
    }
    if (!serialise_aux(f, A, 0)) { 
        fclose(f);  
        remove(nom_de_fichier); 
        return 0; 
    }
    fclose(f);  
    return 1;  
}


int deserialise_aux(FILE* f, Arbre* a) {
    char line[1024];
    fgets(line, sizeof(line), f);
    char *prefix = "Valeur : ";
    char *ss,*val;
    ss = strstr(line,prefix);
    ss += strlen(prefix);
    val = my_strdup(ss);

    char *tmp = val;
    while (*tmp != '\0'){
        if (*tmp == '\n'){
            *tmp = '\0';
            break;
        }
        tmp++;
    }
    *a = alloue_noeud(val);
    free(val);
    if (!*a) return 0;
    if (!fgets(line, sizeof(line), f)) return 0; 
    if (strstr(line, "Gauche : NULL")) {
        (*a)->fg = NULL;
    } else if (strstr(line, "Gauche :")) {
        if (!deserialise_aux(f, &(*a)->fg)) return 0;
    }
    fgets(line, sizeof(line), f);
    if (strstr(line, "Droite : NULL")) {
        (*a)->fd = NULL;
    } else if (strstr(line, "Droite :")) {
        if (!deserialise_aux(f, &(*a)->fd)) return 0;
    }

    return 1;
}



int deserialise(char* nom_de_fichier, Arbre* a) {
    FILE* f = fopen(nom_de_fichier, "r");
    if (!f){
        return 0;
    }
    int result = deserialise_aux(f, a); 
    fclose(f);
    return result;
}
