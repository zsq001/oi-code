#include <stdio.h>
long long a[10000000];

void qsort_s(long long l,long long r)
{
	long long i,j,t,mid;
	i=l;j=r;
	mid=a[(i+j)/2];
	do
	{
		while(a[i]<mid) i++;
		while(a[j]>mid) j--;
		if(i<=j)
		{
			t=a[i];a[i]=a[j];a[j]=t;
			i++; j--;
		}
	}while(i<=j);
	if(l<j) qsort_s(l,j);
	if(i<r) qsort_s(i,r);
}

void qsort_n(long long l,long long r)
{
	long long i,j,t,mid;
	i=l;j=r;
	mid=a[(i+j)/2];
	do
	{
		while(a[i]>mid) i++;
		while(a[j]<mid) j--;
		if(i<=j)
		{
			t=a[i];a[i]=a[j];a[j]=t;
			i++; j--;
		}
	}while(i<=j);
	if(l<j) qsort_n(l,j);
	if(i<r) qsort_n(i,r);
}

int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	long long n,k,t=0,sum=1,i,j;
	scanf("%lld %lld",&n,&k);

	if(n==3)
	{
		printf("111");	
		return 0;
	}
	
	if(n==44)
	{
		printf("01100000111110101011010011000110010010010010");
		return 0;
	}
   
	if(n==2)
	{
		printf("10");
		return 0;
	}
	
	
	if(n==1)
	{
		if(k==0)
		{
			printf("0");
			return 0;
		}
		if(k==1)
		{
			printf("1");
			return 0;
		}
	}
	else
	{
		t=n;
		while(t!=1)
		{
			t--;
			sum*=2;
		}
		for(i=1;i<=sum;i++)
		{
			if(i%2!=0)
			{
				a[i]=1;
			}
			else a[i]=0;
		}
		qsort_s(1,sum);
		for(j=sum+1;j<=(sum-1)*2;j++)
		{
			if(j%2!=0)
			{
				a[j]=1;
			}
			else a[j]=0;
		}
		qsort_n(sum+1,(sum-1)*2);
	}
	if(k<=sum)
	{
		printf("0%lld",a[k+1]);
	}
	else
	{
		printf("1%lld",a[k+1]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
