#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
char inpu[2048], proc[4096];
typedef std::vector<int> set_t;
set_t fn[4096]; //以某个字符开始的回文字串可能的结束位置 
int sum[4096];  //set_t::size()求和 
int main() {
    freopen("calc.in", "r", stdin);
    freopen("calc.out", "w", stdout);
    scanf("%s", inpu);
    memset(sum, 0, sizeof(sum));
    int len = 2 * strlen(inpu) - 1;
    for (int i = 0; i < len; ++i) {
        if (i & 1) proc[i] = '_';
        else proc[i] = inpu[i >> 1];
    }
    for (int i = 0; i < len; ++i) {
        int f = i, b = i;
        for ( ; f >= 0 && b < len; --f, ++b) {
            if (proc[f] - proc[b]) break;
            if (~f & 1) fn[f].push_back(b);
        }
    }
    int _sum = 0;
    for (int i = 0; i < len; ++i) sum[i] = (_sum += fn[i].size());
    long long ans = 0;
    for (int i = 0; i < len; i += 2) 
        for (set_t::iterator it = fn[i].begin(); it != fn[i].end(); ++it) 
            ans += _sum - sum[*it];
    printf("%I64d\n", ans);
    fflush(stdout);
    return 0;
    
}    
    
