#include "stdio.h"
#include "stdlib.h"
#include "Dic.Dinamico.h"
#include "../ListaEncadeada/ListaEncadeada.h"
#include <string.h>
#include <math.h>

typedef struct conjunto{
    char* chave;
    void* info;
}conjunto;

struct TDicDinamic{
    ListaE** listas;
    int tam;
    int numBuscasDinamic;
    int fatorCarga;
    int passouFatorCarga;
    int tamMaiorLista;
    int contReHashs;
};

int comparaConjuntos(void* coisa1, void* coisa2){
    conjunto* coisa11 = coisa1;
    conjunto* coisa22 = coisa2;
    return strcmp(coisa11->chave, coisa22->chave);
}

TDicDinamic* criarDicDinamic(int tam){
    int x;
    TDicDinamic* novoDic = malloc(sizeof(TDicDinamic));
    novoDic->tam = tam;
    novoDic->listas = malloc(sizeof(ListaE*)*tam);
    novoDic->numBuscasDinamic=0;
    novoDic->fatorCarga = 12;
    novoDic->passouFatorCarga = 0;
    novoDic->tamMaiorLista = 0;
    novoDic->contReHashs = 0;



    for(x=0; x<tam; x++){
        novoDic->listas[x] = criarListaEncadeada(&comparaConjuntos);
    }
    return novoDic;
}

/* unsigned int _funcaoHash(void*chave, int tam){  //precisamos introduzir fator de carga
    unsigned char* palavra = chave;                                 
    unsigned int cons = 0xd;                    /// generalizar os parâmetros para agradar a César
    unsigned int acumulador = 0;
    unsigned int i = 0;
    while(palavra[i]){ 
        acumulador += palavra[i] * cons; 
        i++;
        }
        
    return acumulador%tam;
}  */
unsigned int _funcaoHash(void*chave, int tam){ 
    
    unsigned long long int hashVal = 0;
    unsigned char* key = chave; 
	while (*key) {

		hashVal = (hashVal << 4) + *(key++);

		long g = hashVal & 0xF0000000L;

		if (g != 0) hashVal ^= g >> 24;

		hashVal &= ~g;

	}

	return hashVal%tam;

}

static unsigned int primo_proximo(int num){
  short encontrou = 0;
  while(!encontrou){
    int i=2;
    while( (i<num) && ( (num%i) != 0) ){
      i++;
    }
    if (i==num){
      encontrou=1;
    }else{
      num+=1;
    }
  }
  return num;
}


int calculaC(TDicDinamic* dictionary){

    int i; 
    int quantListas=0;
    int n=0;
    int x;

    for(i = 0; i<dictionary->tam; i++){
        x = retornaTamLE(dictionary->listas[i]);
        quantListas += (x*x);
        n += retornaTamLE(dictionary->listas[i]);
    }
    
    double c = (double)quantListas/(double)n - dictionary->fatorCarga;
    if(c>1.0){
        return 1;
    }
    else{
        return 0;
    }
}

void rehash(TDicDinamic* x){
    TDicDinamic* novoDic = criarDicDinamic(primo_proximo((x->tam) + 7));
    novoDic->numBuscasDinamic = x->numBuscasDinamic;
    novoDic->fatorCarga = x->fatorCarga;
    novoDic->passouFatorCarga = x->passouFatorCarga;
    novoDic->tamMaiorLista = x->tamMaiorLista;
    novoDic->contReHashs = x->contReHashs;
    int i;
    unsigned int posicao;
    for(i=0; i<x->tam; i++){
        conjunto* removido;
        removido = removeInicioListaEncadeada(x->listas[i]);
        while(removido!=NULL){
            posicao =_funcaoHash(removido->chave,novoDic->tam); 
            inserirListaEncadeada(novoDic->listas[posicao], removido); 
            removido = removeInicioListaEncadeada(x->listas[i]);
        }
        destroiLista(x->listas[i]);
    }
    *x = *novoDic;
}


void inserirDicDinamico (TDicDinamic* x, void* chave, void* info){      /// generalizar os parâmetros para agradar a César
    unsigned int posicao =_funcaoHash(chave,x->tam); 
    
    conjunto* novo = malloc(sizeof(conjunto));                  /// Definimos um conjunto que une chave e info para inserir na lista encadenada
    novo->chave = chave;
    novo->info = info;
    
    inserirListaEncadeada(x->listas[posicao], novo); 
    if(calculaC(x) == 1){
        x->contReHashs+= 1;
        rehash(x);
    }
}

void* buscarDicDinamico(TDicDinamic* x, void* chave){           /// generalizar os parâmetros para agradar a César
    
    int posicaoBuscada =_funcaoHash(chave,x->tam);           /// Usamos a funçao hash para buscar a chave 
    
    conjunto* conjuntoBuscado = buscarListaEncadeada(x->listas[posicaoBuscada], &(conjunto){.chave=chave});   /// buscamos a chave na lista encadeada 
    x->numBuscasDinamic +=1;

    if (conjuntoBuscado!=NULL){
        return conjuntoBuscado->info;
    }
    else{
        return NULL;
    }
}

void removerDicDinamico(TDicDinamic* x, void* chave){           /// generalizar os parâmetros para agradar a César
    int posicaoBuscada =_funcaoHash(chave,x->tam); 
    removerListaEncadeada(x->listas[posicaoBuscada], chave);  
    return ;
}
int retornaComparacoesTotaisDinamic(TDicDinamic*x){
    int i;
    int compTotais = 0;
    for(i=0; i<x->tam; i++){
        compTotais+= retornaComparacoesLE(x->listas[i]);
    }
    return compTotais;
}

int retornaNumBuscasDinamic(TDicDinamic* x){
    int num = x->numBuscasDinamic;
    return num;
}
int retornaPassouCarga(TDicDinamic* x){
    int i;
    int j = x->fatorCarga;
    for(i = 0; i<x->tam; i++){
        if(retornaTamLE(x->listas[i]) > j){
            x->passouFatorCarga+=1;
        } 
    }
    return x->passouFatorCarga; 
}

int retornaMaior(TDicDinamic*x){
    int i; 
    for(i = 0; i<x->tam; i++){
        if(retornaTamLE(x->listas[i]) > x->tamMaiorLista){
            x->tamMaiorLista= retornaTamLE(x->listas[i]);
        } 
    }
    return x->tamMaiorLista;
}

/// colocar as funcoes abaixo no indice remissivo e depois na funcao main 

int retornaTamVetor(TDicDinamic*x){
    int tamvet = x->tam;
    return tamvet;
}

int retornaQuantiChaves(TDicDinamic*x){                                     //// Aqui percorremos nas posiçoes e somamos a quantidade de chaves nas listas encadeadas
    int i;
    int somatoria=0;
    for(i=0; i<x->tam; i++){
        somatoria += retornaTamLE(x->listas[i]);
    }
    return somatoria;
}

int retornaPosiOcupadas(TDicDinamic*x){                                   /// Percorremos as posiçoes e somamos caso estiverem ocupadas 
    int i;
    int somatoria=0;
    for(i=0; i<x->tam; i++){
        if(retornaTamLE(x->listas[i]) >=1 ){
            somatoria += retornaTamLE(x->listas[i]);
        }
    }
    return somatoria;
}

double mediasPorListas(TDicDinamic* x){                                 
    int i;
    int posiocupadas = retornaPosiOcupadas(x);
    int quantiChaves = retornaQuantiChaves(x);
    return posiocupadas/(double) quantiChaves;
}

int retornaContReHash(TDicDinamic *x){
    int quantiReHash = x->contReHashs;
    return quantiReHash;
}
