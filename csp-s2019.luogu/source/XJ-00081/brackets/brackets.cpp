#include <iostream>
#include <stack>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;

//define
const int maxn = 5e5 + 5;
int n, ans, last_ans;
string ch;

inline bool is_match(string aa){
	stack<int> st;
	int flag = 0;
	for(register int i = 0; i < aa.length(); ++i){
		if(aa[i] == '('){
			st.push(1);
			flag = 1;
		}
		if(aa[i] == ')'){
			if(st.empty())return false;
			st.pop();
		}
	}
	if(st.empty() && flag == 1){
		return true;
	}
	else return false;
}

inline string substrs(int pos1, int pos2){
	string res;
	for(register int i = pos1; i <= pos2; ++i){
		res.push_back(ch[i]);
	}
	return res;
}

//main
int main(){
	ios::sync_with_stdio(false);
	freopen("brackets.in", "r", stdin);
	freopen("brackets.out", "w", stdout);
	cin >> n;
	cin >> ch;
	for(register int i = 1; i < n; ++i){
		int cnt = 0, xorp = i + 1;
		for(register int j = 0; j < i; ++j){
			if(i - j + 1 >= 2)
				if(is_match(substrs(j, i)))cnt++;
		}
		int tmp = last_ans + cnt;
		last_ans = cnt;
		ans = ans^(tmp * xorp);
	}
	cout << ans << endl;
	return 0;
}
