#include<iostream>
#include<cstdio>
using namespace std;
const double eps=1e-4;
double a,b,c,d,L,l,r,mid;
double f(double x) 
{
	return x*x*x*a+x*x*b+x*c+d;
}
int main ()
{
	cin>>a>>b>>c>>d;
	for(L=-100;L<=100;L++)
	{
		l=L;
		r=l+1;//绝对值大于1 
		if(f(l)==0)
		{	
			printf("%.2f ",l);
			continue;
		}
		if(f(l)*f(r)<0)
		{
			while(r-l>eps)
			{
				mid=(l+r)/2;
				if(f(mid)*f(r)<=0)
				l=mid;
				else
				r=mid;
			}
			printf("%.2f ",l);
		}
	}
	return 0;
} 
