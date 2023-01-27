#include "stdio.h"
#include "stdlib.h"
#include "indiceRemissivo.h"
typedef struct pagOcorre{    
    int pagina;
    int ocorrencias;
}pagOcorre;

struct InfoDic{
    pagOcorre* vetDeOcorrencias;    
    int ocorrenciasTotal;
    int paginasTotal;
};

InfoDic* criarInfoDic(){    
    InfoDic* tipox = malloc(sizeof(InfoDic));
    tipox -> vetDeOcorrencias = malloc(sizeof(pagOcorre) * 2);    
    tipox -> ocorrenciasTotal = 0;
    tipox -> paginasTotal = 0;    
    return tipox;
}

void mostrarVetorOcorrencias(InfoDic* blocoDeInfo){
   int x = 0;
   pagOcorre* aux = blocoDeInfo->vetDeOcorrencias;  
    while(x<5){
       printf("página: %d", aux[x].pagina);       
       printf("página: %d", aux[x].ocorrencias);
   }    
   printf("ocorrencias totais = %d", blocoDeInfo-> ocorrenciasTotal);
   printf("paginas totais: %d", blocoDeInfo->paginasTotal);  
   return;                                                               
   }
///criar a funcao INSERE ORDENADAMENTE
pagOcorre* criarPagOcorre(int ocorrenciasXX, int paginaXX){    
    pagOcorre* x = malloc(sizeof(pagOcorre));
    x-> pagina = paginaXX;   
    x-> ocorrencias = ocorrenciasXX;
    return x;}


struct tipoIndiceRemissivo{
    };