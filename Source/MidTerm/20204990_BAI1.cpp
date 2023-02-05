#include <iostream>
#include <cmath>

using namespace std;

int countSubsequence(int arr[], int n, int k, int m) {
    int count = 0;

    for (int i = 0; i <= n - k; i++) {
        int sum = 0;
        for (int j = i; j < i + k; j++) {
            sum += arr[j];
        }
        if (sum == m) {
            count++;
        }
    }

    return count;
}

int main() {
    int n, k, m;
    cin >> n >> k >> m;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << countSubsequence(arr, n, k, m) << endl;

    return 0;
}
