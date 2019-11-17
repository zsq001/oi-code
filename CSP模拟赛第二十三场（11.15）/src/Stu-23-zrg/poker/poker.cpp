#include<stdio.h>
#include<algorithm>
#include<string.h>
typedef int int_;
#define int long long
#define maxn 1005
using namespace std;
template <class T> void read(T &x){
	x=0;bool f=0;char s=getchar();
	while(s<'0'||s>'9') { if(s=='-') f=1;s=getchar();}
	while(s>='0'&&s<='9') { x=(x<<3)+(x<<1)+(s^48); s=getchar();}
	x=f?-x:x;
}
int a[maxn],n,m,f[maxn];
bool chack(int x){
	for(int i=1;i<=n;i++) f[i]=0;
	int sum=0,w;
	for(int i=1;i<=n;i++){
		w=x-a[i];
		if(w<=0) break;
		sum+=w;
		f[i]=w;
	}
	if(sum>m) return 0;
	for(int i=1;i<=n;i++)
		if(sum-f[i]>a[i]) return 0;
	return 1;
}
int_ main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+n+1);
	int l=a[1],r=a[n];
	while(l<=r){
		int mid=l+((r-l)>>1);
		if(chack(mid)) l=mid+1;
		else r=mid-1;
	}
	printf("%lld",r);
	return 0;
}
