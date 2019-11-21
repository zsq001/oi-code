#include<bits/stdc++.h>
#define MAXN 100010
using namespace std;
template<class T>void read(T &x)
{
	x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48); ch=getchar();}
}
struct edge{
	int v,nxt;
}e[MAXN*5];
int tr[MAXN*5],k,head[MAXN*5],cnt;
long long ANS,tmp;
char tmp[MAXN*5];
void add_edge(int u,int v){e[++cnt].v=v;e[cnt].nxt=head[u];head[u]=cnt;}
int dfs1(int kk){
	int tmp1=0;
	for(int i=2;i<=kk;++i)
	{
		if(ttmp[i]-1==ttmp[i-1]) {
			tmp1++;
			if(la==i-2){
				for(int j=tmp1;j>=1;j--) 
				tmp1+=j;
			}
			
		}
	}
}

void add(int u,long long ans){
	long long f1=u,i=1;
	tmp=0;
	while(1){
		ttmp[i++]=tr[f1];
		if(f1==1) break;
		f1=fa[f1];
	}
	dfs1(i)
	ANS=ANS^(u*tmp);
}
void dfs(int u,int l,long long ans)
{
	if(tr[u]==1) l++;
	else if(l>0&&tr[u]==2) {
	l--;
	ans++;
	}
	add(u,ans);
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].v;
		dfs(v,l,ans);
	}
}
int main()
{
	freopen("brackets.in","r",stdin);
//	freopen("brackets.out","w",stdout);
	int n,m;
	read(n);
	scanf("%s",tmp);
	m=strlen(tmp);
	for(int i=0;i<m;++i)
	{
		if(tmp[i]=='(') tr[i+1]=1;
		else tr[i+1]=2;
	}
	for(int i=1;i<n;++i)
	{
		int x;read(x);
		add_edge(x,i+1);
		fa[i+1]=i;
	}
	dfs(1,0,0);
	printf("%lld",ANS);
}
