#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int N=5050;

char s[N];
int n,ans=0;
int cnt[N];

int main(){
	freopen("calc.in","r",stdin);
	freopen("calc.out","w",stdout);
	
	scanf("%s",s+1);
	n=strlen(s+1);
	int l,r,t;
	for(int i=1;i<=n;i++){
		l=i; r=i; t=i*2-1;
		while(1<=l&&r<=n&&s[l]==s[r]){
			++cnt[t];
			--l; ++r;
		}
	}
	for(int i=1;i<n;i++){
		l=i; r=i+1; t=i*2;
		while(1<=l&&r<=n&&s[l]==s[r]){
			++cnt[t];
			--l; ++r;
		}
	}
	t=n*2;
	int a,b,c,d;
	
//	int al,br;
//	for(int i=1;i<t;i++)printf("%d ",cnt[i]);puts("");
	
	for(int i=1;i<t;i++){
		if(!cnt[i])continue;
		l=i+2+(i%2==0);
		a=(i&1)?((i+1)/2+cnt[i]-1):(i/2+cnt[i]);
//		al=(i&1)?((i+1)/2-cnt[i]+1):(i/2-cnt[i]+1);
		for(int j=l;j<=t;j++){
			if(!cnt[j])continue;
			b=(j&1)?((j+1)/2-cnt[j]+1):(j/2-cnt[j]+1);
//			br=(j&1)?((j+1)/2+cnt[j]-1):(j/2+cnt[j]);
//			printf("%d %d | (%d,%d) (%d,%d) ",i,j,al,a,b,br);
			r=0;
			if(a<b)r+=cnt[i]*cnt[j];
			else {
				r+=(cnt[i]-(a-b+1))*cnt[j];
//				r+=cnt[i]*(a-b);
				r+=cnt[j]*(a-b+1)-((a-b+2)*(a-b+1))/2;
			}
//			printf("%d\n",r);
			ans+=r;
		}
	}
	printf("%d\n",ans);
	return 0;
}
