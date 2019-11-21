#include <fstream>
//#include <algorithm>
using namespace std;
ifstream fin;
ofstream fout;
inline unsigned max(unsigned a,unsigned b){
	return (a>b?a:b);
}

//f[n][m]
//使用n种方法，m种主食的最多方案 
unsigned f[105][2010],k[105][2010],maxm[2010],maxn[105];
//unsigned f[105][2010],k[105][2010],maxm[105][2010],maxn[105][2010];
short n,m;
int main(){
	fin.open("meal.in",ios::in);
	fout.open("meal.out",ios::out);
	fin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			fin>>k[i][j];
			if(!(maxm[j]%998244353)||maxm[j]%998244353<k[i][j]%998244353)
				maxm[j]=k[i][j]%998244353;
			if(!(maxn[i]%998244353)||maxn[i]%998244353<k[i][j]%998244353)
				maxn[i]=k[i][j]%998244353;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			f[i][j]=max((f[i][j-1]%998244353+maxm[j]%998244353)%998244353,(f[i-1][j]%998244353+maxn[i]%998244353)%998244353);
	fout<<f[n][m]%998244353<<endl;
	fin.close();
	fout.close();
	return 0;
}
