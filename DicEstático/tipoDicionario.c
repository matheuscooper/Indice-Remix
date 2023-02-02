#include <string.h>
#include"stdio.h"
#include "stdlib.h"
#include "tipoDicionario.h"
#include "../ListaEncadeada/ListaEncadeada.h"

struct tipoDicionario{
    ListaE** listas;
    int ocupacao;
    int tam;
    cmpDic comparatorFunction;
    
};

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

DE* criarDEstatico(int tam, cmpDic fucCmp){
    
    DE* x = malloc(sizeof(DE));

    x->listas = malloc(sizeof(ListaE*)*tam);

    x->ocupacao = 0;
    x->tam = tam;

    for(int i=0; i<tam; i++){
        x->listas[i] = criarListaEncadeada(fucCmp);
    }

    x->comparatorFunction = fucCmp;
    return x;
}

void inserirDEstatico(DE* x, void* chave){
    unsigned int posicao = funcaoHash(chave,x->tam); 
                    /// Definimos um conjunto que une chave e info para inserir na lista encadenada
    inserirListaEncadeada(x->listas[posicao], chave); 
}

void* buscarDEstatico(DE* x, void* chave){
 
    int posicaoBuscada = funcaoHash(chave,x->tam);           /// Usamos a funçao hash para buscar a chave 
    
    void* chaveBuscada = buscarListaEncadeada(x->listas[posicaoBuscada], chave);   /// buscamos a chave na lista encadeada 
    
    if (chaveBuscada!=NULL){
        return chaveBuscada;
    }
    else{
        return NULL;
    }
}