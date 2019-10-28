#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
template <class T> void read(T &x){
	bool t=0;x=0;char s=getchar();
	while(s<'0'||s>'9') { if(s=='-') t=1; s=getchar();}
	while(s>='0'&&s<='9') { x=(x<<3)+(x<<1)+(s^48); s=getchar();}
	x=t?-x:x;
}
int ret;
int gcd(int a,int b){
	if(b==0){
		return a;
	}
	ret=gcd(b,a%b);
	return ret;
}
int T,a,b,g_x,g_y;
int move[4][2];
int main(){
	freopen("vector.in","r",stdin);
	freopen("vector.out","w",stdout);
	read(T);
	for(int i=1;i<=T;i++){
		read(a),read(b),read(g_x),read(g_y);
		
		if((g_x%(gcd(a,b)*2)==0&&g_y%(gcd(a,b)*2)==0)||((g_x+a+b)%(gcd(a,b)*2)==0&&(g_y+a+b)%gcd(a,b)==0)||(g_x+a)%(gcd(a,b)==0&&(g_y+b)==0)%gcd(a,b)||(g_x+b)%(gcd(a,b)==0&&(g_y+a)%gcd(a,b)==0))
			{
				printf("Y\n");
			}
		else printf("N\n");
	}
	return 0;
	
}
