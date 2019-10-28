#include<cstdio>
int n,mo=100000007,cnt;
bool vis[10000000];
int p[100000];
long long ans=1;

int ksm(int a,int b)
{
	int ans=1;
	while(b){
		if(b & 1)ans=ans*a;
		b=b>>1;
		a=a*a;
	}
	return ans;
}

void sai(int n) {
	for (int i = 2; i <= n; ++i) {
		if (!vis[i])
		{
			p[cnt++] = i;
		} 
		for (int j = 0; i * p[j] <= n; ++j) {
				vis[i * p[j]] = 1;
				if (i % p[j] == 0) break;
			}
	}
}

int main()
{
	int i,j;
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d",&n);
	sai(n);
	cnt--;
	long long maxx;
	for(i=0;i<=cnt;i++)
	{
		for(j=1;j<=n;j++)
		{
			maxx=ksm(p[i],j);
			if(maxx > n){
				break;
			}
			ans*=p[i];
			ans=((ans%mo)+mo)%mo;
		}
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
