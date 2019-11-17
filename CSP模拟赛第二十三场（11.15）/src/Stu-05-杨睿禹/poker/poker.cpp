#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>
#include<queue>
typedef int int_;
#define int long long
#define N 50010
#define M 5010
#define P 510
#define oo 1000000007
using namespace std ;
int n,m,a[N];

bool cmp(int x,int y){
	return x<=y;
}

int_ main(){
	std::ios::sync_with_stdio(false);
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1,cmp);
	if(m>=a[2])
		cout<<a[1]+a[2]<<endl;
	else 
		cout<<a[1]+m<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
