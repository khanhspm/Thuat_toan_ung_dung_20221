// Biểu diễn tập hợp

#include <bits/stdc++.h>
using namespace std;

bool contain(int x, int S){
    if(S & (1 << x)) return true;
    else return false;
}
int main(){
    for(int i = 0; i <= 5; i++){
        int a = (1 << i);
        cout << i << ": " << a << endl;
    }

    int b = (1 << 0) | (1 << 3) | (1 << 4);   // b = 2^0 + 2^3 + 2^4
    cout << "b = " << b << endl;
    cout << contain(7, b) << endl;
    b = b | (1 << 7); // insert 7 into the set represented by b
    cout << contain(7,b) << endl;


    return 0;
}
