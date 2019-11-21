#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int n;
long long k;

inline int f(int n,long long k){
	int ans[70];
	long long n1,n2,n3=n;
	for(register int i=0;i<n;i++){
		n1=pow(2,n3);
		n2=pow(2,n3-1);
		if(k>n2-1){
		  ans[i]=1;
		  k=n1-1-k;
		}
		else if(k<=n2-1) ans[i]=0;
		n3--;
	}
	for(register int i=0;i<n;i++) cout<<ans[i];
}

int main(){
	ios::sync_with_stdio(false);
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	cin>>n>>k;
	f(n,k);
	return 0;
}
