#include<cstdio>
#include<stack>
#include<algorithm>
using namespace std;
#define inf 1000000009

int n,k,vis[20],dis[20][20];
int flag;
int st[20],ed[20],ans=inf,num=1;
stack<int> s;

void dfs(int o,int d){
	if(num == n) ans=min(ans,d+ed[o]); 
	s.push(o);vis[o]=1;
	for(int i=1;i<=n;i++){
		if(i==o || vis[i]) continue;
		num++,dfs(i,d+dis[o][i]);
		num--;
	}
	s.pop();vis[o]=0;
}


int main()
{
	freopen("save.in","r",stdin);
	freopen("save.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&st[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&ed[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&dis[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		int tp;
		for(int j=1;j<=5;j++){
			for(int l=1;l<=5;l++){
				scanf("%d",&tp);
				flag|=tp;
			}
		}
	}
	if(flag!=0){
		printf("NO");
		return 0;
	}
	for(int i=1;i<=n;i++){
		dfs(i,st[i]);
	}
	printf("YES\n");
	printf("%d",ans);
	return 0;
}
