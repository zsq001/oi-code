#include<bits/stdc++.h>
#define maxn 500010
#define inf 1<<29
using namespace std;
typedef long long ll;
int n,m,st[maxn][21],Log2[maxn];
void init(){
	for(int j=1;(1<<j)<=n;++j)
		for(int i=1;i+(1<<j)-1<=n;++i)
			st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]); 
	for(int i=2;i<=n;++i){
		Log2[i]=Log2[i-1];
		if((1<<(Log2[i]+1))==i) Log2[i]++;
	}
}
int query(int l,int r){
	int k=Log2[r-l+1];
	return max(st[l][k],st[r-(1<<k)+1][k]);
}
int main()
{
	int l,r;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%d",&st[i][0]);
	init();
	while(m--){
		scanf("%d%d",&l,&r); 
		printf("%d\n",query(l,r));
	}
	return 0;
}
