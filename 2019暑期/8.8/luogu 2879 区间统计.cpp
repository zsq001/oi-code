#include<cstdio>
#include<cmath>
#include<ctime>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#define maxn 1010
#define inf 1<<29
#define base 10000
using namespace std;
typedef long long ll;
map<ll,int>mp;
int n,i,h,m,l,r,sum[10010];
ll cal(int x,int y){return 1ll*10001*x+y;}
int main()
{
	scanf("%d%d%d%d",&n,&i,&h,&m);
	for(int i=1;i<=m;++i){
		scanf("%d%d",&l,&r);
		if(l>r) swap(l,r);
		if(mp[cal(l,r)]) continue;
		mp[cal(l,r)]=1;
		sum[l+1]--;
		sum[r]++;
	}
	for(int i=1;i<=n;++i) sum[i]+=sum[i-1],printf("%d\n",h+sum[i]);
	return 0;
}
