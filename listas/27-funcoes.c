#include <stdio.h>
#include <stdlib.h>



int main(){

  int n,k;

  scanf("%d", &n);

  for(int i=0; i<n; i++){
    if(i==0 || i==n-1){
      for(int j=0; j<(n-1)/2; j++){
        printf(" ");
      }
      printf("*\n");
      continue;
    }
    if(i == (n-1)/2){
      printf("*");
      for(int j=0; j<(n-2); j++){
        printf(" ");
      }
      printf("*\n");
      continue;
    }
    if(i<(n-1)/2){
      for(int j=0; j < (((n-1)/2)-1) - (i-1); j++){
        printf(" ");
      }
      printf("*");
      for(int j=0; j<i+(i-1); j++){
        printf(" ");
      }
      printf("*\n");
      continue;
    }
    if(i>(n-1)/2){
      for(int j=0; j<(i-3); j++){
        printf(" ");
      }
      printf("*");
      for(int j=0; j< i-((n-1)/2);j++){
        printf(" ");
      }
      printf("*\n");
    }
  }

return 0;
}
