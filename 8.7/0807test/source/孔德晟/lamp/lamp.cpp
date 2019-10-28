#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

char num[20];
int cm2[20]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144};
bool den[140010];
int sum[140010],flag[140010];
int main() {
	int n,k;
	freopen("lamp.in","r",stdin);
	freopen("lamp.out","w",stdout);
	scanf("%d%d\n",&n,&k);
	while (n--) {
		int ret=0;
		scanf("\n%s",num);
		int l=strlen(num),cnt=0;
		for (int i=l-1;i>=0;i--){
			if(num[i]=='1') ret+=cm2[cnt];
			cnt++;
		}
		den[ret]=true;
	}
	int tot=0;
	for(int i=0;i<cm2[k+1];i++){
		if(den[i]) tot++;
		else{
			int hh=i;
			for(int j=0;j<=k;j++){
				for(int z=0;z<=j;z++){
					if(hh & cm2[j]==0){
						hh += cm2[z];
						if(den[hh]){
							hh -= cm2[z];
							sum[hh]++;
						}
					}
				}
				if(hh & cm2[j]==0) hh += cm2[j];
			}
			for(int j=0;j<=k;j++){
				for(int z=0;z<=j;z++){
					if(hh & cm2[j]){
						hh -= cm2[z];
						if(den[hh]){
							hh += cm2[z];
							sum[hh]++;
						}
					}
				}
				if(hh & cm2[j]) hh -= cm2[j];
			}  
		}
	}
	int ax=-1;
	for(int i=0;i<=k;i++){
		ax=max(sum[i],ax);
	}
	printf("%d",ax);
	return 0;
}
