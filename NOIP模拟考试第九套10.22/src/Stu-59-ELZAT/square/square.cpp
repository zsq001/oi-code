#include<cstdio>
int a[200010];
int suma_front[200010],sumb_front[200010],suma_back[200010],sumb_back[200010];
int main()
{
	freopen("square.in","r",stdin);
	freopen("square.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++)
	{
		scanf("%d",&a[i]);
		suma_front[i] = suma_front[i-1];
		sumb_front[i] = sumb_front[i-1];
		if(i%2) suma_front[i] += a[i];
		else sumb_front[i] += a[i];
	}
	
	for(int i = n;i >= 1;i --)
	{
		suma_back[i] = suma_back[i+1];
		sumb_back[i] = sumb_back[i+1];
		if(i%2) suma_back[i] += a[i];
		else sumb_back[i] += a[i];
	}
	
	int ans = 0;
	for(int i = 1;i <= n;i ++)
	{
		int ansa = suma_front[i-1] + sumb_back[i+1];
		int ansb = sumb_front[i-1] + suma_back[i+1];
		if(ansa == ansb) ans ++;
	}
	printf("%d",ans);
	return 0;
}
