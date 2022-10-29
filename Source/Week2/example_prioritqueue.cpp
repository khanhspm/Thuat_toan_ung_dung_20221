#include <bits/stdc++.h>
using namespace std;

struct Node{
    int k;
    int value;
    string name;
    Node(int _k, int _value){
        k = _k; value = _value;
    }
};

bool cmp(Node& n1, Node& n2){
    return n1.k < n2.k;
}

int main(){
    priority_queue<int> Q; // max priority queue
    priority_queue<int, vector<int>, greater<int> > P; // min priority queue
    Q.push(4);  P.push(4);
    Q.push(1); P.push(1);
    Q.push(100); P.push(100);
    Q.push(50);  P.push(50);

    while(!Q.empty()){
        int e = Q.top(); Q.pop(); int f = P.top(); P.pop();
        cout << "POP Q " << e << "  : POP P " << f << endl;
    }

    stack<int> S;
    S.push(4);
    S.push(9);
    S.push(1);
    while(!S.empty()){
        int e = S.top();
        S.pop(); // loai bo e khoi S
        cout << "S pop " << e << endl;
    }

    queue<int> QQ;
    QQ.push(4);
    QQ.push(9);
    QQ.push(1);
    while(!QQ.empty()){
        int e = QQ.front();
        QQ.pop(); // loai bo phan tu ra khoi queue
        cout << "POP QQ " << e << endl;
    }


    // thu vien cho tap hop set
    set<int> R;
    R.insert(7);
    R.insert(2);
    R.insert(10);
    set<int>::iterator it;
    for(it = R.begin(); it != R.end(); it++){
        cout << "R : " << *it << endl;
    }

    // find operation on set
    int k = 100;
    it = R.find(k);
    if(it == R.end()){
        cout << "not found " << k << endl;
    }else{
        cout << "found " << k << endl;
    }

    // remove an element from te set
    R.erase(2);
    cout << "after remove " << endl;
    for(it = R.begin(); it != R.end(); it++){
        cout << "R : " << *it << endl;
    }

    // vector: dynamic array
    vector<int> a;
    vector<int> b (5, 100);
    for(int i = 1; i <= 10; i++) a.push_back(i);
    for(int i = 0; i < b.size(); i++)
        cout << b[i] << " ";
    cout << endl;

    // mapping library
    map<string, int> m;
    m["abc"] = 1;
    m["xyz"] = 10;
    m["tuv"] = 100;

    string s("abc");
    cout << "map[" << s << "] = " << m[s] << endl;

    for(map<string,int>::iterator it = m.begin(); it != m.end(); it++){
        cout << it->first << " " << it->second << endl;
    }

    // sort library
    a[0] = 123;
    a[1] = 12;
    a[2] = 456;
    a[3] = 789;

    cout << "before sorting: ";
    for(int i = 0; i < a.size(); i++) cout << a[i] << " "; cout << endl;

    vector<int>::iterator it1 = a.begin(); it1++;
    sort(it1, a.end(), greater<int>());

    cout << "after sorting: ";
    for(int i = 0; i < a.size(); i++) cout << a[i] << " "; cout << endl;

    vector<Node> V;
    V.push_back(Node(1,99));
    V.push_back(Node(2,98));
    V.push_back(Node(9,91));
    V.push_back(Node(4,96));
    sort(V.begin(), V.end(), cmp);
    for(int i = 0; i < V.size(); i++){
        cout << V[i].k << "," << V[i].value << endl;
    }
    return 0;
}
