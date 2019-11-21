#include<cstdio>
int n;
int kk,f[5000010];
int t[100];
void wrk(int x)
{
	int cnt = 0;
	while(x)
	{
		t[++cnt] = x & 1;
		x >>= 1;
	}
	for(int i = n;i;i --)
	{
		printf("%d",t[i]);
	}
}

int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d%d",&n,&kk);
	f[0] = 0;
	f[1] = 1;
	int flag = 1;
	for(int i = 2;i <= kk;i += 2)
	{
		if(flag == 1)
		{
			f[i] = f[i/2]*2 + 1;
			f[i+1] = f[i] - 1;
			flag = 0;
		}
		else
		{
			f[i] = f[i/2] * 2;
			f[i+1] = f[i] + 1;
			flag = 1;
		}
	}	
	wrk(f[kk]);
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
