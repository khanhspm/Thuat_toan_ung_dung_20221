#include<bits/stdc++.h>
#include<algorithm>
#include<functional>
#include<math.h>
using namespace std;

const int maxA = 1000;  // max of n,m
int n, m;

int max_histogram(int colums[]){
    deque<int> hcn;
    int topvalue; // top of deque
    int S = 0;
    int max_S = 0; // S of hcn
    int i = 0;
    while(i < n){
        if(hcn.empty() || colums[hcn.front()] <= colums[i]) hcn.push_front(i++);
        else{
            topvalue = colums[hcn.front()];
            hcn.pop_front();
            S = topvalue * i;
            if(!hcn.empty()){
                S = topvalue * (i - hcn.front() - 1);
        }
        max_S = max(S, max_S);
        }
    }

    while(!hcn.empty()){
        topvalue = colums[hcn.front()];
        hcn.pop_front();
        S = topvalue * i;
        if(!hcn.empty()){
                S = topvalue * (i - hcn.front() - 1);
        }
        max_S = max(S, max_S);
    }
    return max_S;
}

int max_hcn(int A[maxA][maxA]){
    int hcn = max_histogram(A[0]);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(A[i][j]){
                A[i][j] += A[i-1][j];
            }
        }
        hcn = max(hcn, max_histogram(A[i]));
    }
    return hcn;
}

int main(){
    cin >> n >> m;
    int a[maxA][maxA];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    cout << max_hcn(a);
}