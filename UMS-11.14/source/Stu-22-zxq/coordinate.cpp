#include <cstdio>
int ans[]={0,3,7,17,41,99,239,577,1393,3363,8119,19601,47321,
           114243,275807,665857,1607521,3880899,9369319,22619537,54608393};
using namespace std;
int n;
int main(){
	freopen("coordinate.in","r",stdin);
	freopen("coordinate.out","w",stdout);
	scanf("%d",&n);
	printf("%d",ans[n]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

/*
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int mod=1e9+7;
int dx[]={0,-1,1};
int dy[]={1,0,0};
int ans,n;
int v[10000][10000],vv[1000][1000];
void dfs(int x,int y,int cnt){
	if(cnt==0){
		ans=(ans+1)%mod;
		return ;
	}
	for(int i=0;i<=2;i++)
		if(!v[x+dx[i]+1000][y+dy[i]]){
			v[x+dx[i]+1000][y+dy[i]]=1;
			dfs(x+dx[i],y+dy[i],cnt-1);
			v[x+dx[i]+1000][y+dy[i]]=0;
		}
}
int main(){
	freopen("ans.out","r",stdout);
	for(int i=1;i<=100;i++){
		ans=0;
		memset(v,0,sizeof(v));
		v[1000][0]=1;
		dfs(0,0,i);
		printf("%d,",ans);
	}
	return 0;
}*/
