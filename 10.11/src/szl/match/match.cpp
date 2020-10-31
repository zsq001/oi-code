#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define maxn (100100)

using namespace std;

int n, m, x, y, b, idx(1), ans;
int a[maxn];

int main() {
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	
	scanf("%d %d %d %d",&n,&m,&x,&y);
	for(int i=1; i<=n; i++) scanf("%d",&a[i]);
	for(int i=1; i<=m; i++) {
		scanf("%d",&b);
		while(idx<=n && a[idx]+y<b) idx++;
		if(idx<=n && a[idx]-x<=b) {
			idx++;
			ans++;
		}
	}
	printf("%d\n",ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
