#include <cstdio>
#include <algorithm>
#include <cstring>
#define maxn 10010
using namespace std;

int block[7][5],bfsn[maxn],bfsc[maxn],bfsp[maxn];

void org() {
	block[1][1] = 3; block[1][2] = 2;
	block[1][3] = 5; block[1][4] = 4;
	
	block[2][1] = 1; block[2][2] = 4;
	block[2][3] = 3; block[2][4] = 6;
	
	block[3][1] = 1; block[3][2] = 5;
	block[3][3] = 2; block[3][4] = 6;
	
	block[4][1] = 1; block[4][2] = 5;
	block[4][3] = 2; block[4][4] = 6;
	
	block[5][1] = 1; block[5][2] = 4;
	block[5][3] = 3; block[5][4] = 6;
	
	block[6][1] = 3; block[6][2] = 2;
	block[6][3] = 5; block[6][4] = 4;
}//block[i][j]  当顶部为 i 时, 四周的数字 

int main() {
	freopen("dice.in","r",stdin);
	freopen("dice.out","w",stdout);
	org();
	int T;
	scanf("%d",&T);
	while(T--) {
		int n,cnt=0;
		scanf("%d",&n);
		if( n <= 12 ) {
			if( n == 2 || n == 3 || n == 4 || n == 5 ) {
				printf("1\n");
				continue;
			} else if( n == 12 ) {
				printf("3\n");
				continue;
			} else {
				printf("2\n");
				continue;
			}
		} else if( n == 18 ){
			printf("4\n");
			continue;
		} else if( n > 12 ) {
			int flfl = n/11;
			n %= 11;
			cnt += flfl<<1;
		}
		if( n == 7) {
			printf("%d",cnt+2);
			continue;
		}
		int l=0,r=1,flag=1;
		bfsn[0]=n;
		bfsc[0]=cnt;
		bfsp[0]=6;
		while(flag) {
			for(int i = 1 ;i < 5 ;i++) {
				if( bfsn[l] - block[bfsp[l]][i] == 0 ) {
					bfsc[r] = bfsc[l]+1;
					printf("%d\n",bfsc[r]);
					flag=0;
					break;
				} else if( bfsn[l] - block[bfsp[l]][i] > 0) {
					bfsn[r] = bfsn[l] -block[bfsp[l]][i];
					bfsp[r] = block[bfsp[l]][i];
					bfsc[r] = bfsc[l]+1;
					r++;
				}
			}
			l++;
		}
	}
	return 0;
}
