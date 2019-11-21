#include<cstdio>
#include<algorithm>
using namespace std;

struct node{
	int next,to;
}e[500005];

int n,cnt=1;
int head[500005];
char s[500005];
int ans;
int fa[500005],fu[500005];
int dp[500005][2];

int findd(int x){
//	printf("%d %d\n",x,fa[x]);
	if(x!=fa[x]) return fa[x]=findd(fa[x]);
	else return fa[x];
}


void ade(int from,int to){
	e[++cnt].next=head[from];
	e[cnt].to=to;
	head[from]=cnt;
}

int get_ans(int o){
	int ret=0;
	o=findd(o);
	while(o!=1){
		ret+=dp[o][1];
		o=fu[o];
	}
	ret+=dp[1][1];
	return ret;
}

void dfs(int o){
//	if(o==25) out();
	if(o==1){
		fa[o]=o;
		if(s[1] == '(') dp[1][0]=1;
		else dp[1][0]=0;
	}
	else{
		ans^=(o*get_ans(o));
	}
	int fa0=findd(o);
	int tp1=dp[fa0][1];
	int tp0=dp[fa0][0];
	int tp2=0;
	for(int i=head[o];i!=0;i=e[i].next){
		tp2=-1;
		int x=e[i].to;
		fa[x]=x;
		if(s[x] == '('){
			if(s[o] == '('){
				fa[x]=findd(o);
			}
			dp[fa[x]][0]=dp[fa[x]][0]+1;
			dp[fa[x]][1]=0;
		}
		else{
			if(dp[fa[o]][0]>0){
				fa[x]=findd(o);
				dp[fa[x]][0]=dp[fa[x]][0]-1;
				dp[fa[x]][1]=dp[fa[x]][1]+1;
			}
			else{
				dp[fa[x]][o]=-1;
				dp[fa[x]][1]=0;
			}
			if(dp[fa[x]][0]==0){
				fa[fa[x]]=fa[fu[fa[x]]];
				tp2=dp[fa[fa[x]]][1];
				if((fa[fa[x]] != fa[x]) && dp[fa[fa[x]]][1]!=0) dp[fa[fa[x]]][1]+=dp[fa[x]][1]+1;
				else if((fa[fa[x]] != fa[x])) dp[fa[fa[x]]][1]+=dp[fa[x]][1];
				
			}
		}
		dfs(x);
		if(tp2!=-1) dp[fa[fa[x]]][1]=tp2;
		fa[fa0]=fa0;
		dp[fa0][1]=tp1;
		dp[fa0][0]=tp0;
	}
}


int main()
{
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	scanf("%d",&n);
	scanf("%s",s+1);
	fu[1]=1;
	for(int i=2;i<=n;i++){
		int tp;
		scanf("%d",&tp);
		ade(tp,i);
		fu[i]=tp;
	}
	dfs(1);
	printf("%d",ans);
	return 0;
}
