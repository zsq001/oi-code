#include<stdio.h>
typedef int int_;
#define int long long
int find(int n){
	if(n==1) return 1;
	else return 1+find(n-((n+1)>>1));
}
int_ main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int n;
	scanf("%lld",&n);
	printf("%lld",find(n));
	return 0;
}
