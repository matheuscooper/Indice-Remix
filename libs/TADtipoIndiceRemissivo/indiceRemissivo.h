#ifndef TIPOINDICEREMISSIVO_H
#define TIPOINDISSEREMISSIVO_H

typedef struct tipoIndiceRemissivo tipoIndiceRemissivo;

tipoIndiceRemissivo * criarIndice(char*nomeArquivo, void*stopMundo);

int mostrarIndice(tipoIndiceRemissivo* nomeIndice);


typedef struct InfoDic InfoDic;
InfoDic* criarInfoDic();
void* searchElement(tipoIndiceRemissivo * index, char * key);
void mostraIndiceRemissivo(tipoIndiceRemissivo* index);
void* searchElementARQUIVO(tipoIndiceRemissivo * index, char * key, FILE* nomeArquivo);
void mostraIndiceRemissivoARQUIVO(tipoIndiceRemissivo* index, FILE* nomearquivo);

//retorna dados
int returnIndexComparation(tipoIndiceRemissivo* index);
int returnIndexBusca(tipoIndiceRemissivo* index);
int passouFatorCargaIndex(tipoIndiceRemissivo* index);
int passouTamMaior(tipoIndiceRemissivo*index); 
int tamVetDiclivro(tipoIndiceRemissivo* index);
int quantiChavesDicLivro(tipoIndiceRemissivo* index);
int posiOcupadasDicLivro(tipoIndiceRemissivo* index);
double mediasPorListaDicLivro(tipoIndiceRemissivo* index);
int ContReHashDicLivro(tipoIndiceRemissivo* index);

#endif