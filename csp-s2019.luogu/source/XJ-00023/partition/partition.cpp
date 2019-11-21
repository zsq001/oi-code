#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<iostream>
using namespace std;
int n, typed, ans = 9999999;
int a[5001];
int anew[5001];

void he(int x, int y)
{
	if(x > y)
	{
		a[x-1] = a[x] + a[x-1];
		for(int i = x; i < n; i++)
			a[i] = a[i+1];
	}
	else if(x < y)
	{
		a[x] = a[x] + a[x+1];
		for(int i = x+1; i < n; i++)
			a[i] = a[i+1];
	}
}

void fen(int pd, int yw, int xw, int yn, int xn)
{
	if(pd == 1)
	{
		for(int i = n+1; i > xw; i--)
			a[i] = a[i-1];
		a[yw] = yn;
		a[xw] = xn;
	}
	if(pd == -1)
	{
		for(int i = n+1; i > yw; i--)
			a[i] = a[i-1];
		a[yw] = yn;
		a[xw] = xn;
	}
}

void dfs()
{
	int pd = 0;
	for(int i = 1; i <= n; i++)
		if(a[i] > a[i+1])
		{
			pd = 1;
			break;
		}
	if(pd == 0)
	{
		int sum = 0;
		for(int i = 1; i <= n; i++)
			sum = sum + a[i]*a[i];
//		if(sum==1256)
		ans = min(ans, sum);
		
			
		return;
	}
	for(int i = 1; i < n; i++)
		if(a[i] > a[i+1])
		{
			int iplus = a[i+1];
			int idelet = a[i-1];
			int ii = a[i];
			if(i+1<=n)
			{
				he(i, i+1);
			n--;
			dfs();
			fen(1, i, i+1, ii, iplus);
			n++;
			}
			
			if(i-1>0)
			{
			he(i, i-1);
			n--;
			dfs();
			fen(-1, i, i-1, ii, idelet);
			n++;	
			}
			
		}
}

int main()
{
	freopen("partition.in", "r", stdin);
	freopen("partition.out", "w", stdout);
	scanf("%d %d", &n, &typed);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	dfs();
	printf("%d", ans);
	return 0;
}

