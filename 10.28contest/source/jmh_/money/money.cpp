#include<cstdio>
#include<algorithm>
using namespace std;
#define inf 1000000009


int T,n,maxn,ans;
int a[150];
bool dp[1050];

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		maxn=0;
		scanf("%d",&n);
		ans=n;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			maxn=max(maxn,a[i]);
		}
		sort(a+1,a+1+n);
		dp[0]=true;
		for(int i=1;i<=maxn;i++){
			dp[i]=false;
		}
		for(int i=1;i<=n;i++){
			if(dp[a[i]]){
				ans--;
				continue;
			}
			for(int j=1;j<=maxn;j++){
				if(j-a[i]>=0) dp[j]=dp[j-a[i]];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
