#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct node{
	int next,x,n;
}; 
node e[500050];
int a[500050];
char c[500050];
int b[500050],tot,cnt=1;





int main()
{
	freopen("key.in","r",stdin);
    freopen("key.out","w",stdout);
	scanf("%s",c);
	int len=strlen(c);
	a[1]=(int)(c[0]-'0');
	for(int i=2;i<=len;i++){
		a[i]=(int)(c[i-1]-'0');
		if(a[i] ^ a[i-1]) tot++;
	} 
	int ans=2*len/3-tot;
	if(ans>0){
		a[0]=a[1];
		a[len+1]=a[len];
		for(int i=1;i<=len-1;i++){
			if(a[i]==a[i-1] && a[i+1]==a[i+2]){
				e[cnt+1].n=i;
				if((i-2) == e[cnt].n){
					e[++cnt].next=cnt-2;
				}
				else e[++cnt].next=cnt-1;
			} 
		}
		ans=(ans+1)>>1;
		tot=ans+1;
		printf("%d\n",ans);
		for(int i=cnt;tot>1;i=e[i].next){
			a[--tot]=e[i].n;
		}
		for(int i=1;i<=ans;i++){
			printf("%d ",a[i]);
		}
	}
	else printf("0");
	return 0;
}
