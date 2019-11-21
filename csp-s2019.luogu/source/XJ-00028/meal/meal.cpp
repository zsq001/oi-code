#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const long long MOD = 998244353;
long long a[110][2010], N, M, ans;
bool visN[110];
int visM[2010];
void DFS(int K, int J, long long cnt){
	if (K > N/2){
		ans += cnt;
		ans %= MOD;
	}
	for (int j = J; j <= M; j++){
		if (visM[j]+1 <= (K+1)/2){
			for (int i = 1; i <= N; i++){
				if (!visN[i] && a[i][j]){
					visN[i] = true;
					visM[j] += 1;
					DFS(K+1, j, cnt%MOD*a[i][j]);
					visN[i] = false;
					visM[j] -= 1;
				}
			}	
		}
	}
	return;
}
int main(){
	freopen("meal.in", "r", stdin);
	freopen("meal.out", "w", stdout);
	cin >> N >> M;
	memset(a, 0, sizeof(a));
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= M; j++){
			cin >> a[i][j];
		}
	}
	for (int j = 1; j <= M; j++){
		for (int i = 1; i <= N; i++){
			if (a[i][j]){
				memset(visN, 0, sizeof(visN));
				memset(visM, 0, sizeof(visM));
				visN[i] = true;
				visM[j] += 1;
				DFS(1, j, a[i][j]);
				visN[i] = false;
				visM[j] -= 1;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
