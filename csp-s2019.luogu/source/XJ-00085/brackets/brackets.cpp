#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<stack>
#include<queue>
typedef int int_;
#define int long long 
#define oo 1000000007
#define N 800100
#define M 5010
#define P 510
using namespace std ;
struct edge{
	int u,v,next;
}e[N];
char s[N];
int n,numz[N],numy[N],ans[N],Ans,a[N];
int cnt,head[N],dep[N];
void add(int u,int v){
	e[++cnt].v=v;
	e[cnt].u=u;
	e[cnt].next=head[u];
	head[u]=cnt;
}
void dfs2(int x,int fa){
	for(int i=head[x];i;i=e[i].next){
		int v=e[i].v;
		if(fa==v) continue;
		if(s[v]=='(') numz[v]=numz[x]+1,numy[v]=numy[x],ans[v]=ans[x];
		if(s[v]==')') numz[v]=numz[x],numy[v]=numy[x]+1;
		dfs2(v,x);
	}
}
void dfs3(int x,int fa){
	for(int i=head[x];i;i=e[i].next){
		int v=e[i].v;
		if(fa==v) continue;
		if(s[v]==')'){
			ans[v]=ans[x]+numz[i];
		}
		dfs3(v,x);
	}
}
int_ main(){
	std::ios::sync_with_stdio(false);
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	cin>>n;
	cin>>(s+1);
	for(int i=2;i<=n;i++){
		cin>>a[i];
		add(a[i],i);
	}
	dfs2(1,0);
	dfs3(1,0);
	for(int i=1;i<=n;i++){
		Ans=Ans^(ans[i]*i);
	}
	cout<<Ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
