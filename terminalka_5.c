#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
    int n;
    printf("Введите количество уравнений:");
    scanf("%d",&n);
    double** A = (double**)malloc(n*sizeof(float*));
    printf("Введите расширенную матрицу системы:\n");
    for(int i = 0; i<n; i++){
        A[i] = (double*)malloc((n+1)*sizeof(double));
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n+1; j++){
            scanf("%lf",&A[i][j]);
        }
    }
    int i = 0;
    int j = 0;
    int znak = 0;
    while(i<n){
        while(j<n){
            //max в столбце
            double max = 0.0;
            int r = 0;
            for(int q = j; q<n; q++){
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
            for(int q = j+1; q<n; q++){
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
    double* B = (double*)malloc(n*sizeof(double));
    for(int q = n-1; q>=0; q--){
        double sum = A[q][n];
        for(int j = q+1; j<n; j++){
            sum -= A[q][j]*B[j];
        }
        if(A[q][q]){
            B[q] = sum/(double)A[q][q];
        }else{
            printf("Система либо не имеет решений, либо имеет бесконечно много решений\n");
            return 0;
        }
    }
    for(int i = 0; i<n; i++){
        printf("x%d = %.3lf\n",i+1,B[i]);
    }
}
