#include<cstdio>
int map[1010][1010];
int hang[1010];
int lie[1010];
int tot;
struct node{
	int num,val,ans;
	bool flag;
}e[1000010];


int main()
{
	int n,m,q;
	int i,j,k;
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	int x,y,z;
	while(q--){
		scanf("%d%d%d",&x,&y,&z);
		if(x==1){
			tot++;
			if(hang[y] > 0){
				e[hang[y]].flag=true;
			}
			hang[y]=tot;
			e[tot].num=1;
			e[tot].ans=y;
			e[tot].val=z;
		}
		else {
			tot++;
			if(lie[y] > 0){
				e[lie[y]].flag=true;
			}
			lie[y]=tot;
			e[tot].ans=y;
			e[tot].num=2;
			e[tot].val=z;
		}
	}
	for(i=1;i<=tot;i++){
		if(e[i].flag==true){
			continue;
		}
		if(e[i].num==1){
			for(j=1;j<=m;j++){
				map[e[i].ans][j]=e[i].val;
			}
		}
		else if(e[i].num==2){
			for(j=1;j<=n;j++){
				map[j][e[i].ans]=e[i].val;
			}
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			printf("%d ",map[i][j]);
		}
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
