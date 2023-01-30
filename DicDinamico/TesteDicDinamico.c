#include "stdio.h"
#include "stdlib.h"
#include "Dic.Dinamico.h"
#include "assert.h"
#include <string.h>

int funcaocompara(void* coisa1, void* coisa2){
    char* coisa11 = coisa1;
    char* coisa22 = coisa2;
    return strcmp(coisa11,coisa22);
}


int main(){
    TDicDinamic* NossoDic = criarDicDinamic(100, funcaocompara);
    assert(NossoDic!=NULL);
    FILE* nomeArquivo = fopen("ParteOguarani", "r");
    assert(nomeArquivo!=NULL);
    char* palavraLivro = malloc(sizeof(char)*46);
    while(fscanf(nomeArquivo, "%s", palavraLivro)==1){
        
        printf("P: %s\n", palavraLivro);

        inserirDicDinamico(NossoDic, palavraLivro, palavraLivro);
        palavraLivro = malloc(sizeof(char)*46);
    }
}