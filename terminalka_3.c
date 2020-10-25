#include <stdio.h>
#include <stdlib.h>
int main(){
    int n;
    int k;
    printf("Введите количество координат у вектора:");
    scanf("%d",&n);
    printf("Введите количество векторов:");
    scanf("%d",&k);
    int** A = (int**)malloc(k*sizeof(int*));
    for(int i = 0; i<k; i++){
        A[i] = (int*)malloc(n*sizeof(int));
    }
    printf("Введите координаты векторов:\n");
    for(int i = 0; i<k; i++){
        for(int j = 0; j<n; j++){
            scanf("%d",&A[i][j]);
        }
    }
}
