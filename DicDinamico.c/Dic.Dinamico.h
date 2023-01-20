#ifndef TIPODICDINAMICO_H
#define TIPODICDINAMICO_H

typedef struct TDicDinamic TDicDinamic;
void inserir(TDicDinamic* x, char* chave, void* info);
void* buscar(TDicDinamic* x, char* chave);
void remover(TDicDinamic* x, char* chave);
TDicDinamic* criarDicDinamic(int tam);

#endif