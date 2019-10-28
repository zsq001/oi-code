#include<cstdio>
#include<algorithm>
using namespace std;

int n,k;

int state[200050];
int ansstate[200050],tot,cnt,minn=101,ans=-1;
int a[200050];

void init_(){
	for(int i=0;i<=(1<<k)-1;i++){
		if(ansstate[i]==0)
		state[++cnt]=i;
	}
}



int main()
{
	freopen("lamp.in","r",stdin);
	freopen("lamp.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int j=1;j<=n;j++){
		int t=0;
		for(int i=k-1;i>=0;i--){
   	    	int tp;
     		scanf("%1d",&tp);
     		t|=tp<<i;
	    }   
	    if(ansstate[t]==0){
	    	a[++tot]=t;
	    	ansstate[t]=1;
		}
	}
	init_();
    for(int j=1;j<=cnt;j++){
    	minn=101;
    	for(int i=1;i<=tot;i++){
    		int tp=a[i]^state[j];
    		int t=0;
    		while(tp>0){
    			int qaq=tp&(-tp);
    			tp-=qaq;
    			t++;
			}
			minn=min(minn,t);
		}
		ans=max(minn,ans);
	}
	if(cnt==0) printf("%d",0);
	else
	printf("%d",ans);
}

