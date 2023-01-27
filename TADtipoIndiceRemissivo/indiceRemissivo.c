#include "stdio.h"#include "stdlib.h"
#include "indiceRemissivo.h"
typedef struct pagOcorre{    int pagina;
    int ocorrencias;}pagOcorre;
struct InfoDic{
    pagOcorre* vetDeOcorrencias;    int ocorrenciasTotal;
    int paginasTotal;};

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