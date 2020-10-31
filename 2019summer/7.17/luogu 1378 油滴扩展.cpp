#include<bits/stdc++.h>
#define maxn 200010
using namespace std;
typedef long long ll;
int n,vis[10],rec[10];
double ans,x7,y7,x8,y8,x[10],y[10],rad[10];
double cal(double X,double Y){return sqrt(X*X+Y*Y);}
void dfs(int k){
	if(k==(n+1)){
		for(int i=1;i<=n;++i){
			double tmp=10000.0;
			for(int j=1;j<i;++j)
				tmp=min(tmp,max(0.0,cal(x[rec[i]]-x[rec[j]],y[rec[i]]-y[rec[j]])-rad[j]));
			tmp=min(tmp,cal(x[rec[i]]-x7,0.0));
			tmp=min(tmp,cal(x[rec[i]]-x8,0.0));
			tmp=min(tmp,cal(0.0,y[rec[i]]-y7));
			tmp=min(tmp,cal(0.0,y[rec[i]]-y8));
			rad[i]=tmp;
		}
		double t=0;
		for(int i=1;i<=n;++i)
			t+=acos(-1)*rad[i]*rad[i];
		ans=max(ans,t);
		return;
	}
	for(int i=1;i<=n;++i){
		if(vis[i]) continue;
		vis[i]=1;
		rec[k]=i;
		dfs(k+1); 
		vis[i]=0;
	}
}
int main()
{
	cin>>n>>x7>>y7>>x8>>y8;
	for(int i=1;i<=n;++i) cin>>x[i]>>y[i];
    if(n) dfs(1);
    printf("%.0lf",fabs((y8-y7)*(x8-x7))-ans);
	return 0;
}
