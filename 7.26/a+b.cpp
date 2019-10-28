#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
char sa[210]={0},sb[210]={0};
int a[210]={0},b[210]={0};
int main()
{
	int i,j=0;
	cin>>sa;	
	a[0]=strlen(sa);
	for(i=1;i<=a[0];i++)
		a[i]=sa[a[0]-i]-48;
	cin>>sb;
	b[0]=strlen(sb);
	for(i=1;i<=b[0];i++)
		b[i]=sb[b[0]-i]-48;
	if(a[0]<b[0])
		a[0]=b[0];
	for(i=1;i<=a[0];i++)
		a[i]+=b[i];
	for(i=1;i<=a[0];i++)
	{
		a[i+1]+=a[i]/10;
		a[i]%=10;
	}
	if(a[a[0]+1])
		a[0]++;
	for(i=a[0];i>=1;i--)
	{
		if(a[i]!=0)j++;
		if(j!=0)cout<<a[i];
	}
	if(j==0)
		cout<<0;
	return 0;
}
