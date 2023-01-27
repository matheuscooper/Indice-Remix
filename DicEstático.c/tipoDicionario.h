#ifndef TIPODIC_H
#define TIPODIC_H
typedef struct tipoDicionario DE;
DE* criarDEstatico(int tam);
void inserirDEstatico(DE* x, void* y);
int buscarDEstatico(DE* x, void* palavra);
void ordenaDEstatico(DE* dic);


#endif