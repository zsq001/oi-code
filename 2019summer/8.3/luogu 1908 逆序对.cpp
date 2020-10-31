#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct P{
	int num,pos;
}a[500010];
ll now,n,ans,tree[500010];
bool cmp(P x,P y){return x.num<y.num;}
void add(int x){for(;x<=n;x+=x&-x) ++tree[x];}
ll query(int x){
	ll ret=0;
	for(;x;x-=x&-x) ret+=tree[x];
	return ret;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i].num;
		a[i].pos=i;
	}
	sort(a+1,a+n+1,cmp);
	now=1;
	for(int i=1;i<=n;++i){
		if(a[i].num!=a[i-1].num)
			while(now<i)
				add(a[now++].pos);
		ans+=query(n)-query(a[i].pos);
	}
	cout<<ans<<endl;
	return 0;
}
