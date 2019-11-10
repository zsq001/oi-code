#include<iostream>
#include<cstdio>
#include <initializer_list>
using namespace std;
#define mmm 15
int dp[mmm][mmm][mmm][mmm],pc[mmm][mmm];
int mmax(initializer_list<int> a){
    int ans=-2147483641;
    for(auto i:a){
        ans=max(i,ans);
    }
    return ans;
}
int main()
{
	int n;
	cin>>n;
	int x,y,c;
	while(1)
	{
		cin>>x>>y>>c;
		if(x==y and y==c and c==0)
			break;
		pc[x][y]=c;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
			{
				int w=i+j-k;
				if(w<0)
					break;
				dp[i][j][k][w]=mmax({dp[i-1][j][k-1][w],dp[i-1][j][k][w-1],dp[i][j-1][k-1][w],dp[i][j-1][k][w-1]});
				if(i==k and j==w)
					dp[i][j][k][w]+=pc[i][j];
				else
					dp[i][j][k][w]+=pc[i][j]+pc[k][w];
			}
	cout<<dp[n][n][n][n]<<endl;
	return 0;
}
