#include <stdio.h>
int main(){
    double a1,b1,c1;
    double a2,b2,c2;
    double a3,b3,c3;
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
    } else {
        printf("\nВекторы некомпланарны\n");
    }
    // проверка коллинераности
    double ax = a1/(float)a2, ay = a2/(float)a3, az = a1/(float)a3;
    double bx = b1/(float)b2, by = b2/(float)b3, bz = b1/(float)b3;
    double cx = c1/(float)c2, cy = c2/(float)c3, cz = c1/(float)c3;
    if (ax == bx && bx == cx && ay == by && by == cy && az == bz && bz == cz){
        printf("\nВсе введенные векторы коллинеарны\n");
    } else {
        if (ax == bx && bx == cx){
            printf("\nВекторы 1 и 2 коллинеарны\n");
        }
        if (ay == by && by == cy){
            printf("\nВекторы 2 и 3 коллинеарны\n");
        }
        if (az == bz && bz == cz){
            printf("\nВекторы 1 и 3 коллинеарны\n");
        }
    }
}
