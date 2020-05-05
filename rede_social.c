#include <stdio.h>
#include <stdlib.h>

int** criaMatriz(int n){


  int** matriz = (int**)malloc(sizeof(int*)*n);

  for(int i=0; i<n; i++){
    matriz[i] = (int*)malloc(sizeof(int)*n);
  }

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      matriz[i][j] = 0;
    }
  }

  return matriz;
}

void mostraMatriz(int** matriz, int n){

  for(int i =0; i<n; i++){
    for(int j=0; j<n; j++){
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }
}

void amizade(int** matriz, int a, int b, int n){

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(i == a && j == b){
        matriz[i][j] = 1;
      }
      else if(i == b && j == a){
        matriz[i][j] = 1;
      }
    }
  }
}

float geraRand(){
  float scale = rand() / (float) RAND_MAX;
    return scale;
}

  void popularRedeSocialAleatoriamente (float p, int ** matriz, int n){
    float r = 0;
    for(int i=0; i<n; i++){
      for(int j=i+1; j<n; j++){
        r = geraRand();
        //printf("%f\n", r);
        if(r < p){
          amizade(matriz, i, j, n);
        }
      }
    }
  }

  int numAmigosEmComum (int** matriz, int n, int a, int b){
    int cont=0;
    printf("Id amigos em comum: ");
    for(int i=0; i<n; i++){
      if(matriz[a][i] == 1 && matriz[b][i] == 1){
        cont++;
        printf("%d ", i);
      }
    }
    printf("\n");
    return cont;
  }

  float coeficienteAglomeracao (int ** matriz, int n, int a){
    int amigos = 0;
    int cont = 0;
    for(int i=0; i<n; i++){
      if(matriz[a][i] == 1){
         amigos++;
         cont+= numAmigosEmComum(matriz,n,a,i);
       }
    }
    return cont/(amigos*(amigos-1)/2);
  }

int main(){

  // Criando a matriz
  int n;
  printf("Numero de usuarios: ");
  scanf("%d", &n);
  int** matriz = criaMatriz(n);
  mostraMatriz(matriz, n);

  // Relação de amizade entre a e b
  int a, b;
  printf("Amigos: ");
  scanf("%d %d", &a, &b);
  amizade(matriz, a, b, n);
  mostraMatriz(matriz, n);

  // Numero aleatório entre 0 e 1
  float aleatorio = geraRand();
  printf("Rand: %f\n", aleatorio);

  // Popular aleatoriamente
  float p;
  printf("Valor de P: ");
  scanf("%f", &p);
  popularRedeSocialAleatoriamente (p, matriz, n);
  mostraMatriz(matriz, n);

  // Amigos em comum
  printf("Amigos: ");
  scanf("%d %d", &a, &b);
  int comum = numAmigosEmComum(matriz, n, a, b);
  printf("%d amigos em comum \n", comum);

  // Coeficiente de aglomeração
  printf("Usuario: ");
  scanf("%d", &a);
  float coeficiente = coeficienteAglomeracao(matriz, n, a);
  printf("Coeficiente de aglomeracao: %f\n", coeficiente);

  return 0;
}
