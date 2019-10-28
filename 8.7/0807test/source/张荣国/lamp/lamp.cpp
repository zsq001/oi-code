#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
//typedef int int_;
//#define int long long
#define maxn 500005
using namespace std;
void read(int &x){
		x=0;char s=getchar();
	while(s<'0'||s>'9') s=getchar();
	while(s>='0'&&s<='9'){
		if(s=='1') x&=1;
		x<<1;
		s=getchar();
	}
	x>>1;
}
int cmp(int a,int b){
	int cnt=0;
	while(a&&b){
		if(((a&1)==0&&(b&1)==1)||((a&1)==1&&(b&1)==0)) cnt++;
		a>>=1;
		b>>=1;
	}
	return cnt;
}
int maxx,ans[maxn],n,k;
int main(){
	freopen("lamp.in","r",stdin);
	freopen("lamp.out","w",stdout);
	scanf("%d%d",&n,&k);
	memset(ans,0x3f,sizeof(ans));
	int num,m=pow(2.0,(double)(k+1));
	for(int i=1;i<=n;i++){
		read(num);
		for(int j=1;j<=m;j++)
			ans[j]=min(ans[j],cmp(num,j));
	}
	for(int i=1;i<=n;i++)
		maxx=max(ans[i],maxx);
	printf("%d",maxx);
	return 0;
}
