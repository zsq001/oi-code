#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int n, k;
char s[5000001][65];

int main()
{
	freopen("code.in", "r", stdin);
	dreopen("code.out", "w", stdout);
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i++)
	{
		int mid = (int)pow(2, i-1);
		int maxx = (int)pow(2, i);
		for(int j = 1; j <= mid; j++)
			for(int q = i; q > 1; q--)
				s[j][q] = s[j][q-1];
		for(int j = mid+1; j <= maxx; j++)
			for(int q = 1; q <= i; q++)
				s[j][q] = s[maxx-j+1][q];
		for(int j = 1; j <= mid; j++)
			s[j][1] = '0';
		for(int j = mid+1; j <= maxx; j++)
			s[j][1] = '1';
//		for(int j = 1; j <= mid; j++)
//		{
//			for(int q = 1; q <= i; q++)
//				printf("%c", s[j][q]);
//			printf(" ");
//		}
//		printf("\n");
//		for(int j = mid+1; j <= maxx; j++)
//		{
//			for(int q = 1; q <= i; q++)
//			printf("%c",s[j][q]);
//			printf(" ");
//		}
//		printf("\n\n");
	}
	for(int i = 1; i <= n; i++)
		printf("%c", s[k+1][i]);
	return 0;
}

