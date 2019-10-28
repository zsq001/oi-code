#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
int n,nnd;
double r[100000][11],inf=1e5,esp=1e-5,di[10][10],X[10],Y[10],ANS=0;
int lk[100000][150],nlk[100000],newd[100000];
bool mk[100000];
vector<int> q[10];
void init(int b){
	int dem=0;
	int a=b;
	for(int i=0;i<n;i++){
		if(a%3==2)dem++;
		else{
			r[b][i]=(a%3)*inf;
			int c=b-pow(3,i)*(a%3)+pow(3,i)*2;
			lk[c][nlk[c]++]=b;
//			add(b-pow(3,i)*(a%3)+pow(3,i)*2,b);
		}
		a/=3;
	}
	q[dem].push_back(b);
}
double area(int a){
	double ans=0;
	for(int i=0;i<n;i++)ans+=r[a][i]*r[a][i];
	return ans;
}
void addnode(int a,int b,int c,int d){
	//(di-inmax.r[a]-inmax.r[b])/(outmax.r[a]-inmax.r[a]+outmax.r[b]-inmax.r[b]);
	double gm=(di[c][d]-r[a][c]-r[a][d])/(r[b][c]+r[b][d]-r[a][c]-r[a][d]);
//	printf("ND %d(%.2lf)@%.9lf\n",nnd,di[c][d],gm);
	for(int i=0;i<n;i++){
		r[nnd][i]=r[a][i]+(r[b][i]-r[a][i])*gm;
//		printf("%.2lf\t",r[nnd][i]);
	}
//	printf("fa:%d %d(%d,%d)\n",c,d,a,b);
//	for(int i=0;i<n;i++){
//		printf("%.2lf\t",r[a][i]);
//	}
//	printf("\n");
//	for(int i=0;i<n;i++){
//		printf("%.2lf\t",r[b][i]);
//	}
	
//	printf("\n");
}
void calc(int a,int b){
	//D0 
	for(int i=0;i<q[0].size();i++){
		if(r[q[0][i]][a]+r[q[0][i]][b]>di[a][b]+esp)mk[q[0][i]]=1;
	}
	//D1
	for(int i=0;i<q[1].size();i++){
		int p=q[1][i];
		if(mk[p])continue;
		int f=lk[p][0],t=lk[p][1];
//		printf("<%d,(%d,%d)>%d\n",p,f,t,nlk[p]);
		if(mk[f]&&mk[t]){
			mk[p]=1;
			continue;
		}
		int fg=0;
		if(mk[f]==0&&mk[t]==1)fg=1;
		else if(mk[f]==1&&mk[t]==0)fg=2;
		if(fg){
//			printf("(%d)",p);
			if(mk[t])addnode(f,t,a,b);
			else     addnode(t,f,a,b);
			q[0].push_back(nnd);
			if(fg==1)lk[p][1]=nnd;
			else lk[p][0]=nnd;
			newd[p]=nnd;
			nnd++;
		}
	}
	for(int dm=2;dm<=n;dm++){
		for(int i=0;i<q[dm].size();i++){
			int p=q[dm][i];
			int fg=0;
			for(int j=0;j<nlk[p];j++)if(mk[lk[p][j]]==0){
				if(newd[lk[p][j]])lk[nnd][nlk[nnd]++]=newd[lk[p][j]];
				fg=1;
			}
			if(fg==0){
				mk[p]=1;
//				printf("mk:%d(%d)-------------------\n",p,dm);
			}
			if(nlk[nnd]<dm){
				nlk[nnd]=0;
				continue;
			}
			if(nlk[nnd]){
				q[dm-1].push_back(nnd++),newd[p]=nnd-1;
				lk[p][nlk[p]++]=nnd-1;
			}
		}
	}
	for(int dm=0;dm<=n;dm++){
		for(int i=0;i<q[dm].size();i++){
			int p=q[dm][i];
			newd[p]=0;
			if(mk[p])swap(q[dm][i],q[dm].back()),q[dm].pop_back();
			else{
				for(int j=0;j<nlk[p];j++){
					if(mk[lk[p][j]]){
						swap(lk[p][j],lk[p][--nlk[p]]);
					}
				}
			}
		}
	}
}
int main(){
	freopen("protect.in","r",stdin); 
	freopen("protect.out","w",stdout); 
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%lf %lf",X+i,Y+i);
	nnd=(int)pow(3,n);
	for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)di[i][j]=di[j][i]=sqrt(pow(X[i]-X[j],2)+pow(Y[i]-Y[j],2));
	for(int i=0;i<nnd;i++){
		init(i);
	}
	//for(int ii=0;ii<n;ii++){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			calc(i,j);
		}
	}
	//}
	for(int i=0;i<q[0].size();i++)if(mk[q[0][i]]==0){
		double tp=area(q[0][i]);
//		for(int j=0;j<n;j++)printf("%.2lf\t",r[q[0][i]][j]);
//		printf("%d %lf######\n",q[0][i],tp);
		ANS=max(ANS,tp);
	}
	printf("%.2lf",ANS);
}
