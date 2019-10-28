#include <cstdio>
#include <cstring>
using namespace std;
char ch[2010];
int lenn;
long long tot,ans;
struct pack {int l,r;} save[200010];
void DEBUG(){
	printf("DEBUG:\n");
	for(int i=1;i<=tot;++i) printf("%d %d\n",save[i].l,save[i].r);
	printf("\n");
}
int main(){
	freopen("calc.in","r",stdin);
	freopen("calc.out","w",stdout);
	scanf("%s",ch); lenn=strlen(ch);
	for(int i=0;i<lenn;++i)
		for(int j=i;j<lenn;++j)
			if(ch[i]==ch[j]){
				int ii=i,jj=j;
				while(ii<=jj){
					if(ch[ii]!=ch[jj]) break;
					++ii; --jj;
				}
				if(ii>jj) {save[++tot].l=i; save[tot].r=j;}
			}
//	DEBUG();
	for(int i=1;i<=tot;++i)
		for(int j=1;j<=tot;++j)
			if(i!=j&&save[j].l>save[i].r) {++ans; /*printf("%d %d %d %d\n",save[i].l,save[i].r,save[j].l,save[j].r);*/}
	printf("%lld",ans);
	return 0;
}
