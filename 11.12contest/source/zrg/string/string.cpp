#include<stdio.h>
#include<algorithm>
#include<string.h>
#define maxn 200005
using namespace std;
template <class T> void read(T &x){
	x=0;bool f=0;char s=getchar();
	while(s<'0'||s>'9') { if(s=='-') f=1;s=getchar();}
	while(s>='0'&&s<='9') { x=(x<<3)+(x<<1)+(s^48); s=getchar();}
	x=f?-x:x;
}
char s[maxn];
int cnt[255],only[255],T,n;
int cone,ctwi,delf,qaq,qwq;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	read(T);
	while(T--){
		read(n);
		scanf("%s",s+1);
		for(int i=1;i<=250;i++) cnt[i]=only[i]=0;
		cone=ctwi=0;
		for(int i=1;i<=n;i++) {
			if(cnt[s[i]-' ']==0) cone++,only[s[i]-' ']=i;
			else if(cnt[s[i]-' ']==1) cone--,ctwi++,only[s[i]-' ']=0;
			cnt[s[i]-' ']++;
		}
		if(cone<=1&&ctwi==1) {
			printf("1\n");
			break;
		}
		if(ctwi==0) {
			printf("%d\n",cone);
			break;
		}
		if(cone>1) {
			int left,right;
			for(int i=1;i<=n;i++) 
				if(only[i]) {
					left=i;
					break;
				}
			for(int i=n;i;i--) 
				if(only[i]) {
					right=i;
					break;
				}
			if(n-right>=left) {
				printf("%d\n",n);	
				break;
			}
			int j;
			bool fflag=0;
			for(int i=right;i<=n;i++){
				for(j=1;j<=n;j++){
					if(s[j]!=s[j+i]) 
						break;
				}
				if(j==n+1){
					printf("%d\n",i);
					fflag=1;
					break;
				}
			}
			if(fflag){
				fflag=0;
				break;
			}
			else {
				printf("%d\n",n);
				break;
			}
		}
		else if(cone==0){
			int flag=0;
			for(int i=ctwi;i<=n;i++){
				for(int k=1;;k++){
					for(int j=1;j<=ctwi;j++){
						int pt=k*i+j+delf;
						if(pt>n) {
							printf("%d\n",i);
							flag=2;
							break;
						}
						if(s[pt]!=s[pt-i-qaq]){
							if(delf) {
								qaq=delf=0;
								flag=1;
								break;
							}
							if(s[pt+1]==s[pt-i]){
								delf=1;
								qwq=i;
							}
							if(qwq) qwq--;
							if(delf&&qwq==0) qaq=1;
						}
						
					}
					if(flag==1) {
							flag=0;
							break;
						}
					if(flag==2) break;
				}
				if(flag==2) break;
			}
		}
		else if(cone==1) {
			int del;
			for(int i=1;i<=250;i++) 
			if(only[i]){
				del=only[i];
				n--;
				break;
			}
			for(int i=del;i<=n;i++)
				s[i]=s[i+1];	
			bool flag=0;
			for(int i=ctwi;i<=n;i++){
				for(int j=1;j<=ctwi;j++){
					if(flag){
						break;
					}
					for(int k=1;;k++){
						int pt=k*i+j;
						if(pt>n) break;
						if(s[pt]!=s[pt-i]){
							flag=1;
							break;
						}
					}
				}
				if(flag==0) {
					printf("%d\n",i);
					break;
				}
				flag=0;
			}
		}

	}
	return 0;
}
