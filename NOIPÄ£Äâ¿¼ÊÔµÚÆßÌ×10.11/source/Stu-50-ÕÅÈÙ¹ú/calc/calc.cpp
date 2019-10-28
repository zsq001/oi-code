#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
#define maxn 10005
#define maxm 500005
//#define inf 1<<30
//typedef int int_;
//#define int long long
bool flag1,flag2;
char s[maxn],ch1,ch2;
int left[maxm],right[maxm],len,cnt,lts[maxm],rts[maxm],rs,ans;
using namespace std;
int main(){
	freopen("calc.in","r",stdin);
	freopen("calc.out","w",stdout);
	scanf("%s",s+1);
	len=strlen(s+1);
	for(int i=1;i<=len;i++){
		for(int j=0,l=i,r=i+1;i-j>0,i+j<=len+1;j++,l=i-j,r=i+j+1){
			if(l<=0||r>len+1) break;
			flag1=flag2=0;
			if(s[l]==s[r-1]){
				left[++cnt]=l;
				right[cnt]=r-1;
			}
			else flag1=1;
			if(r==len+1) continue;
			if(s[l]==s[r]){
				left[++cnt]=l;
				right[cnt]=r;
			}
			else flag2=1;
			if(flag1&&flag2) break;
		}
	}
	sort(left+1,left+1+cnt);
	sort(right+1,right+1+cnt);
	lts[cnt]=rts[cnt]=cnt;
	for(int i=cnt-1;i>0;i--){
		if(left[i]<left[i+1]) lts[i]=i;
		else lts[i]=lts[i+1];
		if(right[i]<right[i+1]) rts[i]=i;
		else rts[i]=rts[i+1];
	}
	lts[cnt+1]=-2;
	rs=1;
	for(int lp=1;lp<=cnt;lp++){
		if(rs<0) break;
		for(int rp=rs;rp<=cnt;rp++){
			if(left[rp]<=right[lp]) {
				if(left[rp]==right[lp]){
					rs=lts[lts[rp]+1]+1;
				}
				rp=lts[rp];
				continue;
			}
			else ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
