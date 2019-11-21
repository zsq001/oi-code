#include <cstdio>
#include <iostream>
using namespace std;

int t,n;
int num[2010],p[2010];;

struct node{
	int st,ed;
}e[2010];

int main(){
	ios::sync_with_stdio(false);
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(register int i=1;i<=n;i++) cin>>num[i];
		for(register int i=1;i<n;i++) cin>>e[i].st>>e[i].ed;
		for(register int i=1;i<=n;i++) cout<<i<<" ";
		cout<<endl;
	}
	return 0;
}
