#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
int n,nnd;
double r[11],inf=1e5,esp=1e-5,di[10][10],X[10],Y[10],ANS=0;
bool mk[11];
double ddd[11];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%lf %lf",X+i,Y+i);
	for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)di[i][j]=di[j][i]=sqrt(pow(X[i]-X[j],2)+pow(Y[i]-Y[j],2));
	for(int kk=0;kk<n;kk++){
		int I=0;
		while(mk[I])I++;
		for(int i=0;i<n;i++)if(mk[i]==0){
			ddd[i]=inf;
			for(int j=0;j<n;j++)if(i!=j){
				ddd[i]=min(ddd[i],di[i][j]);
			}
			if(ddd[i]>ddd[I])I=i;
		}
		r[I]=ddd[I];
		mk[I]=1;
		for(int i=0;i<n;i++)di[i][I]-=r[I],di[I][i]-=r[I];
	}
	for(int i=0;i<n;i++)ANS+=r[i]*r[i];
	printf("%lf",ANS);
}
