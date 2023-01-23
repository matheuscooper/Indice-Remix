#ifndef TIPODIC_H
#define TIPODIC_H
typedef struct tipoDicionario DE;
DE* criarDE(int tam);
void inserirDE(DE* x, void* y);
int buscarDE(DE* x, char* palavra);



#endif