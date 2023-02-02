#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "./libs/TADtipoIndiceRemissivo/indiceRemissivo.h"
#include "./libs/TADSTopMundo/stop.h"

int main(int argc, char * argv[]){

    // assert(argc == 3);

    tipoStop * stWord = criarStop(argv[1]);

    tipoIndiceRemissivo * indiceRemissivo = criarIndice(argv[2],stWord);

    char busca[50];

    scanf("%s", busca);

    searchElement(indiceRemissivo, busca);

    // showIndex(indiceRemissivo);

    // analiseDataStopWord(stWord);


}