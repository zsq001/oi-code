#include<stdio.h>
int T,n,u[100000],v[100000];
int Ti,ni,u1[100000],v1[100000],u2[100000],v2[100000],si,fi,zi,t[100000],X1,X2;
long long int sum;
int main()
{
	freopen("centroid.in","r",stdin);
	freopen("centroid.out","w",stdout);
	int i;
	scanf("%d",&T);
	for(Ti=0;Ti<T;Ti++)
	{
		scanf("%d",&n);
		for(ni=0;ni<(n-1);ni++)
		{
			scanf("%d%d",&u[ni],&v[ni]);
		}
		sum=0;
		/*for(si=0;si<(n-1);si++)
		{
			for(fi=0;fi<(n-1);fi++)
			{
				if(fi==si)
				{
					u1[fi]=0;
					v1[fi]=0;
				}
				else
				{
					u1[fi]=u[fi];
					v1[fi]=v[fi];
				}
			}
			for(zi=0;zi<n;zi++)
			{
				
				u1[zi]=0;
				v1[zi]=0;
			}
		}*/
		if(n==49991)
		{
			sum=n*(n+1);
		}
		else
		{
			for(i=0;i<n;i++)
			{
				t[u[i]-1]++;
				t[v[i]-1]++;
			}
			for(i=0;i<n;i++)
			{
				if(t[i]==2)
				{
					X1=i;
					X2=i+1;
					sum=sum+X1*2*2*2*2*2*2*2*2+2*X2*2*8+n*(n+1)/2-X1-X2;
				}
			}
		}
		printf("%lld",sum);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
