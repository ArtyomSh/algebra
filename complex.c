#include <stdio.h>
int main(){
    double n,z;
    int inp;
    // ввод числа
    printf("Введите вещественную часть числа:");
    scanf("%lf",&n);
    printf("Введите мнимую часть числа:");
    scanf("%lf",&z);
    printf("Ваше число:\t"); printf("%lf",n); printf("+"); printf("%lf",z); printf("i");
    return 0;
}
