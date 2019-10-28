#include <cstdio>
#include <cstring>
#include <iostream>
#include<algorithm>
#define ll long long 
using namespace std;

char ch[2010];
bool dp[2010][2010];
int lenn;
int qaq[2010],qwq[2010];//之前，之后 
ll ans;

int main()
{
    freopen("calc.in","r",stdin);
    freopen("calc.out","w",stdout);
	scanf("%s",ch+1); 
	lenn=strlen(ch+1);
    for(int i=1;i<=lenn;++i) dp[i][i]=true;
    for(int i=lenn;i>=1;--i)
    {
	 	for(int j=i;j<=lenn;++j)
	 	{ 
            if(j>=i&&ch[i]==ch[j])
			{
                if(i==j) dp[i][j]=true;//a>>ok
                else if(j-i+1==2) dp[i][j]=true;//aba>>ok
                else dp[i][j]=dp[i+1][j-1];//abcba>>ok adcsa>>nook
            }
        } 
    } 
    for(int i=1;i<=lenn;++i)
	{
        qaq[i]=qaq[i-1];
        for(int j=1;j<=i;++j)
        {
        	if(dp[j][i]) ++qaq[i];
		} 
            
    }
    for(int i=1;i<lenn;++i)
    {
    	 for(int j=i;j<=lenn;++j)
    	 {
    	 	if(dp[i+1][j]) ++qwq[i];
		 }
	}
    for(int i=1;i<=lenn;++i) ans+=qaq[i]*qwq[i];
    printf("%lld",ans);
    return 0;
}
