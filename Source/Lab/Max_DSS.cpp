#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

int T, N[], C[], result[];

void input(){
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> N[i];
        for(int j = 0; j < N[i]; j++){
            cin >> C[j];
        }
    }
}



int main(){
    input();
}