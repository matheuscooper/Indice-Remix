#ifndef TIPODICDINAMICO_H
#define TIPODICDINAMICO_H

typedef int (*cmpDicDinamic)(void*,void*);
typedef struct TDicDinamic TDicDinamic;

void inserirDicDinamico(TDicDinamic* x, void* chave, void* info);
void* buscarDicDinamico(TDicDinamic* x, void* chave);
void removerDicDinamico(TDicDinamic* x, void* chave);
TDicDinamic* criarDicDinamic(int tam, cmpDicDinamic comparatorFunctionDicDinamic);

#endif