#include "stdio.h"
#include "stdlib.h"
#include "indiceRemissivo.h"

typedef struct pagOcorre{
    int pagina;
    int ocorrencias;
}pagOcorre;

struct InfoDic{
    pagOcorre* vetDeOcorrencias;
    int ocorrenciasTotal;
    int paginasTotal;
};
