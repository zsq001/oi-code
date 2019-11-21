#include <stdio.h>
#include <string.h>

int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n,s=1,str;
	long long k=0,pf=1,L,js=1;
	char a[100];
	int gc[100];
	scanf("%d ",&n);
	scanf("%s",a);
	str=strlen(a);
	for(int i=0;i<=str-1;i++)
			a[i]-='0';
	if(str>19)
	{
		for(int i=str-1;i>=0;i--)
		{
			k+=a[i]*js/2;
			js*=10;
		}
		k++;
		n-=2;
		L=k;
		gc[s]=1;
		L=pf*2-L+1;	
		s++;
		for(int i=1;i<=n;i++)
			pf*=2;
		while(pf!=1)
		{
			if(L<=pf)
			{
				gc[s]=0;
			}
			if(L>pf)
			{
				gc[s]=1;
				L=pf*2-L+1;	
			}
			
			s++;
			pf/=2;
		}
	}
	else
	{
		for(int i=str-1;i>=0;i--)
		{
			k+=a[i]*js;
			js*=10;
		}
		k++;
		n--;
		L=k;
		for(int i=1;i<=n;i++)
			pf*=2;
		while(pf!=1)
		{
			if(L<=pf)
			{
				gc[s]=0;
			}
			if(L>pf)
			{
				gc[s]=1;
				L=pf*2-L+1;	
			}
			
			s++;
			pf/=2;
		}
	}

	
	for(int i=1;i<=s-1;i++)
		printf("%d",gc[i]);
	if(L==1)
		printf("0\n");
	if(L==2)
		printf("1\n");
	
	return 0;
}

