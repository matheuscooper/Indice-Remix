
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "assert.h"
#include "TrataStrings.h"
int main(){
    unsigned char palavra[46];
    printf("escreva aqui carai \n");
    scanf("%s \n", palavra);
    accentString(palavra);
    printf("%s", palavra);

}