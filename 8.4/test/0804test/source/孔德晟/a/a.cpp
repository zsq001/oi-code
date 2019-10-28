#include<stdio.h>
#include<algorithm>
#define maxn 200010
using namespace std;
int cnt,n,m,line[maxn],vis[maxn],ans;
int j[maxn],jcnt;
int o[maxn],ocnt;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		if(i&1) scanf("%d",&j[++j[0]]);
		else scanf("%d",&o[++o[0]]);
	}
	sort(j+1,j+1+j[0],cmp);
	sort(o+1,o+1+o[0],cmp);
	if(m>(n>>1)){
		printf("Error!");
		return 0;
	}
	int ans=-(1<<29),sumj=0,sumo=0;
	for(int i=1;i<=m;i++){
		sumj+=j[i];
		sumo+=o[i];
	}
	ans=max(ans,max(sumj,sumo));
	printf("%d",ans);
	return 0;
}
