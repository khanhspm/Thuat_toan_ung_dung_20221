#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

#define MAX 100005

int n;    
vector<int> a;

void insert(int x) {
    a.push_back(x);
    push_heap(a.begin(), a.end(), greater<int>());
}

void deleteMax() {
    pop_heap(a.begin(), a.end(), greater<int>());
    a.pop_back();
}

int returnMax(){
    int size = sizeof(a) / sizeof(a[0]);
    int max = *std::max_element(a, a + size);
    return max;
}

int main(){

    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin>> x;
        insert(x);
    }

    string input;

    do{
        cin >> input;
        if(input == "*") continue;
        else if(input == "insert"){
            int x;
            cin >> x;
            insert(x);
        }
        else if(input == "delete-max"){
            cout << returnMax() << endl;
            deleteMax();
        }
    }
    while(input != "*");
    
    return 0;
}
