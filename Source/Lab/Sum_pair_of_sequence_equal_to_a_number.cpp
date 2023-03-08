#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

void delete_more_M(vector<int> &a, int M) {

    // Sắp xếp các phần tử trong vector theo thứ tự tăng dần
    sort(a.begin(), a.end());
    // Loại bỏ các phần tử lớn hơn M
    a.erase(remove_if(a.begin(), a.end(), [M](int i) { return i > M; }), a.end());

}

int countPairs(vector<int> &vec, int M) {
    unordered_map<int, int> hashTable;
    int count = 0;

    // Khởi tạo bảng băm
    for (int i = 0; i < vec.size(); i++) {
        int elem = vec[i];
        if (hashTable.find(elem) == hashTable.end()) {
            hashTable[elem] = 1;
        } else {
            hashTable[elem]++;
        }
    }

    // Duyệt lại các phần tử trong vector để tìm kiếm cặp phù hợp
    for (int i = 0; i < vec.size(); i++) {
        int elem = vec[i];
        if (hashTable.find(M - elem) != hashTable.end()) {
            count += hashTable[M - elem];
        }

        // Trường hợp phần tử hiện tại có giá trị bằng M - elem, phải trừ đi 1 để không tính trùng
        if (M - elem == elem) {
            count--;
        }
    }

    // Số lượng cặp phù hợp được tìm thấy
    return count / 2;
}


int main(){

    vector<int> a;
    int M, n;
    cin >> n >> M;

    // Nhập giá trị cho vector
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    delete_more_M(a, M);

    cout << countPairs(a, M) << endl;

    return 0;
}