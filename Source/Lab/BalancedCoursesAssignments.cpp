#include <iostream>
#include <cstring>
using namespace std;

const int MAXM = 10;
const int MAXN = 30;
const int MAXK = 100;

int m, n, k;
int teacher[MAXM][MAXN];
bool conflict[MAXN][MAXN];
int dp[MAXM][1<<MAXN];

int solve(int i, int mask) {
    if (mask == (1<<n)-1) return 0;
    if (i == m) return 1e9;
    if (dp[i][mask] != -1) return dp[i][mask];
    int ans = 1e9;
    for (int j = 0; j < (1<<n); j++) {
        if ((mask & j) == 0) {
            bool ok = true;
            for (int c1 = 0; c1 < n && ok; c1++) {
                if ((j & (1<<c1)) != 0) {
                    for (int c2 = c1+1; c2 < n && ok; c2++) {
                        if ((j & (1<<c2)) != 0 && conflict[c1][c2]) {
                            ok = false;
                        }
                    }
                    bool found = false;
                    for (int t = 0; t < MAXN && !found; t++) {
                        if ((j & (1<<c1)) != 0 && teacher[i][t] == c1+1) {
                            found = true;
                        }
                    }
                    if (!found) {
                        ok = false;
                    }
                }
            }
            if (ok) {
                ans = min(ans, max(solve(i+1, mask|j), __builtin_popcount(j)));
            }
        }
    }
    return dp[i][mask] = ans;
}

int main() {
    memset(dp, -1, sizeof(dp));
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> teacher[i][j];
        }
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        int c1, c2;
        cin >> c1 >> c2;
        conflict[c1-1][c2-1] = conflict[c2-1][c1-1] = true;
    }
    int ans = solve(0, 0);
    if (ans == 1e9) {
        cout << "-1" << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}
