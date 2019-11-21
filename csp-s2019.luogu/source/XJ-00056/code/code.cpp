#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n,cnt,t[105];
long long k;
bool flag=0;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d%lld",&n,&k);
	while(k)
	{
		t[++cnt]=k%2;
		k>>=1;
	}
	for(int i=n;i;--i)
	{
		if(t[i])
		{
			if(flag) printf("0");
			else printf("1"),flag=1;
		}
		else
		{
			if(flag) printf("1");
			else printf("0");
			flag=0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
