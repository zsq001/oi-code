#include <bits/stdc++.h>
using namespace std;
int p, q, i = 1;
string s;
int main() {
	cin >> s;
	string t = s;
	cin >> p >> q;
	cout << s.substr(p, q) << endl;
	s.erase(0, 0);
	cout << s.substr(p, q) << endl;
	return 0;
}
