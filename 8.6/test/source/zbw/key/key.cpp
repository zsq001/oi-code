#include<cstdio>
#include<algorithm>
#include<cstring>
int n,m,cnt,sum,a[100010],ans[100010];
char s[100010];
int main(){
	freopen("key.in","r",stdin);
	freopen("key.out","w",stdout);
	scanf("%s",&s);
	while(s[++n]) a[n]=s[n-1]-'0';
	a[n]=s[n-1]-'0';
	m=n/3*2;
	for(int i=2;i<=n;i++){
		if(a[i]!=a[i-1]) sum++;
		if(sum>=m){
			puts("0");
			return 0;
		}
	}
	m-=sum;
	int i=1;
	while(m>0){
		if(a[i]==1){
			if(a[i-1]==0&&a[i-2]==0&&a[i+1]==1&&i-2>=1&&i+1<=n){
				ans[++cnt]=i-1;
				m-=2;
			}
			else if(a[i-1]==1&&a[i+1]==0&&a[i+2]==0&&i-1>=1&&i+2<=n){
				ans[++cnt]=i;
				m-=2;
			}
		}
		if(m<=0) break;
		if(a[n-1]==(a[n]^1)&&a[n-2]==(a[n]^1)&&n-2>=1){
			ans[++cnt]=i-1;
			m-=1;
		}
		if(m<=0) break;
		if(a[2]==(a[1]^1)&&a[3]==(a[1]^1)&&3<=n){
			ans[++cnt]=i-1;
			m-=1;
		}
		i++;
	}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++) printf("%d ",ans[i]);
}
