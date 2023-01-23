#ifndef TIPOINDICEREMISSIVO_H
#define TIPOINDISSEREMISSIVO_H

typedef struct tipoIndiceRemissivo tipoIndiceRemissivo;


tipoIndiceRemissivo * criarIndice(char*nomeArquivo, void*stopMundo);

int buscarIndice(tipoIndiceRemissivo*nomeIndice, char* nomeArquivo);



#endif