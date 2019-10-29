#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
double ans;

struct node {
	double a, t;
}rul[100005], Mrul[100005];

int cmp(const node s1, const node s2) {
	return s1.a > s2.a;
}

double calcc(double v0, double t, double a) {
	return v0 * t + 0.5 * a * t * t;
}

int main() {
	freopen("physics.in", "r", stdin);
	freopen("physics.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%lf%lf", &rul[i].a, &rul[i].t);
		Mrul[i].a = rul[i].a;
		Mrul[i].t = rul[i].t;
	}
	sort(Mrul + 1, Mrul + 1 + n, cmp);
	double last = 0;
	for(int i = 1; i <= n; i++) {
		ans = ans + calcc(last, Mrul[i].t, Mrul[i].a);
		last = last + Mrul[i].a * Mrul[i].t;
	}
	last = 0;
	for(int i = 1; i <= n; i++) {
		ans = ans - calcc(last, rul[i].t, rul[i].a);
		last = last + rul[i].a * rul[i].t;
	}
	printf("%.1lf", ans);
	return 0;
}
