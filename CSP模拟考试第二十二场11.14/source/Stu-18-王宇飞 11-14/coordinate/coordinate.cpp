#include<iostream>
#include<cstdio>
using namespace std;
const int mo=1e9+7;
int f[1000009],p[1000009];
int main () {
	freopen("coordinate.in","r",stdin);
	freopen("coordinate.out","w",stdout);
	int n;
	cin>>n;
	f[1]=3;
	for(int i=2;i<=n;i++){
		p[i]=(i-1)*2-1;
		f[i]=(p[i]*3+(f[i-1]-p[i])*2)%mo;
	}
	cout<<f[n];
	return 0;
}
