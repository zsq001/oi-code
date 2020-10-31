#include<cstdio>
#include<cstring>
using namespace std;
int n,m,x,y;
int i,num = 0;
int a[100010];
int b[100010];
bool visit[1000010];
int match[100001]; 
bool mark[100001000];
int main()
{
	freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&x,&y);
	for(i = 1;i <= n;++i)
	{
		scanf("%d",&a[i]);
	}
	int l = 0;
	for(i = 1;i <= m;++i)
	{
		scanf("%d",&b[i]);
		int r = n;
		while(l < r-1)
		{
			int mid = (l+r)/2;
			if(b[i] > a[mid] + y) l = mid;
			else r = mid;
		}
		if(a[r] + y>= b[i] && a[r]-x <= b[i]) num++,l = r;
	}
	printf("%d",num);
	return 0;
} 
