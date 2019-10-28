#include<stdio.h>
#include<string.h>
int numl[2500],numr[2500],s[2500];
char ss[2500];
bool check(int l,int r)
{
	while(l<r)
	{
		if(s[l]!=s[r])return false;
		l++,r--;
	}
	return true;
}
int main()
{
	freopen("calc.in","r",stdin);
	freopen("calc.out","w",stdout);
	scanf("%s",ss);
	int l=strlen(ss);
	for(int i=0;i<l;i++)
	{
		s[i+1]=ss[i];
	}
	for(int i=1;i<=l;i++)
	{
		for(int j=i;j<=l;j++)
		{
			if(check(i,j))
			{
				numl[i]++;
				numr[j]++;
			}
		}
	}
	long long int sumans=0;
	for(int i=1;i<=l;i++)
	{
		long long int sum1=0;
		for(int j=i+1;j<=l;j++)
			sum1+=numl[j];
		sumans+=sum1*numr[i];
	}
	printf("%lld",sumans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
