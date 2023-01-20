#include "stdio.h"
#include "stdlib.h"
#include "ListaEncadeada.h"

typedef struct TipoNo{
    void* info;
    TipoNo* prox;
}TipoNo;

struct ListaE{
    TipoNo* prim;
    compara funcaoDeComparar;
};

ListaE* criarLista(compara funcao){
    ListaE* novaLista = malloc(sizeof(ListaE));
    novaLista->prim = NULL;
    novaLista->funcaoDeComparar = funcao;
    return novaLista;
}


void inserirLista(ListaE* lista, void* infoNova){
    TipoNo* novo = malloc(sizeof(TipoNo));
    novo->info = infoNova;
    novo->prox = lista->prim;
    lista->prim = novo;
}

void* buscarLista(ListaE* lista, void* chave){
    TipoNo* x = lista->prim;
    while(x != NULL){
        if(lista->funcaoDeComparar(x->info,chave)==0){
            return x->info;
        }
        x = x->prox;
    }
    return NULL;
}

void* removeNo(ListaE* lista, TipoNo* no, void* info){
    TipoNo* aux;
    if(no == NULL){
        return NULL;
    }
    if(lista->funcaoDeComparar(no->info ,info) == 0){
        aux = no->prox;
        free(no);
        return aux;
    }
    else{
        no->prox = removeNo(lista, no->prox, info);
        return no;
    }
}

void removerLista(ListaE* lista, void* info){
    lista->prim = removeNo(lista, lista->prim, info);

}
