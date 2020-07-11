#include <stdio.h>
#include <stdlib.h>


void printMatriz(int** matriz, int n, int m){

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            printf("%d\t", *(*(matriz + i) + j));
        }
        printf("\n");
    }
    printf("\n\n");
}

void palavraCruzada(int** matriz, int n, int m){
    int cont = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){

            int celula = *(*(matriz + i) + j);

            if(i == 0 && j == 0 && celula == 0){ //PRIMEIRA LINHA PRIMEIRA COLUNA
                if(*(*(matriz + i) + j+1) == 0 || *(*(matriz + i+1) + j) == 0) *(*(matriz + i) + j) = cont++;
                continue;
            }
            if(i == 0 && j == m-1 && celula == 0){ //PRIMEIRA LINHA ÚLTIMA COLUNA
                if(*(*(matriz + i+1) + j) == 0) *(*(matriz + i) + j) = cont++;
                continue;
            }
            if(j == 0 && i == n-1 && celula == 0){ //ÚLTIMA LINHA PRIMEIRA COLUNA
                if(*(*(matriz + i+1) + j) == 0) *(*(matriz + i) + j) = cont++;
                continue;
            }
            if(j == m-1 && i == n-1 && celula == 0){ //ÚLTIMA LINHA ÚLTIMA COLUNA
                // NUNCA SERÁ O INÍCIO DE UMA PALAVRA ;)
                continue;
            }
            if(i == 0 && celula == 0){ //PRIMEIRA LINHA
                if( (*(*(matriz + i) + j+1) == 0 && *(*(matriz + i) + j-1) == -1) || (*(*(matriz + i+1) + j) == 0)) *(*(matriz + i) + j) = cont++;
                continue;
            }
            if(j == 0 && celula == 0){ //PRIMEIRA COLUNA
                if( (*(*(matriz + i) + j+1) == 0) || (*(*(matriz + i+1) + j) == 0 && *(*(matriz + i-1) + j) == -1)) *(*(matriz + i) + j) = cont++;
                continue;
            }
            if(i == n-1 && celula == 0){ //ÚLTIMA LINHA
                if(*(*(matriz + i) + j+1) == 0 && *(*(matriz + i) + j-1) == -1 ) *(*(matriz + i) + j) = cont++;
                continue;
            }
            if(j == m-1 && celula == 0){ // ÚLTIMA COLUNA
                if(*(*(matriz + i+1) + j) == 0 && *(*(matriz + i-1) + j) == -1 ) *(*(matriz + i) + j) = cont++;
                continue;
            }
            if(celula == 0){  // MEIO
                if( (*(*(matriz + i) + j+1) == 0 && *(*(matriz + i) + j-1) == -1) || (*(*(matriz + i+1) + j) == 0 && *(*(matriz + i-1) + j) == -1)) *(*(matriz + i) + j) = cont++;
                continue;            
            }
        }
    }
}



int main(){

    int n = 8;
    int m = 7;

    int** matriz;

    matriz = malloc(sizeof(int*)*n);
    
    for(int i=0; i<n; i++){
        matriz[i] = malloc(sizeof(int)*m);
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if( (double) rand() / (RAND_MAX) <= 0.5) *(*(matriz + i) + j) = 0;
            else *(*(matriz + i) + j) = -1;
        }
    }

    printf(">>>>>> MATRIZ INICIAL <<<<<<\n\n");
    printMatriz(matriz, n, m);

    palavraCruzada(matriz, n, m);

    printf("\n>>>>>> MATRIZ FINAL <<<<<<\n\n");
    printMatriz(matriz, n, m);

    return 0;
}