#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue> 
#define maxn 100010
using namespace std;

struct flat {
	int height;
	double kxie;
}f[maxn];
double kx[maxn];
int QAQ[maxn];

int main() {
	freopen("building.in","r",stdin);
	freopen("building.out","w",stdout);
	int n,m,mimi=0;
	scanf("%d%d",&n,&m);
	for(int i = 1 ;i <= m ;i++) {
		int cnt=0,x,y;
		double view=0,ax=0;
		scanf("%d%d",&x,&y);
		mimi=max(mimi,x);
		f[x].height = y;
		f[x].kxie = f[x].height*1.0/x*1.0;
		for(int i = 1 ;i <= mimi ;i++) {
			if( f[i].height == 0) continue;
			if( f[i].kxie > ax ) cnt++;
			ax = max(ax,f[i].kxie);
		}
		printf("%d\n",cnt); 
	}
	return 0;
}
