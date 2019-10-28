#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll rnd(){
	return 1ll*rand()*rand();
}
ll down,up,n,m,l,r;
int main()
{
	srand(time(0));
	freopen("sculpture3.in","w",stdout);
	down=1000000000;
	up=1000000000;
	n=100;
	m=100;
	cout<<n<<endl;
	for(int i=1;i<=n;++i){
		cout<<rand()<<" ";
		/*ll x=rand();
		if(x>30000) cout<<0<<" ";
		else if(x>20000) cout<<1<<" ";
		else cout<<x<<" ";*/
	}
	puts("");
	cout<<m<<endl;
	while(m--){
		l=rand()%n+1;
		r=l+rand()%(n-l);
		cout<<rand()%2<<" "<<l<<" "<<r<<endl;
	}
	return 0;
}
