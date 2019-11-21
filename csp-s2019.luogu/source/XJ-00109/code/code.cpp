#include<stdio.h>
#include<algorithm>
#define maxn (65)
#define maxm (10000010)
using namespace std;

long long int a[maxn],k;
int s[maxm];
int n;

void work(int bit,long long int x,bool op)
{
	if(bit==0)return;
	if(!op)x=a[bit]-x+1;
	if(x<=a[bit-1])s[n-bit]=0;
	else if(x>a[bit-1])s[n-bit]=1;
	if(x<a[bit-1])
		work(bit-1,x,true);
	else work(bit-1,x-a[bit-1],false);
}

int main ( )
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d %I64d",&n,&k);
	a[0]=1;
	for(int i=1;i<=n;i++)
        a[i]=a[i-1]*2;
    work(n,k+1,true);//1为正 0为反 
    for(int i=0;i<n;i++)
        printf("%d",s[i]);
    printf("\n");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//今天也 只做了一道题 
//明天是我最后一次了 祝好运 
