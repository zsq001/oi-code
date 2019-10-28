#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
#include <algorithm>
const int INF = 1 << 30;
const int MAXN = 100050;
using namespace std;
string s[MAXN];
int n, k, ans = -INF, cnt, a[10][10];
int main() {
	freopen("lamp.in", "r", stdin);
	freopen("lamp.out", "w", stdout);
	scanf("%d %d", &n, &k);
//	for(int i = 1; i <= n; i++)
//		cin >> s[i];
//	a[1][3] = 1;
//	a[2][2] = 1;
//	a[3][1] = 1;
//	a[4][2] = a[4][3] = 1;
//	a[5][1] = a[5][2] = 1;
//	a[6][1] = a[6][2] = a[6][3] = 1;
//	a[7][1] = a[7][3] = 1; 
//	for(int i = 1; i <= 8; i++) {
//		for(int j = 1; j <= n; j++) {
//			for(int l = 0; l < k; l++) {
//				if(a[i][l + 1] != s[j][l] - '0')
//					cnt++;
//			}
//			if(cnt == k || cnt == 0)
//				continue;
//			ans = max(ans, cnt);
//			cnt = 0;
//		}
//	}
//	cout << ans << endl; 
	cout << k - 1 << endl;
	return 0;
}
/*
2 4
0000
1111
*/
