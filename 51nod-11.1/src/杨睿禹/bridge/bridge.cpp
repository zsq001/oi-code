#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#define N 3000
using namespace std ;

int T,n,d,head[N],cnt,dfn[N];
char s[60][60];
bool vis[N];
struct edge{
	int v,next,u;
}e[N];
struct node{
	int du,num;
}tp[N];
bool cmp(node x,node y){
	return x.du<y.du;
}
void add(int u,int v){
	e[++cnt].v=v;
	e[cnt].u=u;
	e[cnt].next=head[u];
	head[u]=cnt;
}
queue<int> q;
void bfs(int x){
	q.push(x);
	vis[x]=1;
	dfn[x]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].v;
			if(vis[v]) continue;
			dfn[v]=dfn[e[i].u]+1;
			vis[v]=1;
			q.push(v);
		}
	}
}
int main(){
	std::ios::sync_with_stdio(false);
	freopen("bridge.in","r",stdin);
	freopen("bridge.out","w",stdout);
	cin>>T;
	while(T--){
		memset(head,0,sizeof head);
		memset(vis,0,sizeof vis);
		cin>>n>>d;
		int all=n;
		for(int i=1;i<=n;i++)
			cin>>(s[i]+1);
		cnt=0;
		for(int i=1;i<=n;i++)
			tp[i].du=0,dfn[i]=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				if(s[i][j]=='Y'){
					add(i,j);
					add(j,i);
					tp[i].du++,tp[i].num=i,tp[j].du++,tp[j].num=j;
					all--;
				}
			}
		}
		if(all>1){
			cout<<"-1"<<endl;
			continue;
		}
		sort(tp+1,tp+n+1,cmp);
		cnt=0;
		bfs(tp[1].num);
		int maxx=0;
		for(int i=1;i<=n;i++){
			maxx=max(maxx,dfn[i]);
		}
		cout<<maxx*d<<endl;
	}
	return 0;
}
