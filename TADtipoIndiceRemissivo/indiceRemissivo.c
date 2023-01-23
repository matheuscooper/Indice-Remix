#include "stdio.h"
#include "stdlib.h"
#include "../ListaEncadeada/ListaEncadeada.h"

typedef struct pagOcorre{
    int pagina;
    int ocorrencias;
}pagOcorre;

typedef struct InfoDic{
    ListaE listaDePags;
    int ocorrenciasTotal;
    int paginasTotal;
}InfoDic;

InfoDic* criarInfoDic(char* chave){

}