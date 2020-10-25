#include <stdio.h>
#include <stdlib.h>
int main(){
    int n;
    int k;
    printf("Введите количество координат у вектора:");
    scanf("%d",&n);
    printf("Введите количество векторов:");
    scanf("%d",&k);
    float** A = (float**)malloc(k*sizeof(float*));
    for(int i = 0; i<k; i++){
        A[i] = (float*)malloc(n*sizeof(float));
    }
    printf("Введите координаты векторов:\n");
    for(int i = 0; i<k; i++){
        for(int j = 0; j<n; j++){
            scanf("%f",&A[i][j]);
        }
    }
    // приведение к ступенчатому виду
    int m = 0;
    for(int q = 0; q<k-1; q++){
        for(int i = m; i<k-1;i++){
            float koef = -(A[i+1][m]/(float)A[m][m]);
            for(int j = m; j<n; j++){
                A[i+1][j] = A[m][j]*koef + A[i+1][j];
            }
        }
        m += 1;
    }
}
