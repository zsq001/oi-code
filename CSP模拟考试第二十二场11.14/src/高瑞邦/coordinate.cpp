#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,ans; 
long long l,r,u,x,y,z; 
int main()
{
 freopen("coordinate.in","r",stdin);		
 freopen("coordinate.out","w",stdout);	
 scanf("%d",&n);  
 l=1;r=1;u=1; 
 for (int i=2;i<=n;i++) 
 {x=l;y=r;z=u;
 l=(x+z)%1000000007; 
 r=(y+z)%1000000007; 
 u=(x+y+z)%1000000007; 
 } 
 ans=(l+r+u)%1000000007; 
  printf("%d",ans); 
 fclose(stdin);
 fclose(stdout);
 return 0;	
}

