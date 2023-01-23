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
    int tam;
};

TDicDinamic* criarDicDinamic(int tam){
    int x;
    TDicDinamic* novoDic = malloc(sizeof(TDicDinamic));
    novoDic->listas = malloc(sizeof(ListaE*)*tam);
    for(x=0; x<tam; x++){
        novoDic->listas[x] = criarLista();
    }
    return novoDic;
}

int funcaoHash(char*chave, int tam){
    char* palavra = chave;                                 
    unsigned int cons = 0xf;
    unsigned int acumulador = 0;
    unsigned int i = 0;
    while(palavra[i]){ 
        acumulador += palavra[i] * cons; 
        i++;
        }
    return acumulador%tam;
}

void inserirDicDinamico (TDicDinamic* x, char* chave, void* info){
    int posicao = funcaoHash(chave,x->tam); 
    conjunto* novo = malloc(sizeof(conjunto));                 /// Definimos um conjunto que une chave e info para inserir na lista encadenada
    novo->chave = chave;
    novo->info = info;
    inserirLista(x->listas[posicao], novo); 
}

void* buscarDicDinamico(TDicDinamic* x, char* chave){
    int posicaoBuscada = funcaoHash(chave,x->tam);           /// Usamos a funçao hash para buscar a chave 
    return buscarLista(x->listas[posicaoBuscada], chave);   /// buscamos a chave na lista encadeada 
    
}

void removerDicDinamico(TDicDinamic* x, char* chave){
    int posicaoBuscada = funcaoHash(chave,x->tam); 
    removerLista(x->listas[posicaoBuscada], chave);  
    return ;
} 