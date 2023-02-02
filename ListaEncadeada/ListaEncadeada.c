#include "stdio.h"
#include "stdlib.h"
#include "ListaEncadeada.h"

typedef struct TipoNo{
    void* info;
    struct TipoNo* prox;
}TipoNo;

struct ListaE{
    TipoNo* prim;
    comparaListaEncadeada funcaoDeComparar;
};

ListaE* criarListaEncadeada(comparaListaEncadeada funcao){
    ListaE* novaLista = malloc(sizeof(ListaE));
    novaLista->prim = NULL;
    novaLista->funcaoDeComparar = funcao;
    return novaLista;
}


void inserirListaEncadeada(ListaE* lista, void* infoNova){
    TipoNo* novo = malloc(sizeof(TipoNo));
    novo->info = infoNova;
    novo->prox = lista->prim;
    lista->prim = novo;
}

void inserirLE_por_conteudo(ListaE *lista, void* conteudo){
    TipoNo* novo = malloc(sizeof(TipoNo));
    TipoNo* aux = lista->prim;
    TipoNo* tmp;
    novo->info = conteudo;
    if(lista->prim == NULL){
        lista->prim=novo;
        novo->prox = NULL;
        return ;
    }
    if((aux!= NULL)&&(lista->funcaoDeComparar(aux->info, conteudo)>0)){
        novo->prox= aux;
        lista->prim = novo;
        return ;
    }
    while((aux)&&(lista->funcaoDeComparar(aux->info, conteudo)<0)){
        tmp = aux;
        aux = aux->prox;
    }
    tmp->prox = novo;
    novo->prox = aux;
}

void* buscarListaEncadeada(ListaE* lista, void* chave){
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

void removerListaEncadeada(ListaE* lista, void* info){
    lista->prim = removeNo(lista, lista->prim, info);

}

void* removeInicioListaEncadeada(ListaE* lista){
    if(lista->prim!= NULL){
        TipoNo* Oexcluido = lista->prim;
        void* infoDoExcluido = lista->prim->info;
        lista->prim = Oexcluido->prox;
        free(Oexcluido);
        return infoDoExcluido;
    }
    else{
        return NULL;
    }
}