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
    int comparacoes;
    int tam;
};

ListaE* criarListaEncadeada(comparaListaEncadeada funcao){
    ListaE* novaLista = malloc(sizeof(ListaE));
    novaLista->prim = NULL;
    novaLista->tam = 0;
    novaLista->funcaoDeComparar = funcao;
    novaLista->comparacoes = 0;
    return novaLista;
}


void inserirListaEncadeada(ListaE* lista, void* infoNova){
    TipoNo* novo = malloc(sizeof(TipoNo));
    novo->info = infoNova;
    novo->prox = lista->prim;
    lista->prim = novo;
    lista->tam+= 1;
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
    lista->tam+=1;
}

void* buscarListaEncadeada(ListaE* lista, void* chave){
    TipoNo* x = lista->prim;
    
    while(x != NULL){
        
        if(lista->funcaoDeComparar(x->info,chave)==0){
            lista->comparacoes +=1;
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
        lista->comparacoes +=1;
        lista->tam-=1;
        aux = no->prox;
        free(no);
        return aux;
    }
    else{
        no->prox = removeNo(lista, no->prox, info);
        lista->comparacoes +=1;
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
        lista->tam-=1;
        free(Oexcluido);
        return infoDoExcluido;
    }
    else{
        return NULL;
    }
}
int retornaComparacoesLE(ListaE* lista){
    int x = lista->comparacoes;
    return x;
}
int retornaTamLE(ListaE*lista){                                
    int y = lista->tam;
    return y; 

}
void destroiLista(ListaE* lista){
    free(lista);
}

