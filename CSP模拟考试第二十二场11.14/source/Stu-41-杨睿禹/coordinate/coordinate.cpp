#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<stack>
#include<queue>
#define N 500100
#define M 5010
#define P 510
#define oo 1000000007
using namespace std ;
int up[N],lr[N];
int n;
int main(){
	std::ios::sync_with_stdio(false);
	freopen("coordinate.in","r",stdin);
	freopen("coordinate.out","w",stdout);
	cin>>n;
	up[0]=1,lr[0]=0;
	for(int i=1;i<=n;i++){
		up[i]=up[i-1]+lr[i-1];
		up[i]%=oo;
		lr[i]=up[i-1]*2+lr[i-1];
		lr[i]%=oo;
	}
	cout<<(up[n]+lr[n])<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
