#include <cstdio>
#include <algorithm>
#define maxn 200010
using namespace std;

int hh[maxn],den[maxn];
int main() {
	freopen("sheep.in","r",stdin);
	freopen("sheep.out","w",stdout);
	int n,M;
	scanf("%d",&n);
	for(int i = 0 ;i < n ;i++)
		scanf("%d",&hh[i]);
	scanf("%d",&M);
	while(M--) {
		int pd,num,c,cnt=0;
		scanf("%d%d",&pd,&num);
		if( pd == 2 ) {
			scanf("%d",&c);
			hh[num] = c;
			den[num] = 0;
			continue;
		}
		int organ=num;
		while(num<n) {
			num += hh[num];
			cnt++;
		}
		den[organ] = cnt;
		printf("%d\n",cnt);
	}
	return 0;
}
