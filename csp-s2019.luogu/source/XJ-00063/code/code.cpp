#include<stdio.h>
long long a[70];
int ans[70];
bool vis[70];
int main(){
	int n;long long k;
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d%I64d",&n,&k);k++;a[0]=1;
	for(int i=1;i<=n;i++)a[i]=(long long)1<<i;
	if(n==64&&k<=a[31]){
		for(int i=1;i<=32;i++)printf("0");
		n-=32;
	}
	for(int i=n;i>=2;i--)
		if(k>a[i-1]){k=a[i]+1-k;vis[i]=1;}
	k--;ans[1]=k;
	for(int i=2;i<=n;i++)
		ans[i]=vis[i];
	for(int i=n;i>=1;i--)printf("%d",ans[i]);
	fclose(stdin);fclose(stdout);
	return 0;
}
