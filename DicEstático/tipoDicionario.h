#ifndef TIPODIC_H
#define TIPODIC_H
typedef int (*comparaDEstatico)(void*, void*);
typedef struct tipoDicionario DE;

DE* criarDEstatico(int tam, comparaDEstatico funcaoCompara);
void inserirDEstatico(DE* x, void* y);
void* buscarDEstatico(DE* x, void* palavra);
void ordenaDEstatico(DE* dic);


#endif