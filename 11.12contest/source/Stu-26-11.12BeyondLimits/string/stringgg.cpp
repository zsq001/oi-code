#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
using namespace std;
const int INF = 1 << 30;
int q, n, k, ans = INF;
string s, t, st;
bool flag;
int main() {
	cin >> q;
	while(q--) {
		cin >> n >> s;
		t = s;
		for(int i = 0; i < (int)s.length(); i++) {
			i == 0 ? s.erase(i, i + 1) : s.erase(i, i);
			cout << "s:" << " " << s << endl;
			for(int j = 1; j < n; j++) {
				st.clear();
				st = s.substr(0, j);
				cout << "st:" << " " << st << endl;
				k = 0;
				for(k = j; k < (n - 1) - ((n - 1) % j); k += j) {
					string res;
					res.clear();
					int o = k + j;
					res = s.substr(k, o);
					cout << "res:" << " " << res << endl;
					if(res != st) {
						flag = true;
						break;
					}
				}
				if(!flag) {
					string m, w;
					m.clear();
					w.clear();
					m = s.substr(k, n);
					w = st.substr(0, n - k + 1);
					if(m == w)
						ans = min(ans, j);
				}
				flag = false;
			}
			s = t;
		}
		cout << ans << "\n";
		s.clear();
		t.clear();
	}
	return 0;
}
/*
1
8 wywyxwyw
*/
