#include<iostream>
#include<cstdio>
#define mmm 120
using namespace std;
int a[400],b[5],c[mmm][mmm][mmm][mmm];
int main()
{
	int n,m,ans=-1,val;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		int c;
		cin>>c;
		b[c]++;
	}
	c[0][0][0][0]=a[1];
	for(int q=0;q<=b[1];q++)
	for(int w=0;w<=b[2];w++)
	for(int e=0;e<=b[3];e++)
	for(int r=0;r<=b[4];r++)
	{
		ans=-1;
		if(q==r&&w==e&&e==r&&r==0)
		continue;
		val=q+1+2*w+3*e+4*r;
		if(q!=0)
		ans=max(ans,c[q-1][w][e][r]+a[val]);
		if(w!=0)
		ans=max(ans,c[q][w-1][e][r]+a[val]);
		if(e!=0)
		ans=max(ans,c[q][w][e-1][r]+a[val]);
		if(r!=0) 
		ans=max(ans,c[q][w][e][r-1]+a[val]);
		c[q][w][e][r]=max(c[q][w][e][r],ans);
	}
	cout<<c[b[1]][b[2]][b[3]][b[4]];
	return 0;
}
