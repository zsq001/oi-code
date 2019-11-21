#include <bits/stdc++.h>
const int MAXN = 101;
using namespace std;
string s[30][5050];
int n, k;
int main() {
	freopen("code.in", "r", stdin);
	freopen("code.out", "w", stdout);
	cin >> n >> k;
	s[1][0] = "0";
	s[1][1] = "1";
	for(int i = 2; i <= n; i++) {
		int pos, cnt;
		pos = cnt = (int)pow(2, i - 1);
		for(int j = 0; j < cnt; j++) {
			string t = s[i - 1][j];
		//	cout << t << endl;
			reverse(t.begin(), t.end());
		//	cout << t << endl;
			s[i][j] = t + '0';
		//	cout << s[i][j] << endl;
			reverse(s[i][j].begin(), s[i][j].end());
		//	cout << s[i][j] << endl;
		}
		pos --;
		for(int j = cnt; j < (cnt << 1); j++) {
			string t = s[i - 1][pos];
			reverse(t.begin(), t.end());
			s[i][j] = t + '1';
			reverse(s[i][j].begin(), s[i][j].end());
			pos--;
		}
	}
//	for(int i = 0; i < (int)pow(2, n); i++)
//		cout << s[n][i] << "\n";
	cout << s[n][k] << "\n";
	return 0;
}
