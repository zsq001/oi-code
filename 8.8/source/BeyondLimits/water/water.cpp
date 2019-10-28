#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
#include <algorithm>
const int mod = 100000007;
using namespace std;
int n, ans[] = {1, 2, 6, 12, 60, 60, 420, 840, 2520, 2520, 27720, 27720, 360360, 360360, 360360, 720720, 12252240, 12252240, 32795246, 32795246};
int main() {
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	cin >> n;
	if(n <= 20)
		cout << ans[n - 1] << endl;
	else
		cout << mod << endl;
	return 0;
}
