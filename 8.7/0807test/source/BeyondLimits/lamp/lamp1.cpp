#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int a[1000], u, cnt;
int main() {
	//for(int i = 1; i <= (1 << k); i++) {
	u = 1;
	for(int l = 0; l < 4; l++) {
			a[++cnt] = u << (l + 1);
			u >>= 1;
		}
	//}
	for(int i = 1; i <= cnt; i++)
		cout << a[i];
	return 0;
}
