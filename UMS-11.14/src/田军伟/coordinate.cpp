#include<stdio.h>
#include<math.h>
int main(){
	freopen("coordinate.in","r",stdin);
	freopen("coordinate.out","w",stdout);
	int a=0,b=0,c=0,n,x=0,y=0,z=0;
	scanf("%d",&n);
	int t=1;
	a=1;b=1;c=1;
	while(t!=n){
		t++;
		x=a+b;
		y=a+b+c;
		z=b+c;
		a=x;b=y;c=z;
	}
	printf("%d",(a+b+c)%(1000000007));
}
