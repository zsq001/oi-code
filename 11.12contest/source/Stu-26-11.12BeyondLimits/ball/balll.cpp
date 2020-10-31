#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
using namespace std;
int n, cnt;
string s;
bool check() {
	for(int i = 0; i < (int)s.length(); i++) {
		if(s[i] == 'B')
			return false;
	}
	return true;
}
int main() {
	cin >> n >> s;
	while(!check()) {
		int pos = -1;
		for(int i = 0; i < (int)s.length(); i++){
			if(s[i] == 'B') {
				pos = i;
				break;
			}
		}
		if(pos == -1)
			break;
		for(int i = 0; i <= pos; i++)
			s[i] == 'R' ? s[i] = 'B' : s[i] = 'R';
		++cnt;
	//	cout << s << endl;
	}
	cout << cnt << endl;
	return 0;
}
