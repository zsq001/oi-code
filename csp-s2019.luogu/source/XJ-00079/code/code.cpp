#include<stdio.h>
#include<algorithm>
using namespace std;

long long n,k;
int code[70],cnt=0;

long long quick_pow(long long x,long long m)
{
	unsigned long long res=1;
	while(m)
	{
		if(m&1) res*=x;
		x*=x;
		m>>=1;
	}
	return res;
}

void dfs(long long xn,long long xk)
{
	long long jd=quick_pow(2,xn-1);
	if(xk<=jd) 
	{
		code[++cnt]=0;
	}
	else 
	{
		code[++cnt]=1;
		if(xk%jd)xk=jd-xk%jd;
		else xk=xk%jd;
		xk++;
	}
	if(cnt==n-1) 
	{
		if(xk==1) code[++cnt]=0;
		else if(xk==2) code[++cnt]=1;
		return;
	}
	dfs(xn-1,xk);
}

int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	
	scanf("%lld%lld",&n,&k);
//	printf("%lld",quick_pow(n,k));
	dfs(n,k+1);
	for(int i=1;i<=n;i++)
		printf("%d",code[i]);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}



