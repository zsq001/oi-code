#include<cstdio>
#include<algorithm>
using namespace std;
typedef int int_;
#define int long long 
int n,ans;

int f(int x){
	if(x==1) return 1;
	int a=(x+1)/2;
	return f(x-a)+1;
}


int_ main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);																																																																												
	scanf("%lld",&n);
    ans=f(n);
    printf("%lld",ans);
    return 0;
}
