#include<stdio.h>
int a[100001],b[100001],ans;
int main()
{
	int n,m,i,j,x,y,l,r;
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&x,&y);
	for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(j=1;j<=m;j++)
	scanf("%d",&b[j]);
	i=1;j=1;
	while(1)
	{
		l=a[i]-x;
		r=a[i]+y;
		while(i<=n&&j<=m)
		{
			if(b[j]<l)j++;
			else if(b[j]>r)
			{
				i++;
				break;
			}
			else if(b[j]>=l&&b[j]<=r)
			{
				i++;j++;
				ans++;
				break;
			}
			
		}
		if(i>n||j>m)break;
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
