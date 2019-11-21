#include<bits/stdc++.h>
using namespace std;
int a[110][2020],vis[110][2020],tong[2020],ans,n,m,ans1;
const int mod = 998244353;
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
void dfs(int tot,int num,int mut,int last){
	if(n-last+1<num)return ;
	if(num == 0){
		ans=(ans+mut)%mod;
		return ;
	}
	for(int i = last; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(tong[j]>=(tot>>1))continue;
			if(!a[i][j])continue;
			tong[j]++;
			dfs(tot,num-1,mut*a[i][j],i+1);
			tong[j]--;
		}
	}
}

int main(){
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	n = read(),m = read();
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			a[i][j] = read();
	for(int i = 2; i <= n; i++){
		dfs(i,i,1,1);
	}
	printf("%d",ans);
}
