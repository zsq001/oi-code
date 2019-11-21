#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
int main(){
	freopen("code.in", "r", stdin);
	freopen("code.out", "w", stdout);
	int n; unsigned long long k, tmp;
	cin >> n >> k; tmp = 0ull; int flag = 0;
	for (int i = n - 1;i >= 0;i--){
		if (k - tmp < (1ull << (unsigned long long)(i))) printf("%d", flag), flag = 0;
		else printf("%d", 1 - flag), tmp += (1ull << (unsigned long long)(i)), flag = 1;
	}
	return 0;
}
