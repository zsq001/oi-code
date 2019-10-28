#include<cstdio>
#include<map>
#include<algorithm>
#include<stdlib.h>
#include<string>
using namespace std;
pair<int,int>e[1000005];
map<pair<int,int>,bool>h;
bool dog[1000005],house[1000005];
int n,m,k,maxd,maxk;
int random(int i){
	return (int)(rand()*rand()%i);
}
int main(){
	int a;
	scanf("%d",&a);
	char na[100];
	sprintf(na,"data%d.in",a);
	freopen(na,"w",stdout);
	scanf("%d %d %d %d %d",&n,&m,&k,&maxd,&maxk);
	for(int i=1;i<n;i++){
		int fa=random(i)+1;
		e[i]=make_pair(fa,i+1);
		h[e[i]]=h[make_pair(i+1,fa)]=1;
	}
	for(int i=n;i<=m;i++){
		int x,y;
		do{
			x=random(n)+1;
			y=random(n)+1;
		}while(x==y||h[make_pair(x,y)]);
		e[i]=make_pair(x,y);
		h[e[i]]=h[make_pair(y,x)]=1;
	}
	random_shuffle(e+1,e+m+1);
	for(int i=1;i<=k;i++){
		int f,t;
		do{
			f=random(n)+1;
			t=random(n)+1;
		}while(f==t||dog[f]||dog[t]||house[f]||house[t]);
		dog[f]=1;
		house[t]=1;
	}
	printf("%d %d %d %d %d\n",n,m,k,random(n)+1,maxk);
	for(int i=1;i<=n;i++){
		if(dog[i])printf("%d ",i);
	}
	printf("\n");
	for(int i=1;i<=n;i++){
		if(house[i])printf("%d ",i);
	}
	printf("\n");
	for(int i=1;i<=m;i++){
		printf("%d %d %d %d\n",e[i].first,e[i].second,random(maxd)+1,random(maxd));
	}
}

