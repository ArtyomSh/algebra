#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
    int n;
    printf("Введите размер квадратной матрицы:");
    scanf("%d",&n);
    
    //создается матрица А
    double** A = (double**)malloc(n*sizeof(float*));
    printf("Введите матрицу:\n");
    for(int i = 0; i<n; i++){
        A[i] = (double*)malloc(n*sizeof(double));
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            scanf("%lf",&A[i][j]);
        }
    }
    
    //создается единичная матрица В
    double** B = (double**)malloc(n*sizeof(float*));
    for(int i = 0; i<n; i++){
        B[i] = (double*)malloc(n*sizeof(double));
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(i == j){
                B[i][j] = 1;
            }else{
                B[i][j] = 0;
            }
        }
    }
    
    int i = 0;
    int j = 0;
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
                for(int q = 0; q<n; q++){
                    double p = A[j][q];
                    A[j][q] = A[r][q];
                    A[r][q] = p;
                    double w = B[j][q];
                    B[j][q] = B[r][q];
                    B[r][q] = w;
                }
            }
            if(A[j][i] == 0){
                break;
            }
            //зануление в прямую сторону
            for(int q = j+1; q<n; q++){
                double koef=-(A[q][i]/(double)A[j][i]);
                for(int l = 0; l<n; l++){
                    A[q][l] = A[q][l] + koef*A[j][l];
                    B[q][l] = B[q][l] + koef*B[j][l];
                }
            }
            j += 1;
            i += 1;
        }
        i += 1;
    }
    
    //вычисление детерминанта
    double det = 1;
    for(int i = 0; i<n; i++){
        det *= A[i][i];
    }
    if(det == 0){
        printf("Введенная матрица вырожденная, обратной не существует\n");
        return 0;
    }
    
    //зануление в обратную сторону
    int f = n-1;
    int g = n-1;
    while(f>=0){
        while(g>=0){
            for(int q = g-1; q>=0; q--){
                double koef=-(A[q][f]/(double)A[g][f]);
                for(int l = n-1; l>=0; l--){
                    A[q][l] = A[q][l] + koef*A[g][l];
                    B[q][l] = B[q][l] + koef*B[g][l];
                }
            }
            f -= 1;
            g -= 1;
        }
        f -= 1;
    }
    
    //превращение диагональной матрицы A в единичную (и соответствующие изменения в B)
    for(int q = 0; q<n; q++){
        for(int l = 0; l<n; l++){
            B[q][l] /= A[q][q];
        }
        A[q][q] = 1;
    }
    
    //вывод обратной матрицы
    printf("Матрица, обратная к матрице A:\n");
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            printf("%.3lf ",B[i][j]);
        }
        printf("\n");
    }
}
