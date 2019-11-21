#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
using namespace std;
int n;
int type;
char a[100];
int main()
{
	
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	cin >> n>> type;
	cin.getline(a,100);
	int len = sizeof(a);
	sort(a,a+len);
	int answer;
	for(int i = 0;i <= len - 1;i++)
	{
		answer = answer + a[i]^2; 
	}
	cout << answer;
	return 0;
}
