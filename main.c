#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "./libs/TADtipoIndiceRemissivo/indiceRemissivo.h"
#include "./libs/TADSTopMundo/stop.h"
#include "./libs/writeFiles/writeFiles.h"

int main(int argc, char** argv){
  
    tipoIndiceRemissivo* index = writeInFiles(argv[1], argv[2]);
    // Para buscar uma palavra:
    char* palavra = malloc(sizeof(char)*46);
    while(scanf("%s", palavra)==1){
        searchElement(index, palavra);
    }

}
