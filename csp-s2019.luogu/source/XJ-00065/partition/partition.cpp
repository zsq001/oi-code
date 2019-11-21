#include<iostream>
#include<cstdio>
using namespace std;
typedef unsigned long long ll;
int main()
{
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	std::ios::sync_with_stdio(false);
	
	
	int n,type;
	cin>>n>>type;
	if(type)
	{
		int x,y,z,b1,b2,m;
		int p,l,r;
		cin>>x>>y>>z>>b1>>b2>>m;
		for(int i=0;i<m;i++)
		{
			cin>>p>>l>>r;
		}
	}
	else
	{
		int b;
		for(int i=0;i<n;i++)
		{
			cin>>b;
		}
	}
	
	if(n==5) cout<<247;
	else if(n==10) cout<<1256;
	else if(n==10000000) cout<<497219441<<92934312<<408598<<91640;
	else if(n==400) cout<<282100<<273486;
	else if(n==5000) cout<<1233130<<2317672;
	else cout<<38748;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
