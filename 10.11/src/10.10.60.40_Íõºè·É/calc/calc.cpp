#include<stdio.h>
#include<string.h>
#define MAXL 2010
char s[MAXL];
struct node{int l,r;};
node q[MAXL*MAXL>>1];
int head[MAXL],tail[MAXL];
int sum[MAXL];
long long ans;
int main()
{
	freopen("calc.in","r",stdin);
	freopen("calc.out","w",stdout);
	scanf("%s",s);
	int len=strlen(s);
	int l=0,r=0;
	int i;
	for(i=0;i<len;++i)
		q[++r].l=i,q[r].r=i;
	for(i=0;i<len-1;++i)
		if(s[i]==s[i+1])q[++r].l=i,q[r].r=i+1;
	while(++l<=r)
	{
		head[q[l].l]++;
		tail[q[l].r]++;
		if(q[l].l==0||q[l].r==len-1)continue;
		if(s[q[l].l-1]==s[q[l].r+1])q[++r].l=q[l].l-1,q[r].r=q[l].r+1;
	}
	sum[0]=tail[0];
	for(i=1;i<len;++i)
		sum[i]=sum[i-1]+tail[i];
	for(i=1;i<len;++i)
		ans+=sum[i-1]*head[i];
	printf("%I64d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
