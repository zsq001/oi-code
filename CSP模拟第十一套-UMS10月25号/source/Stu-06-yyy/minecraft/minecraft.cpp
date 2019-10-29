#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

template<class T>void read(T &x){
	x=0; char c=getchar();
	while(c<'0'||'9'<c)c=getchar();
	while('0'<=c&&c<='9'){x=(x<<1)+(x<<3)+(c^48); c=getchar();}
}
typedef long long ll;

int b,n,d,m;
int absl(int x){return x<0?-x:x;}
namespace pt1{
	int p[10050][5],ans;
	bool check(int i,int j){
		int t=0;
		for(int k=1;k<=b;k++)t+=absl(p[i][k]-p[j][k]);
		return t<=d;
	}
	void solve(){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=b;j++)read(p[i][j]);
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(check(i,j))++ans;
			}
		}
		printf("%d\n",ans);
	}
}

namespace pt2{
	int a[100050];
	ll ans;
	void solve(){
		for(int i=1;i<=n;i++)read(a[i]);
		sort(a+1,a+n+1);
		a[n+1]=2147483647;
		int p;
		for(int i=1;i<n;i++){
			if(a[i+1]-a[i]>d)continue;
			p=upper_bound(a+1,a+n+1,a[i]+d)-a;
//			if(a[p-1]<=a[i]+d&&a[i]+d<a[p])
			ans+=p-i-1;
		}
		printf("%lld\n",ans);
	}
}

int main(){
	freopen("minecraft.in","r",stdin);
	freopen("minecraft.out","w",stdout);
	read(b); read(n); read(d); read(m);
	if(n*n<=50000000)pt1::solve();
	else if(b==1)pt2::solve();
	return 0;
}
