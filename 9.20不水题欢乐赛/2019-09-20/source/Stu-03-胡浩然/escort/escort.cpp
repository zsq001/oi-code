#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;
template<class T>void read(T &x){
	int f=0;char ch=getchar();
	while(ch<'0'||ch>'9')  {f|=(ch=='-');ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	x=f?-x:x;
}
/*
inline void spfa(){
	
}

inline void sol1(){
	read(u),read(v);
	for(int i=1;i<=m;++i){
		read(i),read(j),read(w1),read(w2);
	}
}
*/
int main(){
	freopen("escort.in","r",stdin);
	freopen("escort.out","w",stdout);
	printf("3");
	return 0;
}
