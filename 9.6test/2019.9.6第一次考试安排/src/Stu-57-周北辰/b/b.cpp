#include<bits/stdc++.h>
using namespace std;
int ans=0;
int fun(int x)
{   if(x%2!=0)x+=1;
    ans=ans+(x/2);
    x/=2;
     
    if(x!=1) return fun(x);
    else return ans;
}
int main()
{
    freopen ("b.in","r",stdin);
    freopen ("b.out","w",stdout);
	int i,a=0,b=0,j,c=0,n;
	scanf("%d",&n);
	for(int i=1;;i++)
	{
		a+=i;
		b++;
		if(a==n) 
		{
	    ans=fun(b);
		break;	
		}
		if(a>n)
		{
		ans=fun(b);
		break;	
		}

	}
	printf("%d",(ans+1)%1000000007);
	return 0;
	fclose(stdin);
	fclose(stdout);
}
