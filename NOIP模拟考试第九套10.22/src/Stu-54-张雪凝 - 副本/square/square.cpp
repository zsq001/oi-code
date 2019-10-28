#include<cstdio>
#define maxn 200005
int sum1[maxn],sum2[maxn];
int main(){
	freopen("square.in","r",stdin);
	freopen("square.out","w",stdout);
	int n,cnt1=0,a,ans=0,cnt2=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a);
		if(i&1){
			sum1[++cnt1]=sum1[cnt1-1]+a;
		}else sum2[++cnt2]=sum2[cnt2-1]+a;
	}
	int sum=sum1[cnt1]+sum2[cnt2];
	if(n&1) sum2[cnt2+1]=sum2[cnt2];
	for(int i=1;i<=cnt1;++i){
		int s1,s2;
		s1=sum1[i-1]+sum2[cnt2]-sum2[i-1];
		s2=sum-s1-sum1[i]+sum1[i-1];
		//printf("i=%d,s1=%d,s2=%d\n",i,s1,s2);
		if(s1==s2) ans++;
	}
	//puts("qwq");
	for(int i=1;i<=cnt2;++i){
		int s1,s2;
		s2=sum2[i-1]+sum1[cnt1]-sum1[i];
		s1=sum-s2-sum2[i]+sum2[i-1];
		//printf("i=%d,s1=%d,s2=%d\n",i,s1,s2);
		if(s1==s2) ans++;
	}
	printf("%d",ans);
}
