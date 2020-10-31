#include<cstdio>
#include<cstring>

using namespace std;

const int maxn=100010;

int n,m,q;
int rec1[maxn],rec2[maxn];   
int las1[maxn],las2[maxn]; 

inline int in(){
	int x=0;char ch=getchar();
	while(ch>'9' || ch<'0') ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return x;
}

int main(){

	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);

	scanf("%d%d%d",&n,&m,&q);

	int k,x,d;

	for(int i=1;i<=q;i++){
		k=in(),x=in(),d=in();
		
		if(k==1) rec1[x]=d,las1[x]=i;
		else rec2[x]=d,las2[x]=i;
		
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(las1[i]>las2[j])
				printf("%d ",rec1[i]);
			else
				printf("%d ",rec2[j]);
		}
		putchar('\n');
	}

	return 0;
}
