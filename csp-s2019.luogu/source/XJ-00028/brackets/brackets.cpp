#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> G[500010];
stack<int> Left;
int N;
long long sum, ans[500010];
const bool LEFT = false, RIGHT = true;
bool C[500010], vis[500010];
string S;

void DFS(int num, bool l, long long cLeft, long long cRight){
	if (cLeft == cRight)
		ans[num]++;
	for (int i = 0; i < G[num].size(); i++){
		int to = G[num][i];
		if (!vis[to] && C[to]^l){
			vis[to] = true;
			if (l == LEFT)
				DFS(to, C[to], cLeft, cRight + 1);
			else if (l == RIGHT)
				DFS(to, C[to], cLeft + 1, cRight);
			vis[to] = false;
		}
	}
	return;
}

int main(){
	freopen("brackets.in", "r", stdin);
	freopen("brackets.out", "w", stdout);
	memset(C, 0, sizeof(C));
	memset(vis, 0, sizeof(vis));
	memset(ans, 0, sizeof(ans));
	S.clear();
	while (!Left.empty()) Left.pop();
	cin >> N; for (int i = 0; i <= N; i++) G[i].clear();
	cin >> S;
	for (int i = 1, x; i <= N; i++){
		if (i != 1){
			cin >> x;
			G[x].push_back(i);
			G[i].push_back(x);
		}
		if (S[i-1] == '('){
			C[i] = LEFT;
			Left.push(i); 
		}
		else if (S[i-1] == ')')
			C[i] = RIGHT;
			
	}
	while (!Left.empty()){
		int last = Left.top();
		Left.pop();
		vis[last] = true;
		DFS(last, LEFT, 1, 0);
		vis[last] = false;
	}
	sum = ans[1];
	for (int i = 2; i <= N; i++){
		sum ^= i*ans[i];
	}
	cout << sum;
	return 0;
}
