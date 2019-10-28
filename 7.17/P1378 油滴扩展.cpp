#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define mmm 100
using namespace std;
double xa,ya,xb,yb,ansss,x[mmm],y[mmm],s[mmm],r[mmm];
int n;
double ban(int i)
{
	double s1=min(abs(x[i]-xa),abs(x[i]-xb));
	double s2=min(abs(y[i]-ya),abs(y[i]-yb));
	double ans=min(s1,s2);
	for(int j=1;j<=n;j++)
	if(i!=j&&s[j])
	{
		double now=sqrt(pow((x[i]-x[j]),2)+pow(y[i]-y[j],2));
		ans=min(ans,max(now-r[j],0.0));
	}
	return ans;
}
void dfs(int k,double tot)
{
	if(k>n)
	{
		ansss=max(ansss,tot);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!s[i])
		{
			r[i]=ban(i);
			s[i]=1;
			dfs(k+1,tot+pow(r[i],2)*3.1415926535);
			s[i]=0;
		}
	}
}
int main()
{
	double ss;
	cin>>n;
	cin>>xa>>ya>>xb>>yb;
	ss=abs(xa-xb)*abs(ya-yb);
	for(int i=1;i<=n;i++)
	cin>>x[i]>>y[i];
	dfs(1,0);
	printf("%d",int(ss-ansss+0.5));
	return 0;
}
