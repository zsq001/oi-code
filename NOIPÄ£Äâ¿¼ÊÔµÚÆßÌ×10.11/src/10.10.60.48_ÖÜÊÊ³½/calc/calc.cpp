#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
char a[3000];
int f[3000][3000];
bool p[3000][3000];
long long int ans;
int main()
{
	freopen("calc.in","r",stdin);
	freopen("calc.out","w",stdout);
 gets(a+1);
 int len=strlen(a+1);
 for(int i=1;i<=len;i++)
 {
 	int vm=0,vn=0;
 for(int j=i;j<=len;j++)
 {  
  int l,v=(i+j)>>1,t=i+j-1;
  for( l=i;l<=v;l++)
  {
   if(p[l][t-l+1]){l=v+1;break;}
   if(a[l]!=a[t-l+1])break;
  }
  if(l==v+1)
  {
   p[i][j]=true;
   f[1][j]++;
   f[i][len]++;
  }
 }
 }

 for(int i=len;i>=1;i--)
 {
  f[i][len]+=f[i+1][len];
 } 
 for(int i=1;i<len;i++)
  ans+=f[1][i]*f[i+1][len];
 printf("%I64d",ans);
 fclose(stdin);
 fclose(stdout);
 return 0;
}
