#include<stdio.h>
#include<math.h>
long long int n,m;
char a[1000000],temp[1000000],b[1000000];
int wei=1; 
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	
	scanf("%lld %lld",&n,&m);//n位二进制   第m个 
	a[0]='0';
	a[1]='1';
	
	for(int i=0;i<n-1;i++)
	{
		int r=(wei+1)*pow(2,wei+1)/2;
		int q=(wei+1)*pow(2,wei+1)/4;
	    
		for(int j=i+1,k=0;j<r;j=j+i+1+1,k++)
		{
		for(int w=0;w<i;w++)
			{
				
				b[j-w]=a[k];
			}
			
		}
			for(int f=0;f<r-(i+1);f+=(i+1)+1)
			{
				b[f]='0';
			}
	
		
		for(int l=r+(i+1),u=q*(i+1)-1,ji=0;ji<q;l+=(i+1)+1,u--,ji++)
		{
	
			b[l]=a[u];
		}
		for(int f=r+(i+1)-1,p=0;p<q;f+=(i+1)+1,p++)
		{
			b[f]='1';
		}
		for(int t=0;t<r*2;t++)
		{
			a[t]=b[t];
		}
		wei++;
	
	}
	
	for(long long int i=m*wei;i<wei+(m+1)*wei-wei;i++)
	{
		printf("%c",a[i]);
	}
	return 0;
}
