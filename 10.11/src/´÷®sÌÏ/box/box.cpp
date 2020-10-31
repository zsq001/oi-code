#include<cstdio>
#include<cmath>
int V,S,ans=1000000010;
int main(){
	freopen("box.in","r",stdin),freopen("box.out","w",stdout);
	scanf("%d",&V);
	for(int a=1;a<=sqrt(V);a++){
		if(V%a==0)
		for(int b=1;b<=sqrt(V);b++){
			if(V%b==0){
				int c=V/a/b;
				if(a*b*c==V&&V%c==0&&a*b*2+a*c*2+b*c*2<ans){
					ans=a*b*2+a*c*2+b*c*2;
				}
			}
		}
	}
	printf("%d",ans);
}
