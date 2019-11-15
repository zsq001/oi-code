#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int read(int &x){
	char c=getchar(),last;x=0;
	while(c>'9'||c<'0')last=c,c=getchar();
	while(c<='9'&&c>='0')x=(x<<1)+(x<<3)+c-'0',c=getchar();
	if(last=='-')x=-x;
	return x;
}
int dist[210],been[210],first[2010],vis[210],cnt;
struct ed{
	int from,to,next,val;
}edge[2010];
void addedge(int a,int b,int c){
	edge[++cnt].from=a;edge[cnt].to=b;edge[cnt].val=c;
	edge[cnt].next=first[a];
	first[a]=cnt;
}
void spfa(){
	queue<int>q;
	int st=1;
	memset(dist,11,sizeof(dist));
	vis[st]=1;dist[st]=0;
	been[st]=1;
	q.push(st);
	while(!q.empty()){
		int from=q.front();
		q.pop();vis[from]=0;
		for(int i=first[from];i;i=edge[i].next){
			if(been[from]+1>been[edge[i].to]&&dist[from]+edge[i].val<dist[edge[i].to]){
				dist[edge[i].to]=dist[from]+edge[i].val;
				been[edge[i].to]=been[from]+1;
				if(!vis[edge[i].to]){
					vis[edge[i].to]=1;
					q.push(edge[i].to);	
				}	
			}
			else if(been[from]+1==been[edge[i].to]&&dist[from]+edge[i].val<dist[edge[i].to]){
				dist[edge[i].to]=dist[from]+edge[i].val;
				been[edge[i].to]=been[from]+1;
				if(!vis[edge[i].to]){
					vis[edge[i].to]=1;
					q.push(edge[i].to);	
				}	
			}
			else if(been[from]+1>been[edge[i].to]&&dist[from]+edge[i].val<=dist[edge[i].to]){
				dist[edge[i].to]=dist[from]+edge[i].val;
				been[edge[i].to]=been[from]+1;
				if(!vis[edge[i].to]){
					vis[edge[i].to]=1;
					q.push(edge[i].to);	
				}	
			}
		
			else if(been[from]+1==been[edge[i].to]&&dist[from]+edge[i].val<=dist[edge[i].to]){
				dist[edge[i].to]=dist[from]+edge[i].val;
				been[edge[i].to]=been[from]+1;
				if(!vis[edge[i].to]){
					vis[edge[i].to]=1;
					q.push(edge[i].to);	
				}	
			}
		}
	}
}
int main(){
	freopen("calabash.in","r",stdin);
	freopen("calabash.out","w",stdout);
	int n,m;
	read(n);read(m);
	for(int i=1;i<=m;i++){
		int a,b,c;
		read(a);read(b);read(c);
		addedge(a,b,c);
	}
	spfa();
	printf("%.3lf",((double)dist[n])/been[n]);
}
