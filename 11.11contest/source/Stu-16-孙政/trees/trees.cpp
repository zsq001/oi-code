#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("trees.in","r",stdin);
	freopen("trees.out","w",stdout);
	int T;
	cin>>T;
	int N,K;
	while(T--){
		cin>>N>>K;
		int o=N-1;
		while(o--){
			int ai;
			cin>>ai;
		}
		if(K%2!=0)
			cout<<(K/2)+1<<endl;
		else
			cout<<K/2<<endl;
		
	}
	return 0;
}
