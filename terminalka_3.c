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
    int i = 0;
    int j = 0;
    while(i<n){
        while(j<k){
            //max в столбце
            float max = 0.0;
            int r = 0;
            for(int q = j; q<k; q++){
                if(fabsf(A[q][i]) > max){
                    max = A[q][i];
                    r = q;
                }
            }
            //перестановка
            if(r){
                for(int q = 0; q<n; q++){
                    float p = A[j][q];
                    A[j][q] = A[r][q];
                    A[r][q] = p;
                }
            }
            //
            if(A[j][i] == 0){
                break;
            }
            //зануление
            for(int q = j+1; q<k; q++){
                float koef=-(A[q][i]/(float)A[j][i]);
                for(int l = 0; l<n; l++){
                    A[q][l] = A[q][l] + koef*A[j][l];
                }
            }
            j += 1;
            i += 1;
        }
        i += 1;
    }
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

