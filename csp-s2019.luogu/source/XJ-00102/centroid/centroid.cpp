#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("centroid.in","r",stdin);
	freopen("centroid.out","w",stdout);
	int t,a[4],b[1000];
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d",&b[i]);
	}
	printf("%d %d %d %d %d",a[0],a[1],a[2],a[3],a[4]);
	return 0;
	fclose(stdin);
	fclose(stdout);
}
