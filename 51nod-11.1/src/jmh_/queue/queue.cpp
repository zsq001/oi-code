#include<cstdio>
#include<algorithm>
using namespace std;

int l[50050];
int maxn;
int n;

int main()
{
	freopen("queue.in","r",stdin);
	freopen("queue.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int tp;
		scanf("%d",&tp);
		l[tp]=l[tp-1]+1;
	    maxn=max(maxn,l[tp]);
	}
	printf("%d",n-maxn);
	return 0;
}
