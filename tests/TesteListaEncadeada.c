#include "stdio.h"
#include "stdlib.h"
#include "../libs/ListaEncadeada/ListaEncadeada.h"
#include "assert.h"
#include <string.h>

int func_compara(void* coisa1, void*coisa2){
    char* coisa11 = coisa1;
    char* coisa22 = coisa2;
    return strcmp(coisa11, coisa22);
}




int main(){
    ListaE* NossaLista;
    NossaLista = criarListaEncadeada(&func_compara);
    FILE* nomeArquivo = fopen("./bases-dicionario/Aventuras.base", "r");
    assert(nomeArquivo != NULL);
    char* palavraLivro = malloc(sizeof(char)*46);
    while(fscanf(nomeArquivo, "%s", palavraLivro)==1){
        inserirLE_por_conteudo(NossaLista, palavraLivro);
        palavraLivro = malloc(sizeof(char)*46);
    }
    char* primeiro = removeInicioListaEncadeada(NossaLista);
    while(primeiro != NULL){
        printf("%s \n", primeiro);
        primeiro = removeInicioListaEncadeada(NossaLista);
    }
}