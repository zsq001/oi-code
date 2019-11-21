#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#define ll long long int
using namespace std;
ll n,n1,k,num=1,cnt,cnt1,ans;
char p,p1,p2;
ll a[100005],b[100005];
queue<char> q;
int main()
{
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	ll i;
	scanf("%lld\n",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%c",&p);
		q.push(p);
	}
	for(i=1;i<n;++i)
	{
		scanf("%lld",&a[i]);
	}
	while(q.size())
	{
		p1=q.front();
		q.pop();
		cnt++;
		p2=q.front();
		q.pop();
		cnt++;
		if(p1=='('&&p2==')')
		{
			cnt1++;
		}
		b[cnt]=cnt1;
	}
	for(i=1;i<=n;++i)
	{
		ans=ans^(i*b[i]);
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
