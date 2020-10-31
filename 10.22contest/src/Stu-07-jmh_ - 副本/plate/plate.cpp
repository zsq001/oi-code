#include<cstdio>
#include<algorithm>
using namespace std;

int n,m,p,ans;
int k[505][505];
int fa[505],w[505];

int findd(int x){
	if(x!=fa[x]) return fa[x]=findd(fa[x]);
	else return fa[x];
}

int main()
{
	freopen("plate.in","r",stdin);
	freopen("plate.out","w",stdout);
    scanf("%d %d %d",&n,&m,&p);
    for(int i=1;i<=n;i++){
    	fa[i]=i;
    	w[i]=1;
	}
    if(m==1){
    	printf("%d",(n-1)*n/2);
    	return 0;
	}
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		scanf("%d",&k[i][j]);    		
		}
		sort(k[i]+1,k[i]+1+m);
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int flag=2;
			int dif=k[i][1]-k[j][1];
			dif=(dif+p)%p;
			for(int l=m;l>=2;l--){
				int ddd=k[i][l]-k[j][l];
				ddd=(ddd+p)%p;
				if(ddd != dif){
					flag--;
					break;
				}
			}
			dif=k[i][1]-k[j][m];
			dif=(dif+p)%p;
			for(int l=m-1;l>=1;l--){
				int ddd=k[i][m-l+1]-k[j][l];
				ddd=(ddd+p)%p;
				if(ddd != dif){
					flag--;
					break;
				}
			}
			if(flag!=0){
				if(findd(i)!=i) continue;
				ans+=w[findd(i)];
				fa[j]=i;
				w[i]+=w[j];
			}
		}
	}
	printf("%d",ans);
	return 0;
}
/*
5 2 4
1 2
2 3
3 4
4 1
2 3
*/
