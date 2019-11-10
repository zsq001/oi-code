#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;




int n,m,ans;
int s[1000005],tf[1000005],tb[1000005];
int t[1000005];
int numf[100005],numb[1000005];
int ft,bk,lth;
vector<int> pos[1005];


int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&s[i]);
		pos[s[i]].push_back(i-1);
	}
	for(int k=1;k<=m;k++){
		int opt,tp;
		scanf("%d %d",&opt,&tp);
	    if(opt==0){
	    	ans=0;
	    	tb[++bk]=tp;
	    	for(int i=1;i<=(int)pos[tp].size();i++){
	    		int ppp=bk-pos[tp][i-1];
	    		if(ppp<=0){
	    			ppp=-ppp+1;
	    			if(ppp>ft) continue;
	    			numf[ppp]--;
				} 
				else{
					numb[ppp]--;
				}
			}
			for(int i=1;i<=ft;i++){
				if(numf[i]>=0) ans++;
			}	
			for(int i=1;i<=bk;i++){
				if(numb[i]>=0) ans++;
			}
		}
		else{
			tf[++ft]=tp;
			int pt=1,flag=0;
			for(int i=ft;i>=1;i--){
				if(s[pt]==tf[i]) flag=1;
				pt++;
			}
			for(int i=1;i<=bk;i++){
				if(s[pt]==tb[i]) flag=1;
				pt++;
			}
			if(flag) numf[ft]=-1;
			else ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
