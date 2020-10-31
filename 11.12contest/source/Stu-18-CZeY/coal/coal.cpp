#include<cstdio>
int n;
double k,c,w,max;
double map[100010];
bool flag;
struct node{
	int num;
	double val;
}e[100010];

int js(int p){
	p=p-(p*k);
	return p;
}

void dfs(double p,int now,double g){
	if(g > map[now]){
		map[now]=g;
	}
	if(now > n){
		return ;
	}
	if(e[now].num==1){
		flag=false;
		dfs(p*(1-k),now+1,g+(e[now].val*p));
		dfs(p,now+1,g);
	}
	if(e[now].num==2){
		flag=true;
		dfs(p*(1+c),now+1,g-(e[now].val*p));
		dfs(p,now+1,g);
	}
	return ;
}

int main()
{
	int i,j;
	freopen("coal.in","r",stdin);
	freopen("coal.out","w",stdout);
	scanf("%d%lf%lf%lf",&n,&k,&c,&w);
	if(k!=100){
		k=k/100;c=c/100;
	}
	for(i=1;i<=n;i++){
		scanf("%d%lf",&e[i].num,&e[i].val);
		if(e[i].num==1 && e[i].val > max){
			j=i;
			max=e[i].val;
		}
	}
	int ww=w;	
	if(k==100.0){
		printf("%.2lf",w*max);
		return 0;
	}
	if(n<=20){
		dfs(ww,1,0.0);
		printf("%.2lf",map[n+1]);
		return 0;
	}
	int bx=e[1].num;
	double g=0,min;
	if(bx==1){
		max=e[i].val;
	}
	else {
		min=e[i].val;
	}
	for(i=2;i<=n+1;i++){
		if(bx==1 && e[i].num==1 && e[i].val > max){
			max=e[i].val;
		}
		else if(bx==2 && e[i].num==2 && min > e[i].val){
			min=e[i].val;
		}
		else if(bx!=e[i].num){
			if(bx==1){
				g+=max*w;
				w=w*(1-k);
			}
			else {
				if(min*w < g){
					g-=min*w;
					w=w*(1+c);
				}
			}
			bx=e[i].num;
			if(bx==1){
				max=e[i].val;
			}
			else {
				min=e[i].val;
			}
		}
	}
	printf("%.2lf\n",g);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
