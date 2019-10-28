#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int main() {
	freopen("box.in","r",stdin);
	freopen("box.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--) {
		int n,jsum=0,osum=0,a;
		scanf("%d",&n);
		for(int i = 1 ;i <= n ;i++) {
			scanf("%d",&a);
			if( i&1 )
				jsum += a;
			else
				osum += a;
		}
		if( jsum<osum ) swap(jsum,osum);
		printf("%d\n",jsum-osum);
	}
	return 0;
}
