#include<cstdio>
#include<iostream>
#include<cmath>
#define mmm 1000000
typedef int int_;
#define int long long
int num[mmm];
const int mod =1000003;
using namespace std;
struct node{
	int x, y;
}a[mmm];
int ans=0;
int hash1(int x)
{
	return x%mod;
}
int find(int x)
{
	int y=hash1(abs(x));
	while(a[y].x and a[y].x!=x)
		y=hash1(++y);
	return y;
}
int check(int x)
{
	return a[find(x)].y;
}
int push(int x)
{
	int y=find(x);
	a[y].y++,a[y].x=x;
	return y;
}
int_ main()
{
	int n,c;
	cin>>n>>c;
	for(int i=1;i<=n;i++)
		cin>>num[i],push(num[i]);
	for(int i=1;i<=n;i++)
		ans+=check(num[i]-c);
	cout<<ans<<endl;
	return 0;
}
