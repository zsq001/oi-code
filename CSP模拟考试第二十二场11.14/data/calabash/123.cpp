#include<stdio.h>
int main() {
    int n=0;
    int xxx[100]={0};
    float c=0,sum=0;
    scanf("%d",&n);
    for (int j=1;j<=n;j++) 
        scanf("%d",&xxx[j]);
    for (int i=1;i<=n;i++) 
        sum+=xxx[i];
    c=sum/n;
    printf ("%.2f",c);
    return 0;
}
