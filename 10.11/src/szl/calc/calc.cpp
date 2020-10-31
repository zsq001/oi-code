#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define maxL (2100)

using namespace std;
typedef long long LL;

int n;
LL sum_1[maxL];
LL sum_2[maxL];
char str[maxL];

int main() {
	freopen("calc.in","r",stdin);
	freopen("calc.out","w",stdout);
	ios::sync_with_stdio(false);
	
	scanf("%s",str+1);
	n = strlen(str+1);
	for(int i=1; i<=n; i++) {
		for(int L=0; i-L>=1 && i+L<=n; L++) {
			if(str[i-L] != str[i+L]) break;
			else {
				sum_1[i+L]++;
				sum_2[i-L]++;
			}
		}
		for(int L=0; i-L>=1 && i+L+1<=n; L++) {
			if(str[i-L] != str[i+L+1]) break;
			else {
				sum_1[i+L+1]++;
				sum_2[i-L]++;
			}
		}
	}
	
	LL ans = 0;
	for(int i=2; i<=n; i++) {
		sum_1[i] += sum_1[i-1];
	}
	for(int i=1; i<=n; i++) {
		ans += sum_1[i] * sum_2[i+1];
	}
	
	cout << ans << endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
