#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define ll long long
#define maxn 100005

int in(){
	int ret=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') {
		ret=(ret<<3)+(ret<<1)+(ch&15);
		ch=getchar();
	}
	return ret;
}

int p[1005],g[1005],maxc[1005],sum[1005];

double po[1005],dp[1005][1005];

void init(int n,double ba){
	po[0]=1.0;
	for(int i=1;i<=n;i++) po[i]=po[i-1]*ba;
}

int main(){
	freopen("coal.in","r",stdin);
	freopen("coal.out","w",stdout);
	int n,k,c,w;
	n=in();k=in();c=in();w=in();
	int op,ans=0;
	for(int i=1;i<=n;i++){
		op=in();
		sum[i]=sum[i-1];
		if(op==1) g[i]=in();//煤矿 
		else p[i]=in(),sum[i]++; //补给 
	}
	if(k==100){//买了j个补给时最多的钱
		for(int i=1;i<=n;i++) ans=max(ans,g[i]);
		printf("%d",ans*w);
	}
	return 0;
}
