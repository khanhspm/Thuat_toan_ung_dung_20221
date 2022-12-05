#include<bits/stdc++.h>

using namespace std;

int n;
int a[100002];
int TSA = 0;

void input(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
}

void Check(int arr[]){
    for(int i = 1; i < n; i++){
        if(a[i] > a[i+1] && a[i] > a[i-1]){
            TSA++;
        }
    }
}

int main(){
    input();
    Check(a);
    cout << TSA;
    return 0;
}