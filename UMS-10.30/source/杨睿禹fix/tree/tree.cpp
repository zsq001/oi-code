#include<cstdio>
#include<algorithm>
#include<iostream>
#define N 2000100
#define M 5050
using namespace std ;
struct node{
	long long father,num,sum_of_son,num_of_son,son[M];
}tree[M];
void add(long long x,long long a){
	for(long long i=1;i<=tree[x].num_of_son;i++){
		tree[tree[x].son[i]].num+=a;
		add(tree[x].son[i],a);
	}
}
long long n,m;
int main(){
	std::ios::sync_with_stdio(false);
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>tree[i].num;
	}
	for(long long i=1;i<n;i++){
		long long u,v;
		cin>>u>>v;
		tree[u].num_of_son++;
		tree[u].son[tree[u].num_of_son]=v;
		tree[v].father=u;
	}
	for(long long i=1;i<=m;i++){
		long long op;
		cin>>op;
		if(op==1){
			long long x,a;
			cin>>x>>a;
			tree[x].num+=a;
		}
		if(op==2){
			long long x,a;
			cin>>x>>a;
			tree[x].num+=a;
			add(x,a);
		}
		if(op==3){
			long long x,ans=0;
			cin>>x;
			for(long long i=x;i;i=tree[i].father){
				ans+=tree[i].num;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
} 
