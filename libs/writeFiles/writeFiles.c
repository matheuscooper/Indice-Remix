#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "../TADtipoIndiceRemissivo/indiceRemissivo.h"
#include "../TADSTopMundo/stop.h"

char * getName(char * fileName){

    char * newName = malloc(sizeof(char)*50);
    strcpy(newName,"showingResults/");
    int indexNewName = 15;
    int lenFileName = strlen(fileName);

    int i_start = 0;
    int j_end = lenFileName;
    // int j_end = lenFileName-1;
    // while ((j_end > i_start) && fileName[j_end] != 46) j_end--;
    while ((j_end > i_start) && fileName[i_start] != 47) i_start++;
    
    i_start++;
    int i;
    for(i=i_start; i < j_end; i++){
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

tipoIndiceRemissivo* writeInFiles(char* nomeStopsWords, char * NomeLivro){

    // gcc ./libs/*/*.c main.c -lm -o job.n && ./job.n stopwords/stopwords_br.txt bases-dicionario/Guarani.base 
    // ./job.n stopwords/stopwords_br.txt bases-dicionario/Guarani.base 

    tipoStop * stWord = criarStop(nomeStopsWords);

    tipoIndiceRemissivo * indiceRemissivo = criarIndice(NomeLivro,stWord);

    char * name = getName(NomeLivro);

    FILE * fp = fopen(name,"w");

    int comparations = returnIndexComparation(indiceRemissivo);
    int searchs = returnIndexBusca(indiceRemissivo);

    fprintf(fp, "showing results: \n \n");
    fprintf(fp,"comparations:%d  \n \n", returnIndexComparation(indiceRemissivo));
    fprintf(fp,"searchs :%d  \n \n", returnIndexBusca(indiceRemissivo));


    double media = comparations/(double) searchs;
    fprintf(fp,"a media = comparation/searchs %lf \n \n", media);


    int k = passouFatorCargaIndex(indiceRemissivo); 

    fprintf(fp,"number of carga ultrapassadass: %d\n \n", k); 

    int b =passouTamMaior(indiceRemissivo);
    fprintf(fp, "number of size list: %d \n", b);

    int c = tamVetDiclivro(indiceRemissivo);
    fprintf(fp,"number of size vet: %d \n", c); 

    int d = quantiChavesDicLivro(indiceRemissivo);
    fprintf(fp,"number of quantity key : %d \n", d); 

    int e = posiOcupadasDicLivro(indiceRemissivo);
    fprintf(fp,"number of posicoesOcupadasDicLivro: %d \n", e);

    double f = mediasPorListaDicLivro(indiceRemissivo);
    fprintf(fp,"number of medias of list: %lf \n", f);

    int g = ContReHashDicLivro(indiceRemissivo);
    fprintf(fp,"number of ReHashing: %d \n \n", g); 



    mostraIndiceRemissivoARQUIVO(indiceRemissivo, fp);

    fclose(fp);
    
    return indiceRemissivo;
}
