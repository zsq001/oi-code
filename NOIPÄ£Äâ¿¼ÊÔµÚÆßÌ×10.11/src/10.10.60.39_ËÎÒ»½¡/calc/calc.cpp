#include<cstdio>
#include<cstring>
char a[2005];
int ans=0,cnt=0;
struct node{
	int l,r;
}s[2005<<5];
bool ok(int l,int r)
{
	int k;
	if(l==r)return true;
	if((r-l+1)%2)
	{
		while(l!=r)
		{
			if(a[l]==a[r]){
				l++;
				r--;
				continue;
			}
			return false;
		}
	}
	else {
		k=(l+r)>>1;
		while(l<=k)
		{
			if(a[l]==a[r]){
				l++;
				r--;
				continue;
			}
			return false;
		}
	}
	return true;
}
int main()
{
	freopen("calc.in","r",stdin);
	freopen("calc.out","w",stdout);
	int k,i,j;
	scanf("%s",a+1);
	int n=strlen(a+1);
	for(k=1;k<=n;k++)
	for(i=1;i<=n-k+1;i++)
	if(ok(i,i+k-1)){
		s[++cnt].l=i;
		s[cnt].r=i+k-1;
	}
	for(i=1;i<=cnt;i++)
	for(j=i+1;j<=cnt;j++)
	if(s[i].l>s[j].r||s[i].r<s[j].l)ans++;
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
