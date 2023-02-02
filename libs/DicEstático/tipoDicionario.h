#ifndef TIPODIC_H
#define TIPODIC_H

typedef int (*cmpDic)(void*,void*);
typedef struct tipoDicionario DE;

DE* criarDEstatico(int tam, cmpDic fucCmp);
void inserirDEstatico(DE* x, void* chave);
void* buscarDEstatico(DE* x, void* chave);
void ordenaDEstatico(DE* dic);
#endif