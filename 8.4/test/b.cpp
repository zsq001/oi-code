#include<iostream>
using namespace std;
struct node{
	int col,vis;
}a[1000010];
int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	int n,m,p,q;
	cin>>n>>m>>p>>q;
	for(int i=1;i<=m;i++)
	{
		a[i].vis=0;
		a[i].col=0;
	}
	for(int i=m;i>=1;i--)
	{
		int y=max((i*p+q)%n+1,(i*q+p)%n+1),x=min((i*p+q)%n+1,(i*q+p)%n+1);
		if(a[x].vis!=0&&a[y].vis!=0)
		continue;
		if(a[x].vis!=0)
		{
			x=y;
			while(a[x].vis==0)
			{
				a[x].col=i;
				x--;
			}
		}
		if(a[y].vis!=0)
		{
			y=x;
			while(a[y].vis==0)
			{
				a[y].col=i;
				y++;
			}
		}
		else
		for(int j=x;j<=y;j++)
		{
			a[j].col=i;
			a[j].vis=1;
		}
	}
	for(int i=1;i<=n;i++)
	cout<<a[i].col<<endl;
	return 0;
}
