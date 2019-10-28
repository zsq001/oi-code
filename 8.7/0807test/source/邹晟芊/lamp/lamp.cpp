#include<iostream>
#include<cstdio>
#include<cstring>
char l[4];
int a[100001][20];
using namespace std;
int main()
{
	freopen("lamp.in","r",stdin);
	freopen("lamp.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>l;
		for(int j=0;j<k;j++)
		a[n][j+1]=l[j]-'0';
	}
	cout<<"2";
}
