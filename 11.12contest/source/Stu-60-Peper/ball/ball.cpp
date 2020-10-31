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

long long ans,n;
long long f[77];
char s[77];
int main(){
    freopen("ball.in","r",stdin);
    freopen("ball.out","w",stdout);
	read(n);
    scanf("%s",s+1);
    f[0]=1;                                          
    for(int i=1;i<=57;++i) f[i]=f[i-1]<<1;
    for(int i=1;i<=n;++i)
		if(s[i]=='B'){
        ans+=f[i-1];
        if(ans>(long long)1e18){
        	printf("-1");
        	return 0;
		}    	
	}
    printf("%lld\n",ans);
    return 0;
}
