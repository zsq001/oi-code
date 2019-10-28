#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

struct point{
	double x,y;
}p[10];
bool cmp(double a,double b) {
	return a - b < 0;
}
double dis[10][10],k[10][10];
double a[5],l[10],r[10];
int n;
//int pd() {
//	double x = p[1].x - p[2].x;
//	double y = p[1].y - p[2].y;
//	if (x != 0 && y != 0) {
//		double k = y / x;
//		double b = p[1].y-p[1].x*k;
//		for (int i = 3; i <= n; i ++) {
//			if ((p[i].x * k + b) != p[i].y) return 0;
//		}
//		return 1;
//	} else if (x == 0) {
//		for (int i = 3; i <= n; i ++) {
//			if (p[i].x != 0) return 0;
//		}
//		return 1;
//	} else if (y == 0) {
//		for (int i = 3; i <= n; i ++) {
//			if (p[i].y != 0) return 0;
//		}
//		return 1;
//	}
//}
int main() {
	freopen("protect.in","r",stdin);
	freopen("protect.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1; i <= n; i ++)
		scanf("%lf%lf",&p[i].x,&p[i].y);
//	if (n >= 3) flag = pd();
	if (n == 3) {
		for (int i = 1; i <= 3; i ++) {
			for (int j = 1; j <= 3; j ++) {
				if (i == j) continue;
				int x = p[i].x - p[j].x;
				int y = p[i].y - p[j].y;
				if (x < 0) x = -x;
				if (y < 0) y = -y;
				dis[i][j] = sqrt(x*x*1.0+y*y*1.0);
			}
		}
		a[1] = dis[1][2];
		a[2] = dis[2][3];
		a[3] = dis[1][3];
		sort(a+1,a+1+3,cmp);
		double ans =a[2]*a[2]+(a[3]-a[2])*(a[3]-a[2]);
		printf("%.2lf\n",ans);
	}
//	} else if (flag == 1) {
//		
//	}
//	}
//
//	
//	
//	
//	
//	
//	
//	for (int i = 1; i <= n; i ++) {
//		for (int j = 1; j <= n; j ++) {
//			if (i == j) continue;
//			int x = p[i].x - p[j].x;
//			int y = p[i].y - p[j].y;
//			if (x < 0) x = -x;
//			if (y < 0) y = -y;
//			dis[i][j] = sqrt(x*x*1.0+y*y*1.0);
//		}
//	}
//	double minx = (1 << 29) * 1.0;
//	for (int i = 1; i <= n; i ++) {
//		for (int j = 1; j <= n; j ++) {
//			if (i != j && minx - dis[i][j] > 0) minx = dis[i][j];
//		}
//	}
//	for (int i = 1; i <= n ; i ++) {
//		for (int j = 1; j <= n; j ++) {
//			printf("%.4lf ",dis[i][j]);
//		}
//		printf("\n");
//	}
//	printf("%.5lf",minx);
	return 0;
}
