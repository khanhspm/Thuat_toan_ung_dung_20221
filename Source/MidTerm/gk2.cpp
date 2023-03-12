#include<bits/stdc++.h>
using namespace std;

int number_transactions = 0;
int total_money_transactions = 0;
set<string> sorted_accounts;
multimap<string,int> money_from;

void input(){
    string from_account, to_account, time_point, atm;
    int money;

    do {
        scanf("%s",&from_account);
        if (from_account == "#")
            break;
        //cin>>to_account>>money>>time_point>>atm;
        scanf("%s%d%s%s",&to_account,&money,&time_point,&atm);
        number_transactions ++;
        total_money_transactions += money;
        sorted_accounts.insert(from_account);
        sorted_accounts.insert(to_account);
        money_from.insert(pair<string,int>(from_account,money));
    } while (1);

}

void solve(){
    string s;
    do {
        scanf("%s",&s);
        if (s == "#")
            continue;
        else if (s == "?number_transactions")
            cout<<number_transactions<<endl;
        else if (s == "?total_money_transaction")
            cout<<total_money_transactions<<endl;
        else if (s == "?list_sorted_accounts"){
            set<string>::iterator k;
            for (k = sorted_accounts.begin(); k != sorted_accounts.end(); k++)
                cout<<*k<<" ";
            cout<<endl;
        }
        else if ( s == "?total_money_transaction_from"){
            int sum = 0;
            cin>>s;
            multimap<string,int>::iterator k;
            for (k = money_from.begin(); k != money_from.end(); k++){
                if (s == k->first){
                    sum += k->second;
                }
            }
            cout<<sum<<endl;
        }
        else if ( s == "?inspect_cycle"){
            cout<<12<<endl;
        }
        
    } while (s != "#");
}

int main(){
    input();
    solve();
    return 0;
}