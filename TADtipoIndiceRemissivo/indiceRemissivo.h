#ifndef TIPOINDICEREMISSIVO_H
#define TIPOINDISSEREMISSIVO_H

typedef struct tipoIndiceRemissivo tipoIndiceRemissivo;
typedef struct InfoDic;

tipoIndiceRemissivo * criarIndice(char*nomeArquivo, void*stopMundo);

int buscarIndice(tipoIndiceRemissivo* nomeIndice, char* palavraDoArquivo);



#endif