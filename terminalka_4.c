#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
    int n;
    printf("Введите размер квадратной матрицы:");
    scanf("%d",&n);
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
                for(int q = 0; q<n; q++){
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
                for(int l = 0; l<n; l++){
                    A[q][l] = A[q][l] + koef*A[j][l];
                }
            }
            j += 1;
            i += 1;
        }
        i += 1;
    }
    double det = 1;
    if(znak%2 == 0){
        znak = 1;
    }else{
        znak = -1;
    }
    for(int i = 0; i<n; i++){
        det *= A[i][i];
    }
    if(det == 0){
        znak = 1;
    }
    printf("Определитель матрицы: %.3lf\n",det*znak);
}
