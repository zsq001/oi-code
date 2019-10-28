#include<bits/stdc++.h>
#define N 200010
using namespace std ;
int v,Ans=N,ans[N],cnt;
int main(){
	std::ios::sync_with_stdio(false);
	freopen("box.in","r",stdin);
	freopen("box.out","w",stdout);
	cin>>v;
	for(int h=1;h<=v;h++){
		if(v%h) continue;
		int s=v/h;
		for(int a=1;a<=sqrt(s+0.0);a++){
			if(s%a) continue;
			int b=s/a;
			if(a*b*h!=v) continue;
			ans[++cnt]=2*(a*b+a*h+b*h);
		}
	}
	for(int i=1;i<=cnt;i++)
		if(ans[i]) Ans=min(Ans,ans[i]);
	cout<<Ans<<endl;
	return 0;
}
