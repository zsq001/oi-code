#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
typedef int intt;
#define int long long
using namespace std;
int xx, yy, m, n, l, x, y, r;
int exgcd(int a, int b, int &x, int &y) {
	if(b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	int d = exgcd(b, a % b, x, y);
	int t = x;
	x = y;
	y = t - a / b * y;
	return d;
}
int Mod(int a, int b) { return (a % b + b) % b; }
intt main() {
	freopen("toad.in", "r", stdin);
	freopen("toad.out", "w", stdout);
	cin >> xx >> yy >> m >> n >> l;
	if(m - n < 0) {
		swap(m, n);
		swap(yy, xx);
	}
	int gcd = exgcd(m - n, l, x, y);
	if((yy - xx) % gcd != 0) {
		cout << "Impossible" << endl;
		return 0;
	}
	r = (yy - xx) / gcd;
	l /= gcd;
	x = (int)x * r;
	cout << Mod(x, l) << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
