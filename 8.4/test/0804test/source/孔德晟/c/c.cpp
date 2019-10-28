#include<stdio.h>
#include<algorithm>
#define maxn 1000010
using namespace std;
int hill[maxn],able;
int n,Q,cnt;
int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&hill[i]);
	scanf("%d",&Q);
	while(Q--){
		scanf("%d",&able);
		if(able==1){
			for(int i=1;i<=n;i++){
				if(hill[i]>hill[i-1]) cnt++;
			}
			printf("%d\n",cnt);
			cnt=0;
		}
		else{
			int pos=1;
			while(pos!=n){
				int ax=-1,in=-1,posax,posin;
				for(int i=pos;i<=pos+able&&i<=n;i++){
					if(ax<hill[i]){
						ax=hill[i];
						posax=i;
					}
					if(in<=hill[i]&&hill[i]<=hill[pos]&&i!=pos){
						in=hill[i];
						posin=i;
					}
				}
				if(in>=hill[pos]||in==-1){
					pos=posax;
					cnt++;
				}
				else{
					pos=posin;
				}
			}
			printf("%d\n",cnt);
			cnt=0;
		}
	}
	return 0;
}
