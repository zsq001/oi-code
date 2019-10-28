#include<cstdio>
#include<math.h>
#include<algorithm>
typedef int int_;
#define int long long 
using namespace std;
int V,a[100005],t,minn=1e9+7;
void gcd(int x){
	for(int i=1;i<=sqrt(x);i++){
		if(x%i==0)a[++t]=i,a[++t]=x/i;
	}
}
int_ main()
{
	freopen("box.in","r",stdin);
	freopen("box.out","w",stdout);
	scanf("%lld",&V);
	gcd(V);
	/*for(int i=1;i<=t;i++)
		for(int j=i;j<=t;j++){
			if(( V % ( a[i] * a[j] ) == 0 ) && ( V >= (a[i]*a[j]) ) ){
				int A=a[i],B=a[j],C=V/(a[i]*a[j]);
				//if(minn>2*(A*B+A*C+B*C))printf("%d %d %d ",A,B,C);
				minn=min(minn,2*(A*B+A*C+B*C));
			}
		}
	printf("%d",minn);*/
	int A=a[t-1];
	V=a[t],t=0;
	for(int i=1;i<=t;i++)a[i]=0;
	gcd(V);
	int B=a[t-1],C=a[t];
	int ans=2*(A*B+A*C+B*C);
	printf("%lld",ans);
	return 0;
}
