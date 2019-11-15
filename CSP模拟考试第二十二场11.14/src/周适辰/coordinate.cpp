#include<cstdio>
int n;
long long re[1000005],gr[1000005];
void frein()
{
 freopen("coordinate.in","r",stdin);
 freopen("coordinate.out","w",stdout);
}
void freout()
{
 fclose(stdin);
 fclose(stdout);
}
int main()
{
  frein();
 scanf("%d",&n);
 re[0]=1;
 gr[0]=0;
 for(int i=1;i<=n;i++)
 {
  gr[i]=(gr[i-1]+2*re[i-1])%1000000007;
  re[i]=(re[i-1]+gr[i-1])%1000000007;
 }
 printf("%I64d",(gr[n]+re[n])%1000000007);
 freout();
 return 0;
}
