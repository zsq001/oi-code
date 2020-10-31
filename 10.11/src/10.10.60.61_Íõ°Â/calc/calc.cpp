#include<stdio.h>
#include<string.h>
char a[3000];
long long L[3000],ans;
bool s[3000][3000];
bool check(int ss,int tt)
{
	if(a[ss]==a[tt])
	{
		if(tt-ss>1)
			return s[ss][tt]=check(ss+1,tt-1);
		else return true;
	}
	else return false;
}
int main()
{
	freopen("calc.in","r",stdin);
	freopen("calc.out","w",stdout);
	scanf("%s",a+1);
	int len=strlen(a+1);
	for(int i=1;i<=len;i++)
		for(int j=i;j<=len;j++)
		if(!s[i][j])s[i][j]=check(i,j);
	for(int i=1;i<=len;i++)
		for(int j=i;j<=len;j++)
			if(s[i][j])L[2]++,L[i+1]--;
	int num=0;
	for(int i=1;i<=len;i++)
		num+=L[i],L[i]=num;
	for(int i=1;i<=len;i++)
		for(int j=i;j<=len;j++)
		if(s[i][j]&&j!=len)ans+=L[j+1];
	printf("%d",ans);
	return 0;
}
