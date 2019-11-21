#include <fstream>
//#include <vector>
//#include <map>
using namespace std;
ifstream fin;
ofstream fout;
//vector<vector<unsigned> > link;
//vector<pair<unsigned,unsigned> > sides;
unsigned t,n,a,b;
//typedef pair<unsigned,unsigned> Pair;
unsigned long long ans;
int main(){
	fin.open("centroid.in",ios::in);
	fout.open("centroid.out",ios::out);
	fin>>t;
	for(int w=0;w<t;w++){
		fin>>n;
//		link.resize(n+1);
		for(int i=0;i<n;i++){
			fin>>a>>b;
//			link[a].push_back(b);
//			link[b].push_back(a);
//			sides.push_back(Pair(a,b));
			ans+=a+b;
		}
//		for(vector<Pair>::iterator it=sides.begin();it!=sides.end();it++){
//			link[it->first].erase(find(link[it->first].begin(),link[it->first].end(),it->second));
//			link[it->second].erase(find(link[it->second].begin(),link[it->second].end(),it->first));
//			for()
//		}
	}
	fout<<ans<<endl;
	fin.close();
	fout.close();
	return 0;
}
