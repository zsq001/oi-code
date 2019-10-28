#include<stdio.h>
#include<string.h>
int ans,n,f[2010][2010];
char a[2010];
bool judge(int l,int r)
{
	while(l<r)
	{
		if(a[l]==a[r])
		{
			l++;r--;
		}
		else return false;
	}
	return true;
}
int main()
{
	freopen("calc.in","r",stdin);
	freopen("calc.out","w",stdout);
	scanf("%s",a+1);
	n=strlen(a+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(judge(i,j))f[i][j]++;
		}
	}
	for(int i=1;i<n;i++)
	{
		for(int ii=i;ii<n;ii++)
		{
			if(f[i][ii])
			{
				for(int j=ii+1;j<=n;j++)
				{
					for(int jj=j;jj<=n;jj++)
					{
						if(f[j][jj])ans+=f[i][ii]*f[j][jj];
					}
				}
					
			}
		}
	}		
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
