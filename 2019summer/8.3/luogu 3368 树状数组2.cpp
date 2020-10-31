#include<cstdio>
#include<iostream>
using namespace std;
int n,m,tree[500010];
void update(int x,int k){for(int i=x;i<=n;i+=i&-i) tree[i]+=k;}
int query(int x){
	int ret=0;
	for(int i=x;i;i-=i&-i) ret+=tree[i];
	return ret;
}
int main()
{
	int op,x,y,k;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>x;
		update(i,x);
		update(i+1,-x);
	}
	while(m--){
		cin>>op>>x;
		if(op==1){
			cin>>y>>k;
			update(x,k);
			update(y+1,-k);
		}
		else cout<<query(x)<<endl;
	}
	return 0;
}
