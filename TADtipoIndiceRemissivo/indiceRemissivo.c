#include "stdio.h"
#include "stdlib.h"
#include "indiceRemissivo.h"
#include "../DicDinamico/Dic.Dinamico.h"
#include "../TrataStrings/TrataStrings.h"




typedef struct pagOcorre{    
    int pagina;
    int ocorrencias;
}pagOcorre;

struct InfoDic{
    pagOcorre* vetDeOcorrencias;    
    int ocorrenciasTotal;
    int paginasTotal;
};


InfoDic* criarInfoDic(){    
    InfoDic* tipox = malloc(sizeof(InfoDic));
    tipox -> vetDeOcorrencias = malloc(sizeof(pagOcorre) * 2);    
    tipox -> ocorrenciasTotal = 0;
    tipox -> paginasTotal = 0;    
    return tipox;
}

void mostrarVetorOcorrencias(InfoDic* blocoDeInfo){
   int x = 0;
   pagOcorre* aux = blocoDeInfo->vetDeOcorrencias;  
    while(x<5){
       printf("página: %d", aux[x].pagina);       
       printf("página: %d", aux[x].ocorrencias);
   }    
   printf("ocorrencias totais = %d", blocoDeInfo-> ocorrenciasTotal);
   printf("paginas totais: %d", blocoDeInfo->paginasTotal);  
   return;                                                               
   }
///criar a funcao INSERE ORDENADAMENTE
pagOcorre* criarPagOcorre(int ocorrenciasXX, int paginaXX){    
    pagOcorre* x = malloc(sizeof(pagOcorre));
    x-> pagina = paginaXX;   
    x-> ocorrencias = ocorrenciasXX;
    return x;}


struct tipoIndiceRemissivo{
    TDicDinamic* Dicionario_do_livro;
    
};

tipoIndiceRemissivo * criarIndice(char*nomeArquivo, void*stopMundo){
    tipoIndiceRemissivo* IndiceRe_atual = malloc(sizeof(tipoIndiceRemissivo));
    IndiceRe_atual->Dicionario_do_livro = criarDicDinamic(100);
    FILE* Arquivo_atual = fopen(nomeArquivo, "r");
    char* palavraLida = malloc(sizeof(char)*46); 
    int página;
    while(fscanf(Arquivo_atual, "%s", palavraLida)==1){
        ////LowerString(palavraLida);
        printf("%s \n", palavraLida);
        if(strcmp(palavraLida, "PA")==0){
        }
        else if(verificaStop(stopMundo, palavraLida)==0){
            inserirDicDinamico(IndiceRe_atual->Dicionario_do_livro, palavraLida, palavraLida);
        }

    }
    fclose(Arquivo_atual);
}

int main(){
    char x[20];
    scanf("%s", x);
    criarIndice(x, NULL);
}