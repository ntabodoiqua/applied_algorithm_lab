
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<sstream>
#include<iomanip>
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
int timeToSeconds(const string& from_time) {
    int h, m, s;
    char colon; // Để bỏ qua dấu ':'
    stringstream ss(from_time);
    ss >> h >> colon >> m >> colon >> s;
    return h * 3600 + m * 60 + s;
}
int main() {
    input();
    cout << "From " << from_number[0] << " to " << to_number[0] << " from " << from_time[0] << " to " << end_time[0] << endl;
    cout << from_number[1] << endl;
    cout << from_number.size() << endl;
    cout << timeToSeconds(from_time[0]) << endl;
    return 0;

}