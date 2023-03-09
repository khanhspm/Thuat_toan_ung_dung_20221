#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
int n;
pair<int, int> segs[MAXN];

// Hàm so sánh 2 đoạn thẳng, dùng để sắp xếp mảng segs theo thứ tự tăng dần của điểm kết thúc
bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    // Đọc dữ liệu vào
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        segs[i] = {a, b};
    }

    // Sắp xếp các đoạn thẳng theo thứ tự tăng dần của điểm kết thúc
    sort(segs, segs + n, cmp);

    // Dùng phương pháp chọn lựa tham lam để tìm tập con các đoạn thẳng không giao nhau
    int res = 0, last = -1;
    for (int i = 0; i < n; i++) {
        if (segs[i].first > last) {
            last = segs[i].second;
            res++;
        }
    }

    // In ra kết quả
    cout << res << endl;
    return 0;
}
