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
    double** A = (double**)malloc(m*sizeof(double*));
    printf("Введите матрицу системы:\n");
    for(int i = 0; i<m; i++){
        A[i] = (double*)malloc((n)*sizeof(double));
    }
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            scanf("%lf",&A[i][j]);
        }
    }
    int i = 0;
    int j = 0;
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
            double koef;
            for(int q = j+1; q<m; q++){
                if(A[j][i] != 0){
                    koef=-(A[q][i]/(double)A[j][i]);
                    for(int l = 0; l<n; l++){
                        A[q][l] = A[q][l] + koef*A[j][l];
                    }
                }
            }
            j += 1;
            i += 1;
        }
        i += 1;
    }
    
    //удаление нулевых строк
    int count = 0;
    int count_null = 0;
    for(i = 0; i<m; i++){
        for(j = 0; j<n; j++){
            if(fabs(A[i][j]) == 0 || fabs(A[i][j])*1000000 < 10){
                count += 1;
            }
        }
        if(count == n){
            count_null += 1;
        }
        count = 0;
    }
    m -= count_null;
    
    //создание матрицы решений
    double** B = (double**)malloc(m*sizeof(double*));
    for(int i = 0; i<m; i++){
        B[i] = (double*)malloc((n+1)*sizeof(double));
    }
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n+1; j++){
            B[i][j] = 0;
        }
    }
    
    //заполнение матрицы решений
    for(int i = m-1; i>=0; i--){
        int j = 0;
        while(fabs(A[i][j]) == 0){
            j += 1;
        }
        B[i][n] = j;
        for(int l = j+1; l<n; l++){
            B[i][l] = -A[i][l]/(double)A[i][j];
        }
    }
    
    //выражение связанных переменных через свободные
    int q = m-1;
    while (q>=0){
        int k = B[q][n];
        for(int l = q-1; l>=0; l--){
            for(int g = 0; g<n; g++){
                B[l][g] += B[l][k]*B[q][g];
            }
            B[l][k] = 0;
        }
        q -= 1;
    }
    
    //создание матрицы ответов
    double** C = (double**)malloc(n*sizeof(double*));
    for(int i = 0; i<n; i++){
        C[i] = (double*)malloc((n-m)*sizeof(double));
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n-m; j++){
            C[i][j] = 0;
        }
    }
    
    //заполнение свободных переменных единицами и нулями для нахождения ФСР
    int l = 0;
    int flag = 1;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(i == B[j][n]){
                flag = 0;
                break;
            }
            flag = 1;
        }
        if(flag){
            C[i][l] = 1;
            l += 1;
        }
    }
    
    //нахождение фундаментальной системы решений
    for(int j = 0; j<n-m; j++){
        for(int q = 0; q<m; q++){
            int k = B[q][n];
            double sum = 0;
            for(int i = 0; i<n; i++){
                sum += B[q][i]*C[i][j];
            }
            C[k][j] = sum;
            sum = 0;
        }
    }
    
    //вывод ответа
    printf("Фундаменатльная система решений:\n");
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n-m; j++){
            printf("x%d = ",i+1);
            printf("%.3lf\t",C[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

