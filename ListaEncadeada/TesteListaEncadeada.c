#include "stdio.h"
#include "stdlib.h"
#include "ListaEncadeada.h"
#include "assert.h"





int main(){
    ListaE* NossaLista;
    NossaLista = criarListaEncadeada(NULL);
    FILE* nomeArquivo = fopen("ParteOguarani", "r");
    assert(nomeArquivo != NULL);
    char* palavraLivro = malloc(sizeof(char)*46);
    while(fscanf(nomeArquivo, "%s", palavraLivro)==1){
        inserirListaEncadeada(NossaLista, palavraLivro);
        palavraLivro = malloc(sizeof(char)*46);
    }
    char* primeiro = removeInicioListaEncadeada(NossaLista);
    while(primeiro != NULL){
        printf("%s \n", primeiro);
        primeiro = removeInicioListaEncadeada(NossaLista);
    }
}