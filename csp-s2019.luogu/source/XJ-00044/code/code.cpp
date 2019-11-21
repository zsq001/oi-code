#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
long long n2[100];
char s[100];
void dfs(int n,long long k,int dep)
{
	if(n == -1) return ;
	if(k - n2[n] < 0)
	{
		s[dep] = '0';
		dfs(n - 1,k,dep + 1);
	}
	else
	{
		s[dep] = '1';
		dfs(n - 1,n2[n + 1] - k,dep + 1);
	}
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n;
	long long k;
	cin >> n;
	cin >> k;
	n2[0] = 1;
	for(int i = 1;i <= n;i++)
		n2[i] = n2[i - 1] * 2;
	dfs(n - 1,k,0);
	printf("%s",s);
	return 0;
}
