#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
queue<int> q;
int red[1000200];
int main()
{
	freopen("tea.in","r",stdin);
	freopen("tea.out","w",stdout);
	int m,czy;
	cin>>m>>czy;
	for(int i=1;i<=m;i++)
	{
		int nu;
		cin>>nu;
		if(nu==1)
		{
			int y;
			cin>>y;
			red[y]=1;
		}
		if(nu==2)
		{
			int y;
			cin>>y;
			red[y]=0;
			q.push(y);
		}
		if(nu==3)
		{
			int y=q.front();
			red[y]=1;
		}
		if(nu==4)
		{
			int i=-1;
			while(1)
			{
				i++;
				if(!red[i])
				{
					cout<<i<<endl;
					break;
				}
			}
		}
	}
	return 0;
}
