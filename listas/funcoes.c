#include <stdio.h>
#include <stdlib.h>



int main(){

  int n;
  int j=0;

  scanf("%d", &n);

  for(int i=1; i<=n; i++){
    for(j=1; j<=i; j++){
      printf("%d ", j);
    }
    for(int k=(j-2); k>0; k--){
      printf("%d ", k);
    }
    printf("\n");
  }

  return 0;
}
