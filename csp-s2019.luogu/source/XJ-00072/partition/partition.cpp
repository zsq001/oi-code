#include<bits/stdc++.h>
using namespace std;
int a[2020],vis[2020],del[2020],sum[2020],ans=1<<29,n,maxx,t;

int read(){
	int x = 0,fl = 1;
	char ch = getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')fl = -1;
		ch = getchar();
	}
	while(ch<='9'&&ch >= '0'){
		x = (x<<1)+(x<<3)+(ch-'0');
		ch = getchar();
	}
	return x * fl;
}

void dfs(int x,int tot,int val){
	if(x==n){
		ans = min(ans,tot);
		return ;
	}
	for(int i = x+1; i <= n; i++){
		if(sum[i]-sum[x]<val)continue;
		dfs(i,tot+(sum[i]-sum[x])*(sum[i]-sum[x]),sum[i]-sum[x]);
	}
}

int main(){
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	scanf("%d%d",&n,&t);
	for(int i = 1; i <= n; i++){
		scanf("%d",&a[i]);
		sum[i] = sum[i-1]+a[i];
	}
	dfs(0,0,0);
	printf("%d",ans);
}
