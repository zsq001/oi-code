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

int n,m,p,ans;
int a[507][507];
bool flag;


int main(){
	freopen("plate.in","r",stdin);
	freopen("plate.out","w",stdout);
	read(n),read(m),read(p);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j)
			read(a[i][j]);
		sort(a[i]+1,a[i]+m+1);
	}
	for(int i=1;i<=n;++i)
	  for(int j=i+1;j<=n;++j){
	  	flag=0;
	  	for(int k=1;k<=m;++k){
	  		if(a[i][k]-a[i][1]!=a[j][k]-a[j][1]){
	  			flag=1;
				  break;
			  }
		  }
		  if(!flag) ans++;
	  }
	printf("%d",ans);
	return 0;
}
