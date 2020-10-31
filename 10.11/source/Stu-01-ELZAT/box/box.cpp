#include<cstdio>
#include<cmath>
long long cal(int a,int b,int c)
{
	return (long long)2*a*b+2*b*c+2*a*c;
}

int main()
{
	freopen("box.in","r",stdin);
	freopen("box.out","w",stdout);
	int v;
	scanf("%d",&v);
	int vv = sqrt(v);
//	printf("%d",vv);
	bool flag = 0;
	int ans;
	for(int i = 1;i <= vv;i ++)
	{
		long long tmp = (long long)i * i * i;
		if(tmp == v)
		{
			flag = 1;
			ans = i;
			break;
		}
		if(tmp > v) break;
	}
	if(flag) printf("%lld",cal(ans,ans,ans));
	else printf("%lld",cal(1,1,v));
	return 0;
}
