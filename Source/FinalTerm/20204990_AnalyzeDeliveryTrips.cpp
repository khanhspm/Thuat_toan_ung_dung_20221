#include<bits/stdc++.h>

using namespace std;

/*đọc dữ liệu và thực hiện truy vấn
Input: gồm 3 phần:
    -phần 1: một chuõi các ngày liên tiếp, mỗi ngày trên 1 dòng theo định dạng YYYY--MM--DD. được kết thúc bơie một dòng chứa dấu *.
    -phần 2: gồm thông tin về các chuỗi giao hàng. mỗi dòng mô tả về 1 chuyến giao hàng, có định dạng:
                <trip_code> <customer_code> <date> <time> qty
            trong đó: - <tripcode> là mã của chuyến giao hàng, là  xâu kí tự dài trong khoảng [5,20]
                      - <customer_code> là mã khách hàng: là một xâu kí tự dài trong khoảng [5,20]
                      - <date> <time>: ngày giờ giao hnagf của chuyến có mã <trip_code> tới khách hàng có mã <customer_code>,
                        date có định dạng YYYY--MM--DD và time có định dạng hh:mm:ss
                      - qty là số lượng gói hàng mà chuyến có mã <trip_code> giao tới khách có mã <customer_code>
        Mỗi chuyến hàng có thể đi giao tới nhiều khách. thời gian làm việc của 1 chuyến hàng được tính từ thời điểm ngày giờ sớm nhất đến thời điểm ngày giờ muộn nhất 
        mà chuyến đã giao cho khách.              

*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct delivery {
    string trip_code;
    string customer_code;
    string date;
    string time;
    int qty;
};

// Hàm đọc thông tin về các chuyến giao hàng
vector<delivery> read_deliveries() {
    vector<delivery> deliveries;
    string line;

    while (getline(cin, line)) {
        // Kết thúc đọc nếu gặp dấu ***
        if (line == "***") break;

        // Tách thông tin chuyến giao hàng từ dòng đọc được
        delivery d;
        istringstream iss(line);
        iss >> d.trip_code >> d.customer_code >> d.date >> d.time >> d.qty;
        deliveries.push_back(d);
    }

    return deliveries;
}

// Hàm đọc danh sách các ngày liên tiếp
vector<string> read_dates() {
    vector<string> dates;
    string line;

    while (getline(cin, line)) {
        // Kết thúc đọc nếu gặp dấu *
        if (line == "*") break;

        // Thêm ngày vào danh sách
        dates.push_back(line);
    }

    return dates;
}

int CountTime(string ftime, string etime){
    int startTime = 3600*((ftime[0] - '0') * 10 + ftime[1] - '0') + 60 * ((ftime[3] - '0') * 10 + ftime[4] - '0')
                    + ((ftime[6] - '0') * 10 + ftime[7] - '0');
    int endTime = 3600*((etime[0] - '0') * 10 + etime[1] - '0') + 60 * ((etime[3] - '0') * 10 + etime[4] - '0')
                    + ((etime[6] - '0') * 10 + etime[7] - '0');
    return endTime - startTime;
}

// Hàm tìm chuyến giao hàng sớm nhất và muộn nhất trong ngày của chuyến giao hàng
void find_earliest_and_latest_delivery(vector<delivery>& deliveries, string date, string& earliest_time, string& latest_time) {
    earliest_time = "99:99:99";
    latest_time = "00:00:00";

    for(delivery d : deliveries) {
        if(d.date == date) {
            earliest_time = min(earliest_time, d.time);
            latest_time = max(latest_time, d.time);
    }
}
}

// Hamf trả về thời gian làm việc của chuyến giao hàng
void travel_trip_time(vector<delivery>& deliveries, string trip_code){
     string earliest_time = "99:99:99";
    string latest_time = "00:00:00";

    for(delivery d : deliveries) {
        if(d.trip_code == trip_code) {
            earliest_time = min(earliest_time, d.time);
            latest_time = max(latest_time, d.time);
        }
    }
    cout << CountTime(earliest_time, latest_time) << endl;
}

//Hàm tính tổng số tượng gói hàng mà tất cả chuyến hnag đã giao
int total_quantity(vector<delivery>& deliveries) {
    int sum = 0;
    for (delivery& d : deliveries) {
        sum += d.qty;
    }
    return sum;
}

//Ham tính tổng số lượng gói hàng đã giao cho khách hàng có mã <customer_code>
int total_quantity_customer(vector<delivery>& deliveries, string customer_code) {
    int sum = 0;
    for(delivery& d : deliveries) {
        if(d.customer_code == customer_code){
            sum += d.qty;
        }
    }
    return sum;
}

// Hàm trả về số lượng chuyến giao hàng có trong cơ sở dữ liệu
void total_trip(vector<delivery>& deliveries){
map<string, int> trip_count;
    for (delivery d : deliveries) {
        trip_count[d.trip_code]++;
    }
    cout << trip_count.size() << endl;
}

int main() {
    // Đọc thông tin về các chuyến giao hàng và danh sách các ngày
    vector<string> dates = read_dates();
    vector<delivery> deliveries = read_deliveries();

    string type;
    do{
        cin >> type;
        if(type == "***") continue;
        else if(type == "TOTAL_QTY") cout << total_quantity(deliveries) << endl;
        else if(type == "QTY_CUSTOMER"){
            string input;   
            cin >> input;
            cout << total_quantity_customer(deliveries, input) << endl;
        }
        else if(type == "QTY_MAX_PERIOD"){
            
        }
        else if(type == "TOTAL_TRIPS"){
            total_trip(deliveries);
        }
        else if(type == "TRAVEL_TIME_TRIP"){
            string input;
            cin >> input;
            travel_trip_time(deliveries, input);
        }
        else if(type == "MAX_CONFLICT_TRIP"){

        }
    }while(type != "***");

    return 0;
}
