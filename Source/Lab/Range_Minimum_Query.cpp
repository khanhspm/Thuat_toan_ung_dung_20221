#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

const int maxN = 1000000;
const int log2maxN = 20;

int n, m, a[maxN], first[maxN], last[maxN], M[maxN][log2maxN];;
int Q = 0; // sum of rmq

void preprocess(int N, int A[maxN]){
    int i, j;
    // Khởi tạo M với các khoảng độ dài 1
    for (i = 0; i < N; i++)
        M[i][0] = i;

  // Tính M với các khoảng dài 2^j
    for (j = 1; 1 << j <= N; j++)
        for (i = 0; i + (1 << j) - 1 < N; i++)
        if (A[M[i][j - 1]] < A[M[i + (1 << (j - 1))][j - 1]])
            M[i][j] = M[i][j - 1];
        else
            M[i][j] = M[i + (1 << (j - 1))][j - 1];        
};

int query(int A[], int st, int ed){
    int j = (int)log2(ed - st +1);  // j = log2(last - first + 1)
    if (A[M[st][j]]
        <= A[M[ed - (1 << j) + 1][j]])
        return A[M[st][j]];
 
    else
        return A[M[ed - (1 << j) + 1][j]];
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    preprocess(n, a);
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> first[i] >> last[i];
        Q += query(a, first[i], last[i]);
    }

    cout << Q;
    
    return 0;
}