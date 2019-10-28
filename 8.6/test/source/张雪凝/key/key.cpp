#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char c[100010];
bool a[100010];
int ans[100010];
int main(){
	int tot=0;
	freopen("key.in","r",stdin);
	freopen("key.out","w",stdout);
	scanf("%s",c+1);
	int len=strlen(c+1);
	int n=len/3;
	a[1]=c[1]-'0';
	int cnt=1;
	for(int i=1;i<len;i++){
		a[i+1]=c[i+1]-'0';
		if(a[i]!=a[i+1])cnt++;
	}
	if(cnt>2*n){
		printf("0");
	} else {
		if(n==1){
			printf("1\n1");
			return 0;
		}
		for(int i=4;i<=len;i++){
			if(a[i]==a[i-1]&&a[i-1]==a[i-2]&&a[i-2]==a[i-3]){
				a[i-2]=a[i-1]=!a[i];
				ans[++tot]=i-2;
				cnt+=2;
			}
			if(a[i]==a[i-1]&&a[i-1]!=a[i-2]&&a[i]!=a[i-3]){
				a[i-1]=!a[i-1];
				a[i-2]=!a[i-2];
				ans[++tot]=i-2;
				cnt+=2;
			}
			if(cnt>=2*n){
				printf("%d\n",tot);
				for(int i=1;i<=tot;i++){
					printf("%d ",ans[i]);
				}
				return 0;
			}
		}
	}
}
