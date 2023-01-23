#include"stdio.h"
#include "stdlib.h"
#include "tipoDicionario.h"
#include "string.h"

struct tipoDicionario{
char** vet;
int ocupacao;
int tam;
};

tipoDicionario* criarvetor(int tam){
    tipoDicionario* x = malloc(sizeof(tipoDicionario));
    x->vet = malloc(sizeof(char*)*tam);
    x->ocupacao = 0;
    x->tam = tam;
    return x;
}


void inserir(tipoDicionario* x, char* y){
    if(x->ocupacao == x->tam){
        return;
    }
    strcpy(x->vet[x->ocupacao], y);
    x->ocupacao++;
    return ;
}
int buscar(tipoDicionario* x, char* palavra){
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

void ordenaDicionario(tipoDicionario*x){
    qsort(x->vet,x->ocupacao,sizeof(char*),&strcmp);

}