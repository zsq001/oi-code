#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=55;

int n;
char s[N];
ll ans;
//ll m[N],f[N],

int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d\n",&n);
	scanf("%s",s+1);
	/*for(int i=1;i<=n;i++){
		m[i]=1<<i;
		m[i]+=m[i-1];
		f[i]=m[i]-i;
	}
	for(int i=1;i<=n;i++){
		if(s[i]=='B')ans+=i+f[i-1];
	}
	printf("%lld\n",ans);
	ans=0;*/
	for(int i=1;i<=n;i++){
		if(s[i]=='B')ans+=1<<(i-1);
		if(ans>1e18){puts("-1"); return 0;}
	}
	printf("%lld\n",ans);
	return 0;
}
