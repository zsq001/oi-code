#include<stdio.h>
const int mod=998244353;
int a[105][2005],l[2005],r[2005],k[2005],ans;
int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x*f;
}
int main(){
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	int n=read(),m=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			a[i][j]=read();
			if(j==1)l[j]+=a[i][j];
			if(j==2)r[j]+=a[i][j];
			if(j==3)k[j]+=a[i][j];
		}
	if(m==2){
		for(int i=1;i<=n;i++)
			ans+=a[i][1]*(r[n]-a[i][2]);
		for(int i=1;i<=n;i++)
			ans+=a[i][2]*(l[n]-a[i][1]);
	}
	if(m==3){
		for(int i=1;i<=n;i++)
			ans+=a[i][1]*(r[n]-a[i][2]);
		for(int i=1;i<=n;i++)
			ans+=a[i][1]*(k[n]-a[i][3]);
		for(int i=1;i<=n;i++)
			ans+=a[i][2]*(l[n]-a[i][1]);
		for(int i=1;i<=n;i++)
			ans+=a[i][2]*(k[n]-a[i][3]);
		for(int i=1;i<=n;i++)
			ans+=a[i][3]*(l[n]-a[i][1]);
		for(int i=1;i<=n;i++)
			ans+=a[i][3]*(r[n]-a[i][2]);
	}
	printf("%d",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
