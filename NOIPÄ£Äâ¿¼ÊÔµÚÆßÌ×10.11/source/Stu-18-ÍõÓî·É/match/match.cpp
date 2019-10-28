#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,maxc_Ai,maxc_Bj,maxc_i,maxc_j,cnt,a[100010],b[100010],pd,c,maxc=-1,j;
int main () {
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>n>>m>>x>>y;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>b[i];
	for(int i=1;i<=n-cnt;i++){
		for(j=1;j<=m-cnt;j++){
			if(a[i]-x<=b[j]&&a[i]+y>=b[j]){
				pd=1;
				if(a[i]-b[j]>=0) c=a[i]-b[j];
				else c=b[j]-a[i];
				maxc=max(maxc,c);
				if(c==maxc){
					maxc_Ai=a[i];
					maxc_Bj=b[j];
					maxc_i=i;
					maxc_j=j;
				}
			}
		}
		if(pd==1){
			pd=0;
			cnt++;
			for(int twa=maxc_i;twa<=n-cnt;twa++){
				a[twa]=a[twa+1];
			}
			for(int twb=maxc_j;twb<=m-cnt;twb++){
				b[twb]=b[twb+1];
			}
			i--;j--;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
