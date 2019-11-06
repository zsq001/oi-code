#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int dis[51][51];
int t,n,d,ans;

int main()
{
	freopen("bridge.in","r",stdin);
	freopen("bridge.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		memset(dis,0x3f,sizeof(dis));
		ans=0;
		scanf("%d %d\n",&n,&d);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				char tp;
				dis[i][i]=0;
				scanf("%c",&tp);
				if(tp=='Y') dis[i][j]=dis[j][i]=d;
			}
			scanf("\n");
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					dis[j][i]=dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,dis[i][j]);
			}
		}
		if(ans==1061109567) printf("-1\n");
		else printf("%d\n",ans);
	}
}
