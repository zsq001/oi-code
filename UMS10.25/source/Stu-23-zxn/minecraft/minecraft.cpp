#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
#define maxn 100005
int x[maxn],y[maxn],z[maxn];
int read(){
	int ret=0;char c;
	c=getchar();
	while(c>'9'||c<'0') c=getchar();
	while(c<='9'&&c>='0'){
		ret=((ret<<3)+(ret<<1)+(c&15));
		c=getchar();
	}
	return ret;
}
int main(){
	int n,b,d,m;
	freopen("minecraft.in","r",stdin);
	freopen("minecraft.out","w",stdout);
	scanf("%d%d%d%d",&b,&n,&d,&m);
	int ans=0;
	if(b==1){
		for(int i=1;i<=n;i++){
			scanf("%d",&x[i]);
		}
		sort(x+1,x+1+n);int r=1;
		for(int l=1;l<=n;l++){
			while(x[r]-x[l]<=d&&r<=n) r++;
			ans+=r-l-1;
		}
		printf("%d",ans);
	}
	if(b==2){
		for(int i=1;i<=n;i++)scanf("%d%d",&x[i],&y[i]);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(abs(x[i]-x[j])+abs(y[i]-y[j])<=d) ans++;
			}
		}
		printf("%d",ans);
	}
	if(b==3){
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&x[i],&y[i],&z[i]);
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(abs(x[i]-x[j])+abs(y[i]-y[j])+abs(z[i]-z[j])<=d) ans++;
			}
		}
		printf("%d",ans);
	}
}
