#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
template<class T>void read(T &x){
	int f=0;x=0;char ch=getchar();
	while(ch<'0'||ch>'9')  {f|=(ch=='-');ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	x=f?-x:x;
}

char s[500];
int n,flag,ans;
int k[500],fa[500];

inline bool check(int x,int y){
	char st[500];
	int pos=0;
	for(int i=x;i<=y;++i){
		st[++pos]=s[i];
		if(s[i]==')'&&st[pos-1]=='(') pos-=2;
	}
	if(pos!=0) return 0;
	return 1;
}
int main(){
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	read(n);
	scanf("%s",s+1);
	fa[1]=1;
	for(int i=2;i<n;++i){
		read(fa[i]);
		if(fa[i]!=i-1) flag=1;
	}
	if(flag==0){
		for(int i=2;i<=n;++i){
			for(int j=1;j<i;++j)
				if(check(j,i)) k[i]++;
			k[i]+=k[i-1];
		}
		for(int i=1;i<=n;++i){
			ans^=(i*k[i]);
		}
		printf("%d\n",ans);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
