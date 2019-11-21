#include<algorithm>
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstdio>
using namespace std;
//priority_queue<>q;
int t;
bool vis[2000];
struct ege{
	int f,t,head;
}edge[2000];
int head[2000],cnt;
void add(int x,int y){
	edge[cnt].t=x;
	edge[cnt].f=y;
	edge[cnt].head=head[y];
	head[y]=cnt;
	cnt++;
}
int zxl,zxr,ls,rs;
int siz(int x){
	int sz=1;vis[x]=1;
	for(int i=head[x];i;i=edge[i].head){
		if(edge[i].t==0||vis[edge[i].t]==1)continue;
		sz+=siz(edge[i].t);
	}
	vis[x]=0;
	return sz;
}
int ans=0,dt=0,minx=1151513154;
int dfs(int x,int f){
	int size=0;vis[x]=1;
	for(int i=head[x];i;i=edge[i].head){
		if(edge[i].t==0||vis[edge[i].t]==1)continue;
		int sl=dfs(edge[i].t,f),rl=(f==0?ls:rs)-sl;
		size+=sl;
		if(max(sl,rl)<minx){
			minx=max(sl,rl);
			dt=edge[i].f;
		}
		else if((max(sl,rl)==minx))dt+=edge[i].f;
	}
	vis[x]=0;
	if(max(size,(f==0?ls:rs)-size)<minx){
		minx=max(size,(f==0?ls:rs)-size);
		dt=edge[x].f;
	}
	else if((max(size,(f==0?ls:rs)-size)==minx))dt+=edge[x].f;
	return size+1;
}
int m;
int main(){
	freopen("centroid.in","r",stdin);
	freopen("centroid.out","w",stdout);
	int a=0;
	cin>>t;
	while(t--){
		cin>>m;
		for(int i=1;i<m;i++){
			int x,y;
			cin>>x>>y;
			add(x,y);
			add(y,x);
		}
		for(int i=0;i<cnt;i+=2){
			int xx=edge[i].f,yx=edge[i].t,headt=edge[i].head;
			
			edge[i].t=edge[i].f=edge[i+1].f=edge[i+1].t=0;
			zxl=zxr=0;
			minx=541324651;
			dt=xx;
			ls=siz(xx);rs=siz(yx);
			dfs(xx,0);ans+=dt;
			minx=541324651;dt=yx;
			dfs(yx,1);ans+=dt;
			edge[i+1].t=edge[i].f=xx;
			edge[i+1].f=edge[i].t=yx;
			edge[i].head=headt;
		}
		cout<<ans;
	}
	
}
