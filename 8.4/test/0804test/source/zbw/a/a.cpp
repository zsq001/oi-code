#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
#define maxn 200010
typedef int int_;
#define int long long
struct A{
	int val,id;
}a[maxn];
int n,m,cnt,v[maxn],ans;
bool cmp(A x,A y){
	return x.val>y.val;
}
signed main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i].val);
		a[i].id=i;
	}
	if(2*m>n){
		puts("Error!");
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	cnt=1;
	while(m){
		if(!v[a[cnt].id]){
			m--;
			if(a[cnt].id==1) v[n]=1;
			if(a[cnt].id==n) v[1]=1;
			ans+=a[cnt].val;
			v[a[cnt].id+1]=v[a[cnt].id-1]=v[a[cnt].id]=1;
		}
		cnt++;
	}
	printf("%lld",ans);
}
