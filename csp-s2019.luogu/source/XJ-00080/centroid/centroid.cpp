#include<iostream>
#include<cstdio>
using namespace std;
int a[1001];
int main()
{
	freopen("centroid.in","r",stdin);
	freopen("centroid.out","w",stdout);
	int i,T=0,S=0,total=0;
	for(i=0;i<T*S;i++)
	{
		cin>>a[i];
	}
	for(i=0;i<T*S;i++)
	{
		total+=a[i];
	}
	for(i=0;i<T;i++)
	cout<<total<<endl;
	return 0;
}
