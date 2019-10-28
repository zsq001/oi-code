#include<cstdio>
#include<cstring>
int dx[4]={0,0,-1,1},dy[4]={1,-1,0,0};
int dis1[16],dis2[16],want,cnt,head[20],f[16][16],fa[17];
bool vis[16][16],flag;

struct node{
	int v,next,w,u;
}e[250];

void add(int u,int v,int w){
	e[++cnt].next=head[u];
	e[cnt].u=u;
	e[cnt].v=v;
	e[cnt].w=w;
	head[u]=cnt;
}

int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

void cha(){
	//sort(e+1,e+cnt+3,e++);
	for(int i=1;i<=cnt+2;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		int fu=find(u),fv=find(v);
		if(fu==fv)continue;
		
	}
}

bool check(){
	for(int i=1;i<=5;i++)
		for(int j=1;j<=5;j++)
			if(f[i][j])return 0;
	return 1;
}

void update(int x,int y){
	f[x][y]=f[x][y]?0:1;
	for(int i=0;i<4;i++){
		int nx=dx[i]+x,ny=dy[i]+y;
		if(nx<=5&&nx>0&&ny<=5&&ny>0)f[nx][ny]=f[nx][ny]?0:1;
	}
}

void Print(){
	for(int i=1;i<=5;i++){
		for(int j=1;j<=5;j++)printf("%d ",f[i][j]);
		puts("");
	}
}

bool dfs(int now){
	if(now==want){
		return check();
	}
	for(int i=1;i<=5;i++){
		for(int j=1;j<=5;j++){
			if(vis[i][j]) continue;
			vis[i][j]=1;
			update(i,j);
			if(dfs(now+1)){
//				printf("%d %d\n",i,j);
//				Print();puts("");
				return 1;
			}
			vis[i][j]=0;
			update(i,j);
		}
	}
	return 0;
}

int main(){
	int n,k,a,qwq;
	freopen("save.in","r",stdin);
	freopen("save.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&dis1[i]);
	//	add(n+1,i,qwq);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&dis2[i]);
	//	add(i,n+2,qwq);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&a);
			if(a)add(i,j,a);
		}
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=5;j++){
			for(int k=1;k<=5;k++){
				scanf("%d",&f[j][k]);
			}
		}
		flag=0;
		for(want=0;want<=25;want++){
			if(dfs(0)){
				break;
			}
		}
		if(want==26){
			puts("NO");
			return 0;
		}
		sum+=want*k;
	//	printf("want=%d,sum=%d\n",want,sum);
		std::memset(vis,0,sizeof(vis));
	}
	puts("YES");
	if(n==1){
		printf("%d",sum+dis1[1]+dis2[1]);
		return 0;
	}
	if(n==2){
		printf("%d",sum+dis1[1]+dis2[2]+e[1].w);
		return 0;
	}
	//add(1,)
//	for(int i=1;i<=n+4;i++)fa[]
	//dfs(n+2);
}
//1 1
//0
//0
//1
//0 0 1 0 0
//0 1 1 1 0
//1 0 1 0 0
//1 1 0 0 0
//1 0 0 0 0

//2 4
//2 3
//1 1
//0 6
//6 0
//0 0 0 0 0
//1 0 0 0 0
//1 1 0 0 0
//1 0 0 0 0
//0 0 0 0 0
//0 0 1 0 0
//0 1 1 1 0
//1 0 1 0 0
//1 1 0 0 0
//1 0 0 0 0

