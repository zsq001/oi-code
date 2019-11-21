#include <cstdio>
#include <iostream>
using namespace std;

const int maxn=1e5+5;
int n,type,x,y,z,b1,b2,m;
int a[5*maxn],p[maxn],l[maxn],r[maxn];
unsigned long long ans=0;

int main(){
	ios::sync_with_stdio(false);
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	cin>>n>>type;
	if(!type) for(register int i=1;i<=n;i++) cin>>a[i];
	else{
	  cin>>x>>y>>z>>b1>>b2>>m;
		for(register int i=1;i<=m;i++) cin>>p[i]>>l[i]>>r[i];
	}
	cout<<ans;
}
