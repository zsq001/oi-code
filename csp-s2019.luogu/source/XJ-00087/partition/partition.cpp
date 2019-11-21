#include<cstdio>
int n,typ,a[10000],s[10000],nxt[10000],ans = 0x3f3f3f3f;

bool chk(int pre)
{
	nxt[pre] = n;
	int lst = 0;
	for(int i = nxt[0];i < n;i = nxt[i])
	{
		if(s[i] - s[lst] > s[nxt[i]] - s[i]) return false;
		lst = i;
	}
	return true;
}

void dfs(int lmt,int k,int ppre,int pre,int sum)
{
	if(s[pre] - s[ppre] > s[n] - s[pre]) return;
	if(k == lmt && chk(pre))
	{
		if(sum < ans) ans = sum + (s[n] - s[pre]) * (s[n] - s[pre]);
		return ;
	}
	for(int i = pre+1;i <= n-1;i ++)
	{
		nxt[pre] = i;
		dfs(lmt,k+1,pre,i,sum + (s[i] - s[pre]) * (s[i] - s[pre]));
	}
}

int main()
{
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	scanf("%d%d",&n,&typ);
	for(int i = 1;i <= n;i ++)
	{
		scanf("%d",&a[i]);
		s[i] = s[i-1] + a[i];
	}
	for(int i = 1;i <= n-1;i ++)
	{
		dfs(i,0,0,0,0);
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
