#include"stdio.h"



typedef struct no TNo;
    struct no{
        void* info; 
        TNo* sae;
        TNo* sad;
        TNo* pai;
    };

TNo* criarNO(TNo*pai, void*c){
    TNo* p = malloc(sizeof(TNo));
    p->info = c;
    p->sae = NULL;
    p->sad = NULL;
    p->pai = pai;
    return p;
}

struct abb{
  // callbacks
  // TImprimirABB impressora;
  TCompararABB comparar;
  // TDestroyABB destroy;

  TNo* raiz;
  int tamanho;
//  int altura;
};