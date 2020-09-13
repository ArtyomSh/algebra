#include <stdio.h>
#include <math.h>
#define pi    3.1415926535
int main(){
    // ввод числа
    double n,z;
    printf("Введите вещественную часть числа:");
    scanf("%lf",&n);
    printf("Введите мнимую часть числа:");
    scanf("%lf",&z);
    printf("\nВаше число:\t"); printf("%lf",n); printf("+"); printf("%lf",z); printf("i\n");
    // выбор операции
    int inp;
    printf("Возможные операции:\n 0 - вывести тригонометрическую запись числа\n 1 - вывести обратное число\n 2 - возвести в степень\n 3 - взять корень n-той степени\n");
    printf("Выберите операцию:");
    scanf("%d",&inp);
    // тригонометрическая запись
    if (inp == 0){
        printf("Тригонометрическая запись числа:\t");
        printf("%.3lf",sqrt(n*n+z*z));
        printf("(cos"); printf("%.3lf",atan(z/(float)n)*180/(float)(pi)); printf(" + i*sin"); printf("%.3lf",atan(z/(float)n)*180/(float)(pi)); printf(")\n");
        
    }
    // обратное число
    if (inp == 1){
        printf("Обратное к введенному числу число:\t");
        if (z/(float)(n*n+z*z) > 0){
            printf("%.3lf",1/(float)sqrt(n*n+z*z));
            printf("(cos"); printf("%.3lf",atan(z/(float)n)*180/(float)(pi)); printf(" - i*sin"); printf("%.3lf",atan(z/(float)n)*180/(float)(pi)); printf(")\n");;
        }else{
            printf("%.3lf",1/(float)sqrt(n*n+z*z));
            printf("(cos"); printf("%.3lf",atan(z/(float)n)*180/(float)(pi)); printf(" + i*sin"); printf("%.3lf",atan(z/(float)n)*180/(float)(pi)); printf(")\n");
        }
    }
    // возведение в степень
    if (inp == 2){
        int k;
        printf("Ввведите степень, в которую хотите возвести число:");
        scanf("%d",&k);
        printf("%.3lf",pow(sqrt(n*n+z*z),k));
        printf("(cos"); printf("%.3lf",k*atan(z/(float)n)*180/(float)(pi)); printf(" + i*sin"); printf("%.3lf",k*atan(z/(float)n)*180/(float)(pi)); printf(")\n");;
    }
    return 0;
}
