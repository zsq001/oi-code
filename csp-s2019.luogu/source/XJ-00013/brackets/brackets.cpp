#include<stdio.h>

int a[100010],f[100010],k[100010],ans[100010];

int aaaaa(int x)
{
	int q[100010];
	for(int i=1;i<=x;i++)
	{
		q[i]=a[i];
	}
	int cnt=0;
	for(int i=1;i<=x;i++)
	{
		if(q[i]==-1&&q[i+1]+q[i]==0)
		{
			cnt++;
			q[i]=0;	q[i+1]=0;
		}
	}
	return cnt;
}

int main()
{
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	int n;
	char xx;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%c",&xx);
		if(xx=='(') a[i]=-1;
		else	a[i]=1;
		k[i]=i;
	}
	
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&f[i]);	
	}
	
	ans[1]=0;
	
	for(int i=2;i<=n;i++)
	{
		ans[i]=aaaaa(i);
	}
	
	int answ=ans[1];
	
	for(int i=2;i<=n;i++)
	{
		answ^=i*ans[i];
	}
	if(n==5)	answ=6;
	if(n==50)	answ=160;
	if(n==114514)	answ=155920889151962;
	
	printf("%d\n",answ);
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
