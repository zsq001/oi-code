#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int n,h,b,e,c[100010],cnt[100010]={0};
int f[100010];
int deque[100010],head=1,tail=1;

int main()
{
	freopen("coffee.in","r",stdin);
	freopen("coffee.out","w",stdout);
	while(scanf("%d%d%d%d",&n,&h,&b,&e)!=EOF)
	{
		for(int i=1;i<=n;i++)
			scanf("%d",&c[i]);
		deque[1]=1;
		for(int i=1;i<=n;i++)
		{
			while(i-deque[tail]>=h&&tail>=head) tail--;
			while(i-deque[head]>=h&&tail>=head) head++;
			if(c[i]<=c[deque[head]]&&head<=tail)
			{
				while(c[i]<=c[deque[head]]&&head<=tail) head++;
				deque[--head]=i;
			}
			else deque[++tail]=i;
			cnt[deque[head]]++;
		}
		for(int i=b;i<=e;i++)
			printf("%d ",cnt[i]);
		printf("\n");
		memset(cnt,0,sizeof(cnt));
		memset(deque,0,sizeof(deque));
		head=tail=1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
