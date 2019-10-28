#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define mmm 500000
using namespace std;
int a[mmm],bb[mmm];
int main()
{
	freopen("coffee.in","r",stdin);
	freopen("coffee.out","w",stdout);
	int e,n,h,b;
	while(cin>>n>>h>>b>>e)
	{
		memset(a,0,sizeof(a));
		memset(bb,0,sizeof(bb));
		bb[1]=1;
		for(int i=1;i<=n;i++)
		cin>>a[i];
		int bu=1;
		for(int i=2;i<=n;i++)
		{
			if(a[bu]<a[i]&&(i-bu)<=h)
			{
				bb[bu]++;
			}
			else 
			{
				bu=i;
				bb[bu]++;
			}
		}
		for(int i=b;i<=e;i++)
			cout<<bb[i]<<" ";
		cout<<endl;
	}
	return 0;
}
