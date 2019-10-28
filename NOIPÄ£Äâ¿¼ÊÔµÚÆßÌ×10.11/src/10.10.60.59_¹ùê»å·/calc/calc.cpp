#include<cstdio>
#include<cstring>
char c[2004];
bool sf[2001][2001];
long long f[2001],ans;
int main()
{
	freopen("calc.in","r",stdin),freopen("calc.out","w",stdout);
	int n;
	scanf("%s",c);
	n=strlen(c);
	for(int i=1;i<=n;i++)
		for(int j=0;j<n;j++)
			if(i==1) sf[j][j]=1;
			else if(c[j]==c[j+i-1]&&(i==2||sf[j+1][j+i-2])) sf[j][j+i-1]=1;
	f[0]=1;
	for(int i=1;i<n;i++)
	{
		f[i]=f[i-1];
		for(int j=0;j<=i;j++)
			if(sf[j][i]) f[i]++;
	}
	for(int i=1;i<n;i++)
		for(int j=i;j<n;j++)
			if(sf[i][j]) ans+=f[i-1];
	printf("%I64d",ans);
	fclose(stdin),fclose(stdout);
	return 0;
}
