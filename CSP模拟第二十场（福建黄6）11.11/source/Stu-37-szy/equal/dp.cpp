#include <bits/stdc++.h>

int main() {
    for (int tim = 0; ; ++tim) {
        system("gen.exe");
        system("equal.exe");
        system("bf.exe");
        if (system("fc bf.out equal.out")) {
            printf("WA on pretest %d\n", tim);
            break;
        } else {
            printf("AC on pretest %d\n", tim);
        }
    }
    return 0;
}
