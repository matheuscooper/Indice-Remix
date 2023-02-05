#include "stdio.h"
#include "stop.h"
#include <stdlib.h>
#include <string.h>
#include "../DicEstatico/tipoDicionario.h"

struct tipoStop{
    DE * dic;
};

int cmpValues(void * a, void * b){

    char * aa = a;
    char * bb = b;

    return strcmp(aa,bb);
}

tipoStop* criarStop(char*arquivoStop){

    tipoStop * stopWords = malloc(sizeof(tipoStop));

    stopWords->dic = criarDEstatico(400,&cmpValues);

    FILE * fp = fopen(arquivoStop, "r");

    char * tmp = malloc(sizeof(char)*46);

    while (fscanf(fp,"%s", tmp) == 1){
        
        inserirDEstatico(stopWords->dic, tmp);

        tmp = malloc(sizeof(char)*46);
    }

    fclose(fp);

    return stopWords;
}

int verificaStop(tipoStop* stop, char* PalavraDoLivro){
    
    if(buscarDEstatico(stop->dic, PalavraDoLivro)) return 1;
    else return 0;

}

int retornaComparacoesTotaisSTOP(tipoStop* stop){
    DE* x = stop->dic;
    int i;
    i = retornaComparacoesTotaisDE(x);
    return i;
}
int retornaNumBuscasSTOP(tipoStop* stop){
    DE* x = stop->dic;
    int i;
    i = retornaNumBuscasDE(x);
    return i;
}