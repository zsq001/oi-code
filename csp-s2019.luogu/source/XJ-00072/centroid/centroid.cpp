#include<bits/stdc++.h>
using namespace std;
int size[2020],vis[2020],del[2020],fa[2020],ans,n,maxx;
struct node{
	int to,next,u;
}edge[200010];int cnt,first[2020],from[2020];
void add(int u,int v){
	edge[++cnt].to = v;
	edge[cnt].u = u;
	edge[cnt].next = first[u];
	first[u] = cnt;
}
void init(){
	cnt = 0;ans=0;
	memset(first,0,sizeof first);
}
int read(){
	int x = 0,fl = 1;
	char ch = getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')fl = -1;
		ch = getchar();
	}
	while(ch<='9'&&ch >= '0'){
		x = (x<<1)+(x<<3)+(ch-'0');
		ch = getchar();
	}
	return x * fl;
}

void dfs(int s){
	size[s]=1;
	for(int i = first[s];i;i = edge[i].next){
			int to = edge[i].to;
			if(del[i])continue;
			if(fa[s]==to)continue;
			fa[to]=s;
			dfs(to);
			size[s]+=size[to];		
	}
}

void spfa1(){
	
	for(int o = 1; o <= n; o++){
		memset(size,0,sizeof size);
		memset(fa,0,sizeof fa);
		dfs(o);
		bool flag = 1;
		for(int i = first[o];i;i = edge[i].next){
			if(del[i])continue;
			dfs(edge[i].to);
			if(size[edge[i].to]>(size[o]>>1)){
				flag=0;break;
			}
		}
		if(flag)ans+=o;
	}
}

int main(){
	freopen("centroid.in","r",stdin);
	freopen("centroid.out","w",stdout);
	int T = read();
	while(T--){
		init();
		n = read();
		for(int i = 1;i < n; i++){
			int x,y;
			x = read(),y = read();
			add(x,y);add(y,x);
			fa[x]=y;fa[y]=x;
		}
		for(int i = 1; i <= cnt; i+=2){
			del[i]=del[i+1]=1;
			int x = edge[i].u;
			int y = edge[i].to;
			spfa1();
//			printf("(%d,%d) %d\n",x,y,ans);
			del[i]=del[i+1]=0;
		}
		printf("%d\n",ans);
	}
	
}
