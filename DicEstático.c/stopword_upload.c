#include "tipoDicionario.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

void carrega_stopword(char word[30], DE *dic){
    FILE *arq = fopen(word,"r");
    char * stop_word = malloc(sizeof(char)*50);

    if( arq == NULL ){
        printf("Erro ao abrir arquivo.");
        exit(1);
    }
    else{
        fscanf(arq,"%s",stop_word);
        while (!feof(arq))
        {
            //printf("%s",stop_word);
            inserirDE(dic,stop_word);
            printf("%s\n",stop_word);
            stop_word = malloc(sizeof(char)*50);
            fscanf(arq,"%s",stop_word);
        }
        
    }
    printf("sucesso!\n");
}

/*int main(int argc, const char *argv[]){
    DE* dic = criarDE(394);

    carrega_stopword("stopwords_br.txt",dic);
    printf("dicionario criado\n");

    ordenaDic(dic);

    char palavra[30];
    scanf("%[^\n]%*c",palavra);
    printf("%d",buscarDE(dic, palavra));
}*/
