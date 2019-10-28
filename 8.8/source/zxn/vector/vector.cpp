#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
void exgcd(int a,int b,int &x,int &y){
	if(b==0)x=1,y=0;
	else{
		exgcd(b,a%b,y,x);
		y-=a/b*x;
	}
}
int gcd(int a,int b){
	return b?(gcd(b,a%b)):a;
}
int main(){
	int T,a,b,x,y;
	freopen("vector.in","r",stdin);
	freopen("vector.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d",&a,&b,&x,&y);
		int a1,a2,b1,b2;
		a=abs(a);
		b=abs(b);
		x=abs(x);
		y=abs(y);
		int ans1,ans2;
		int g=gcd(a,b);
		if(x%g||y%g){
			puts("N");
			continue;
		}
		exgcd(a,b,ans1,ans2);
		ans1*=(x/g),ans2*=(x/g);
		puts("Y");
	}
	return 0;
}
