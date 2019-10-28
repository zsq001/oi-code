#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 10000
char a[2010];
long long tail[2100],head[2100];
struct node
{
	long long head,tail;
};
node b[MAXN];
long long h,t;
int main()
{
	freopen("calc.in","r",stdin);
	freopen("calc.out","w",stdout);
	scanf("%s",a);
	long long len=strlen(a);
	h=1,t=0;
	for(long long i=0;i<len;i++)
	{
		b[++t].head=i;
		b[t].tail=i;
		head[b[t%MAXN].head]++;
		tail[b[t%MAXN].tail]++;
	}
	for(long long i=0;i<len-1;i++)
	{
		if(a[i]==a[i+1])
		{
			b[++t].head=i;
			b[t].tail=i+1;
			head[b[t%MAXN].head]++;
			tail[b[t%MAXN].tail]++;
		}
	}
	while(h<=t)
	{
		if(b[h%MAXN].head==0||b[h%MAXN].tail==len-1)
		{
			h++;
			continue;
		}
		if(a[b[h%MAXN].head-1]==a[b[h%MAXN].tail+1])
		{
			t++;
			b[t%MAXN].head=b[h%MAXN].head-1;
			b[t%MAXN].tail=b[h%MAXN].tail+1;
			head[b[t%MAXN].head]++;
			tail[b[t%MAXN].tail]++;
		}
		h++;
	}
	long long ans=0;
	for(long long i=0;i<len;i++)
	{
		if(i!=0)tail[i]+=tail[i-1];
		ans+=tail[i]*head[i+1];
	}
	cout<<ans;
	fclose(stdout);
	fclose(stdin);
	return 0;
}
