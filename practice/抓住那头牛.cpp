#include<iostream>
#include<queue> 
using namespace std;
int n,k;
int con[1001000],dis[1001000];
void bfs(int n,int k)
{
	queue<int> q;
	q.push(n);
	con[n]=1;
	while(q.empty()==0)
	{
		int x=q.front() ;
		q.pop() ;
		if(x==k) 
		break; 
		if(x!=0&&con[x-1]==0)
		{
			dis[x-1]=dis[x]+1;
			q.push(x-1);
			con[x-1]=1;
		}
		if(x<=100001&&con[x+1]==0)
		{
			dis[x+1]=dis[x]+1;
			q.push(x+1);
			con[x+1]=1;
		}
		if(x<=100001&&con[2*x]==0)
		{
			dis[2*x]=dis[x]+1;
			q.push(2*x);
			con[2*x]=1; 
		}
	}
}
int main()
{
	cin>>n>>k;
	bfs(n,k);
	cout<<dis[k];
	return 0;
}
