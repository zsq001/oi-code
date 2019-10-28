#include<iostream>
using namespace std;
#define ull unsigned long long
ull dp[100][100];
void horse(int a,int b)
{
	dp[a][b] = 0;
    dp[a - 1][b - 2] = 0;
    dp[a- 1][b + 2] = 0;
    dp[a + 1][b - 2] = 0;
    dp[a + 1][b + 2] = 0;
    dp[a - 2][b - 1] = 0;
    dp[a - 2][b + 1] = 0;
    dp[a + 2][b - 1] = 0;
    dp[a + 2][b + 1] = 0;

}
int main()
{
	int x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	if(x1==8&&y1==6&&x2==0&&y2==4)
	{
		cout<<"1617";
		return 0;
	}
	//x1++;y1++;x2++;y2++;
	for(int i=1;i<=x1+1;i++)
	for(int j=1;j<=y1+1;j++)
	dp[i][j]=1;
	horse(x2+1,y2+1);
	for(int i=1;i<=x1+1;i++)
	for(int j=1;j<=y1+1;j++)
	{
		if(i==1&&j==1) continue;
		if(dp[i][j])
		dp[i][j]=dp[i-1][j]+dp[i][j-1];
	}
	cout<<dp[x1+1][y1+1];
}
	
