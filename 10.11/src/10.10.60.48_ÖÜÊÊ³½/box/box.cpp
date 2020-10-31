#include<cstdio>
#include<math.h>
#include<algorithm>
using namespace std;
int v,ans=2147483647;
int main()
{
	freopen("box.in","r",stdin);
	freopen("box.out","w",stdout);
 scanf("%d",&v);
 int left=1,right=v+1;
 while(left+1<right)
 {
   long long int mid=(left+right)>>1;
   if(mid*mid>v)right=mid;
   else if(mid*mid*mid>v)right=mid ;
   else left=mid;
   }   
 for(int i=1;i<=right;i++)
 {
  if(v%i==0)
  {
   int k=v/i;
   int m=(int)sqrt(k);
   for(int j=m;j>=1;j--)
   {
    if(k%j==0)
     {
	 ans=min(ans,2*(i*j+v/i+v/j));
     }
    }
  } 
 }
 printf("%d",ans);
 fclose(stdin);
 fclose(stdout);
 return 0;
}
