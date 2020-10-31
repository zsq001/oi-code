#include<cstdio>
#include<algorithm>
using namespace std;
#define mod 1000000007

struct node{
	int next,to,dp[2];
}e[3000050];
int n,cnt=1,ans;
int head[2000050];

void ade(int from,int to){
	e[++cnt].next=head[from];
    e[cnt].dp[1]=e[cnt].dp[0]=-1;
	e[cnt].to=to;
	head[from]=cnt;
}

void dfs(int o,int fa,int &dp0,int &dp1){
	int t_11=1,t_10=1,t_00=1,t_01=1,flag=0;
	for(int i=head[o];i!=0;i=e[i].next){
		int x=e[i].to;
		if(x==fa) continue;
		flag=1;
	    if(e[i].dp[0]==-1 && e[i].dp[1]==-1) dfs(x,o,e[i].dp[0],e[i].dp[1]);
	    t_11=(1ll*t_11*e[i].dp[1])%mod;
	    t_10=(1ll*t_10*e[i].dp[0])%mod;
	    t_00=(1ll*t_00*e[i].dp[0])%mod;
	    t_01=(1ll*t_01*e[i].dp[1])%mod;
	}
	
	dp0=(t_11+t_00)%mod;
	dp1=(t_10+t_01)%mod;
    
    if(flag!=1) dp0=1,dp1=1;
}



int main()
{
	freopen("huazhong.in","r",stdin);
	freopen("huazhong.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int tp1,tp2;
		scanf("%d %d",&tp1,&tp2);
		ade(tp1,tp2);
		ade(tp2,tp1);
	}
	
	for(int i=1;i<=n;i++){
		int tp1=0,tp2=0;
		dfs(i,0,tp1,tp2);
		ans=(ans+tp1)%mod;
	}
	
	printf("%d",ans);
	
	return 0;
}
