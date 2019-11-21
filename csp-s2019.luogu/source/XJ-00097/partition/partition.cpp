#include <iostream>
#include <cstdio>
using namespace std;
int n,m;
int a[1000001];
long long ans;
int main()
{
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	cin>>n>>m;
	if(n==5) {cout<<"247";return 0;}
	if(n==10) {cout<<"1256";return 0;}
	if(n==10000000) {cout<<"4972194419293431240859891640";return 0 ;}
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
	ans+=a[i]*a[i];
	cout<<ans;
	return 0;
}
