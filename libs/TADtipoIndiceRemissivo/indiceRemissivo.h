#ifndef TIPOINDICEREMISSIVO_H
#define TIPOINDISSEREMISSIVO_H

typedef struct tipoIndiceRemissivo tipoIndiceRemissivo;

tipoIndiceRemissivo * criarIndice(char*nomeArquivo, void*stopMundo);

int mostrarIndice(tipoIndiceRemissivo* nomeIndice);


typedef struct InfoDic InfoDic;
InfoDic* criarInfoDic();
void* searchElement(tipoIndiceRemissivo * index, char * key);
void mostraIndeceRemissivo(tipoIndiceRemissivo* index);
int returnIndexComparation(tipoIndiceRemissivo* index);
int returnIndexBusca(tipoIndiceRemissivo* index);
int passouFatorCargaIndex(tipoIndiceRemissivo* index);
int passouTamMaior(tipoIndiceRemissivo*index); 

#endif