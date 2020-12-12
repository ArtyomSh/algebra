#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
    int m;
    int n;
    printf("Введите количество уравнений:");
    scanf("%d",&m);
    printf("Введите количество переменных:");
    scanf("%d",&n);
    double** A = (double**)malloc(m*sizeof(float*));
    printf("Введите расширенную матрицу системы:\n");
    for(int i = 0; i<m; i++){
        A[i] = (double*)malloc((n+1)*sizeof(double));
    }
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n+1; j++){
            scanf("%lf",&A[i][j]);
        }
    }
    int i = 0;
    int j = 0;
    int znak = 0;
    while(i<m){
        while(j<n){
            //max в столбце
            double max = 0.0;
            int r = 0;
            for(int q = j; q<m; q++){
                if(fabs(A[q][i]) > max){
                    max = A[q][i];
                    r = q;
                }
            }
            //перестановка
            if(r){
                znak += 1;
                if(r == j){
                    znak -= 1;
                }
                for(int q = 0; q<n+1; q++){
                    double p = A[j][q];
                    A[j][q] = A[r][q];
                    A[r][q] = p;
                }
            }
            //
            if(A[j][i] == 0){
                break;
            }
            //зануление
            for(int q = j+1; q<m; q++){
                double koef=-(A[q][i]/(double)A[j][i]);
                for(int l = 0; l<n+1; l++){
                    A[q][l] = A[q][l] + koef*A[j][l];
                }
            }
            j += 1;
            i += 1;
        }
        i += 1;
    }
    
    //зануление в обратную сторону
    int f = n-1;
    int g = m-1;
    double koef;
    while(f>=0){
        while(g>=0){
            for(int q = g-1; q>=0; q--){
                if(A[g][f] != 0){
                    koef=-(A[q][f]/(double)A[g][f]);
                }else{
                    break;
                }
                for(int l = n+1; l>=0; l--){
                    A[q][l] = A[q][l] + koef*A[g][l];
                }
            }
            f -= 1;
            g -= 1;
        }
        f -= 1;
    }
    
    //удаление нулевых строк
    int count = 0;
    int count_null = 0;
    for(i = 0; i<m; i++){
        for(j = 0; j<n+1; j++){
            if(fabs(A[i][j]) == 0){
                count += 1;
            }
        }
        if(count == n+1){
            count_null += 1;
        }
        count = 0;
    }
    m -= count_null;
    
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n+1; j++){
            printf("%lf ",A[i][j]);
        }
        printf("\n");
    }
}
