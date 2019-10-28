#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>

const int mod = 1000000007;

using namespace std;

int n, ans = 1, cnt, t;
stack<int> s;

int main() {
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; t + i <= n; i++)
	{
		t += i;
		s.push(i);
		cnt++;
	}
	if(t < n)
	{
		int x = s.top();
		s.pop();
		x += (n - t);
		s.push(x);
	}
	
	int x1, x2, temp;
	for(int i = 1; i < cnt; i++)
	{
		x1 = s.top();
		s.pop();
		x2 = s.top();
		s.pop();
		if((x1 - x2) % 2 == 0) temp = (x1 - x2) / 2;
		else temp = (x1 - x2) / 2 + 1;
		ans = (ans + temp) % mod;
		s.push(x1 + x2);
	}
	printf("%d", ans);
	return 0;
}
