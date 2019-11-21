#include<bits/stdc++.h>
int n,k,sum=1,left,right;
bool leftright[10],t,change;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d%d",&n,&k);
	bool line[n];
	line[0]=false;
	line[1]=true;
	for(int j=1;j<=n;j++)
		sum*=2;
	sum--;
	left=0;
	right=sum;
	for(int i=n;i>=1;i--)
	{
		if(k<=(left+right)/2)
		{
			if(!change)
				leftright[i]=true;
			right=(left+right)/2;
		}
		else if(k>(left+right)/2)
		{
			if(change)
				change=false;
			else
				change=true;
			leftright[i]=false;
			left=(left+right)/2+1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(leftright[i])
		{
			for(int j=i;j>=0;j--)
				line[j+1]=line[j];
			line[0]=false;
		}
		else if(!leftright[i])
		{
			for(int j=0;j<n;j++)
			{
				t=line[j];
				line[j]=line[n-j-1];
				line[n-j-1]=t;
			}
			for(int j=i;j>=0;j--)
				line[j+1]=line[j];
			line[0]=true;
		}
	}
	for(int i=0;i<n;i++)
		if(line[i])
			printf("1");
		else
			printf("0");
	printf("\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
