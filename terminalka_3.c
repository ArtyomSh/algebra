#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
    
    //упорядочивание
    float max = 0.0;
    int max_ind = 0;
    for(int i = 0; i<n; i++){
        for(int j = i; j<k; j++){
            if(fabsf(A[j][i]) > max){
                max = A[j][i];
                max_ind = j;
            }
        }
        if(max == 0.0){
            break;
        }
        for(int j = 0; j<n; j++){
            float p = A[i][j];
            A[i][j] = A[max_ind][j];
            A[max_ind][j] = p;
        }
        max = 0.0;
    }
    
    // приведение к ступенчатому виду
    for(int q = 0; q<k-1; q++){
        for(int i = q; i<k-1;i++){
            float koef = -(A[i+1][q]/(float)A[q][q]);
            for(int j = q; j<n; j++){
                A[i+1][j] = A[q][j]*koef + A[i+1][j];
            }
        }
    }
    
    // высчитывание ранга
    int egnar = 0;
    for(int i = 0; i<k; i++){
        int count = 0;
        for(int j = 0; j<n; j++){
            if(fabsf(A[i][j]) == 0){
                count += 1;
            }
        }
        if(count == n){
            egnar += 1;
        }
    }
    printf("\nРанг системы векторов равен %d",(k-egnar));
    if(egnar == 0){
        printf(" и система линейно независима\n");
    }else{
        printf(" и система линейно зависима\n");
    }
}
