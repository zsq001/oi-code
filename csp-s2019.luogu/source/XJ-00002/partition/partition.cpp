#include<stdio.h>
int n,type,a[40000000],x,y,z,b[40000000],m,p[100000],l[100000],r[100000];
long long int ej[39999999],fg[39999999],fgi,xb,sum,xsum;
int main()
{
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	int i,j,k;
	scanf("%d%d",&n,&type);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	/*ej[n-2]=1;
	while(ej[0]==0)
	{
		for(i=0;i<fgi;i++)
		{
			fg[i]=0;
		}
		for(i=0,j=0,fgi=0;i<(n-1);i++)
		{
			if(ej[i]==1)
			{
				for(k=j;k<=i;k++)
				{
					fg[fgi]=fg[fgi]+a[k];
				}
				j=i+1;
				fgi++;
			}
		}
		for(k=j;k<=i;k++)
		{
			fg[fgi]=fg[fgi]+a[k];
		}
		fgi++;
		xb=0;
		for(i=1;i<fgi;i++)
		{
			if(fg[i]<fg[i-1])
			{
				xb=1;
				break;
			}
		}
		if(xb==1)
		{
			break;
		}
		xsum=0;
		for(i=0;i<fgi;i++)
		{
			xsum=xsum+fg[i]*fg[i];
		}
		if(sum==-1)
		{
			sum=xsum;
		}
		else
		{
			if(xsum<sum)
			{
				sum=xsum;
			}
		}
		for(i=n-2;i>0&&ej[i]==1;i--)
		{
		}
		ej[i]=1;
		for(j=i+1;j<(n-1);j++)
		{
			ej[j]=0;
		}
	}*/
	sum=0;
	a[1]=a[0]+a[1];
	for(i=1;i<n;i++)
	{
		sum=sum+a[i]*a[i];
	}
	printf("%lld",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
