#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int a[70];
int main()
{
	int k,s=1,n,i;
    int ch=0,t=0;
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(i=1;i<=n;i++)
	  s=s*2;
	for(i=1;i<=n;i++)
	{
        s/=2;
		if(k<s){
			  if(ch==0)t=0;
			  else t=1;
			  ch=0;
		    }
	    if(k>=s) {
	    	if(ch==0)t=1;
	    	else t=0;
	    	ch=1;
	    	k-=s;
	    }
	    a[i]=t;
	}
	for(i=1;i<=n;i++)
	  printf("%d",a[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
