#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int n,m;
double u[2010],v[2010],w[2010];
bool pan[2010]={0};
double minx=1e9,po,tot=0;
int step,head;
double ans;
void dfs(){
	 head=1,po=0,step=1,tot=0;	
	 
		for(int i=1;i<=n;++i){
			if(u[i]==head&&pan[i]!=1){
			head=v[i];
			po+=w[i];
			step++;
			pan[i]=1;
		}
		if(head==n){
			pan[i]=1;
			break;
		}	 	
	}
			ans=po/step;
			ans=min(minx,ans);
	for(int i=1;i<=n;++i)
	tot+=pan[i];
}
int main(){
	freopen("calabash.in","r",stdin);
	freopen("calabash.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;++i)
	scanf("%lf %lf %lf",&u[i],&v[i],&w[i]);
	if(n==2&&m==1){
		printf("%.3lf",w[1]);
		return 0;
	}
	else
	{
		while(tot!=n){
			dfs();
		}
		printf("%.3lf",ans);
		return 0;
	}
}
