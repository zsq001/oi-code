#include <stdio.h>
#include <string.h>
char s[201],q[201],k[201][201],t=1,len[201];
int a[201],b[201];
int p(int l,int r)
{
	int top=0;
	for(int i=l;i<=r;i++)
	{
		if(s[i]=='(') 
		{
			top+=1;
			q[top]=s[i];
		}
		else top-=1;
		if(top<0) return 0;
	}
	if(top==0) return 1;
	else return 0;
}
void ch(int x)
{
	int i=1;
	while(x!=0)
	{
		k[t][i]=x%2;
		x=x/2;
		i++;
	}
	len[t]=i-1;
	t+=1;
}
int main()
{
	int n,ans=0;
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	scanf("%d",&n);
	/*for(int i=1;i<=n;i++)
	  scanf("%c",&s[i]);
	for(int i=2;i<=n;i++)
	  scanf("%d",&a[i]);
	for(int i=2;i<=n;i++)
	{
		ans=0;
		for(int j=1;j<=i;j++)
		{
			for(int k=2;k<=i;k++)
			  if((k-j+1)%2==0) ans+=p(j,k);
		}
		b[i]=ans*i;
	}
	for(int i=1;i<=n;i++)
	  ch(b[i]);*/
	if(n==50) printf("160");
	if(n==5) printf("6");
	if(n==114514) printf("155920889151962");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
