#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
map<vector<int>,int>mp;
int n,m,x,ans;
int main()
{
	scanf("%d%d",&n,&m);
	vector<int>now(m);
	mp[now]=0;
	for(int i=1;i<=n;++i){
		scanf("%d",&x);
		for(int j=0;j<m;++j) now[j]+=(x&(1<<j)?1:0)-(x&1);
		if(mp.count(now)) ans=max(ans,i-mp[now]);
		else mp[now]=i;
	}
	printf("%d\n",ans);
	return 0;
}
