#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define hash(a) a%p
const int p=10000003;
typedef int int_;
#define int long long 
int h[100000];
int find(int x)
{
	int y=abs(x);
	while(h[y] and h[y]!=y)
		h[y]=hash(++y);
	return y;
}
int push(int x)
{
	h[find(x)]=x;
}
bool check(int x)
{
	return h[find(x)]==x;
}
int_ main()
{
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n;
		cin>>n;
		memset(h,0,sizeof(h));
		for(int i=1;i<=n;i++)
		{
			int x;
			cin>>x;
			if(!check(x))
			{
				cout<<x<<" ";
				push(x);
			}
		}
		cout<<endl;
	}
	return 0;
}
