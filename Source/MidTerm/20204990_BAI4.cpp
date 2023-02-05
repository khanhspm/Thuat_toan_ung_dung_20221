#include <iostream>
#include <cmath>

using namespace std;

int maxSubsequence(int arr[], int n) {
    int dp[n];
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);

    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);
    }

    return dp[n - 1];
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << maxSubsequence(arr, n) << endl;

    return 0;
}
