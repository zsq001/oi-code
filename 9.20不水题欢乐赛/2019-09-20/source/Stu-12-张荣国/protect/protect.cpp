#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
#define maxn 10
using namespace std;
template <class T> void read(T &x){
	x=0;char s=getchar();bool t=0;
	while(s<'0'||s>'9') {if(s=='-') t=1;s=getchar();}
	while(s>='0'&&s<='9') { x=(x<<3)+(x<<1)+(s^48); s=getchar();}
	x=t?-x:x;
}
int x[maxn],y[maxn];
double d[maxn][maxn],qaq[maxn];
double calc(int x1,int x2,int y1,int y2){
	return sqrt((double)(x1-x2)*(x1-x2)+(double)(y1-y2)*(y1-y2));
}
int main(){
	freopen("protect.in","r",stdin);
	freopen("protect.out","w",stdout);
	int n;
	read(n);
	for(int i=1;i<=n;i++) read(x[i]),read(y[i]);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			d[i][j]=calc(x[i],x[j],y[i],y[j]);
		}
	if(n==3){
		qaq[1]=d[1][2];
		qaq[2]=d[1][3];
		qaq[3]=d[2][3];
		sort(qaq+1,qaq+4);
		printf("%.2lf",qaq[2]*qaq[2]+(qaq[3]-qaq[2])*(qaq[3]-qaq[2]));
	}
	return 0;
}
