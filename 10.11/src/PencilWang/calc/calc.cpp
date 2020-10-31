#include<stdio.h>
#include<string.h>
char a[2200];
long long L[2200],ans;
bool s[2200][2200];
int main()
{
	freopen("calc.in","r",stdin);
	freopen("calc.out","w",stdout);
	scanf("%s",a+1);
	int len=strlen(a+1);
	for(int i=1;i<=len;i++)s[i][i]=true;
	for(int i=1;i<len;i++)if(a[i]==a[i+1])s[i][i+1]=true;
	for(int i=2;i<=len;i++)
		for(int j=1;j+i<=len;j++)
		if(s[j+1][j+i-1]&&a[j]==a[j+i])s[j][j+i]=true;
	for(int i=1;i<=len;i++)
		for(int j=i;j<=len;j++)
			if(s[i][j])L[2]++,L[i+1]--;
	long long num=0;
	for(int i=1;i<=len;i++)
		num+=L[i],L[i]=num;
	for(int i=1;i<=len;i++)
		for(int j=i;j<=len;j++)
		if(s[i][j]&&j!=len)ans+=L[j+1];
	printf("%lld",ans);
	return 0;
}
