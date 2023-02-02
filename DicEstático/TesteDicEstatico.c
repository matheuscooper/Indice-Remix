#include "tipoDicionario.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "assert.h"

int comparaDics(void* palavra1, void* palavra2){
    char* palavra11 = palavra1;
    char* palavra22 = palavra2;

    return strcmp(palavra11,palavra22);
}



int main(){
    DE* NossoDic = criarDEstatico(392, &comparaDics);
    FILE* nomeArquivo = fopen("stopsMundo.txt", "r");
    assert(nomeArquivo!=NULL);
    char* palavraStop = malloc(sizeof(char)*150);
    while(fscanf(nomeArquivo, "%s", palavraStop)==1){
        inserirDEstatico(NossoDic, palavraStop);
        palavraStop = malloc(sizeof(char)*46);
    }
    
    fseek(nomeArquivo, 0, SEEK_SET);
    
    char* palavraLendo = malloc(sizeof(char)*150);
    char* retorno;
    while(fscanf(nomeArquivo, "%s", palavraLendo)==1){
        retorno = buscarDEstatico(NossoDic, palavraLendo);
        printf("%s\n", palavraLendo);
        assert(retorno!= NULL);
    }
}