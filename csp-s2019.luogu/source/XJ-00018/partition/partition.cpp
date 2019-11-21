#include <fstream>
using namespace std;
ifstream fin;
ofstream fout;
unsigned a;
unsigned n;
bool type;
unsigned long long ans;
int main(){
	fin.open("partition.in",ios::in);
	fout.open("partition.out",ios::out);
	fin>>n>>type;
	for(int i=0;i<n;i++){
		fin>>a;
		ans+=a*a;
	}
	fout<<ans<<endl;
	fin.close();
	fout.close();
	return 0;
}
