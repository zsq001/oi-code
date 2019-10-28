#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
long long ans=2147483647,a1,a2,a3;
bool check(int n)
{
	int k=(int)sqrt(n);
	for(int i=2;i<=k;i++)
	{
		if(n%i==0)return false;
	}
	return true;
}
void work2(int n)
{
	int k=(int)sqrt(n);
	for(int i=0;i<k;i++)
	{
		if(n%(k-i)==0)
		{
			a2=k-i;
			a3=n/a2;
			ans=min(ans,a1*a2+a2*a3+a1*a3);	
			if(n%(k+i)==0)
			{
				a2=k+i;
				a3=n/a2;
				ans=min(ans,a1*a2+a2*a3+a1*a3);
			}
			return;
		}
		if(n%(k+i)==0)
		{
			a2=k+i;
			a3=n/a2;
			ans=min(ans,a1*a2+a2*a3+a1*a3);
			return;
		}
	}
}
void work1(int n)
{
	int k=(int)sqrt(n);
	for(int i=0;i<k;i++)
	{
		if(n%(k-i)==0)
		{
			a1=k-i;
			work2(n/(k-i));
			if(n%(k+i)==0)
			{
				a1=k+i;
				work2(n/(k+i));
			}
		}
		if(n%(k+i)==0)
		{
			a1=(k+i);
			work2(n/(k+i));
		}
	}
}
int main()
{
	freopen("box.in","r",stdin);
	freopen("box.out","w",stdout);
	int n;
	scanf("%d",&n);
	if(check(n)||n==1)
	{
		ans=2*(1+n+n);
		printf("%I64d",ans);
		return 0;
	}
	work1(n);
	printf("%I64d",2*ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
