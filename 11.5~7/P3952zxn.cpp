#include<cstdio>
#include<algorithm>
#include<cstring>
#include<stack>
using namespace std;

#define maxn 110
int read(){
	int ret=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') {
		ret=(ret<<3)+(ret<<1)+(ch&15);
		ch=getchar();	
	}
	return ret;
}

void getl(char *ch){
	memset(ch,0,sizeof(ch));
	int i=0;ch[i]=getchar();
	while(ch[i]!='\n'){
		ch[i+1]=getchar();
		i++;
	}
}
int main(){
	int T;
//	freopen("complexity.in","r",stdin);
//	freopen("complexity.out","w",stdout);
	scanf("%d",&T);int qwqwq=getchar();
	while(T--){
		int ans=0;
		char ch[20];
		getl(ch);
		stack <int> add;
		stack <char> s;
		int j=0;
		int n=0,now=0,cf=0;
		while(ch[j]<='9'&&ch[j]>='0'){
			n=n*10+ch[j]-'0';j++;
		}
		if(ch[j+1]=='1') cf=0;
		else {
			j+=5;
			while(ch[j]<='9'&&ch[j]>='0'){
				cf=cf*10+ch[j]-'0';j++;
			}
		}
		bool f[30]={0},flg=0,no=0;
		
		for(int i=1;i<=n;i++){
			getl(ch);
			if(ch[0]=='F') {
				if(f[ch[2]-'a']){
					flg=1;continue;
				}
				if(ch[1]==' '){
					s.push(ch[2]);
					f[ch[2]-'a']=1;
				}else {
					flg=1;
					continue;
				}
				int j=4,num1=0,num2=0;
				while(ch[j]<='9'&&ch[j]>='0') {
					num1=num1*10+ch[j]-'0';
					j++;
				}
				j--;
				if(j==3&&ch[4]=='n') num1=1<<29;//第一位为n
				if(j>3){//第一位为数字 
					j=j+2;//第二位 
					while(ch[j]<='9'&&ch[j]>='0'){
						num2=num2*10+ch[j]-'0';
						j++;
					}
					j--;
					if(ch[j+1]=='n'&&num2==0) num2=1<<29;//为n 
				}else {
					j=6;
					while(ch[j]<='9'&&ch[j]>='0'){
						num2=num2*10+ch[j]-'0';
						j++;
					}
					j--;
					if(ch[j+1]=='n'&&num2==0) num2=1<<29;
				}
				if(!no){
					if(num2-num1>=0){
						if(num2-num1>=1<<28) add.push(1),now++;
						else add.push(0);
					}else add.push(-1),no=1;
				}else add.push(0);
			}
			if(ch[0]=='E') {
				if(s.empty()) flg=1;
				else{
					f[s.top()-'a']=0;
					s.pop();
					if(!no){
						ans=max(ans,now);
						now-=add.top();
					}
					if(add.top()==-1) no=0;
					add.pop();
				}
			}
			if(i==n){
				if(!s.empty())flg=1;
				if(flg){puts("ERR");
				}else{
					if(ans==cf) puts("Yes");
					else puts("No");
				}
			}
			
		}
	}
	return 0;
}

