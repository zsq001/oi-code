#include<iostream> 
#include<cstdio>
using namespace std;
typedef int int_;
#define int double
const int eps=1e-7;
const int_ mmm=10086;
int n,j,xs[mmm],l,r;
int f(int x)
{
	int ret=0;
	for(int_ i=0;i<=n;i++)
	{
	 	int cf=1;
		for(int_ j=1;j<=i;j++)
		cf*=x;
		ret+=xs[i]*cf;
	}
	return ret;
}
int_ main()
{
	cin>>n>>l>>r;
	for(int_ i=n;i>=0;i--)
	cin>>xs[i];
	while(r-l>eps)
	{
		double mid=(l+r)/2.0;
		double mmid=(mid+r)/2.0;
		if(f(mid)>f(mmid))
		r=mmid;
		else l=mid;
	}
	printf("%.5lf",l);
	return 0;
}
