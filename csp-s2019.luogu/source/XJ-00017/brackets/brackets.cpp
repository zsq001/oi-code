#include<cstdio>
#include<queue>
using namespace std;
queue<int> q;
bool vis[100010];
int f[100010];
char tree[100010];
int ans;
int n;
int num,mun;

int minn(int x,int y){
	if(x<y)return x;
	return y;
}

int main()
{
	int i;
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	scanf("%d\n",&n);
	for(i=1;i<=n;i++){
		scanf("%c",&tree[i]);
	}
	scanf("%c",&i);
	for(i=2;i<=n;i++){
		scanf("%d",&f[i]);
	}
	for(i=n;i>1;i--){
		num=0;
		mun=0;
		int x=f[i];
		q.push(i);
		while(q.size()){
			int y=q.front();q.pop();
			if(tree[y]==')'){
				num++;
			}
			else {
				mun++;
			}
			if(f[y]!=0){
				q.push(f[y]);
			}
		}
		int mi=minn(num,mun);
		if(i==n){
			ans=mi*i;
		}
		else{
			ans=ans^(mi*i);
		}
	}
	ans=ans^0;
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
