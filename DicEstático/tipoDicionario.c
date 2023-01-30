#include"stdio.h"
#include "stdlib.h"
#include "tipoDicionario.h"
#include "string.h"

struct tipoDicionario{
void** vet;
int ocupacao;
int tam;
comparaDEstatico funcaoCompara;
};

DE* criarDEstatico(int tam, comparaDEstatico funcaoCompara){
    DE* x = malloc(sizeof(DE));
    x->vet = malloc(sizeof(void*)*tam);
    x->ocupacao = 0;
    x->tam = tam;
    return x;
}

void inserirDEstatico(DE* x, void* y){
    if(x->ocupacao == x->tam){
        return;
    }
    x->vet[x->ocupacao] = y;
    x->ocupacao++;
    return ;
}

void* buscarDEstatico(DE* x, void* palavra){
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
            return palavra;
        }
    }
    return NULL;
}

int comparaDEstatico(const void * a, const void * b){
    const char **str_a = (const char **)a;
    const char **str_b = (const char **)b;
    return strcmp(*str_a,*str_b);
}

void ordenaDEstatico(DE* dic){
    qsort(dic->vet,393,sizeof(char*),comparaDEstatico);
    printf("vetor ordenado");
}