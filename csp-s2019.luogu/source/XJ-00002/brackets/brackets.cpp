#include<stdio.h>
#include<string.h>
long long int f[500000],sk[500000],ski,skj,skk,n,s,sum=0;
char k[500000];
int main()
{
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	long long int i,j,l;
	scanf("%lld %s",&n,k);
	for(i=1;i<n;i++)
	{
		scanf("%lld",&f[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<ski;j++)
		{
			sk[j]=0;
		}
		ski=0;
		j=i;
		while(j>=0)
		{
			sk[ski]=k[j];
			ski++;
			j=f[j]-1;
		}
		skj=0;
		skk=0;
		for(j=ski-1;j>0;j--)
		{
			if(sk[j]=='(')
			{
				skj++;
				for(l=j;l>=0;l--)
				{
					if(sk[l]==')')
					{
						skk++;
					}
				}
			}
		}
		if(skk>skj)
		{
			s=skk;
		}
		else
		{
			s=skk;
		}
		sum=(sum)xor((i+1)*s);
	}
	printf("%lld\n",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
