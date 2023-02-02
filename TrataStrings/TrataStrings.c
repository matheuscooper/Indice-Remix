#include "stdio.h"
#include "stdlib.h"

void LimpaString(char* string){
    char * palavra = malloc(sizeof(char*));
    int i,j = 0;
    while ( string[i]!=0){
       if (!(string[i] > 33 && string[i] < 43)){
        palavra[j] = string[i];
        j++;
       } 
       i++;
    }
     palavra[j]= 0;
     strcpy(string,palavra); 
     free(palavra);
}

void LowerString(char* string){
    int i = 0;
    while ( string[i]!=0){
       if (!(string[i] > 65 && string[i] < 90)){
        string[i]= string[i] + 32; 
       } 
       i++;
}
}

double idefDF(long int ocorrencias, long int totalPalavras, int n_documentos, int total_documentos){
    return 0;
}
