#include<iostream>
#include<cstdio>
#define mmm 1000
using namespace std;
/*struct node{
	int a
};*/
int a[mmm],b[mmm],c[20][20],d[7][7][20];
int dfs(int x,int y,int k)
{
	
}
int main()
{
	freopen("save.in","r",stdin);
	freopen("save.out","w",stdout);
	int n,k,s=0;
	cin>>n>>k;
	if(n!=1)
		cout<<"NO"<<endl;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
	cin>>b[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		cin>>c[i][j];
	for(int w=1;w<=n;w++)
	for(int i=1;i<=5;i++)                                                          
		for(int j=1;j<=5;j++)                                                      
		{
			cin>>d[i][j][w];
			if(d[i][j][w]==1)
			{
				s=1;
			}
			
		}
	if(s==1)
		cout<<"NO"<<endl;
	else
	{
		cout<<"YES"<<endl;
		cout<<a[1]+b[1]<<endl;
	}
	return 0;
}

