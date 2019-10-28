#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define maxn 100010
typedef int int_;
#define int long long
using namespace std;
int n,num1,num2;
double l,r,a[maxn], ans[5],val,anss;
const int eps=1e-8;
double check(double x){
	num1=0,num2=0,val=0;
	ans[1]=0,ans[2]=0;
	for(int i=1;i<=n;i++){
		val=max(val,fabs(a[i]-x));
		if(a[i]-x>0){
			ans[2]=0,num2=0;
			if(ans[2]) val=max(val,fabs(ans[2]-num2*x));
			ans[1]+=a[i],num1++;
		}
		if(a[i]-x<0){
			ans[1]=0,num1=0;
			if(ans[1]) val=max(val,fabs(ans[1]-num1*x));
			ans[2]+=a[i],num2++;
		}
		
		//printf("%lf\n",val);
	}
	//printf("num1=%d num2=%d val=%lf\n",num1,num2,val);
	return val;
}
int_ main(){
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lf",&a[i]);
	}
	l=-999999;
	r=999999;
	while(r-l>eps){
		double mid=(l+r)/2;
		double mmid=(mid+r)/2;
		//puts("1111111111");
		if(check(mid)>check(mmid)) l=mid+1e-6;
		else r=mmid-1e-6;
		printf("l=%lf r=%lf\n",l,r);
	}
	printf("%lf",check(l));
}
