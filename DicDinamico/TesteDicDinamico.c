#include "stdio.h"
#include "stdlib.h"
#include "Dic.Dinamico.h"
#include "assert.h"
#include <string.h>




int main(){
    TDicDinamic* NossoDic = criarDicDinamic(100);
    assert(NossoDic!=NULL);
    
    char* palavraBuscada;

    FILE* nomeArquivo = fopen("ParteOguarani", "r");
    assert(nomeArquivo!=NULL);

    char* palavraLivro = malloc(sizeof(char)*46);

    while(fscanf(nomeArquivo, "%s", palavraLivro)==1){
        inserirDicDinamico(NossoDic, palavraLivro, palavraLivro);

        palavraBuscada = buscarDicDinamico(NossoDic, palavraLivro);
        printf("%s\n", palavraBuscada);
        palavraLivro = malloc(sizeof(char)*46);
    }
    palavraLivro = malloc(sizeof(char)*46);
    

    fseek(nomeArquivo, 0, SEEK_SET);
    
    while(fscanf(nomeArquivo, "%s", palavraLivro)==1){
        
        palavraBuscada = buscarDicDinamico(NossoDic, palavraLivro);
        printf("%s \n", palavraBuscada);
    }

}