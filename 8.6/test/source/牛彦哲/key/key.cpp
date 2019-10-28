#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n,sco,len,road[100010];
char a[300010];
int check(int m,int pos)
{
	if(sco>=2*n)
	{
		return 1;
	}
	if(m==0)
	{
		return 0;
	}
	int t1,t2,rsco=sco;
	for(int i=pos;i<len-1;i++)
	{
		t1=i+2;
		t2=i-1;
		a[i]='1'-a[i]+'0';
		a[i+1]='1'-a[i+1]+'0';
		if(t1<len)
		{
			if(a[i+1]==a[t1])
			{
				sco--;
			}
			else
			{
				sco++;
			}
		}
		if(t2>=0)
		{
			if(a[i]==a[t2])
			{
				sco--;
			}
			else
			{
				sco++;
			}
		}
		if(check(m-1,i+1))
		{
			sco=rsco;
			a[i]='1'-a[i]+'0';
			a[i+1]='1'-a[i+1]+'0';
			road[m]=i;
			return 1;
		}
		sco=rsco;
		a[i]='1'-a[i]+'0';
		a[i+1]='1'-a[i+1]+'0';
	}
	return 0;
}
int main()
{
	freopen("key.in","r",stdin);
	freopen("key.out","w",stdout);
	scanf("%s",a);
	int i,le,ri,mid,ans;
	len=strlen(a);
	n=len/3;
	le=1;
	ri=n;
	for(i=0;i<len-1;i++)
	{
		if(a[i]!=a[i+1])
		{
			sco++;
		}
	}
	if(sco>=2*n)
	{
		printf("0");
		return 0;
	}
	while(le<ri)
	{
		mid=(le+ri)/2;
		if(check(mid,0))
		{
			ans=mid;
			ri=mid;
		}
		else
		{
			le=mid+1;
		}
	}
	printf("%d\n",ans);
	for(i=ans;i>0;i--)
	{
		printf("%d ",road[i]+1);
	}
	return 0;
}
