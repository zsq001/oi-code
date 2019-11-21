#include<stdio.h>
long long int T,n,cb[2000],b[2000][2000],x,y;
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int Ti,ni,nj,nk,i,j,k,t;
	scanf("%lld",&T);
	for(Ti=0;Ti<T;Ti++)
	{
		for(nj=0;nj<n;nj++)
		{
			for(nk=nj+1;nk<n;nk++)
			{
				b[nj][nk]=0;
			}
		}
		scanf("%lld",&n);
		for(ni=0;ni<n;ni++)
		{
			scanf("%lld",&cb[ni]);
		}
		for(ni=0;ni<(n-1);ni++)
		{
			scanf("%lld%lld",&x,&y);
			b[x][y]=1;
		}
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(b[cb[i]][cb[j]]==1)
				{
					if(cb[i]*10+cb[j]>cb[j]*10+cb[j])
					{
						b[cb[i]][cb[j]]=0;
						t=cb[i];
						cb[i]=cb[j];
						cb[j]=t;
					}
				}
			}
			
		}
		for(i=0;i<n;i++)
		{
			printf("%lld ",cb[i]);
		}
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
