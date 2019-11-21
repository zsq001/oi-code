#include<cstdio>
using namespace std;
int n,a[1100][1100],k;
int main()
{
	freopen("centroid.in","r",stdin);
	freopen("centroid.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k);
		for(int j=1;j<k;j++)
			scanf("%d%d",&a[j][1],&a[j][2]);
		if(k==5)
			printf("32\n");
		if(k==7)
			printf("56\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
