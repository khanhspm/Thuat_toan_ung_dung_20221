#include <iostream>
#include <cstring>
using namespace std;

const int MOD = 1e9 + 7;

typedef __int128 LL;

// Hàm tính toán a^b mod (10^9 + 7) với a, b dạng __int128
LL powMod(LL a, LL b) {
    if (b == 0) {
        return 1;
    }
    if (b == 1) {
        return a % (LL)MOD;
    }
    LL half = powMod(a, b/2);
    if (b % 2 == 0) {
        return half * half % (LL)MOD;
    }
    else {
        return half * half % (LL)MOD * a % (LL)MOD;
    }
}

// Hàm chuyển đổi string thành kiểu dữ liệu __int128
LL strToInt128(string s) {
    LL res = 0;
    for (int i = 0; i < (int)s.length(); i++) {
        res = res * 10 + (s[i] - '0');
    }
    return res;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    LL a = strToInt128(s1);
    LL b = strToInt128(s2);
    cout << (long long)powMod(a, b) << endl;
    return 0;
}
