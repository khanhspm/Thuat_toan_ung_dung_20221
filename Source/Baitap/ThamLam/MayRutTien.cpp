/*Ở cổng trường THPT Chuyên Sơn La mới được lắp mới một máy rút tiền tự động.
Trong máy có nn loại tiền mệnh giá lần lượt là a_1, a_2, …, a_n
a1,a2,…,an, mỗi mệnh giá có số lượng đủ nhiều.
Khi khách hàng có yêu cầu rút số tiền MM, chương trình điều khiển sẽ xác định xem có
thể trả được số tiền đúng bằng MM không, nếu có, chương trình điều khiển sẽ chọn cách
trả với số lượng tờ ít nhất.

Yêu cầu:Hãy tính số lượng tờ tiền ít nhất để trả số tiền M.*/

#include<bits/stdc++.h>
using namespace std;

#define N 20

int n, M, a[N];

void input (){
    cin >> n >> M;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
}

int gready(int x, int y[], int z[], int t){
    int count = 0;
    for(int i = t - 1; i > 0; i--){
        y[i] = 0;
        while(z[i] <= x){
            x -= z[i];
            y[i]++;
        }
        count += y[i];
    }
    return count;
}

int main(){
    int b[N];
	input();
    cout << gready(M, b, a, n);
    
    return 0;
}