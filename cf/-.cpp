#include<iostream>
using namespace std;
typedef long long ll;
char cat[4]={'D','A','C','B'};
int main()
{
	ll a;
	cin>>a;
	ll ans=0;
	char r='E';
	for(int i=0;i<3;i++)
	{if(cat[(a+i)%4]<r){
		ans=i;
		r=cat[(a+i)%4];
	}
	}
	cout<<ans<<" "<<r;
}
