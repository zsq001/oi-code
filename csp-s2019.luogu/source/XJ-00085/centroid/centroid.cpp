#include<cstdio>
#include<iostream>
#include<cstring>
#include<stack>
#include<queue>
#include<algorithm>
#define oo 1000000007
#define N 500100
#define M 5010
using namespace std ;
struct edge{
	int u,v,next,lca;
	bool cut;
}e[N],q[N],E[N];
int cnt,head[N],T,n,dis[N],num,ans,vis[N];
void add(int u,int v){
	e[++cnt].v=v;
	e[cnt].u=u;
	e[cnt].next=head[u];
	head[u]=cnt;
}
int main(){
	std::ios::sync_with_stdio(false);
	freopen("centroid.in","r",stdin);
	freopen("centroid.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		if(n%2){
			for(int i=2;i<=n-1;i++){
				if(n-n/2+1==i) ans+=i*2;
				else ans+=i*3;
			}
			ans+=n*2;ans+=2;
		}
		else{
			for(int i=2;i<n;i++){
				if(n-n/2==i or i==n-n/2+1) ans+=i*2;
				else ans+=i*3;
			}
			ans+=n*2;ans+=2;
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
