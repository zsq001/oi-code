#include<cstdio>
#include<algorithm>
#include<cstring>
#define foru(i,a,b) for(int i=a;i<=b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
			ch=getchar();
		}
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return f*x;
}

int n,type,a[1000];

int main(){
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	n=read(),type=read();
	foru(i,1,n)a[i]=read();
	sort(a,a+n);
	int tot;
	foru(i,1,n)
	tot+=a[i]*a[i];
	printf("%d",tot);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
