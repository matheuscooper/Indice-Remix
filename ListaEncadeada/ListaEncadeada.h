#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H

typedef struct ListaE ListaE;
typedef int (*comparaListaEncadeada)(void*, void*);


ListaE* criarListaEncadeada();


void inserirListaEncadeada(ListaE* lista, void* infoNova);

void* buscarListaEncadeada(ListaE* lista, void* info);

void removerListaEncadeada(ListaE* lista, void* info);

#endif