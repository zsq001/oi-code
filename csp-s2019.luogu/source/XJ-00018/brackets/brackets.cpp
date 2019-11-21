#include <iostream>
#include <fstream>
using namespace std;
ifstream fin;
ofstream fout;
int n;
unsigned long long ans;
char tree[500010];
class _bt{
public:
	int index,r,l,id;
	_bt():index(0),r(0),l(0),id(0){}
	_bt& operator=(const _bt& v){
		index=v.index;
		l=v.l;
		r=v.r;
		return (*this);
	}
};
_bt f[500010];
void Read(){
	fin>>n;
	fin.get();
	char str[500010];
	int p;
	for(int i=0;i<n;i++)
		str[i]=fin.get();
	tree[1]=str[0];
	f[1].id=1;
	for(int i=1;i<n;i++){
		fin>>p;
		if(tree[p*2]){
			tree[p*2+1]=str[i];
			f[p*2+1].id=i+1;
		}
		else{
			tree[p*2]=str[i];
			f[p*2].id=i+1;
		}
	}
}
void DFS(int k){
	f[k]=f[k/2];
	if(tree[k]=='(')
		f[k].l+=1;
	else
		f[k].r+=1;
	if(f[k].l&&f[k].r){
		f[k].l--;
		f[k].r--;
		f[k].index++;
	}
	ans^=f[k].index*f[k].id;
	if(tree[k*2]){
		DFS(k*2);
		if(tree[k*2+1])
			DFS(k*2+1);
	}
}
int main(){
	fin.open("brackets.in",ios::in);
	fout.open("brackets.out",ios::out);
	Read();
	DFS(1);
	fout<<ans<<endl;
	fin.close();
	fout.close();
	return 0;
}
