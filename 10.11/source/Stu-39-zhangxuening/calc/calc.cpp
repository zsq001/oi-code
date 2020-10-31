#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long

int len,cnt;
bool f[2005][2005];

char c[2002];
void find1(int mid){
	int m=min(mid,len-mid+1),l;
	for(l=1;l<=m;l++){
		if(c[mid-l+1]==c[mid+l-1]) f[mid-l+1][mid+l-1]=1;
		else return ;
	}
}

void find2(int left){
	int m=min(left-1,len-left-1),l;
	for(l=0;l<=m;l++) {
		if(c[left-l]==c[left+1+l]) f[left-l][left+1+l]=1;
		else return ;
	}
}


int main(){
	scanf("%s",c+1);
	len=strlen(c+1);
	ll ans=0;
	for(int i=1;i<len;i++){
		find1(i);find2(i);
	}
	find1(len);
	//sort(f+1,f+1+cnt,cmp);
	for(int i=1;i<=len;i++){
		for(int j=i;j<=len;j++)
			if(f[i][j]) printf("%d %d\n",i,j);
	}
	for(int i=1;i<=len;i++){
		for(int j=i;j<=len;j++){
			if(!f[i][j])continue;
			for(int l=j+1;l<=len;l++){
				for(int k=l;k<=len;k++){
					if(f[l][k]) ans++;
				}
			}
		}
	}
	printf("%lld",ans);
}
