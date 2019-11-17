#include<cstdio>
long long map[200010];
int n,m;
int main()
{
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%lld",&map[i]);
	}
	int x,y,z,k,l;
	while(m--){
		scanf("%d",&x);
		if(x==1){
			scanf("%d%d",&y,&z);
			long long max=-1;
			long long min=214748364;
			for(i=y;i<=z;i++){
				if(map[i] > max){
					max=map[i];
				}
				if(map[i] < min){
					min=map[i];
				}
			}
			printf("%lld\n",max-min);
		}
		else {
			scanf("%d%d%d%d",&y,&z,&k,&l);
			for(i=y;i<=z;i++){
				map[i]=k;
				k+=l;
			}
		}
	}
	return 0;
}
