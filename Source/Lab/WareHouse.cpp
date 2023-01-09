#include<bits/stdc++.h>

using namespace std;

#define MAX 1000

int N, T, D;
int a[MAX], t[MAX];

void input(){
    cin >> N >> T >> D;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    for(int i = 0; i < N; i++){
        cin >> t[i];
    }
}