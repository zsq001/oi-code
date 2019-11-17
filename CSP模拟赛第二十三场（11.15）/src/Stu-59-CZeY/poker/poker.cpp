#include<cstdio>
#include<queue>
using namespace std;
long long n,m,map;
long long ans,num;
priority_queue<long long,vector<long long>,greater<long long> >q;
int main()
{
	long long i,j;
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",&map);
		q.push(map);
	}
	if(n==1){
		printf("%lld",m+q.top());
		return 0;
	}
	ans+=q.top();//poker;
	num=q.top();
	q.pop();
	i=1;
	long long now;
	while(m>0){
		if(i>n)i=n;
		now=q.top();
		now-=num;
		if(now <= 0)now=1;
		if(m-(now*i) >= 0 && now > 0){
			ans+=now;
			m-=now*i;
		}
		if(m-(now*i) <= 0){
			break;
		}
		q.pop();
		if(q.empty()){
			q.push(1);
		}
		i++;
		num+=now;
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
