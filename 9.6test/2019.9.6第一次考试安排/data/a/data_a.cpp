#include <cstdio>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
	freopen("a.in", "w", stdout);
	srand(time(0));
	int T = 1000;
	printf("%d\n", T);
	while(T--) {
		int n = 100;
		printf("%d\n", n);
		for(int i = 1; i <= n; i++) {
			printf("%d ", rand() * (rand() % 100) + 1);
		}
		printf("\n");
	}
	
}
