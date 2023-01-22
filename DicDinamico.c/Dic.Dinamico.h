#ifndef TIPODICDINAMICO_H
#define TIPODICDINAMICO_H

typedef struct TDicDinamic TDicDinamic;
void inserirDicDinamico(TDicDinamic* x, char* chave, void* info);
void* buscarDicDinamico(TDicDinamic* x, char* chave);
void removerDicDinamico(TDicDinamic* x, char* chave);
TDicDinamic* criarDicDinamic(int tam);

#endif