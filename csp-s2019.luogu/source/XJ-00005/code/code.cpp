#include<stdio.h>
int ans[1000];
long long int ret=2,n,k,now;
int main()
{
    freopen("code.in","r",stdin);
    freopen("code.out","w",stdout);
	scanf("%lld",&n);
	if(n<=63)
	{
	    scanf("%lld",&k);
		for(int i=1;i<=n;i++)
		{
		 if(i==62)
	  	 {
            now=k;
			if(now<ret/2||now>=ret/2*3)ans[i]=0;
			else ans[i]=1;
			continue;
		 }
		 else if(i==63)
		 {
			now=k;
			if(now<ret)ans[i]=0;
			else   ans[i]=1;
			continue;
		 }
		 ret*=2;
		 now=k%ret;
         if(now<ret/4||now>=ret/4*3)ans[i]=0;
		 else         ans[i]=1;
		}
	 	for(int i=n;i>=1;i--)
		{
			printf("%d",ans[i]);
		}
	}
	else{
	    for(int i=1;i<=64;i++)
	            printf("1");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
