#include<iostream>
using namespace std;
#define mmm 100010
bool vis[mmm];
int main()
{
	freopen("1.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int k=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(++k>n)
			k=1;
			if(vis[k])
			j--;
		}
		printf("%d ",k);
		vis[k]=true;
	}
	return 0;
}
