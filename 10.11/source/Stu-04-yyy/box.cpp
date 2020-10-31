#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;

ll n,a,b,c,ans;
ll s,l,r,L,R;
ll pri[35005],t[31],m;
bool vis[35005];
bool check(){
	for(int i=2;i<=35000;i++){
		if(!vis[i])pri[++pri[0]]=i;
		for(int j=1;j<=pri[0]&&pri[j]*i<=35000;j++){
			vis[pri[j]*i]=1;
			if(i%pri[j]==0)break;
		}
	}
	m=n;
	for(int i=1;i<=pri[0];i++){
		while(m%pri[i]==0){
			m/=pri[i];
			t[++t[0]]=pri[i];
		}
		if(m==1)break;
	}
	if(m!=1)t[++t[0]]=m;
	if(t[0]>3)return 0;
	if(t[0]==1)printf("%lld\n",n*4+2);
	if(t[0]==2)printf("%lld\n",2*(n/t[1]+n/t[2]+n));
	if(t[0]==3)printf("%lld\n",2*(n/t[1]+n/t[2]+n/t[3]));
}
int main(){
	freopen("box.in","r",stdin);
	freopen("box.out","w",stdout);
	
	scanf("%lld",&n);
	if(n==1ll){puts("6");return 0;}
	if(ans=check()){return 0;}
	else ans=1e9;
	s=(int)(pow(n*1.0,1.0/3)+0.5);
//	printf("%lld\n",s);
	l=max(1ll,s-1000);
	r=min(n,s+1000);
	for(b=l;b<=r;b++){
		if(n%b)continue;
		s=n/b;
		s=(int)(pow(s*1.0,1.0/2)+0.5);
		L=max(1ll,s-1000);
		R=min(n,s+1000);
		for(a=L;a<=R;a++){
			if(n/b%a)continue;
			c=n/b/a;
			ans=min(ans,2*(a*b+b*c+c*a));
//			printf("%lld %lld %lld %lld\n",a,b,c,ans);
		}
	}
	printf("%lld\n",ans);
	return 0;
}
