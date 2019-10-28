#include<stdio.h>
#include<algorithm>
#include<map>
using namespace std;

long long a[310];
long long sum=0,tt=0;
long long ans1[310],ans2[310],tot=0;
int n,e,jud=0;
int ind;

bool cmp(int x,int y)
{
	return x<y;
}

bool com()
{
	int i=1,j=n;
	while(i<=n&&j>=1)
	{
		if(ans1[i]!=ans2[j]) return true;
		i++,j--;
		if(ans1[i]>ans2[j]) jud=1;
		if(ans1[i]<ans2[j]) jud=2;
	}
	return false;
}

void swap1()
{
	
}

//void dfs(int m,int stp)
//{
//	for(int i=m+1;i<=e;i++)
//	{
//		if(stp==4) break;
//		tt+=a[i];
//		dfs(i,stp+1);
//		tt-=a[i];
//	}
//	int hh=tt-sum;
//	if(!(tt-sum)%3) ans[++tot]=(tt-sum)/3;
//}

int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%d",&n);
	e=n*(n-1)/2;
	for(int i=1;i<=e;i++)
	{
		scanf("%lld",&a[i]);
		sum+=a[i];
	}
	sort(a+1,a+1+e,cmp);
	ind=n-1;
	sum/=ind;
	
	
	for(int i=1;i<=ind;i++)
	{
//		if(a[i]==a[i-1]) continue;
		tt+=a[i];
	}
	ans1[++tot]=(tt-sum)/(ind-1);
	for(int i=1;i<=ind;i++)
	{
//		if(a[i]==a[i-1]) continue;
		ans1[++tot]=a[i]-ans1[1];
	}
	
	tt=0;
	tot=0;
	
	
	for(int i=e;i>=e-ind+1;i--)
	{
//		if(a[i]==a[i-1]) continue;
		tt+=a[i];
	}
	ans2[++tot]=(tt-sum)/(ind-1);
	for(int i=e;i>=e-ind+1;i--)
	{
//		if(a[i]==a[i-1]) continue;
		ans2[++tot]=a[i]-ans2[1];
	}
	
	if(com())
	{
		printf("2\n");
		if(jud==1)
		{
			for(int i=1;i<=n;i++)
				printf("%d ",ans1[i]);
			printf("\n");
			for(int i=n;i>=1;i--)
				printf("%d ",ans2[i]);
		}
		else 
		{
			for(int i=n;i>=1;i--)
				printf("%d ",ans2[i]);
			printf("\n");
			for(int i=1;i<=n;i++)
				printf("%d ",ans1[i]);
		}
	}
	else 
	{
		printf("1\n");
		for(int i=1;i<=n;i++)
			printf("%d ",ans1[i]);
	}
	fclose(stdin);
	fclose(stdout);	
	return 0;
}
