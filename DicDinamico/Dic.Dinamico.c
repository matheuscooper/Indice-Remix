#include "stdio.h"
#include "stdlib.h"
#include "Dic.Dinamico.h"
#include "../ListaEncadeada/ListaEncadeada.h"
#include <string.h>

typedef struct conjunto{
    char* chave;
    void* info;
}conjunto;

struct TDicDinamic{
    ListaE** listas;
    int tam;
};

int comparaConjuntos(void* coisa1, void* coisa2){
    conjunto* coisa11 = coisa1;
    conjunto* coisa22 = coisa2;
    return strcmp(coisa11->chave, coisa22->chave);
}

TDicDinamic* criarDicDinamic(int tam){
    int x;
    TDicDinamic* novoDic = malloc(sizeof(TDicDinamic));
    novoDic->tam = tam;
    novoDic->listas = malloc(sizeof(ListaE*)*tam);
    for(x=0; x<tam; x++){
        novoDic->listas[x] = criarListaEncadeada(&comparaConjuntos);
    }
    return novoDic;
}

unsigned int funcaoHash(void*chave, int tam){
    unsigned char* palavra = chave;                                 
    unsigned int cons = 0xd;                    /// generalizar os parâmetros para agradar a César
    unsigned int acumulador = 0;
    unsigned int i = 0;
    while(palavra[i]){ 
        acumulador += palavra[i] * cons; 
        i++;
        }
        
    return acumulador%tam;
}

void inserirDicDinamico (TDicDinamic* x, void* chave, void* info){      /// generalizar os parâmetros para agradar a César
    unsigned int posicao = funcaoHash(chave,x->tam); 
    
    conjunto* novo = malloc(sizeof(conjunto));                  /// Definimos um conjunto que une chave e info para inserir na lista encadenada
    novo->chave = chave;
    novo->info = info;
    
    inserirListaEncadeada(x->listas[posicao], novo); 
}

void* buscarDicDinamico(TDicDinamic* x, void* chave){           /// generalizar os parâmetros para agradar a César
    
    int posicaoBuscada = funcaoHash(chave,x->tam);           /// Usamos a funçao hash para buscar a chave 
    
    conjunto* conjuntoBuscado = buscarListaEncadeada(x->listas[posicaoBuscada], &(conjunto){.chave=chave});   /// buscamos a chave na lista encadeada 
    if (conjuntoBuscado!=NULL){
        return conjuntoBuscado->info;
    }
    else{
        return NULL;
    }
}

void removerDicDinamico(TDicDinamic* x, void* chave){           /// generalizar os parâmetros para agradar a César
    int posicaoBuscada = funcaoHash(chave,x->tam); 
    removerListaEncadeada(x->listas[posicaoBuscada], chave);  
    return ;
}
