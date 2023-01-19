#ifndef TIPODIC_H
#define TIPODIC_H
typedef struct tipoDicionario tipoDicionario;
tipoDicionario* criarvetor(int tam);
void inserir(tipoDicionario* x, char* y);
int buscar(tipoDicionario* x, char* palavra);



#endif