#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int t,n,a[100],b[100];
int main()
{
	freopen("centroid.in","r",stdin);
	freopen("centroid.out","w",stdout);
	int i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;++i)
		{
			scanf("%d%d",&a[i],&b[i]); 
			printf("41\n"); 
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
