#include<iostream>
#include<cstdio>
using namespace std;
int r=0,b[1001][1001];
int n;
void up(int &x,int &y)
{
	if(b[x][y+1]!=2&&y<=n)
	{
		y++;r=1;
		return;
		
	}
	return;
	
}
void left(int &x,int &y)
{
	if(b[x-1][y]!=2&&x>=0)
	{
		x--;r=1;
		return;
		
	}
	return;
	
}
void right(int &x,int &y)
{
	if(b[x+1][y]!=2&&x<=n)
	{
		x++;	r=1;
		return;
	}
	return;
	
}
void down(int &x,int &y)
{
	if(b[x][y-1]!=2&&y>=0)
	{
		y--;r=1;
		return;
		
	}
	return;

}
int main()
{
	freopen("bar.in","r",stdin);
	freopen("bar.out","w",stdout);
	int t;
	cin>>t;
	for(int j=1;j<=t;j++)
	{
		cin>>n;
		int x=0,y=0;
		for(int i=1;i<=2*n-2;i++)
		{
			r=0;
			if(r==0)
			up(x,y);
			if(r==0)
			right(x,y);
			if(r==0)
			left(x,y);
			if(r==0)
			down(x,y);
			int g,h;
			cin>>g>>h;
			b[g][h]=2;
		}
		int p=0;
		for(int i=1;i<=10000;i++)
		{
			if(x==n&&y==n)
			{
				p=1;
				cout<<"Yes"<<endl;
				break;
			}
			r=0;
			if(r==0)
			up(x,y);
			if(r==0)
			right(x,y);
			if(r==0)
			left(x,y);
			if(r==0)
			down(x,y);
		}
		if(p==0)
		cout<<"No";
	}
	return 0;
}
