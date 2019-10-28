#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
typedef long long ll;

struct edge{
	int l,r;
	ll cnt,sum;
}a[maxn<<4];
ll d[maxn<<4],cnt[maxn<<4];

void pushup(int o){
	a[o].sum=a[o<<1].sum+a[o<<1|1].sum;
	if(a[o<<1].cnt>=7&&a[o<<1|1].cnt>=7) a[o].cnt=7;
} 

void build(int o,int l,int r){
	a[o].l=l;
	a[o].r=r;
	a[o].cnt=0;
	if(l==r){
		a[o].sum=d[l];
	}
	else{
		int mid=(l+r)>>1;
		build(o<<1,l,mid);
		build(o<<1|1,mid+1,r);
		a[o].sum=a[o<<1].sum+a[o<<1|1].sum;
	}
}

void update(int o,int st,int ed){
	int l=a[o].l;
	int r=a[o].r;
	if(cnt[o]>=7){
		a[o].sum=r-l+1;
		return ;
	}
	if(st<=l&&r<=ed){
		a[o].cnt+=1;
		if(l==r){
			a[o].sum=sqrt(a[o].sum);
		}
		else{
			update(o<<1,st,ed);
			update(o<<1|1,st,ed);
			pushup(o);
		}
	}
	else{
		int mid=(l+r)>>1;
		if(st<=mid) update(o<<1,st,ed);
		if(ed>mid) update(o<<1|1,st,ed);
		pushup(o);
	}
}

ll query(int o,int st,int ed){
	int l=a[o].l;
	int r=a[o].r;
	if(st<=l&&r<=ed) return a[o].sum;
	else{
		int mid=(l+r)>>1;
		int sum1=0,sum2=0;
		if(st<=mid) sum1=query(o<<1,st,ed);
		if(ed>mid) sum2=query(o<<1|1,st,ed);
		return sum1+sum2;
	}
}
int main(){
	freopen("sculpture.in","r",stdin);
	freopen("sculpture.out","w",stdout);
	ll n,m,op,x,y,z;
	cin>>n;
	for(int i=1;i<=n;++i) cin>>d[i];
	build(1,1,n);
	cin>>m;
	while(m--){
		cin>>op>>x>>y;
		if(op==0){
			update(1,x,y);
		}
		else if(op==1){
			cout<<query(1,x,y)<<endl;
		}
	}
	return 0;
}
