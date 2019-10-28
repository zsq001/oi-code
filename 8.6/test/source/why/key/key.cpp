#include<cstdio>
#include<cstring>
#include<algorithm>
#include<deque>
#define maxn 500050
using namespace std;
char a[maxn],t;
int n,m,k,ans,cz[maxn],tot;
int main()
{
	int w=0,i=2;
	freopen("key.in","r",stdin);
	freopen("key.out","w",stdout);
	scanf("%s",a);
	int len=strlen(a);
	for(int i=1;i<len;i++)
	{
		if(a[i]!=a[i-1])
		w++;
	}
	k=len/3;
	if(w+1>=2*k)
	{
		printf("0");
		return 0;
	}
	for(i=0;i<len;i++)
	{
		if(a[i]==a[i-1]&&a[i+1]==a[i+2]&&a[i]!=a[i+1])
		{
			for(int j=i;j<=i+1;j++)
			{
				if(a[j]=='0')
				{
					a[j]='1';
				}
				else a[j]='0';
			}
			cz[++tot]=i;
			ans++; 
		}
		if(a[i]==a[i-1]&&a[i]==a[i+1]&&a[i+1]==a[i+2])
		{
			for(int j=i;j<=i+1;j++)
			{
				if(a[j]=='0')
				{
					a[j]='1';
				}
				else a[j]='0';
			}
			cz[++tot]=i;
			ans++;
		}
		if(ans*2+w+1>=k*2)
		{
			printf("%d\n",ans);
			for(int j=1;j<=ans;j++)
			{
				printf("%d ",cz[j]+1);
			}
			return 0;
		}
	}
}
// 101011011
