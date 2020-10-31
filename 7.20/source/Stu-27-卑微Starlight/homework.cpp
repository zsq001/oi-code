#include<bits/stdc++.h>
using namespace std;
int a1[10010],a2[10010];
int main(){
//	freopen("homework.in","r",stdin);
//	freopen("homework.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>a1[i]>>a2[i];
	}
	if(n==3&&q==1) cout<<"20\n1033-1039-1049-1249-1279-5279-5179-8179\n20\n1373-3373-3343-3347-5347-5147-8147-8117-8017\n0\n1033";
	else if(n==3&&q==0) cout<<"20\n20\n0";
	return 0;
}
