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


    printf(" comparations:%d  \n", returnIndexComparation(indiceRemissivo));
    printf(" searchs :%d  \n", returnIndexBusca(indiceRemissivo));
    
    mostraIndeceRemissivo(indiceRemissivo);

    int comparations = returnIndexComparation(indiceRemissivo);
    int searchs = returnIndexBusca(indiceRemissivo);


    printf(" comparations:%d  \n", returnIndexComparation(indiceRemissivo));
    printf(" searchs :%d  \n", returnIndexBusca(indiceRemissivo));


    double media = comparations/(double) searchs;
    printf(" a media = comparation/searchs %lf \n", media);


    int k = passouFatorCargaIndex(indiceRemissivo); 

    printf("number of carga ultrapassadass: %d\n", k); 

    int b =passouTamMaior(indiceRemissivo);
    printf("number of size list: %d \n", b);

    int c = tamVetDiclivro(indiceRemissivo);
    printf("number of size vet: %d \n", c); 

    int d = quantiChavesDicLivro(indiceRemissivo);
    printf("number of quantity key : %d \n", d); 

    int e = posiOcupadasDicLivro(indiceRemissivo);
    printf("number of positions: %d \n", e);

    double f = mediasPorListaDicLivro(indiceRemissivo);
    printf("number of medias of list: %lf \n", f);

    int g = ContReHashDicLivro(indiceRemissivo);
    printf("number of hashing: %d \n", g); 

    char* palavraBuscada = malloc(sizeof(char)*46);
    scanf("entre com uma palavra: %s", palavraBuscada);
    searchElement(indiceRemissivo,palavraBuscada);
    

}