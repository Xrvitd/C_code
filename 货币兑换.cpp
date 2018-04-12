#include<stdio.h>
int main()
{
    float mei,ou,ri ,wai,zhong;

    scanf("%f %f %f\n",&mei,&ou,&ri);
    scanf("%f\n",&wai);
    scanf("%f",&zhong);
    printf("%0.2f %0.2f %0.2f\n",(wai/100*mei),(wai/100*ou),(wai/100*ri));
    printf("%0.2f %0.2f %0.2f\n",(zhong/mei*100),(zhong/ou*100),(zhong/ri*100));
}
