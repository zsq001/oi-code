#include<cstdio>
#include<iostream>
using namespace std;
int n,m,tree[500010];
void update(int x,int y) {for(int i=x;i<=n;i+=i&-i) tree[i]+=y;}
int query(int x){
	int ans=0;
	for(int i=x;i;i-=i&-i) ans+=tree[i];
	return ans;
}
int main()
{
	int x,y,op;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>x;
		update(i,x);
	}
	while(m--){
		cin>>op>>x>>y;
		if(op==1) update(x,y);
		else cout<<query(y)-query(x-1)<<endl;
	}
	return 0;
}
