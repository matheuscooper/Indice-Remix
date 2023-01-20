#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H

typedef struct ListaE ListaE;
typedef int (*compara)(void*, void*);


ListaE* criarLista();


void inserirLista(ListaE* lista, void* infoNova);

void* buscarLista(ListaE* lista, void* info);

void removerLista(ListaE* lista, void* info);

#endif