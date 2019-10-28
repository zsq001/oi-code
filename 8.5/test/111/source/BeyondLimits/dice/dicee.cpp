#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
#include <queue>
#include <algorithm>
const int INF = 1 << 30;
const int MAXN = 1000050;
using namespace std;
priority_queue<int> q;
int t, n, cnt, f[MAXN], nextt[10][10], cntt[10][10];
int read() {
	int x = 0;
	bool sign = false;
	char alpha = 0;
	while(!isdigit(alpha)) {
		sign |= alpha == '-';
		alpha = getchar();
	}
	while(isdigit(alpha)) {
		x = (x << 1) + (x << 3) + (alpha ^ 48);
		alpha = getchar();
	}
	return sign ? -x : x;
}
void init() {
	memset(f, 127, sizeof(f));
	f[1] = 0;
	f[2] = f[3] = f[4] = f[5] = 1;
}
void dp() {
	for(int i = 6; i <= n; i++) {
		for(int j = 1; j <= 6; j++) {
			for(int k = 1; k <= 6; k++) {
				if(i - nextt[j][k] >= 1)
					q.push(-(f[i - nextt[j][k]] + cntt[j][nextt[j][k]])); 
			}
		}
		f[i] = -q.top();
		while(!q.empty())
			q.pop();
	}
}
int main() {
	//freopen("dice.in", "r", stdin);
	//freopen("dice2.out", "w", stdout);
	t = read();
	for(int i = 1; i <= 6; i++) {
		for(int j = 1; j <= 6; j++) {
			if(i != j && i + j != 7){
				nextt[i][j] = j;
				cntt[i][j] = 1;
			}
			else {
				nextt[i][j] = INF;
				if(i != j)
					cntt[i][j] = 2;
			}
		}
		cnt = 0;
	}
	while(t--) {
		init();
		n = read();
		dp();
		cout << f[n] << endl;
	}	
	return 0;
}
