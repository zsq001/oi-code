#include<stdio.h>
#include<stdlib.h>
int n,f[500005],k[500005],flag;
char a[500005];
int isok(int l,int r)
{
	int i,tot=0;
	for(i=l;i<=r;i++)
	{
		if(a[i]=='(')tot++;
		else tot--;
		if(tot<0)
		{
			return 0;
		}
	}
	if(tot==0)return 1;
	return 0;
}
int main()
{
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	int i,j,ii,t;
	scanf("%d",&n);
	scanf("%s",a);
	for(i=1;i<n;i++)
	{
		scanf("%d",&f[i+1]);
		if(f[i+1]!=i)flag=1;
	}
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			t=isok(i,j);
			if(t==0)
			{
				continue;
			}
			for(ii=j;ii<n;ii++)
			{
				k[ii]++;
			}
		}
	}
	t=0;
	for(i=0;i<n;i++)
	{
		t^=(i+1)*k[i];
	}
	printf("%d",t);
	return 0;
}
