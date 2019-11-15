#include<cstdio>
#include<iostream>
using namespace std;
#define int_ long long
int_ matrix[1010][1010];
int_ read(int_ &x){
	char c=getchar(),last;x=0;
	while(c>'9'||c<'0')last=c,c=getchar();
	while(c<='9'&&c>='0')x=(x<<1)+(x<<3)+c-'0',c=getchar();
	if(last=='-')x=-x;
	return x;
}
struct e{
	int add,num;
}hz[1010],vt[1010];
int main(){
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	int_ n,m,k;
	read(n);read(m);read(k);
	for(int i=1;i<=k;i++){
		int_ x,y,z;
		read(x);read(y);read(z);
		if(x==1)hz[y].add=z,hz[y].num=i;
		else vt[y].add=z,vt[y].num=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(vt[j].add||hz[i].add){
				if(vt[j].num<hz[i].num)
					matrix[i][j]=hz[i].add;
				else if(vt[j].num>hz[i].num)
					matrix[i][j]=vt[j].add;
			}
			printf("%I64d ",matrix[i][j]);
		}	
		printf("\n");
	}
	return  0;
}
