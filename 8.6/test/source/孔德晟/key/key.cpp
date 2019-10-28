#include <cstdio>
#include <algorithm>
#include <cstring>
#define maxn 300010
using namespace std;
char Key[maxn];
int ling[maxn],suml;
int yi[maxn],sumy;
int key[maxn],ans[maxn];
int main() {
	freopen("key.in","r",stdin);
	freopen("key.out","w",stdout);
	int cnt=1;
	scanf("%s",Key+1);
	int l=strlen(Key+1);
	int n=l/3,n2=n<<1;
	for(int i = 1; i <= l; i++) {
		if (Key[i] == '1') {
			key[i] = 1;
			yi[i] = yi[i-1] + 1;
			sumy++;
		} else {
			ling[i] = ling[i-1] + 1;
			suml++;
		}
		if(i != 1 && key[i] != key[i-1]) cnt++;
	}
	if (cnt >= n2) {
		printf("0\n");
		return 0;
	}
	int tot=0;
	if (suml == 0 || sumy == 0) {
		while (cnt < n2) {
			tot++;
			ans[tot]=2*tot;
			cnt+=2;
		}
	}
	while (cnt < n2) {
		for (int i = 1; i <= l; i++) {
			if (yi[i] > 1 && ling[i+1] == 1 && ling[i+2] == 2) {
				ans[++tot] = i;
				key[i] = 0;
				key[i+1] = 1;
				cnt += 2;
			} else if (ling[i] > 1 && yi[i+1] == 1 && yi[i+2] == 2) {
				ans[++tot] = i;
				key[i] = 1;
				key[i+1] = 0;
				cnt += 2;
			} else if (key[i] == 1 && key[i] == key[i-1] && key[i] == key[i+1] && key[i+1] == key[i+2]) {
				ans[++tot] = i;
				key[i] = 0;
				key[i] = 0;
				cnt += 2;
			} else if (key[i] == 0 && key[i] == key[i-1] && key[i] == key[i+1] && key[i+1] == key[i+2]) {
				ans[++tot] = i;
				key[i] = 1;
				key[i] = 1;
				cnt += 2;
			}
			if( cnt >= n2) break;
			if (key[i]) {
				ling[i] = 0;
				yi[i] = yi[i-1] + 1;
			} else {
				yi[i] = 0;
				ling[i] = ling[i-1] + 1;
			}
		}
	}
	printf("%d\n",tot);
	for (int i = 1; i <= tot; i++)
		printf("%d ",ans[i]);
	return 0;
}
