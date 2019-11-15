#include<cstdio>
#define int_ long long
using namespace std;
const int_ mod = (10<<9 )+7;
int f(int a,int b,int n){
	int t=1,y=a;
	while(b!=0){
    	if(b&1==1)t=t*y%n;
    	y=y*y%n;
		b=b>>1;
	}
	return t;
}
int main(){
	freopen("coordinate.in","r",stdin);
	freopen("coordinate.out","w",stdout);
	int_ n,ans=1,x=1;
	scanf("%I64d",&n);
	ans=f(2,n+1,mod);
	ans=ans-1;
	printf("%I64d",ans);
	
	return 0;
}
