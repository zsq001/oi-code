#include<cstdio>
#include<algorithm>
using namespace std;


struct node{
	int next,to,from;
}e[1000006];
int t;
int n,ans,tot,cnt=1;
int head[1000006],d[1000006];
int id[1000006],anti[1000006];

void cleaneage(){
	for(int i=0;i<=n;i++){
		head[i]=0;
		d[i]=0;
	}
	cnt=1;
}

void ade(int from,int to){
	e[++cnt].next=head[from];
	e[cnt].to=to;
	e[cnt].from=from;
	head[from]=cnt;
}

void dfs(int o,int fa){
	id[o]=++tot;
	anti[tot]=o;
	for(int i=head[o];i!=0;i=e[i].next){
		int x=e[i].to;
		if(x==fa) continue;
		dfs(x,o);
	}
}


int main()
{
	freopen("centroid.in","r",stdin);
	freopen("centroid.out","r",stdout);
	scanf("%d",&t);
	while(t--){
		ans=0;
		scanf("%d",&n);
		cleaneage();
		for(int i=1;i<n;i++){
			int tp1,tp2;
			scanf("%d %d",&tp1,&tp2);
			d[tp1]++,d[tp2]++;
			ade(tp1,tp2);
			ade(tp2,tp1);
		}
		for(int i=1;i<=n;i++){
			if(d[i]==1){
				dfs(i,0);
				break;
			}
		}
		for(int i=2;i<=2*(n-1);i+=2){
			int from=e[i].from;
			int to=e[i].to;
			if(id[from]>id[to]) swap(from,to);
			if(id[from]%2==0){
				ans+=anti[id[from]/2]+anti[id[from]/2+1];
			}
			else{
				ans+=anti[id[from]/2+1];
			}
			if((n+id[to])%2!=0){
				ans+=anti[(n+id[to])/2]+anti[(n+id[to])/2+1];
			}
			else{
				ans+=anti[(n+id[to])/2];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
1
5
2 3
3 1
1 5
5 4
*/
