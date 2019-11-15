#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<stack>
#define N 500100
#define M 5010
#define oo 1000000007
using namespace std ;
int n,a[N],op[N];
double ans,k,c,w;
void dfs(double now,int pos,double mon){
	if(pos==n){
		ans=max(ans,mon);
		return ;
	}
	if(now==0.0) return ;
	if(mon<0.0) return ;
	for(int i=pos+1;i<=n;i++){
		if(op[i]==1)
			dfs(now-now*0.01*k,i,mon+a[i]*now);
		if(op[i]==2)
			dfs(now+now*0.01*c,i,mon-a[i]*now);
		dfs(now,i,mon);
	}
}
int main(){
	std::ios::sync_with_stdio(false);
	freopen("coal.in","r",stdin);
	freopen("coal.out","w",stdout);
	cin>>n>>k>>c>>w;
	if(k==100){
		int maxx=0;
		for(int i=1;i<=n;i++){
			cin>>op[i]>>a[i];
			if(op[i]==1) maxx=max(maxx,a[i]);
		}
		printf("%.2lf\n",maxx*w*1.0);
		return 0;
	}
	for(int i=1;i<=n;i++)
		cin>>op[i]>>a[i];
	dfs(w,0,0);
	printf("%.2lf\n",ans);
	return 0;
}
