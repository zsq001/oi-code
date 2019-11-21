#include <cstdio>
#include <iostream>
using namespace std;
unsigned long long a[5010], s[5010], N, TYPE, ans = 0;
void DFS(int K, unsigned long long lastmax, unsigned long long sum){
	if (K == N){
		if (ans == 0){
			ans = sum;
			return;
		}
		if (sum < ans)
			ans = sum;
		return;
	}
		
	for (int i = K+1; i <= N; i++){
		if (s[i] - s[K] >= lastmax)
			DFS(i, s[i] - s[K], sum + (s[i] - s[K])*(s[i] - s[K]));
	}
}
int main(){
	freopen("partition.in", "r", stdin);
	freopen("partition.out", "w", stdout);
	cin >> N >> TYPE;
	if (TYPE == 0){
		s[0] = 0;
		for (int i = 1; i <= N; i++){
			cin >> a[i];
			s[i] = s[i-1] + a[i];
		}
		for (int i = 1; i <= N; i++){
			DFS(i, s[i], s[i]*s[i]);
		}
		cout << ans << endl;
	}
	else{
		//orz
		cout << 0 << endl;
	}
	return 0;
}
