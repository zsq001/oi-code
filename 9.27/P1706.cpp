#include<iostream>
#include<cstdio>
using namespace std;
int n;
#define mmm 55
int pa[mmm],ju[mmm];
void dfs(int k)
{
	if(k==n)
	{
		for(int i=1;i<=n;i++)
			cout<<"    "<<pa[i];
		cout<<endl;
	}
	for(int i=1;i<=n;i++)
	{
		if(!ju[i])
		{
			ju[i]=1;
			pa[k+1]=i;
			dfs(k+1);
			ju[i]=0;
		}
	}
}
int main()
{
	cin>>n;
	dfs(0);
	return 0;
}
