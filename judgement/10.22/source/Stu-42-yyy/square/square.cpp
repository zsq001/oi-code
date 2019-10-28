#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int N=200055;
int n,ans;
int a[N],s1,s2;

int main(){
//	freopen("square.in","r",stdin);
//	freopen("square.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(i&1)s1+=a[i];
		else s2+=a[i];
	}
	if(s1==s2){
		for(int i=1;i<=n;i++)if(a[i]==0)++ans;
		printf("%d\n",ans);
		return 0;
	}
	int d=s1-s2; if(d<0)d=-d;
	if(s1>s2){
		for(int i=1;i<=n;i++){
			if(i%2==1)ans+=(a[i]==d);
		}
	}
	else if(s1<s2){
		for(int i=1;i<=n;i++){
			if(i%2==0)ans+=(a[i]==d);
		}
	}
	printf("%d\n",ans);
	return 0;
}
