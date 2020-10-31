#include<cstdio>
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	int n,i;char s[55];long long ans=0,x=1;
	scanf("%d%s",&n,s);
	for(i=0;i<n;++i)ans+=s[i]=='B'?x:0,x*=2;
	printf("%lld",ans);
}
