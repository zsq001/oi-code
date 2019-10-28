#include<iostream>
#define mmm 500010
using namespace std;
int st[mmm][21],n,m,Log2[mmm];
void init()
{
	for(int j=1;(1<<j)<=n;j++)
	for(int i=1;i+(1<<j)-1<=n;i++)
	st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	for(int i=2;i<=n;i++)
	{
		Log2[i]=Log2[i-1];
		if((1<<(Log2[i]+1))==i)
		Log2[i]++;
	}
}
int query(int l,int r)
{
	int k=Log2[r-l+1];
	return max(st[l][k],st[r-(1<<k)+1][k]);
}
int main()
{
	int l,r;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>st[i][0];
	init();
	while(m--)
	{
		cin>>l>>r;
		cout<<query(l,r)<<endl;
	}
	return 0;
} 
