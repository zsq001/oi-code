#include<bits/stdc++.h>
using namespace std;
int n = 0;
int k = 0;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	cin >> n >> k;
	int b[n];
	for(int i = 0;i <= n - 1;i++)
	{
		b[i] = 0; 
	}
	for(int i = 0;i <= k - 1;i++)
	{
		for(int j = 0;j <= n - 1;j++)
		{
			if(b[j] == 1)
			{
				b[j - 1]++;
				b[j] = 0;
			}
			b[j] = b[j] + 1;
		 	if(b[j] == 0)
			{
					
			}
		}
		
	}
	for (int i = 0;i <= n - 1;i++)
	{
		b[i] = b[i] / k;
		cout << b[i];	
	}
	return 0;
} 
