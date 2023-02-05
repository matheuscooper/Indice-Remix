#include <stdio.h>
#include "stop.h"


int main(int argc, char * argv[]){
   
    tipoStop * stopW =  criarStop(argv[1]);

    for(int i=0; i < 10; i++){

        char seach[46];
        scanf("%s",seach);

        if(verificaStop(stopW,seach)) printf("Eh stop word\n");
        else printf("N eh estop word\n"); 


    }


}