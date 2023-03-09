#include <bits/stdc++.h>
using namespace std;

const int MAXN = 15;

int n, dist[2*MAXN+1][2*MAXN+1], memo[1<<MAXN][MAXN];
// memo[state][pos]: shortest distance starting from pos, visited passengers are in the state

int dp(int state, int pos) {
    if (state == (1<<n)-1) return dist[pos][0]; // all passengers visited, return to 0
    if (memo[state][pos] != -1) return memo[state][pos];
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (!(state&(1<<i))) { // if passenger i has not been visited
            int new_state = state|(1<<i);
            ans = min(ans, dp(new_state, i+1) + dist[pos][i+1]); // pick up passenger i
            for (int j = 0; j < n; j++) {
                if (i == j || (state&(1<<j)) == 0) continue; // if passenger j has not been picked up
                ans = min(ans, dp(new_state, j+1) + dist[pos][i+1] + dist[i+1][j+1]); // drop off passenger j and pick up i
            }
        }
    }
    return memo[state][pos] = ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); // for faster I/O
    memset(memo, -1, sizeof(memo));
    cin >> n;
    for (int i = 0; i < 2*n+1; i++) {
        for (int j = 0; j < 2*n+1; j++) {
            cin >> dist[i][j];
        }
    }
    cout << dp(0, 0) << "\n";
    return 0;
}
