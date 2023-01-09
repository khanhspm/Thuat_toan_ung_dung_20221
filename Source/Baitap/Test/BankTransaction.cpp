#include<bits/stdc++.h>
#include<set>
#include<map>
#include<stdlib.h>

using namespace std;

set<string> Account;

void insertAccount(string s){
    Account.insert(s);
}
void showAccount(){
    for(string x: Account){
        cout << x << " ";
    }
}

map<string, int> totalMoneyTrans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    string type;
    int totalTrans = 0;
    int totalMoney = 0;

// hàm Input    
    do{
        cin >> type;
        if(type == "#") continue;
        totalTrans++;
        string from_account, to_account, time_point, ATM;
        int money;
        cin >> from_account >> to_account; cin >> money; cin >> time_point >> ATM;
        insertAccount(from_account);
        totalMoney += money;
        totalMoneyTrans[from_account] += money;
    }while(type != "#");

// Thực thi
    do{
        cin >> type;
        if(type == "#") continue;
        if(type == "?number_transactions") cout << totalTrans << endl;
        else if(type == "?total_money_transaction") cout << totalMoney << endl;
        else if(type == "?list_sorted_accounts"){
            showAccount();
            cout << endl;
        }
        else if(type == "?total_money_transaction_from"){
            string acc; cin >> acc;
            cout << totalMoneyTrans[acc] << endl;
        }
        else if(type == "?inspect_cycle"){
            int a;
            string acc; cin >> acc >> a;

        }
    }while(type != "#");

    return 0;
}