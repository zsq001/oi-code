#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
#define maxn 100005
#define inf 1<<30
typedef int int_;
#define int long long
using namespace std;
int v,a[maxn],b[maxn],cnt=1,x,y,z,minn=inf;
int_ main(){
	freopen("box.in","r",stdin);
	freopen("box.out","w",stdout);
	scanf("%lld",&v);
	int mx=(int)sqrt(v);
	a[1]=1;
	for(int i=1;i<=mx;i++) if((v%i)==0) a[++cnt]=i,b[cnt-1]=v/i;
	for(int i=1;i<=cnt-1;i++) a[cnt+i]=b[cnt-i];
	cnt=2*cnt-1;
	for(int i=1;i<=cnt;i++) a[cnt+i]=a[i],a[cnt*2+i]=a[i];
	cnt=3*cnt;
	sort(a+1,a+1+cnt);
	for(int i=1;i<=cnt-2;i++){
		for(int j=i+1;j<=cnt-1;j++){
			if(a[i]*a[j]>v) break;
			for(int k=j+1;k<=cnt;k++){
				x=a[i],y=a[j],z=a[k];
				if(x*y*z==v) {
					int calc=2*(x*y+x*z+y*z);
					if(calc<minn) minn=calc;
					break;
				}	
			}
		}
	}
	printf("%lld %lld",minn,cnt);
	return 0;
}
