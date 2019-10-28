#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
#include <queue>
#include <algorithm>
const int MAXN = 1000050;
using namespace std;
struct node {
	int x, y, z;
};
queue<node> q;
int t, n, cnt, f[MAXN], nextt[10][10];
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
void bfs() {
	if(f[n]) {
		cout << f[n] << endl;
		return ;
	}
	q.push((node){1, 0, 0});
	while(!q.empty()) {
		node now = q.front();
		q.pop();
		int x = now.x, y = now.y, z = now.z;
		f[z] = min(f[z], y);
		for(int i = 1; i <= 4; i++) {
			int dx = nextt[x][i];
			if(z + dx < n)
				q.push((node){dx, y + 1, z + dx});
			else if(z + dx == n) {
				printf("%d\n", y + 1);
				return ;
			}
		}
	}
}
void init() {
	while(!q.empty())
		q.pop();
}
int main() {
	freopen("dice.in", "r", stdin);
	freopen("dice.out", "w", stdout);
	t = read();
	for(int i = 1; i <= 6; i++) {
		for(int j = 6; j >= 1; j--) {
			if(i != j && i + j != 7)
				nextt[i][++cnt] = j;
		}
		cnt = 0;
	}
	while(t--) {
		n = read();
		bfs();
		init();
	}	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
