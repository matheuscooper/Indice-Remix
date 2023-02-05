#ifndef TIPODICDINAMICO_H
#define TIPODICDINAMICO_H

typedef int (*cmpDicDinamic)(void*,void*);
typedef struct TDicDinamic TDicDinamic;

TDicDinamic* criarDicDinamic(int tam);
void inserirDicDinamico(TDicDinamic* x, void* chave, void* info);
void* buscarDicDinamico(TDicDinamic* x, void* chave);
void removerDicDinamico(TDicDinamic* x, void* chave);

// as funcoes a seguir mostram dados necessarios para fazer o relatoriooooooooooooooooooooo
int retornaComparacoesTotaisDinamic(TDicDinamic*x);
int retornaNumBuscasDinamic(TDicDinamic* x);
int retornaPassouCarga(TDicDinamic* x);
int retornaMaior(TDicDinamic*x);
int calculaC(TDicDinamic* x);
void rehash(TDicDinamic* x);
int retornaTamVetor(TDicDinamic*x);
int retornaQuantiChaves(TDicDinamic*x);
int retornaPosiOcupadas(TDicDinamic*x);
double mediasPorListas(TDicDinamic* x);
int retornaContReHash(TDicDinamic*x);


#endif