#include"stdio.h"
#include "stdlib.h"
#include "tipoDicionario.h"
#include "string.h"

struct tipoDicionario{
void** vet;
int ocupacao;
int tam;
};

DE* criarDE(int tam){
    DE* x = malloc(sizeof(DE));
    x->vet = malloc(sizeof(void*)*tam);
    x->ocupacao = 0;
    x->tam = tam;
    return x;
}

void inserirDE(DE* x, void* y){
    if(x->ocupacao == x->tam){
        return;
    }
    x->vet[x->ocupacao] = y;
    x->ocupacao++;
    return ;
}

int buscarDE(DE* x, void* palavra){
    int inicio = 0;
    int fim = x->ocupacao;
    int meio;
    while(inicio <= fim){
        meio = (inicio+fim)/2;
        if(strcmp(palavra,x->vet[meio])<0){
            fim = meio - 1;
        }
        else if(strcmp(palavra, x->vet[meio])>0){
            inicio = meio + 1;
        }
        else{
            return 1;
        }
    }
    return 0;
}

void ordenaDic(DE* dic){
    qsort(dic->vet[0],393,sizeof(void*),&strcmp);
}