#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
char a[30];
int ya,ye,yi,yo,yu,numy;
int vis[30];
void print()
{
	for(int i=0;i<=n-1;i++)
	{
		printf("%c",a[vis[i]]);
	}
	printf("\n");
}
void dfs(int now,int num,int y,int f)
{
	if(num==n)
	{
		if(y==0)return;
		if(f<2)return;
		else print();
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(now+i>m)
		{
			return;
		}
		if(ya==now+i||ye==now+i||yi==now+i||yo==now+i||yu==now+i)
		{
			vis[num]=now+i;
			dfs(now+i,num+1,y+1,f);
			vis[num]=0;
		}
		else
		{
			vis[num]=now+i;
			dfs(now+i,num+1,y,f+1);
			vis[num]=0;
		}
	}
	
}
int main()
{
	freopen("ticket.in","r",stdin);
	freopen("ticket.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%c",&a[i]);
		if(a[i]==' '||a[i]=='\n')
		{
			i=i-1;
			continue;
		}
		if(a[i]>='A'&&a[i]<='Z')
		{
			a[i]+=32;
		}
	}
	sort(a+1,a+m+1);
	for(int i=1;i<=m;i++)
	{
		if(a[i]=='a')ya=i;
		if(a[i]=='e')ye=i;
		if(a[i]=='i')yi=i;
		if(a[i]=='o')yo=i;
		if(a[i]=='u')yu=i;
	}
	for(int i=1;i<=m-n+1;i++)
	{	
	    vis[0]=i;
		if(ya==i||ye==i||yi==i||yo==i||yu==i)
		dfs(i,1,1,0);
		else dfs(i,1,0,1);
		vis[0]=0;
	}
}
