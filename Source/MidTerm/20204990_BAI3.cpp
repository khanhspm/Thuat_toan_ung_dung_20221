#include <iostream>
#include <cmath>

using namespace std;

int countSubset(int arr[], int n, int A, int B) {
    int dp[n + 1][B + 1];

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= B; j++) {
            if (j < arr[i - 1]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
            }
        }
    }

    int count = 0;
    for (int i = A; i <= B; i++) {
        count += dp[n][i];
    }

    return count;
}

int main() {
    int n, A, B;
    cin >> n >> A >> B;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << countSubset(arr, n, A, B) << endl;

    return 0;
}
