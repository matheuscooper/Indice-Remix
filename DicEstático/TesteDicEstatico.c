#include "tipoDicionario.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "assert.h"
int main(){
    DE* NossoDic = criarDEstatico(392);
    FILE* nomeArquivo = fopen("stopsMundo.txt", "r");
    assert(nomeArquivo!=NULL);
    char* palavraStop = malloc(sizeof(char)*46);
    while(fscanf(nomeArquivo, "%s", palavraStop)==1){
        inserirDEstatico(NossoDic, palavraStop);
        palavraStop = malloc(sizeof(char)*46);
    }
    
    fseek(nomeArquivo, 0, SEEK_SET);
    
    char* palavraLendo = malloc(sizeof(char)*46);
    
    while(fscanf(nomeArquivo, "%s", palavraLendo)==1){
        palavraLendo = buscarDEstatico(NossoDic, palavraLendo);
        assert(palavraLendo!= NULL);
    }
}