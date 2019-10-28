#include<iostream>
#include<cstdio>
#define mmm 10010
using namespace std;
int a[mmm],b[100]={0,1,2,3,5,10,20};
bool c[mmm]={1};
int main()
{
	int num=0;
	for(int i=1;i<=6;i++)
	{
		int x;
		cin>>x;
		for(int j=1;j<=x;j++)
		a[++num]=b[i];
	}
	for(int i=1;i<=num;i++)
	for(int j=1001;j>=0;j--)
	if(c[j])
	c[j+a[i]]=1;
	int ans=0;
	for(int i=1;i<=1001;i++)
	if(c[i])
	ans++;
	cout<<"Total="<<ans;
	return 0;
}
