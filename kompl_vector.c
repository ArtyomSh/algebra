#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
    double a1,b1,c1;
    double a2,b2,c2;
    double a3,b3,c3;
    int rang1 = 0, rang2 = 0;
    printf("Введите через пробел координаты первого вектора:");
    scanf("%lf%lf%lf",&a1,&b1,&c1);
    printf("Введите через пробел координаты второго вектора:");
    scanf("%lf%lf%lf",&a2,&b2,&c2);
    printf("Введите через пробел координаты третьего вектора:");
    scanf("%lf%lf%lf",&a3,&b3,&c3);
    // проверка компланарности
    double d = a1*b2*c3 + a3*b1*c2 + a2*b3*c1 - a3*b2*c1 - a1*b3*c2 - a2*b1*c3;
    if (d == 0){
        printf("\nВекторы компланарны\n");
        rang1 = 1;
    } else {
        printf("\nВекторы некомпланарны\n");
    }
    // проверка коллинераности
    if ((b1*c2-c1*b2) == 0 && (c1*a2-a1*c2) == 0 && (a1*b2-b1*a2) == 0){
        printf("\nВекторы 1 и 2 коллинеарны\n");
        double k = a1/(float)a2;
        if (k == 0 || a2 == 0){
            k = b1/(float)b2;
            if (k == 0 || b2 == 0){
                k = c1/(float)c2;
                if(c2 == 0){
                    k = 0;
                }
            }
        }
        if(fabs(k)<1 & k!= 0){
            k = 1/(float)k;
        }
        printf("\nКоэффициент коллинеарности равен %lf\n", k);
        rang2 += 1;
    }
    if ((b1*c3-c1*b3) == 0 && (c1*a3-a1*c3) == 0 && (a1*b3-b1*a3) == 0){
        printf("\nВекторы 1 и 3 коллинеарны\n");
        double k = a1/(float)a3;
        if (k == 0 || a3 == 0){
            k = b1/(float)b3;
            if (k == 0 || b3 == 0){
                k = c1/(float)c3;
                if (c3 == 0){
                    k = 0;
                }
            }
        }
        if(fabs(k)<1 & k !=0){
            k = 1/(float)k;
        }
        printf("\nКоэффициент коллинеарности равен %lf\n", k);
        rang2 += 1;
    }
    if ((b2*c3-c2*b3) == 0 && (c2*a3-a2*c3) == 0 && (a2*b3-b2*a3) == 0){
        printf("\nВекторы 2 и 3 коллинеарны\n");
        double k = a2/(float)a3;
        if (k == 0 || a3 == 0){
            k = b2/(float)b3;
            if (k == 0 || b3 == 0){
                k = c2/(float)c3;
                if (c3 == 0){
                    k = 0;
                }
            }
        }
        if(fabs(k)<1 & k != 0){
            k = 1/(float)k;
        }
        printf("\nКоэффициент коллинеарности равен %lf\n", k);
        rang2 += 1;
    }
    // ранг системы векторов
    if ((rang1 == 1 && rang2 == 0) || (rang1 == 1 && rang2 == 1)){
        printf("\nРанг системы векторов равен 2\n");
    }
    if (rang2 >= 2){
        printf("\nРанг системы векторов равен 1\n");
    }
    if (rang1 == 0 && rang2 == 0){
        printf("\nРанг системы векторов равен 3\n");
    }
    if (a1 == 0 && a2 == 0 && a3 == 0 && b1 == 0 && b2 == 0 && b3 == 0 && c1 == 0 && c2 == 0 && c3 == 0){
        printf("\nРанг системы векторов равен 0\n");
    }
    
}
