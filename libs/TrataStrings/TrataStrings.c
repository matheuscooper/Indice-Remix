#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "TrataStrings.h"
#include <math.h>

char isLetter(unsigned char letter){
    return !( 
        ( 0 <= letter &&  letter <=  57) 
    || ( 58 <= letter &&  letter <= 63) 
    || ( 91 <= letter &&  letter <= 96) 
    || ( 123 <= letter &&  letter <= 128)
    || ( 226 <= letter &&  letter <= 226)
    || ( 152 <= letter &&  letter <= 157)  
    || ( 8200 <= letter) 
    );
}

void removeSpecialCharacters(unsigned char * string){

    int tamStr = strlen((char *)string);
    int indexCopia = 0 ;

    int i = 0 ;
    
    while(i < tamStr){
        
        if(string[i] == 195){

            if((string[i+1] >= 160 && string[i+1] <= 165) || (string[i+1] >= 128 && string[i+1] <= 133) ) string[indexCopia] = 97;
            else if((string[i+1] >= 168 && string[i+1] <= 171) || (string[i+1] >= 136 && string[i+1] <= 139) ) string[indexCopia] = 101;
            else if( (string[i+1] >= 172 && string[i+1] <= 174) || (string[i+1] >= 140 && string[i+1] <= 143)   ) string[indexCopia] = 105;
            else if( (string[i+1] >= 178 && string[i+1] <= 181) || (string[i+1] >= 146 && string[i+1] <= 150)   ) string[indexCopia] = 111;
            else if( (string[i+1] >= 185 && string[i+1] <= 188) || (string[i+1] >= 153 && string[i+1] <= 156)   ) string[indexCopia] = 117;
            else if( (string[i+1] == 167 || string[i+1] == 135)    ) string[indexCopia] = 99;

            indexCopia++;
            i = i + 2;

        }else if(string[i] == 194) i = i + 2;

        else{
            string[indexCopia] = string[i];
            indexCopia++;
            i++;
        }
    }

    string[indexCopia] = '\0';


}

void LimpaString(unsigned  char* string){
    int tam = strlen(string);

    int ctI = 0;
    int ctJ = tam-1;

    while (!isLetter(string[ctI])){ ctI++; }
    
    while (!isLetter(string[ctJ])){ ctJ--; }

    int i; 

    for(i = ctI; i <= ctJ; i++ ){ string[i-ctI] = string[i]; }

    string[i-ctI] = 0;
}

void LowerString(char* string){
    int size = strlen(string);
    int i;
    for (i = 0; i < size; i++){
        if (string[i] >= 65 && string[i] <= 90){
            string[i] += 32;
        }else if(string[i] >= 128 && string[i] <= 159){
            string[i] += 32;
        }else if(string[i] == 226){
            i = i + 3;
        }
    }
}




double tf(int wordOccurrences, int docWord){ return wordOccurrences/(double) docWord; }

double idf(int docsWords, int docs){ 

    docsWords = docsWords > 0 ? docsWords: 1;
    double div = docs / (double) docsWords;

    return log2(div);

}

/**
 * @brief 
 * 
 * @param palavra, quantidade de ocorrecias da palavra na pagina 
 * @param doc , quantidade total de palavras da pagina
 * @param qntWords, Quantidade de documentos que a palavra aparece 
 * @param docs , Quantidade total de documentos do livro
 * @return double 
 */
double idefDF(long int ocorrencias, long int totalPalavras, int n_documentos, int total_documentos){
      // tf IDFtfidf(palavra, doc, docs) computa o TF-IDF, que ´e o produto do tf e idf.
    double TF;
    double IDF;
    TF = ocorrencias/(double) totalPalavras;
    if(n_documentos == 0){
        n_documentos = 1;
    }
    IDF = log(total_documentos/ (double) n_documentos);
    double TF_IDF;
    TF_IDF = TF * IDF;    
    return TF_IDF;
}