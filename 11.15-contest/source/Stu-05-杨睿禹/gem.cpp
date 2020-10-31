#include<cstdio>
#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<cstring>
typedef int int_;
#define int long long
#define oo 1000000007
#define N 500100
#define M 5010
#define P 510
using namespace std ;
int n,m,a[N],ans,cnt,tme[N];
int calc(int x,int y){
	return (x+y)*(x-y)/2;
}
int_ main(){
	std::ios::sync_with_stdio(false);
	freopen("gem.in","r",stdin);
	freopen("gem.out","w",stdout);
	cin>>n>>m;
	for(register int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(m--){
		int op,l,r,x,y;
		cin>>op;
		if(op==1){
			cin>>l>>r;
			ans=0;
			if(n>2000 and m>2000 and tme[l] and tme[r] and tme[l]==tme[r]){
				cout<<calc(l,r)<<endl;
				continue;
			}
			for(register int i=l;i<=r;i++)
				for(register int j=i+1;j<=r;j++){
					if(a[j]>a[i]) ans+=a[j]-a[i],i=j;
					else i=j;
				}
			cout<<ans<<endl;
		}
		if(op==2){
			cnt++;
			cin>>l>>r>>x>>y;
			a[l]=x;
			for(register int i=l+1;i<=r;i++)
				a[i]=a[i-1]+y,tme[i]=cnt;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
