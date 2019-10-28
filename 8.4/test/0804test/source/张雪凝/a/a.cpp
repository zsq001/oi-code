#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[100001];
int main(){
	int n,m,a1,a2;
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(m>(n>>1)){
		printf("Error!");
		return 0;
	}
	if(m==(n>>1)&&n%2==0){
		a1=a[1];
		for(int i=2;i<n;i+=2){
			a1+=a[i+1];
			a2+=a[i];
		}
		a2+=a[n];
		if(a2>a1)swap(a1,a2);
		printf("%d",a1);
		return 0;
	}
	
}
