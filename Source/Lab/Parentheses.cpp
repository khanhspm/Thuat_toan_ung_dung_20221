#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

bool isValidExpression(string s) {
    stack<char> st;
    unordered_map<char, char> mapping = {{')', '('}, {']', '['}, {'}', '{'}};
    for (char c : s) {
        if (mapping.count(c)) {
            if (st.empty() || st.top() != mapping[c]) {
                return false;
            }
            st.pop();
        } else {
            st.push(c);
        }
    }
    return st.empty();
}

int main() {
    string s;
    cin >> s;
    if (isValidExpression(s)) {
        cout << "1" << endl;
    } else {
        cout << "0" << endl;
            }
    return 0;
}
