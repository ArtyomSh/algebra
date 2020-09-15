// Таранец Данил группа 20144
#include <stdio.h>
#include <math.h>
#define pi    3.1415926535
int main(){
    // ввод числа
    printf("Здравствуйте! Эта программа позволяет проводить некоторые действия с комплексными числами. Для начала определимся с вводом числа.\n");
    double n,z;
    int q;
    printf("Если хотите ввести вещественную часть числа корнем, то нажмите 0, если нет, то нажмите 1:");
    scanf("%d",&q);
    if (q == 1){
        printf("\nВведите вещественную часть числа:");
        scanf("%lf",&n);
    } else {
        int w,e;
        printf("\nВведите через пробел число, из которого будет браться корень и степень корня:");
        scanf("%d%d",&e,&w);
        n = pow(e,1/(float)w);
    }
    int r;
    printf("\nЕсли хотите ввести мнимую часть числа корнем, то нажмите 0, если нет, то нажмите 1:");
    scanf("%d",&r);
    if (r == 1){
        printf("\nВведите мнимую часть числа:");
        scanf("%lf",&z);
    } else {
        int t,y;
        printf("\nВведите через пробел число, из которого будет браться корень и степень корня:");
        scanf("%d%d",&t,&y);
        z = pow(t,1/(float)y);
    }
    printf("\nВаше число:\t"); printf("%lf",n); printf("+"); printf("%lf",z); printf("i\n");
    // выбор операции
    int inp;
    printf("\nВозможные операции:\n 0 - вывести тригонометрическую запись числа\n 1 - вывести обратное число\n 2 - возвести в степень\n 3 - взять корень n-той степени\n");
    printf("Выберите операцию:");
    scanf("%d",&inp);
    // вычисление аргумента
    double argument = 0.0;
    if (n>0){
        argument = atan(z/(float)n);}
    if (n<0 && z<0){
        argument = atan(z/(float)n) - pi;}
    if (n<0 && z>0){
        argument = atan(z/(float)n) + pi;}
    // тригонометрическая запись
    if (inp == 0){
        printf("Тригонометрическая запись числа:\t");
        printf("%.3lf",sqrt(n*n+z*z));
        printf("(cos"); printf("%.3lf",argument); printf(" + i*sin"); printf("%.3lf",argument); printf(")\n");
        
    }
    // обратное число
    if (inp == 1){
        printf("Обратное к введенному числу число:\t");
        if (z/(float)(n*n+z*z) > 0){
            printf("%.3lf",1/(float)sqrt(n*n+z*z));
            printf("(cos"); printf("%.3lf",argument); printf(" - i*sin"); printf("%.3lf",argument); printf(")\n");;
        }else{
            printf("%.3lf",1/(float)sqrt(n*n+z*z));
            printf("(cos"); printf("%.3lf",argument); printf(" + i*sin"); printf("%.3lf",argument); printf(")\n");
        }
    }
    // возведение в степень
    if (inp == 2){
        int k;
        printf("Ввведите степень, в которую хотите возвести число:");
        scanf("%d",&k);
        printf("%.3lf",pow(sqrt(n*n+z*z),k));
        printf("(cos"); printf("%.3lf",k*argument); printf(" + i*sin"); printf("%.3lf",k*argument); printf(")\n");
    }
    // все корни степени n
    if (inp == 3){
        int l;
        printf("Ввведите значение степени корня, который вы хотите извлечь из числа:");
        scanf("%d",&l);
        printf("%.3lf",pow(sqrt(n*n+z*z),1/(float)l));
        printf("(cos("); printf("%.3lf",argument/(float)l); printf("+2πk/"); printf("%d",l); printf(") + i*sin("); printf("%.3lf",argument/(float)l); printf("+2πk/"); printf("%d",l); printf(")\n");
        printf("где k - любое целое число\n");
    }
    return 0;
}
