#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "./libs/TADtipoIndiceRemissivo/indiceRemissivo.h"
#include "./libs/TADSTopMundo/stop.h"
#include "./libs/writeFiles/writeFiles.h"


// Cesar teste assim:  gcc ./libs/*/*.c main.c -lm -o job.n && ./job.n

int main(int argc, char** argv){
    tipoIndiceRemissivo* index = writeInFiles("stopwords/stopwords_br.txt", "bases-dicionario/Guarani.base");
    tipoIndiceRemissivo* index2 = writeInFiles("stopwords/stopwords_br.txt", "bases-dicionario/Paralelismo.base");
    tipoIndiceRemissivo* index3 = writeInFiles("stopwords/stopwords_br.txt", "bases-dicionario/Aventuras.base");
    // Para buscar uma palavra:
    char* palavra = malloc(sizeof(char)*46);
    while(scanf("%s", palavra)==1){
        searchElement(index, palavra);
        searchElement(index2, palavra);
        searchElement(index3, palavra);
    }

}
