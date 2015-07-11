// Copyright 2015 Hezhu
#include <cstdio>
#include <cstring>

bool b[1000001];

int main() {
    int L, R;
    while (scanf("%d %d", &L, &R) == 2) {
        memset(b, true, sizeof b);
        if (L == 1) {
            b[0] = false;
        }
        for (int i = 2; i < 40000; ++i) {
            for (int j = (L / i > 2 ? L / i : 2) * i; j <= R; j += i) {
                if (j >= L) {
                    b[j - L] = false;
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i <= R - L; ++i) {
            if (b[i]) {
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
