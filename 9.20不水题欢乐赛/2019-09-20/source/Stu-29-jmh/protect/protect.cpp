#include<cstdio>
#include<cmath>
#include<stack>
#include<algorithm>
using namespace std;
#define inf 1000000009.0

int n,vis[10];
double x[10],y[10];
double dis[10][10];
stack<int> s;

double end[10];

void dfs(int o,double sqr){
	s.push(o);vis[o]=1;
	double r=inf;
	for(int i=1;i<=n;i++){
		if(o==i) continue;
	    r=min(r,dis[i][o]);
	}
	for(int i=1;i<=n;i++){
		if(o==i) continue;
	    dis[i][o]-=r;
	    dis[o][i]=dis[i][o];
	}
	int flag=0;
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			dfs(i,sqr+r*r);
			flag|=1;
		}
	}
	if(flag==0) end[o]=max(end[o],sqr);
	for(int i=1;i<=n;i++){
		if(o==i) continue;
		dis[i][o]+=r;
	    dis[o][i]=dis[i][o];
	}
	s.pop();vis[o]=0;
}

int main()
{
	freopen("protect.in","r",stdin);
	freopen("protect.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lf %lf",&x[i],&y[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			double a=x[i]-x[j],b=y[i]-y[j];
			dis[i][j]=sqrt(a*a+b*b);
		}
	}
	dfs(0,0);
	double maxn=0;
	for(int i=1;i<=n;i++){
		maxn=max(maxn,end[i]);
	}
	printf("%.2lf",maxn);
	return 0;
}

