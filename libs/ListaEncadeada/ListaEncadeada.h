#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H

typedef struct ListaE ListaE;
typedef int (*comparaListaEncadeada)(void*, void*);


ListaE* criarListaEncadeada(comparaListaEncadeada funcao);


void inserirListaEncadeada(ListaE* lista, void* infoNova);

void inserirLE_por_conteudo(ListaE *lista, void* conteudo);

void* buscarListaEncadeada(ListaE* lista, void* info);

void removerListaEncadeada(ListaE* lista, void* info);
void* removeInicioListaEncadeada(ListaE* lista);
int retornaComparacoes(ListaE* lista);
int retornaTam(ListaE*lista); 

#endif