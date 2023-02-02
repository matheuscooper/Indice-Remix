#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "TrataStrings.h"


void LimpaString(char* string){
    char * palavra = malloc(sizeof(char) * 46);
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

unsigned char* accentString(unsigned char* string){
    
    int tamStr = strlen(string);
    
    unsigned char * copia = malloc(sizeof(char)*tamStr);
    int indexCopia = 0 ;

    int i = 0 ;
    
    while(i < tamStr){
        
        if(string[i] == 195){

            if((string[i+1] >= 160 && string[i+1] <= 165) || (string[i+1] >= 128 && string[i+1] <= 133) ) copia[indexCopia] = 97;
            else if((string[i+1] >= 168 && string[i+1] <= 171) || (string[i+1] >= 136 && string[i+1] <= 139) ) copia[indexCopia] = 101;
            else if( (string[i+1] >= 172 && string[i+1] <= 174) || (string[i+1] >= 140 && string[i+1] <= 143)   ) copia[indexCopia] = 105;
            else if( (string[i+1] >= 178 && string[i+1] <= 180) || (string[i+1] >= 146 && string[i+1] <= 150)   ) copia[indexCopia] = 111;
            else if( (string[i+1] >= 185 && string[i+1] <= 188) || (string[i+1] >= 153 && string[i+1] <= 156)   ) copia[indexCopia] = 117;
            else if( (string[i+1] == 167 || string[i+1] == 135)    ) copia[indexCopia] = 99;

            indexCopia++;
            i = i + 2;

        }

        else{
            copia[indexCopia] = string[i];
            indexCopia++;
            i++;
        }
    }

    copia[indexCopia] = '\0';

    return copia;

}
double idefDF(long int ocorrencias, long int totalPalavras, int n_documentos, int total_documentos){
    return 0;
}
