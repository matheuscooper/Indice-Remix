#include "stdio.h"
#include "stdlib.h"
#include "Dic.Dinamico.h"
#include "../ListaEncadeada/ListaEncadeada.h"

typedef struct conjunto{
    char* chave;
    void* info;
}conjunto;

struct TDicDinamic{
    ListaE** listas;
    cmpDicDinamic comparatorFunction;
    int tam;
};

TDicDinamic* criarDicDinamic(int tam, cmpDicDinamic comparatorFunctionDicDinamic){
    int x;
    TDicDinamic* novoDic = malloc(sizeof(TDicDinamic));
    novoDic->listas = malloc(sizeof(ListaE*)*tam);
    for(x=0; x<tam; x++){
        novoDic->listas[x] = criarListaEncadeada(novoDic->comparatorFunction);
    }
    return novoDic;
}

int funcaoHash(void*chave, int tam){
    char* palavra = chave;                                 
    unsigned int cons = 0xf;                    /// generalizar os parâmetros para agradar a César
    unsigned int acumulador = 0;
    unsigned int i = 0;
    while(palavra[i]){ 
        acumulador += palavra[i] * cons; 
        i++;
        }
    return acumulador%tam;
}

void inserirDicDinamico (TDicDinamic* x, void* chave, void* info){      /// generalizar os parâmetros para agradar a César
    int posicao = funcaoHash(chave,x->tam); 
    conjunto* novo = malloc(sizeof(conjunto));                  /// Definimos um conjunto que une chave e info para inserir na lista encadenada
    novo->chave = chave;
    novo->info = info;
    inserirListaEncadeada(x->listas[posicao], novo); 
}

void* buscarDicDinamico(TDicDinamic* x, void* chave){           /// generalizar os parâmetros para agradar a César
    int posicaoBuscada = funcaoHash(chave,x->tam);           /// Usamos a funçao hash para buscar a chave 
    return buscarListaEncadeada(x->listas[posicaoBuscada], chave);   /// buscamos a chave na lista encadeada 
    
}

void removerDicDinamico(TDicDinamic* x, void* chave){           /// generalizar os parâmetros para agradar a César
    int posicaoBuscada = funcaoHash(chave,x->tam); 
    removerListaEncadeada(x->listas[posicaoBuscada], chave);  
    return ;
}
