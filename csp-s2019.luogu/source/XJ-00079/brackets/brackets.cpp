#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;

int first[500010],next[500010],to[500010],tot=0;
int n,bra[500010];
int num[500010];
bool vis[500010];

void add(int x,int f)
{
	to[++tot]=x;
	next[tot]=first[f];
	first[f]=tot;
}

void DFS(int fa,bool flag,int cnt)
{
	vis[fa]=1;
	num[fa]=cnt;
	for(int i=first[fa];i;i=next[i])
	{
		int y=to[i];
		if(bra[fa]) flag=true;
//		if(flag&&bra[y]==0) num[y]++;
		if(!vis[y])
		{
			if(!bra[y]&&flag) DFS(y,flag,cnt+1);
			else DFS(y,flag,cnt);
		}
	}
	return;
}

int main()
{
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	
	scanf("%d",&n);
	getchar();
	for(int i=1;i<=n;i++)
	{
		char c;
		scanf("%c",&c);
		if(c=='(') bra[i]=1;
		else bra[i]=0;
	}
	num[1]=0;
	for(int i=1;i<n;i++)
	{
		int f;
		scanf("%d",&f);
		add(i+1,f);
	}
	if(bra[1]) DFS(1,false,0);
	else DFS(1,true,0);
	long long ans=num[1];
	for(int i=2;i<=n;i++)
		ans=ans^(i*num[i]);
	printf("%lld",ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}


