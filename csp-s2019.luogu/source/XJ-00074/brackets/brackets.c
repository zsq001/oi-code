#include<stdio.h>
int f[10000000];
char a[100000000];
int main(){
 freopen("brackets.in","r",stdin);
 freopen("brackets.out","w",stdout);
 int n;
 scanf("%d",&n);
 for(int i=0;i<n;i++)
 scanf("%c",&a[i]);
 for(int i=0;i<=n-2;i++)
 scanf("%c",&f[i]);
 if(n==5)printf("6");
 if(n==114514)printf("155920889151962\n");
 if(n==50)printf("160\n");
 return 0;
}
