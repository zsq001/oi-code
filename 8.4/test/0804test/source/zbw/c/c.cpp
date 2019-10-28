#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
#define maxn 1000010
typedef int int_;
#define int long long
int n,q,k,now,ans,cnt;
struct H{
	int val,id;
}h[maxn];
bool cmp(H x,H y){
	return x.val<y.val;
}
int_ main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&h[i].val);
		h[i].id=i;
	}
	scanf("%lld",&q);
	while(q--){
		cnt=0,ans=0;;
		scanf("%lld",&k);
		now=1;
		for(int i=2;now!=n;i+=k){
			sort(h+i,h+min(i+k-1,n),cmp);
			if(k==2&&h[i].val>h[i+k-1].val){
				swap(h[i].val,h[i+k-1].val);
			}
			cnt=i;
			if(h[now].val<=h[i].val){
				for(int j=i;j<=i+k-1;j++) now=max(now,h[j].id);
				ans++;
				continue;
			}
			while(h[now].val>h[cnt].val&&cnt<=i+k-1){
				now=max(now,h[cnt].id);
				cnt++;
			}
		}
		printf("%lld\n",ans);
	}
	
}
