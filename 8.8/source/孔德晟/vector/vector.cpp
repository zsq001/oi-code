#include <cstdio>
#include <algorithm>
using namespace std;

int x[9],y[9];
double k[9];
int main() {
	freopen("vector.in","r",stdin);
	freopen("vector.out","w",stdout);
	int T,a,b,fx,fy;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d%d%d",&a,&b,&fx,&fy);
		if (a == 0 && b == 0) {
			printf("N\n");
			continue;
		} else if (a == 0 || b == 0) {
			int num;
			if (a != 0) num = a;
			else num = b;
			if (num != 0 && fx % num == 0 && fy % num == 0) {
				printf("Y\n");
				continue;
			} else {
				printf("N\n");
				continue;
			}
		} else if (a != b && fx % abs(a-b) == 0 && fy % abs(a-b) == 0){
			printf("Y\n");
			continue;
		} else {
			printf("N\n");
			continue;
		}
	}
	return 0;
}
