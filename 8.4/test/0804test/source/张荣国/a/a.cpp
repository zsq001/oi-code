#include<stdio.h>
#include<algorithm>
#include<string.h>
#define maxn 200005
using namespace std;
template <class T> void read(T &x){
	bool t=0;x=0;char s=getchar();
	while(s<'0'||s>'9') { if(s=='-') t=1;s=getchar();}
	while(s>='0'&&s<='9'){ x=(x<<3)+(x<<1)+(s^48); s=getchar();}
	x=t?-x:x;
}
int m,n;
bool aval[maxn];
struct node{
	int val,num;
};
int main(){
	freopen("a.in","r",stdin);
	freopen("b.out","w",stdout);
	read(n),read(m);
	if(n/m<2) {
		printf("Error!");	
		return 0;
	}
	return 0;
}
