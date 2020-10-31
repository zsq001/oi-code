#include <stdio.h>
const int maxn = 1 << 29;
int main() {
	freopen("box.in","r",stdin);
	freopen("box.out","w",stdout);
	int a = maxn,b = maxn,c = maxn,V,flag = 0;
	scanf("%d",&V);
	for (int i = 2; i * i <= V; i++) {
		if (V % i == 0 ) flag = 1;
	}
	if (flag) {
		int n = 1,m = 1;
		while (n * n * n <= V) {
			n ++;
		}
		for (int i = n - 1; i >= 1; i --) {
			if (a != maxn && b != maxn && c != maxn) break;
			else a= maxn,b= maxn,c= maxn;
			a = i;
			if(V % a != 0) continue;
			V /= a;
			while (m * m <= V) {
				m ++;
			}
			for (int j = m - 1; j >= 1; j --) {
				b = j;
				if (V % b != 0) continue; 
				c = V / b;
				break;
			}
		}
		printf("%d",2*a*b+2*a*c+2*b*c);
	} else {
		printf("%d",2*V+2*V+2);
	}
	return 0;
}
