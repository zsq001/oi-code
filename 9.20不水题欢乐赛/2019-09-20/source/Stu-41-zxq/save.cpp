#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int ans=0x7fffffff;
#define MAXN 20
int vis[MAXN],x[MAXN][MAXN],n,k,len,fl,ffl,a[6][6],tim;
bool check(){
	for(int i=1;i<=n;i++)
		if(vis[i]==0) return 0;
	return 1;
}
void find_way(int pos){
	if(check()){
		ans=min(ans,len+x[pos][0]);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]&&x[pos][i]) {
			vis[i]=1;
			len+=x[pos][i];
			find_way(i);
			fl=1;
		}
		if(fl){
			vis[i]=0;
			fl=0;
		}
		len-=x[pos][i];
	}
	return ;
}
int solve(){
	int cnt=0;
	for(int i=1;i<=5;i++)
		for(int j=1;j<=5;j++){
			if(a[i][j]==1
			&&(a[i][j-1]==1||j==1)
			&&(a[i-1][j]==1||i==1)
			&&(a[i][j+1]==1||j==5)
			&&(a[i+1][j]==1||i==5)){
				cnt++;
				a[i][j]=0;
				a[i+1][j]=0;
				a[i-1][j]=0;
				a[i][j-1]=0;
				a[i][j+1]=0;
			}
		}
	return cnt;
}
int main(){
	freopen("save.in","r",stdin);
	freopen("save.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&x[0][i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&x[i][0]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&x[i][j]);
	find_way(0);
	while(n--){
		memset(a,0,sizeof(a));
		for(int u=1;u<=5;u++)
			for(int v=1;v<=5;v++)
				scanf("%d",&a[u][v]);	
		tim+=solve()*k;
		for(int i=1;i<=5;i++)
			for(int j=1;j<=5;j++){
				if(a[i][j]){
					printf("NO\n");
				    return 0;
				}
			}
	}
	printf("YES\n");
	printf("%d\n",tim+ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
