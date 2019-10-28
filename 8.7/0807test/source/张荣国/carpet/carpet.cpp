#include<stdio.h>
#include<string.h>
#include<algorithm>
//typedef int int_;
//#define int long long
#define maxn 1005
using namespace std;
template <class T> void read(T &x){
	bool t=0;x=0;char s=getchar();
	while(s<'0'||s>'9') {if(s=='-') t=1;s=getchar();}
	while(s>='0'&&s<='9') {x=(x<<3)+(x<<1)+(s^48);s=getchar();}
	x=t?-x:x;
}
int n,m,now,l[maxn][maxn],a[maxn][maxn];
int main(){
	freopen("lamp.in","r",stdin);
	freopen("lamp.out","w",stdout);
	read(n),read(m);
	int left,right,up,down;
	for(int i=1;i<=m;i++){
		read(up),read(left),read(down),read(right);
		for(int j=up;j<=down;j++)
			l[j][left]++;
		for(int j=up;j<=down;j++)
			l[j][right+1]--;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n+1;j++)
			printf("%d ",l[i][j]);
		puts("");
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			now+=l[i][j];
			a[i][j]=now;
			if(j==n&&l[i][j+1]!=0) now+= l[i][j+1];
		}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			printf("%d ",a[i][j]);
		puts("");
	}
	return 0;
		
}
