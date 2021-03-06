#include <iostream>
#define INV 500000004
#define MOD 1000000007
using namespace std;
long long fpow(long long x,long long y)
{
 long long ans=1;
 while(y)
 {
  if(y&1)ans=ans*x%MOD;
  x=x*x%MOD;
  y>>=1;
 }
 return ans;
}
int main()
{
 freopen("magic.in","r",stdin);
 freopen("magic.out","w",stdout);
 int n;
 cin>>n;
 cout<<(fpow(3,n+1)-1)*INV%MOD<<endl;
 fclose(stdin);
 fclose(stdout);
 return 0;
}
