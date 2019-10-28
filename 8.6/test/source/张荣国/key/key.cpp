#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
/*template <class T> bool read(T &x){
	bool t=0;x=0;char s=getchar();if(s==-1)return 0;
	while(s<'0'||s>'9') {if(s=='-')t=1;else if(s==-1)return 0;s=getchar();}
	while(s>='0'&&s<='9'){ x=(x<<3)+(x<<1)+(s^48); s=getchar();}
	x=t?-x:x;
}*/
#define maxn 100005
int cnt,tot,a[maxn],ans[maxn],qaq;
int main(){
	freopen("key.in","r",stdin);
	freopen("key.out","w",stdout);
	char s;
	while(1){
		s=getchar();
		if(s==-1) break;
		else if(s<'0'||s>'9') continue;
		else s^=48;
		a[++tot]=s;
		if(tot!=1&&a[tot]^a[tot-1]) cnt++;
	}
	tot/=3;
	++cnt;
	if(cnt>=tot*2) {
		printf("0\n");
		return 0;
	}
	if(tot==1){
		printf("1\n");
		return 0;
	}
	for(int i=1;i<=tot*3-4;i++){
		if((a[i]^a[i+1])==0&&(a[i+2]^a[i+3])==0){
			a[i+1]^=1;
			a[i+2]^=1;
			cnt+=2;
			ans[++qaq]=i+1;
		}	
		if(cnt>=tot*2) break;
	}
	printf("%d\n",qaq);
	for(int i=1;i<=qaq;i++) printf("%d ",ans[i]);
	return 0;
}
