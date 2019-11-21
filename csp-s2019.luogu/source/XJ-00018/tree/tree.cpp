#include <iostream>
#include <fstream>
using namespace std;
ifstream fin;
ofstream fout;
int t,n;
int b;
int main(){
	fin.open("tree.in",ios::in);
	fout.open("tree.out",ios::out);
	fin>>t;
	for(int i=0;i<t;i++){
		fin>>n;
		for(int i=1;i<=n;i++)
			fout<<i<<" ";
		for(int i=0;i<n;i++)
			fin>>b;
		for(int i=1;i<n;i++)
			fin>>b;
		for(int i=1;i<n;i++)
			fin>>b;
	}
	fin.close();
	fout.close();
	return 0;
}
