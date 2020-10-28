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
    //преобразую массив
    for(int i = 0; i<n; i++){
        for(int j = i; j<k;j++){
            if(A[j][i] != 0){
                for(int q = 0; q<j; q++){
                    float koef = -(A[q][i]/(float)A[j][i]);
                    for(int l = 0; l<n; l++){
                        A[q][l] = A[q][l] + koef*A[j][l];
                    }
                }
                for(int q = j+1; q<k; q++){
                    float koef = -(A[q][i]/(float)A[j][i]);
                    for(int l = 0; l<n; l++){
                        A[q][l] = A[q][l] + koef*A[j][l];
                    }
                }
                break;
            }
        }
        for(int i = 0; i<k; i++){
            for(int j = 0; j<n; j++){
                printf("%f ",A[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    for(int i = n-1; i>=0; i--){
        for(int j = k-1-(n-1-i); j>=0;j--){
            if(A[j][i] != 0){
                for(int q = 0; q<j; q++){
                    float koef = -(A[q][i]/(float)A[j][i]);
                    for(int l = 0; l<n; l++){
                        A[q][l] = A[q][l] + koef*A[j][l];
                    }
                }
                for(int q = j+1; q<k; q++){
                    float koef = -(A[q][i]/(float)A[j][i]);
                    for(int l = 0; l<n; l++){
                        A[q][l] = A[q][l] + koef*A[j][l];
                    }
                }
                break;
            }
        }
        for(int i = 0; i<k; i++){
            for(int j = 0; j<n; j++){
                printf("%f ",A[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    // высчитываю ранг
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

