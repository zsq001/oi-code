#include<cstdio>
#include<iostream>
#include<algorithm>
#include <cstring>
using namespace std;
long long ans=0x7fffffff;
int main()
{
    freopen("box.in","r",stdin);
    freopen("box.out","w",stdout);
    long long V,i,j;
    cin>>V;
    for(i=1;i*i*i<=V;i++)
    {
     if(V%i==0)
     { 
      for(j=i;j*j<=V;j++)
      {
       if((long long)(V/i)%j==0)
       {
        long long u=(long long)(V/i)/j;
        long long k=((long long)V/i+(long long)V/j+(long long)V/u);
        if(k<=ans)ans=k;
       }
      }
     }
    }
    cout<<ans*2;
    return 0;
}
