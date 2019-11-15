#include<stdio.h>

int main()
{
    float a[12]={0},sum=0,ave=0;
    for(int i=1;i<=12;i++)
    {
        scanf("%f",&a[i]);
        sum=a[i]+sum;
    }
    ave=sum/12;
    
    printf("$%.2f",ave);
    return 0;
}
