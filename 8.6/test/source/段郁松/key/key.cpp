#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char a[300005];
int b[100005];
int t,m,n,num;
int main()
{
	freopen("key.in","r",stdin);
	freopen("key.out","w",stdout);
	int i;
	scanf("%s",a);
	m=strlen(a);
	n=m/3;
	for(i=0;i<m;++i)
	{
		if(a[i]!=a[i+1]) b[t]++;
		if(a[i+1]!=a[i+2]) b[t]++;
		num+=b[t];
		t++;
		i+=2;
	}
	if(num+1>=2*n) 
	{
		printf("0");
		return 0;
	}
	else
	{
		printf("1\n2\n");
	}
}
