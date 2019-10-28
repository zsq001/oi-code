#include<bits/stdc++.h>
#define maxn 100010 
using namespace std;
typedef long long ll;
ll n,m,a[maxn];
void update(int l,int r){
	for(int i=l;i<=r;++i)
		a[i]=sqrt(a[i]); 
}
ll query(int l,int r){
	ll ret=0;
	for(int i=l;i<=r;++i)
		ret+=a[i];
	return ret;
}
int main()
{
	freopen("sculpture.in","r",stdin);
	freopen("sculpture.out","w",stdout);
	int op,l,r;
	cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    cin>>m;
	while(m--){
		cin>>op>>l>>r;
		if(l>r) swap(l,r); 
		if(op==0) update(l,r);
		else cout<<query(l,r)<<endl;
	}
	return 0;
} 
