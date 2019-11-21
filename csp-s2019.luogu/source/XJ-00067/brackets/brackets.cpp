#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
char a[200010];
int lxh;
int fa[200010];
long long m[200010];
bool fl[2010][2010];
int fir;
bool li=true;
int tf;
int tl;
int la;
long long ans;
void dfs(int now,int z,int hf,int ho)
{
	if(now==1)
	{
		if(a[now]==')')
			return;
		if(a[now]=='('&&tl>0)
		{
			m[z]++;
			tf++;
			tl--;
			m[z]++;
			if(tf==ho)
			{
				tf=0;
				ho=0;
				lxh++;
			}
			if(lxh>1)
			{
				m[z]+=lxh*(lxh-1)/2;
			}
		}
		return;
	}
	if(a[now]=='('&&tl>0)
	{
		tf++;
		tl--;
		m[z]++;
		if(tf==ho)
		{
			tf=0;
			ho=0;
			lxh++;
		}
		if(lxh>1)
		{
			m[z]+=lxh*(lxh-1)/2;
		}
		dfs(fa[now],z,1,ho);
	}
	if(a[now]=='('&&tl==0)
	{
		lxh=0;
		dfs(fa[now],z,0,0);
	}
	if(a[now]==')')
	{
		tl++;
		dfs(fa[now],z,1,ho+1);
	}
	return;		
}
int main()
{
	int x;
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	scanf("%d",&n);
	scanf("%s",a+1);
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&x);
		fa[i]=x;
		if(fa[i]!=i-1)
		{
			li=false;
		}
	}
	/*if(li==true)
	{
		long long l=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]=='(')
			{
				tf++;
			}
			if(a[i]==')'&&tf>0)
			{
				l++;
				tf--;
			}
			m[i]=l*i;
			ans=ans xor m[i];
		}
		printf("%lld",ans);
		return 0;
	}*/
	for(int i=1;i<=n;i++)
	{
		dfs(i,i,0,0);
		m[i]*=i;
		tf=0;
		tl=0;
		lxh=0;
		ans=ans xor m[i];
	}
	printf("%lld",ans);
	return 0;
}
