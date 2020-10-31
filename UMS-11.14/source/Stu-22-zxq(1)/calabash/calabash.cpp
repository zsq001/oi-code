#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
int n,m,v[10010],first[10010];
int cnt;
struct Edge{
	int next;
	int to;
	int w;
}a[10010];
void add(int u,int v,int va){
	cnt++;
	a[cnt].to=v;
	a[cnt].w=va;
	a[cnt].next=first[u];
	first[u]=cnt;
}
struct node{
	int dist;
	int minn;
}d[10010];
queue <int> q;
void spfa(){
	d[1].dist=0;
	d[1].minn=1;
	q.push(1);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=first[x];i;i=a[i].next){
			int y=a[i].to;
			if(((double)d[y].dist/(double)d[y].minn)>
			   (double)(d[x].dist+a[i].w)/(double)(d[x].minn+1)){
			   	d[y].dist=d[x].dist+a[i].w;
			   	d[y].minn=d[x].minn+1;
			}
			if(!v[y]){
				v[y]=1;
				q.push(y);
			}
		}
	}
}
int main(){
	freopen("calabash.in","r",stdin);
	freopen("calabash.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		d[i].dist=0x7ffffff;
		d[i].minn=1;
	}
	for(int i=1;i<=m;i++){
		int u,v,va;
		scanf("%d%d%d",&u,&v,&va);
		add(u,v,va);
	}
	spfa();
	printf("%.3lf",(double)d[n].dist/(double)d[n].minn);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
