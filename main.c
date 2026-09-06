#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "arbres_binaires.h"
#include "greffe.h"
#include "saage.h"
#include "dot.h"

int main(int argc, char *argv[]) {
 
    if (strcmp(argv[1], "-E") == 0) {
        Arbre A = NULL;
        printf("Entrez votre arbre (format 1 \"valeur\" pour un noeud, 0 pour un noeud vide) :\n");
        if (!construit_arbre(&A)) {
            fprintf(stderr, "Erreur lors de la construction de l'arbre.\n");
            librer(&A);
            return 1;
        }

        if (!serialise(argv[2], A)) {
            fprintf(stderr, "Erreur lors de la sauvegarde de l'arbre dans %s.\n", argv[2]);
            librer(&A);
            return 1;
        }

        printf("L'arbre a été sauvegardé avec succès dans %s.\n", argv[2]);
        librer(&A);

    } else if (strcmp(argv[1], "-G") == 0) {

        Arbre S = NULL, G = NULL;
        if (!deserialise(argv[2], &S) || !deserialise(argv[3], &G)) {
            fprintf(stderr, "Erreur lors de la désérialisation des arbres.\n");
            return 1;
        }
        expansion(&S, G);
        serialise("stdout.saage", S);
        librer(&S);
        librer(&G);
    }else if (strcmp(argv[1], "-V") == 0){
        Arbre A = NULL;
        if (!deserialise(argv[2], &A)) {
            fprintf(stderr, "Erreur lors de la désérialisation de l'arbre.\n");
            return 1;
        }
        FILE *f = fopen(argv[3], "w");
        dessine(f, A);
        fclose(f);
        char visu[] = "visualise.pdf";
        creePDF(argv[3], visu, A);
        char cmd[1024];
        sleep(1);
        sprintf(cmd, "evince %s &", visu);
        system(cmd);
    }
    else {
        fprintf(stderr, "Option non reconnue: %s\n", argv[1]);
        return 1;
    }
    return 0;
}
