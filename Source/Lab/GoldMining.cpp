#include<bits/stdc++.h>

using namespace std;

#define MAX 10006

int N, L1, L2;
int a[MAX], F[MAX];

void input(){
    cin >> N >> L1 >> L2;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
}

// F[i] là số lượng lớn nhất mỗi khi chọn i.

// Tìm gtri F[i] lớn nhất trong đoạn [i-L2; i-L1]
int MAX_SLL(int i){
    int temp = 0;
    if(i - L2 > 0)
    for(int j = i - L2; j <= i - L1; j++){
        if(F[j] > temp) temp = F[j];
    }
    else for(int j = 0; j <= i - L1; j++){
        if(F[j] > temp) temp = F[j];
    }
    return temp;
}

int MAX_GOLD(){ 
    for(int i = 0; i < N; i++){
        F[i] = a[i] + MAX_SLL(i);
    }
    int temp_g = F[0];
    for(int i = 0; i < N; i++){
        if(F[i] > temp_g) temp_g = F[i];
    }
    return temp_g;
}

int main(){
    input();
    cout << MAX_GOLD;
}