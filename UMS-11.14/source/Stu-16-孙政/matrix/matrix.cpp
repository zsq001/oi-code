#include<bits/stdc++.h>
using namespace std;
int n,m,q;
int matrixSo[1000][1000];
void event_o(int how,int many,int what){
	switch(how) {
		case 1:{
			for(int i=0;i<m;i++){
				matrixSo[many][i]=what;
			}
			break;
		}
		case 2:{
			for(int i=0;i<n;i++){
				matrixSo[i][many]=what;
			}
			break;
		}
		default:
			break;
	}
}
int main(){
	int how,many,what;
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	scanf("%d %d %d",&n,&m,&q);
	memset(matrixSo,0,sizeof(matrixSo));
	for(int i=0;i<q;i++){
		scanf("%d %d %d",&how,&many,&what);
		event_o(how,many-1,what);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m-1;j++){
		printf("%d ",matrixSo[i][j]);
		}	
		printf("%d\n",matrixSo[i][m-1]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
