#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long find(int n){
	if(n==1)return 1;
	return find(n/2)+1;
}
int main(){
	long long n;
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%lld",&n);
	printf("%lld",find(n));
}
