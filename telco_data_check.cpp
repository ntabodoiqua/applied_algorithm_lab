#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<sstream>
using namespace std;

vector<string> from_number;
vector<string> to_number;
vector<string> from_time;
vector<string> end_time;

map<string, int> number_calls;
map<string, int> time_calls;


void input_process(string input, int index) {
    int block = 0;
    string res;
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == ' ') {
            if (block == 1) from_number.push_back(res);
            if (block == 2) to_number.push_back(res);
            if (block == 4) from_time.push_back(res);
            if (block == 5) end_time.push_back(res);
            res = "";
            block++;
            continue;
        } else {
            res += input[i];
        }
    }
    if (block == 1) from_number.push_back(res);
    if (block == 2) to_number.push_back(res);
    if (block == 4) from_time.push_back(res);
    if (block == 5) end_time.push_back(res);
}

void input() {
    string input = "";
    int index = 0;
    while (true) {
    	getline(cin, input);
        if (input == "#") break;
        input_process(input, index);
        index++;
    }
}



int check_phone(string phone) {
    if (phone.size() != 10) return 0;
    for (int i = 0; i < phone.size(); i++) {
        if (phone[i] < '0' || phone[i] > '9') return 0;
    }
    return 1;
}

int query_check_phone() {
    for (int i = 0; i < from_number.size(); i++) {
        if (check_phone(from_number[i]) == 0) return 0;
        if (check_phone(to_number[i]) == 0) return 0;
    }
    return 1;
}

int query_total_calls() {
    return from_number.size();
}

int timeToSeconds(const string& timeStr) {
    int h, m, s;
    char colon; // Để bỏ qua dấu ':'
    stringstream ss(timeStr);
    ss >> h >> colon >> m >> colon >> s;
    return h * 3600 + m * 60 + s;
}

void init_map() {
    for (int i = 0; i < from_number.size(); i++) {
        number_calls[from_number[i]]++;
        time_calls[from_number[i]] += timeToSeconds(end_time[i]) - timeToSeconds(from_time[i]);
    }
}

int query_total_time(string phone) {
    return time_calls[phone];
}

int query_total_calls_from(string phone) {
    return number_calls[phone];
}
void process_query() {
    string query = "";
    while (true) {
        cin >> query;
        if (query == "#") break;
        if (query == "?check_phone_number") {
            cout << query_check_phone() << endl;
        }
        if (query == "?number_calls_from") {
            string phone;
            cin >> phone;
            cout << query_total_calls_from(phone) << endl;
        }
        if (query == "?number_total_calls") {
            cout << query_total_calls() << endl;
        }
        if (query == "?count_time_calls_from") {
            string phone;
            cin >> phone;
            cout << query_total_time(phone) << endl;
        }
    }
}

int main() {
    input();
    init_map();
    process_query();
    return 0;
}