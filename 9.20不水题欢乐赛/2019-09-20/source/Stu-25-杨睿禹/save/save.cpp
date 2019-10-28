#include<bits/stdc++.h>
#define MP 20
#define N 10010
using namespace std ;
struct edge{
	int v,next,val;
}e[N];
int map[MP][MP],cnt,head[N],n,ans=19260817,cost,k,x,a[MP][MP],cntt,sum;
bool vis[N],flag;
void add(int u,int v,int c){
	e[++cnt].v=v;
	e[cnt].val=c;
	e[cnt].next=head[u];
	head[u]=cnt;
}
int tot=0;
void dfs(int x){
	if(x==10000&&tot==n+1){
		ans=min(ans,cost);
		flag=1;
		return ;
	}
	for(int i=head[x];i;i=e[i].next){
		int v=e[i].v;
		int c=e[i].val;
		if(!vis[v]){
			vis[v]=1,cost+=c,tot++;
			dfs(v);
			tot--,cost-=c,vis[v]=0;
		}
	}
}
int main(){
	std::ios::sync_with_stdio(false);
	freopen("save.in","r",stdin);
	freopen("save.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>x;
		add(0,i,x);
	}
	for(int i=1;i<=n;i++){
		cin>>x;
		add(i,10000,x);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>x;
			add(i,j,x);
		}
	}
	for(int l=1;l<=n;l++){
		for(int i=1;i<=5;i++){
			for(int j=1;j<=5;j++){
				cin>>a[i][j];
				if(!a[i][j]){
					cntt++;
				}
			}
		}
		if(cntt==25) sum++;
		cntt=0;
	}
	if(sum==n){
		dfs(0);
		if(flag){
			cout<<"YES"<<endl;
			cout<<ans<<endl;
			return 0;
		}
		else{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	else{
		cout<<"NO"<<endl;
		return 0;
	}
}
