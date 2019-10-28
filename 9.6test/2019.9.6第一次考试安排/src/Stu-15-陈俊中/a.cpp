#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define maxn 110
using namespace std;

int t,n,a[maxn],cnt,b[maxn],num,cnt1,cnt2;

int main()
{
	 freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		memset(a,0,sizeof(a));
		cnt=0;num=0;cnt1=0;cnt2=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]%3==0) 
			{
				cnt++;
//				a[i]=0;
			}
			else if(a[i]%3==1) cnt1++;
			else if(a[i]%3==2) cnt2++;
		}
//			{
//				b[++num]=a[i]%3;
//				if(b[num]==1) cnt1++;
//				if(b[num]==2) cnt2++;
//			}
//		sort(b+1,b+num+1);
//		for(int i=1;i<=num;i++)
//		{
//			if(b[i]==1) cnt1++;
//			if(b[i]==2) cnt2++;
//		}
		if(cnt1>cnt2)
		{
			cnt+=cnt2;
			cnt1-=cnt2;
			cnt+=cnt1/3;
		}
		else cnt+=cnt1;
		printf("%d\n",cnt);
	}
	return 0;
}
