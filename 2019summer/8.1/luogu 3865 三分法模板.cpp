#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const double eps=1e-7;
int n;
double xs[15],l,r;
double solve(double x)
{
	double ret=0;
	for(int i=0;i<=n;++i){
		double cf=1;
		for(int j=1;j<=i;++j) cf*=x;
		ret+=xs[i]*cf;
	}
	return ret;
}
int main()
{
	scanf("%d%lf%lf",&n,&l,&r);
	for(int i=n;i>=0;--i) scanf("%lf",&xs[i]);
	while(r-l>eps){
		double mid=(l+r)/2.0;
		double mmid=(mid+r)/2.0;
		if(solve(mid)>solve(mmid)) r=mmid;
		else l=mid;
	}
	printf("%.5lf",l);
	return 0;
}
