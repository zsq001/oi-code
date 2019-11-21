#include <stdio.h>
#include <math.h>
int v[65]={-1};
int  map[3]={0,0,1};
long long dg(int x,int y)
{
	if(x==1) 
	{
		return map[(int)y];
	}
	if(y<=pow(2,x-1)) v[x]=0;
	else
	{
		y=pow(2,x)-y+1;
		v[x]=1;
	}
	dg(x-1,y);
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	long long  n,k;
   
	scanf("%d %lld",&n,&k);
	int o=dg(n,k+1);
	for(int i=n;i>1;i--)
	{
		printf("%d",v[i]);
	}
	printf("%d",o);
}
