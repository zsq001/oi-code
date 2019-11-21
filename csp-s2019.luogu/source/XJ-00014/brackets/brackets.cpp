#include <stdio.h>
#include <string.h>
int n,father[2100],ans[2100];
char a[2100],str[2100][2100];
int main()
{
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	scanf("%d\n",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%c",&a[i]);
		if(a[i]=='(')     a[i]=')';
		else if(a[i]==')')a[i]='(';
	}
	for(int i=2;i<=n;i++)scanf("%d",&father[i]);
	for(int i=2;i<=n;i++)
	{
		int s=i,j=1;
		while(1) 
		{
			str[i][j]=a[s];
			j++;
			if(s==1)break;
			s=father[s];
		}
		for(int p=1;p<=j;p++)
		{
			if(str[i][p]=='(')
			{
				for(int k=p+1;k<=j;k++)
				if(str[i][k]==')')ans[i]++;
			}
		}
		if(ans[i]==1) ans[i]+=0;
		else ans[i]=ans[i]/2;
	}
	int an=ans[1];
	for(int i=2;i<=n;i++)
	{
		an=(an)xor(i*ans[i]);
	}
	printf("%d",an);
	return 0;
}
