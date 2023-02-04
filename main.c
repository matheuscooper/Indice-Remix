#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "./libs/TADtipoIndiceRemissivo/indiceRemissivo.h"
#include "./libs/TADSTopMundo/stop.h"

int main(int argc, char * argv[]){

    // gcc ./libs/*/*.c main.c -lm -o job.n
    // ./job.n arquivos/stopwords_br.txt bases-dicionario/Guarani.base 
    assert(argc == 3);

    tipoStop * stWord = criarStop(argv[1]);

    tipoIndiceRemissivo * indiceRemissivo = criarIndice(argv[2],stWord);

   
    mostraIndeceRemissivo(indiceRemissivo);

    // showIndex(indiceRemissivo);

    // analiseDataStopWord(stWord);


}