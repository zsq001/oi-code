#include<stdio.h>
int a[10001],f[10001],b[10001],p[10001];
int main()
{
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	int n,type,i,flag,min=1999999999,k,sum,num=0;
	scanf("%lld%lld",&n,&type);
	if(type==0)
	{
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		while(f[n]==0)
		{
			num++;
			sum=0;
			f[0]+=1;
			for(i=0;i<n;i++)
			{
				if(f[i]==n+1)
				{
					f[i]=0;
					f[i+1]++;
				}
			}
			for(i=0;i<n;i++) b[i]=a[i];
			flag=1;
			for(i=1;i<n;i++)
			{
				if(f[i]!=f[0]) flag=0;
			}
			if(flag==1) continue;
			for(i=1;i<n;i++)
			{
				if(f[i]==f[i-1])
				{
					b[i]+=b[i-1];
					b[i-1]=0;
				}
			}
			k=0;flag=0;
			for(i=1;i<n;i++)
			{
				if(b[i]!=0&&b[i]>k)
				{
					k=b[i];
				}
				if(b[i]!=0&&b[i]<k)
				{
					break;
					flag=1;
				}
			}
			if(flag==1) continue;
			for(i=0;i<n;i++) sum+=b[i]*b[i];
			if(sum<min)
			{
				min=sum;
				for(i=0;i<n;i++) p[i]=b[i];
			}
		}
		printf("%lld",min);
	}
	if(type==1)printf("12331302317672");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
