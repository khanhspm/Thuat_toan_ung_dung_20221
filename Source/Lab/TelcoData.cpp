#include<bits/stdc++.h>
#include<string>
#include<vector>
#include<cstring>
#include<sstream>

using namespace std;

const int N = 100000;
vector<string> fnum;
vector<string> frtime;
vector<string> etime;

bool CheckThePhoneNumber(string check_number){
    if(check_number.length() == 10){
        for(int i = 0; i < 10; i++){
            if(check_number[i] != '0' || check_number[i] != '9'){
                return false;
                break;
            }
        }
        return true;
    }else return false;
};


int NumberCallFrom(string from_number){
    int number_call_from = 0;
    for(int i = 0; i < fnum.size(); i++){
        if(fnum[i].compare(from_number) == 0) number_call_from++;
    }
    return number_call_from;
}

int CountTimeCallFrom(string from_number){
    int t = 0;
    for(int i = 0; i < fnum.size(); i++){
        if(fnum[i].compare(from_number) == 0){
            size_t l1;
            char fhour[3];
            l1 = frtime[i].copy(fhour, 2, 0);
            fhour[l1] = '\0';
            size_t l2;
            char fminutes[3];
            l2 = frtime[i].copy(fminutes, 2, 3);
            fhour[l2] = '\0';
            size_t l3;
            char fsecond[3];
            l3 = frtime[i].copy(fsecond, 2, 6);
            fhour[l3] = '\0';
            size_t l4;
            char ehour[3];
            l4 = etime[i].copy(ehour, 2, 0);
            fhour[l4] = '\0';
            size_t l5;
            char eminutes[3];
            l5 = etime[i].copy(eminutes, 2, 3);
            fhour[l5] = '\0';
            size_t l6;
            char esecond[3];
            l6 = etime[i].copy(esecond, 2, 6);
            fhour[l1] = '\0';
            int ft = atoi(fhour) * 3600 + atoi(fminutes) * 60 + atoi(fsecond);
            int et = atoi(ehour) * 3600 + atoi(eminutes) * 60 + atoi(esecond);
            t = et - ft;
        }
    }
    return t;
}

int main(){
    string call;
    int total_calls = 0;
    int number_incorrect = 0;
    do{
        cin >> call;
        if(call == "#") continue;
        total_calls++;
        string from_number , to_number , date , from_time , end_time ;
        cin >> from_number >> to_number >> date >> from_time >> end_time;
        fnum.insert(fnum.begin() ,from_number);
        frtime.insert(frtime.begin(), from_time);
        etime.insert(etime.begin(), end_time);
        if(!CheckThePhoneNumber(from_number) || !CheckThePhoneNumber) number_incorrect++;
    }while(call != "#");

    do{
        cin >> call;
        string S;
        if(call == "#") break;
        if(call == "?check_phone_number"){
            if(number_incorrect == 0) cout << "1" << endl;
            else cout << "0" << endl;
        }else if(call == "?number_calls_from"){
            cin >> S;
            cout << NumberCallFrom(S) << endl;
        }else if(call == "?number_total_calls"){
            cout << total_calls << endl;
        }else if(call == "?count_time_calls_from"){
            cin >> S;
            cout << CountTimeCallFrom(S) << endl;
        }
    }while(1);

    return 0;
}