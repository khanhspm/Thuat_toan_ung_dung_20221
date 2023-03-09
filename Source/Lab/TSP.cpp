#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int n, dist[N][N], dp[1 << N][N];

int tsp(int mask, int pos) {
    if (mask == (1 << n) - 1) return dist[pos][0]; // đã đi qua hết các thành phố
    if (dp[mask][pos] != -1) return dp[mask][pos]; // đã tính toán trước đó

    int ans = INT_MAX;
    for (int city = 0; city < n; city++) {
        if (mask & (1 << city)) continue; // thành phố đã đi qua rồi
        int newMask = mask | (1 << city); // đánh dấu thành phố đã đi qua
        int subproblem = dist[pos][city] + tsp(newMask, city); // tính toán cho bài toán con
        ans = min(ans, subproblem);
    }

    return dp[mask][pos] = ans; // lưu kết quả tính toán
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    memset(dp, -1, sizeof(dp)); // khởi tạo dp
    cout << tsp(1, 0) << endl; // tính toán và in ra kết quả

    return 0;
}
