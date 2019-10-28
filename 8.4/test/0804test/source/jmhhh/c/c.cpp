#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;
#define inf 1000000007 
int n,d[2000050],k,Q,tot,cnt;
struct node{
	int x,n;
	friend bool operator <(node a,node b){
	    if(a.x != b.x) return a.x>b.x;
	    else return d[a.n]<d[b.n];
    }
};
int dp[2000050];
priority_queue<node> q;



void cls(){
	priority_queue<node> empty1;
	swap(empty1,q);
	cnt=0,tot=0;
}

int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&d[i]);
		d[i]=d[i];
	}
	scanf("%d",&Q);
	while(Q--){
	    cls();
		scanf("%d",&k);
		node temp;
    	temp.n=1;
    	temp.x=0;
    	q.push(temp);
    	for(int i=2;i<=n;i++){
    		while(!q.empty()){
    			if(q.top().n < i-k) q.pop();
	    		else break;
       		}
    	    temp=q.top();
    	    if(d[temp.n] <= d[i]){
    	    	dp[i]=temp.x+1;
    		}
    		else{
    			dp[i]=temp.x;
    		}
    		temp.n=i,temp.x=dp[i];
    		q.push(temp);	
    	}
    	
    	/*
    	while(!q.empty()){
    		temp=q.top();
    		printf("%d %d\n",temp.n,temp.x);
    		q.pop();
		}
    	for(int i=2;i<=n;i++){
    		printf("%d ",dp[i]);
		}*/
    	
    	printf("%d\n",dp[n]);
	}
}
