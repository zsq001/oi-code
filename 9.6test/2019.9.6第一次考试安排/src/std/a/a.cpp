
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

#define MAXN 333

int N, a[MAXN], b[MAXN];
int T;  

int main() {
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	scanf("%d", &T);
    while(T--) {
    	
        scanf("%d", &N);
        memset(b, 0, sizeof(b));
        
        for(int i = 1; i <= N; i++) {
            scanf("%d", &a[i]);
            b[a[i] % 3]++;
        }
        int ans = b[0];
        int tmp;
        if(b[2]) {
            tmp = min(b[2], b[1]);
            ans += tmp;
            b[2] -= tmp;
            b[1] -= tmp;
        }
        if(b[1]) ans += b[1] / 3;
        if(b[2]) ans += b[2] / 3;
        printf("%d\n", ans);
    }
    return 0;
}
