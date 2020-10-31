#include<stdio.h>
#include<algorithm>
#include<string.h>
//typedef int int_;
//#define int long long
#define maxn 1005
using namespace std;
template <class T> void read(T &x){
	x=0;bool f=0;char s=getchar();
	while(s<'0'||s>'9') { if(s=='-') f=1;s=getchar();}
	while(s>='0'&&s<='9') { x=(x<<3)+(x<<1)+(s^48); s=getchar();}
	x=f?-x:x;
}
void init(){
	for(int i=1;i)
}
int main(){
	read(n),read(m);
	for(int i=1;i<=n;i++)read(a[i]);
	for(int i=1;i<=n;i++){
		read(opt),read(l),read(r);
		for(int j=l;j<=r;j++){
			for(int k=l;k<j;k++){
				f[j][0]=max(f[k][1]-)
			}
		}
	}
}
