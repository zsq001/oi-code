#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
#define inf 1000000009
#define eps 1e-7

struct node{
	int next,to;
	double val;
}e[2005];
int n,m,cnt=1;
int vis[205];
double dis[205];
int head[205],val[2005];
queue<int> q; 

void ade(int from,int to){
	e[++cnt].next=head[from];
	e[cnt].to=to;
	head[from]=cnt;
}


void init_(double now){
	for(int i=2;i<=cnt;i++){
		e[i].val=1.0*val[i]-now;
	}
}


void cls(){
	for(int i=1;i<=n;i++){
		vis[i]=0;
		dis[i]=1.0*inf;
	}
	dis[1]=0;
}

void spfa(){
	cls();
	q.push(1);
	while(!q.empty()){
		int o=q.front();q.pop();
		vis[o]=0;
		for(int i=head[o];i!=0;i=e[i].next){
			int x=e[i].to;
			if(dis[x]>dis[o]+e[i].val){
				dis[x]=dis[o]+e[i].val;
				if(vis[x]==0){
					vis[x]=1;
					q.push(x);
				}
			}
		}
	}
}


bool check(double now){
	init_(now);
	spfa();
	if(dis[n]<=now) return true;
	else return false;
}


int main()
{
	freopen("calabash.in","r",stdin);
	freopen("calabash.out","w",stdout);
	double ansl=0,ansr=0;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		int tp1,tp2;
		scanf("%d %d %d",&tp1,&tp2,&val[i+1]);
		ansr=max(ansr,1.0*val[i+1]);
		ade(tp1,tp2);
		
	}
	while(ansr-ansl > eps){
		double mid=(ansr+ansl)/2.0;
		if(check(mid)) ansr=mid;
		else ansl=mid;
	}
	printf("%lf",ansl);	
	return 0;
}
