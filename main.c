#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "./libs/TADtipoIndiceRemissivo/indiceRemissivo.h"
#include "./libs/TADSTopMundo/stop.h"

char * getName(char * fileName){

    char * newName = malloc(sizeof(char)*50);

    int indexNewName = 0;

    int lenFileName = strlen(fileName);

    int i_start = 0;
    int j_end = lenFileName;
    // int j_end = lenFileName-1;
    // while ((j_end > i_start) && fileName[j_end] != 46) j_end--;
    while ((j_end > i_start) && fileName[i_start] != 47) i_start++;
    
    i_start++;

    for(int i=i_start; i < j_end; i++){
        newName[indexNewName] = fileName[i];
        indexNewName++;
    }
    
    newName[indexNewName] = '.';
    indexNewName++;
    newName[indexNewName] = 'm';
    indexNewName++;
    newName[indexNewName] = 'd';
    indexNewName++;
    newName[indexNewName] = 0;

    return newName;
    

}

int main(int argc, char * argv[]){

    // gcc ./libs/*/*.c main.c -lm -o job.n
    // ./job.n arquivos/stopwords_br.txt bases-dicionario/Guarani.base 
    assert(argc == 3);
    
    tipoStop * stWord = criarStop(argv[1]);

    tipoIndiceRemissivo * indiceRemissivo = criarIndice(argv[2],stWord);

    char * name = getName(argv[2]);

    FILE * fp = fopen(name,"w");

    fprintf(fp," comparations:%d  \n", returnIndexComparation(indiceRemissivo));
    fprintf(fp," searchs :%d  \n", returnIndexBusca(indiceRemissivo));
    
    mostraIndeceRemissivo(indiceRemissivo);

    int comparations = returnIndexComparation(indiceRemissivo);
    int searchs = returnIndexBusca(indiceRemissivo);


    fprintf(fp," comparations:%d  \n", returnIndexComparation(indiceRemissivo));
    fprintf(fp," searchs :%d  \n", returnIndexBusca(indiceRemissivo));


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

    while (scanf("%s", palavraBuscada) == 1)
    {
        /* code */
        searchElement(indiceRemissivo,palavraBuscada);
    }
    
    fclose(fp);
    

}