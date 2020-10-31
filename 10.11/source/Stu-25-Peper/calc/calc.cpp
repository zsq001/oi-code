#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
template<class T>void read(T &x){
	int f=0;x=0;char ch=getchar();
	while(ch<'0'||ch>'9')  {f|=(ch=='-');ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	x=f?-x:x;
}

bool flag;
int pos,n;
long long ans;
int f[2007],g[2007];
char s[2007];

inline bool cnm(int x,int y){
	while(x<y){
		if(s[x]!=s[y]) return 0;
		x++;y--;
	}
	return 1;	  
}

int main(){
	freopen("calc.in","r",stdin);
	freopen("calc.out","w",stdout);
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;++i){
		pos=i;
		flag=1;
		while(pos<=n){
			if(s[pos]!=s[i]) flag=0;
			if(flag)       ++f[i],++g[pos];
			else if(cnm(i,pos)) ++f[i],++g[pos];
			++pos;
		}
	} 
	for(int i=1;i<n;++i)
	  for(int j=i+1;j<=n;++j)
	  	ans+=g[i]*f[j];
	printf("%lld\n",ans);
	return 0;
}
