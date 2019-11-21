#include<stdio.h>
#include<string.h>
int n,fa[500010];
char a[500010];
int min(int x,int y)
{
	if(x<y) return x;
	return y;
}
int main()
{
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	int i,j,k,sl=0,sr=0;
	long long ans=0,sum=0;
	scanf("%d\n",&n);
	gets(a);
	for(i=2;i<=n;i++)
	{
		scanf("%d",&fa[i]);
	}
	for(i=0;i<n;i++)
	{
		sum=0;
		for(j=0;j<=i;j++)
		{
			if(a[j]=='(')
			{
				sl=1;sr=0;
				for(k=j+1;k<n;k++)
				{
					if(a[k]=='(')
					{
						sl++;
					}
					else
					{
						if(sr<sl)
						{
							sr++;
							ans++;
						}
						else break;
					}
				}
			}
		}
		ans=ans^((long long)(i+1)*sum);
	}
	printf("%lld",ans);
	return 0;
}








