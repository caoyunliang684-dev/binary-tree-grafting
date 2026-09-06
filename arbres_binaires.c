#include <string.h>
#include "arbres_binaires.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct noeud{
    char *val;
    struct noeud *fg,*fd;
}Noeud,*Arbre;

Noeud *alloue_noeud(char *s){
    Noeud *tmp = (Noeud *)malloc(sizeof(Noeud));
    if(tmp){
        tmp->val = my_strdup(s);
        tmp->fd = NULL;
        tmp->fg = NULL;
    }
    return tmp;
}
char* my_strdup(const char* s) {
    size_t len = strlen(s) + 1;
    char* copy = malloc(len);
    if (copy != NULL) {
        strcpy(copy, s);
        return copy;
    }
    return NULL;
}

void librer(Arbre *A){
    if(*A){
        librer(&(*A)->fg);
        librer(&(*A)->fd);
        free((*A)->val);
        free(*A);
        *A = NULL;
    }
}

int zero(const char* line){
    for (int i = 0; line[i];i++){
        if(line[i] != '0' && line[i] != ' ' && line[i] != '\n'){
            return 0;
        }
    }
        return 1;
}

int construit_arbre1(Arbre *a, char **input) {
    if (!**input) {
        return 1; 
    }
    while (**input) {
        if (**input == '1') {  
            (*input) += 2;  
            char* end = strchr(*input, ';');  
            if (end) {
                int length = end - *input;  
                char value[1024];  
                strncpy(value, *input, length); 
                value[length] = '\0';  
                *a = alloue_noeud(value); 
                *input = end + 1; 
                if (!*a) {
                    return 0;  
                }
                if (!construit_arbre1(&(*a)->fg, input)) {
                    return 0; 
                }
                if (!construit_arbre1(&(*a)->fd, input)) {
                    return 0;  
                }
                break;  
            }
        } else if (**input == '0') {
            *a = NULL;
            (*input)+= 2;
            break; 
        }
    }
    return 1;  
}

void cree_A_1(void){
    Arbre A = NULL;
    char *inputs[] = {
            "1 arbre",
            "1 binaires",
            "0 0 1 ternaire",
            "0 0"
    };

    for (int i = 0; i < sizeof(inputs) / sizeof(inputs[0]); i++) {
        construit_arbre1(&A, &inputs[i]);
    }
}
void cree_A_2(void){
    Arbre A = NULL;
    char *inputs[] = {
            "1 Anémone",
            "1 Camomille",
            "0 0 1 Camomille",
            "1 Dahlia",
            "0 1 Camomille",
            "1 Iris",
            "0 0 1 Jasmin",
            "0 0 0"
    };
    for (int i = 0; i < sizeof(inputs) / sizeof(inputs[0]); i++) {
        construit_arbre1(&A, &inputs[i]);
    }
}
void cree_A_3(void){
    Arbre A = NULL;
    char *inputs[] = {
            "1 Intel Core i9",
            "1 Apple M3 Max",
            "0 1 AMD Ryzen 9",
            "1 Intel Core i9",
            "0 0 0 1 Intel",
            "Core i9",
            "1 Intel Core i9 000"
    };

    for (int i = 0; i < sizeof(inputs) / sizeof(inputs[0]); i++) {
        construit_arbre1(&A, &inputs[i]);
    }
}

int construit_arbre(Arbre *a){
    char line[1024];
    char ss[1024] = {0};
    while (fgets(line,sizeof(line),stdin)){
        strcat(ss,line);
        if(zero(line)){
            break;
        }
    }
    char str[1024];
    int j = 0;
    for(int i = 0 ; ss[i] !='\0';i++){
        if(ss[i]!='\n'){
           str[j] = ss[i];
           j++; 
        }
        else {
            str[j] = ';';
            j++;
        }
    }
    str[j] = '\0';
    char *input = str;
    if(construit_arbre1(a,&input)){
        return 1;
    }
    else {
        return 0;
    }
}
