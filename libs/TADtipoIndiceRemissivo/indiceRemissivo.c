#include "stdio.h"
#include "stdlib.h"
#include <string.h>
#include "indiceRemissivo.h"
#include "../DicDinamico/Dic.Dinamico.h"
#include "../TrataStrings/TrataStrings.h"
#include "../TADSTopMundo/stop.h"
#include "../ListaEncadeada/ListaEncadeada.h"


typedef struct pagOcorre{    
    int pagina;
    int ocorrencias;
}pagOcorre;

struct InfoDic{
    pagOcorre* vetDeOcorrencias;
    int tamVetOcorrencias;    
    int ocorrenciasTotal;
    int paginasTotal;
};


InfoDic* criarInfoDic(){    
    InfoDic* tipox = malloc(sizeof(InfoDic));
    tipox -> vetDeOcorrencias = malloc(sizeof(pagOcorre) * 2);
    tipox -> tamVetOcorrencias = 2;    
    tipox -> ocorrenciasTotal = 1;
    tipox -> paginasTotal = 1;    
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
///FALTA criar a funcao INSERE ORDENADAMENT
pagOcorre* criarPagOcorre(int ocorrenciasXX, int paginaXX){    
    pagOcorre* x = malloc(sizeof(pagOcorre));
    x-> pagina = paginaXX;   
    x-> ocorrencias = ocorrenciasXX;
    return x;
}


typedef struct docs{
    int págDoc;
    int Palavras_in_Doc;
}docs;

struct tipoIndiceRemissivo{
    TDicDinamic* Dicionario_do_livro;
    ListaE * listWithWords;
    
};

int _cmpValues(void * a, void * b){

    char * aa = a;
    char * bb = b;

    return strcmp(aa,bb);
}


tipoIndiceRemissivo * criarIndice(char*nomeArquivo, void*stopMundo){

    tipoStop * stop = stopMundo;

    tipoIndiceRemissivo* IndiceRe_atual = malloc(sizeof(tipoIndiceRemissivo));
    
    IndiceRe_atual->Dicionario_do_livro = criarDicDinamic(100);
    IndiceRe_atual->listWithWords = criarListaEncadeada(&_cmpValues);

    FILE* Arquivo_atual = fopen(nomeArquivo, "r");
    char* palavraLida = malloc(sizeof(char)*46); 
    int NumPágina_atual=-1;
    int OcorrenciasNa_página=0; 
    docs* registraDocs = malloc(sizeof(docs)*2);
    int tamRegistraDocs = 2;

    while(fscanf(Arquivo_atual, "%s", palavraLida)==1){

        if(strcmp(palavraLida, "PA")==0){
            NumPágina_atual+= 1;
            if(NumPágina_atual>=tamRegistraDocs){
                tamRegistraDocs *= 2;
                registraDocs = realloc(registraDocs,sizeof(docs)*tamRegistraDocs);
            }
            registraDocs[NumPágina_atual].págDoc = NumPágina_atual;
            registraDocs[NumPágina_atual].Palavras_in_Doc = 0;
        }

        else if(verificaStop(stopMundo, palavraLida)==0){
            
            InfoDic* endPalavra = buscarDicDinamico(IndiceRe_atual->Dicionario_do_livro, palavraLida);
            
            if(endPalavra==NULL){
                printf("entrei aqui");
                InfoDic* infoPalavra = criarInfoDic();
                inserirLE_por_conteudo(IndiceRe_atual->listWithWords,palavraLida);
                infoPalavra->vetDeOcorrencias[0].ocorrencias = 1;
                infoPalavra->vetDeOcorrencias[0].pagina = NumPágina_atual;
                
                inserirDicDinamico(IndiceRe_atual->Dicionario_do_livro, palavraLida, infoPalavra);
                palavraLida = malloc(sizeof(char)*46);
            }
            else{
                endPalavra->ocorrenciasTotal ++;
                pagOcorre* VInfo = endPalavra->vetDeOcorrencias;
                if((VInfo[(endPalavra->paginasTotal)-1].pagina)!= NumPágina_atual){
                    // Se o Número de página atual não está no vetor, temos q adicionar ele.
                    if(endPalavra->tamVetOcorrencias <= endPalavra->paginasTotal){
                        endPalavra->tamVetOcorrencias *= 2;
                        VInfo= realloc(endPalavra->vetDeOcorrencias, sizeof(pagOcorre)*endPalavra->tamVetOcorrencias);
                    }
                    VInfo[endPalavra->paginasTotal].pagina= NumPágina_atual;
                    VInfo[endPalavra->paginasTotal].ocorrencias = 1;
                    endPalavra->paginasTotal++;

                }
                else{
                    VInfo[(endPalavra->paginasTotal)-1].ocorrencias ++;
                }
            }
            registraDocs[NumPágina_atual].Palavras_in_Doc+= 1;

        }

    }
    fclose(Arquivo_atual);

    return IndiceRe_atual;
}

void* searchElement(tipoIndiceRemissivo * index, char * key){

    InfoDic * retorno = buscarDicDinamico(index->Dicionario_do_livro, key);
    int i;
    for( i=0; (i<retorno->ocorrenciasTotal)&&(i<5); i++){
        printf("{ %d, %d  }\n", retorno->vetDeOcorrencias[i].ocorrencias, retorno->vetDeOcorrencias[i].pagina);
    }
    printf(" ocorrenciaaaaas totallllll %d", retorno->ocorrenciasTotal);
    
}
