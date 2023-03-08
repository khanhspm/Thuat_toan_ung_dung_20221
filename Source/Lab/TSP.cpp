#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int INF = 1e9;

int main() {
    int n;
    cin >> n;

    int dist[n+1][n+1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> dist[i][j];
        }
    }

    int dp[n+1][1 << n];
    memset(dp, -1, sizeof(dp)); // Khởi tạo tất cả giá trị thành -1
    for (int i = 2; i <= n; i++) {
        dp[i][(1 << i)-2] = dist[1][i]; // Đi qua các đỉnh trừ i
    }

    for (int k = 3; k <= n; k++) { // Kích thước tập S
        for (int S = 0; S < (1 << n); S++) {
            if (!(S & (1 << (k-1)))) continue; // Tập S chưa chứa đỉnh k
            for (int i = 2; i <= n; i++) {
                if (!(S & (1 << (i-1)))) continue; // Tập S chứa đỉnh i
                for (int j = 2; j <= n; j++) {
                    if ((S & (1 << (j-1))) || (i == j)) continue; // Tập S chưa chứa đỉnh j và i khác j
                    if (dp[i][S] != -1) { // Nếu có thể đi tới đỉnh i
                        int new_dist = dp[i][S] + dist[i][j];
                        int new_S = S | (1 << (j-1));
                        if (dp[j][new_S] == -1 || dp[j][new_S] > new_dist) {
                            dp[j][new_S] = new_dist;
                        }
                    }
                }
            }
        }
    }

    int ans = INF;
    for (int i = 2; i <= n; i++) {
        if (dp[i][(1 << n)-1] != -1) {
            ans = min(ans, dp[i][(1 << n)-1] + dist[i][1]);
        }
    }

    cout << ans << endl;

    return 0;
}
