#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<stdio.h>
#include<vector>
using namespace std;
int T;
int n;
vector<int>son[300000];
vector<int>fa[300000];
int weight[300000];
int uu[300000],vv[300000];
long long ans=0;

int init(int nowa){
	weight[nowa]=1;
	for(int i=0;i<son[nowa].size();i++){
		weight[nowa]+=init(son[nowa][i]);
	}
	return weight[nowa];
}

void solve(int nowa,int k,int cant,int m){
	int maxx=0,num;
	for(int i=0;i<son[nowa].size();i++){
		if(son[nowa][i]==cant)continue;
		if(weight[son[nowa][i]]>maxx){
			maxx=weight[nowa]-weight[son[nowa][i]];
			num=son[nowa][i];
		}
	}
	for(int i=0;i<fa[i].size();i++){
		if(fa[nowa][i]==cant)continue;
		if(weight[fa[nowa][i]]-weight[nowa]>maxx){
			maxx=weight[fa[nowa][i]]-weight[nowa];
			num=son[nowa][i];
		}
	}
	if(maxx>k/2){
		solve(num,k,cant,m);
	}
	else if(maxx==k/2&&k%2==0){
		ans+=num+nowa;
	}
	else{
		ans+=nowa;
	}
}

int main(){
	scanf("%d",&T);
	for(int cas=1;cas<=T;cas++){
		for(int i=1;i<=n;i++){
			son[i].clear();
			fa[i].clear();
		}
		scanf("%d",&n);
		for(int i=1;i<n;i++){
			
			scanf("%d%d",&uu[i],&vv[i]);
			if(uu[i]>vv[i])swap(uu[i],vv[i]);
			son[uu[i]].push_back(vv[i]);
			fa[vv[i]].push_back(uu[i]);
		}
		int fff=init(1);
		
		for(int i=1;i<n;i++){
			solve(vv[i],weight[vv[i]],uu[i],0);
			solve(uu[i],n-weight[vv[i]],vv[i],);
		}
		
		printf("%lld\n",ans);
	}
	return 0;
}
