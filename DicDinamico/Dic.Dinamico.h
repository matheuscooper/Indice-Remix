#ifndef TIPODICDINAMICO_H
#define TIPODICDINAMICO_H

typedef int (*cmpDicDinamic)(void*,void*);
typedef struct TDicDinamic TDicDinamic;

TDicDinamic* criarDicDinamic(int tam);
void inserirDicDinamico(TDicDinamic* x, void* chave, void* info);
void* buscarDicDinamico(TDicDinamic* x, void* chave);
void removerDicDinamico(TDicDinamic* x, void* chave);

#endif