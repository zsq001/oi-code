#include <cstdio>
#include <set>
#include <cstring>
#include <algorithm>
#include<iostream>
using namespace std;
typedef long long ll;
#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=2e5+5;
ll a[N],s[N][2];

int main()
{
	freopen("square.in","r",stdin);
	freopen("square.out","w",stdout);
	int n;
	cin>>n;
	rep(i,1,n)scanf("%lld",a+i);
	rep(i,1,n)
	rep(j,0,1)s[i][j]=s[i-1][j]+(i%2==j)*a[i];
	ll ans=0;
	rep(i,1,n)
	if(s[i-1][1]-s[i-1][0]-(s[n][1]-s[i][1]-s[n][0]+s[i][0])==0)++ans;
	cout<<ans;
}
