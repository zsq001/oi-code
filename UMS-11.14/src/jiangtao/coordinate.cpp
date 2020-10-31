#include<cstdio>
#include<algorithm>
#include<cstring>
long long ans[2]={1,2},tmp[2][2];
using namespace std;
long long read()
{
	char s[50];
	long long ans,len;
	scanf("%s",s);len=strlen(s);ans=s[0]-'0';
	for(long long i=1;i<len;i++)
	ans=ans*10+s[i]-'0';
	return ans;
}
void chen1()
{
	long long a,b;
	a=((ans[0]*tmp[0][0])%1000000007+(ans[1]*tmp[1][0])%1000000007)%1000000007;
	b=((ans[0]*tmp[0][1])%1000000007+(ans[1]*tmp[1][1])%1000000007)%1000000007;
	ans[0]=a;ans[1]=b;
	return;
}
void chen2()
{
	long long k[2][2];
	k[0][0]=((tmp[0][0]*tmp[0][0])%1000000007+(tmp[0][1]*tmp[1][0])%1000000007)%1000000007;
	k[0][1]=((tmp[0][0]*tmp[0][1])%1000000007+(tmp[0][1]*tmp[1][1])%1000000007)%1000000007;
	k[1][0]=((tmp[1][0]*tmp[0][0])%1000000007+(tmp[1][1]*tmp[1][0])%1000000007)%1000000007;
	k[1][1]=((tmp[1][0]*tmp[0][1])%1000000007+(tmp[1][1]*tmp[1][1])%1000000007)%1000000007;
	for(long long i=0;i<2;i++)
	for(long long j=0;j<2;j++)
	tmp[i][j]=k[i][j];
	return;
}
void solve(long long k)
{
	while(k!=0)
	{
		if(k&1)chen1();
		chen2();
		k/=2;
	}
	return;
}
int main()
{
	freopen("coordinate.in","r",stdin);
	freopen("coordinate.out","w",stdout);
	long long n;
    tmp[0][0]=1;tmp[0][1]=2;tmp[1][0]=1;tmp[1][1]=1;
    n=read();
    n--;
    solve(n);
    printf("%lld\n",(ans[0]+ans[1])%1000000007);
    fclose(stdin);
	fclose(stdout);
	return 0;
}
