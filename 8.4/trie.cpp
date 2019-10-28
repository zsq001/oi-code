#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
 
struct node
    {
        int flag;
        node* son[30];
 
        // node(){flag=0;memset(son,0,sizeof(son));}
    };
 
class Trie
{
    private:
        node *root;
 
    public:
        bool exist(string);
        void insert(string);    
        Trie();
};
 
Trie::Trie()
{
    root=new node;
}
 
bool Trie::exist(string s)
{
    int i,c,len=s.size();
    node *now=root;
 
    for(i=0;i<len;i++)
    {
        c=s[i]-'a';
        if(now->son[c] == NULL) return 0;
        now=now->son[c];
    }
    return now->flag==1;
}
 
void Trie::insert(string s)
{
    int i,c,len=s.size();
    node *now=root;
 
    for(i=0;i<len;i++)
    {
        c=s[i]-'a';
        if(now->son[c] == NULL) now->son[c]=new node;
        now=now->son[c];
    }
    now->flag=1;
}
 
Trie ww;
 
void readList()
{
    int T;
    string s;
    cin>>T;
 
    while(T--)
    {
        cin>>s;
        ww.insert(s);
    }
}
 
void work()
{
    int T,cnt=0;
    string s;
    cin>>T;
 
    while(T--)
    {
        cin>>s;
        cnt+=ww.exist(s);
    }
 
    cout<<cnt<<endl;
}
 
int main(void)
{
    freopen("mtest.in","r",stdin);
    freopen("mtest.out","w",stdout);
    
 
    readList();
    work();
    
    return 0;
}
