#include<stdio.h>
//#include<iostream>
#include<string.h>
#define maxn 200055
typedef int int_;
#define int long long
//using namespace std;
int f[maxn],a[maxn],b[maxn],cnt=0,cnt2=0,ans=0,n=0,j=0,t=0;
int_ main(){
	freopen("7.in","r",stdin);
	scanf("%lld",&n);
	memset(f,0,sizeof(f));
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	//cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%lld",&f[i]);
	for(int i=1;i<=n;i+=2)
		a[++cnt]=a[cnt-1]+f[i];
	for(int i=2;i<=n;i+=2)
		b[++cnt2]=b[cnt2-1]+f[i];
	for(int i=1;i<=n;i++){
		t=i%2,j=(i+1)/2;
		if(t){
			if(a[j-1]+b[cnt2]-b[j-1]==b[j-1]+a[cnt]-a[j]) ans++;
		}
		else {
			if(b[j-1]+a[cnt]-a[j]==a[j]+b[cnt2]-b[j]) ans++;
		}
	}
	//cout<<ans;
	printf("%lld",ans);
	return 0;
}
