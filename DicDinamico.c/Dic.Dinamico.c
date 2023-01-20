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