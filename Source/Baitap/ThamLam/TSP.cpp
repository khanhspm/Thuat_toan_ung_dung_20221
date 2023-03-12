#include<bits/stdc++.h>

using namespace std;

const int N = 1000;
int d[N][N];
int n;

void input() {
    cin  >> n;
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> d[i][j];
        }
    }
}

int selectMin(set<int>& C, int cur){
    int minD = 1e9;
    int selected = -1;
    for(set<int>::iterator it = C.begin(); it!= C.end(); it++){
        int i = *it;    
        if(minD > d[cur][i]){
            minD = d[cur][i];
            selected = i;
        }
    }
    return selected;
}

void greedy(){
    set<int> C;     
    for(int i = 2; i < n; i++){
        C.insert(i);
    }
    int cur = 1;
    vector<int> S;
    S.push_back(cur);
    int F = 0;

    while(C.size() > 0){
        int x = selectMin(C, cur);
        C.erase(x);
        F += d[cur][x];
        S.push_back(x);
        cur = x;
    }
    F += d[cur][1];
    for(int i = 0; i < S.size(); i++){
        cout << S[i] << " ";
    }
    cout << 1 << "length = " << F << endl;
}

int main(){
    input();
    greedy();

    return 0;
}