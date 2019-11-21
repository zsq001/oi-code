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
int cnt,head[N],n,ct,a[N],T,du[N],flag,x;
void add(int u,int v){
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}
string s[N];
void dfs(int x){
	for(int i=head[x];i;i=e[i].next){
		int v=e[i].v;
		swap(v,x);
		for(int j=1;j<=n;j++){
			s[++ct]+=a[j];
		}
		swap(x,v);
	}
}
bool cmp(string x,string y){
	return x<y;
}
int_ main(){
	std::ios::sync_with_stdio(false);
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>T;
	while(T--){
		memset(a,0,sizeof a);
		memset(du,0,sizeof du);
		cin>>n;
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
			a[x]=i;
		}
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			add(u,v);
			add(v,u);
			du[u]++,du[v]++;
			if(du[u]==n-1) flag=1,x=u;
			if(du[v]==n-1) flag=1,x=v;
		}
		if(flag==1){
			for(int i=1;i<=n;i++){
				if(i==x) continue;
				if(a[i]>a[x] and x>i) swap(a[x],a[i]);
				if(a[i]<a[x] and x<i) swap(a[x],a[i]);
			}
		}
		for(int i=1;i<=n;i++){
			cout<<a[i]<<" ";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
